/*
 * Copyright 2016 Clément Vuchener
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "K40Device.h"

K40Device::K40Device (libusb_device *dev):
	CorsairDevice (dev, sizeof (K40Status))
{
}

void K40Device::setAnimationMode (unsigned int mode, unsigned int rate)
{
	int ret;
	ret = libusb_control_transfer (_dev, RequestOutType,
						       SetBacklightAnimation, 0, mode,
						       nullptr, 0, 0);
	if (ret < 0) {
		throw std::runtime_error (libusb_error_name (ret));
	}
	if (rate) {
		ret = libusb_control_transfer (_dev, RequestOutType,
						       SetAnimationRate, rate, 0,
						       nullptr, 0, 0);
		if (ret < 0) {
			throw std::runtime_error (libusb_error_name (ret));
		}
	}
}
unsigned int K40Device::getAnimationMode ()
{
	std::vector<uint8_t> raw_status = getRawStatus ();
	K40Status *status = reinterpret_cast<K40Status *> (raw_status.data ());
	return status->animation_mode;
}
unsigned int K40Device::getAnimationRate ()
{
	std::vector<uint8_t> raw_status = getRawStatus ();
	K40Status *status = reinterpret_cast<K40Status *> (raw_status.data ());
	return status->animation_rate;
}

unsigned int K40Device::getBacklightBrightness ()
{
	std::vector<uint8_t> raw_status = getRawStatus ();
	K40Status *status = reinterpret_cast<K40Status *> (raw_status.data ());
	return status->backlight_brightness;
}

void K40Device::setBacklightBrightness (unsigned int brightness)
{
	int ret;
	if (brightness > 3)
		brightness = 3;
	ret = libusb_control_transfer (_dev, RequestOutType, SetBacklightBrightness,
				       brightness << 8, 0, nullptr, 0, 0);
	if (ret < 0) {
		throw std::runtime_error (libusb_error_name (ret));
	}
}

unsigned int K40Device::getCurrentProfile ()
{
	std::vector<uint8_t> raw_status = getRawStatus ();
	K40Status *status = reinterpret_cast<K40Status *> (raw_status.data ());
	return status->current_profile;
}

Color K40Device::getProfileColor (unsigned int profile_index)
{
	std::vector<uint8_t> raw_status = getRawStatus ();
	K40Status *status = reinterpret_cast<K40Status *> (raw_status.data ());
	return status->color;
}

void K40Device::setProfileColor (unsigned int profile_index, Color color)
{
	int ret;
	if (profile_index > 3) {
		throw std::invalid_argument ("Invalid profile index.");
	}
	ret = libusb_control_transfer (_dev, RequestOutType, SetBacklightColor,
				       color.r | color.g << 8, color.b | profile_index << 8,
				       nullptr, 0, 0);
	if (ret < 0) {
		throw std::runtime_error (libusb_error_name (ret));
	}
}

