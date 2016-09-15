/*
 * Copyright 2015 Clément Vuchener
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

#include "KeyUsage.h"

const std::map<std::string, uint8_t> KeyUsage::keymap = {
	{ "A", 0x04 },
	{ "B", 0x05 },
	{ "C", 0x06 },
	{ "D", 0x07 },
	{ "E", 0x08 },
	{ "F", 0x09 },
	{ "G", 0x0a },
	{ "H", 0x0b },
	{ "I", 0x0c },
	{ "J", 0x0d },
	{ "K", 0x0e },
	{ "L", 0x0f },
	{ "M", 0x10 },
	{ "N", 0x11 },
	{ "O", 0x12 },
	{ "P", 0x13 },
	{ "Q", 0x14 },
	{ "R", 0x15 },
	{ "S", 0x16 },
	{ "T", 0x17 },
	{ "U", 0x18 },
	{ "V", 0x19 },
	{ "W", 0x1a },
	{ "X", 0x1b },
	{ "Y", 0x1c },
	{ "Z", 0x1d },
	{ "1", 0x1e },
	{ "2", 0x1f },
	{ "3", 0x20 },
	{ "4", 0x21 },
	{ "5", 0x22 },
	{ "6", 0x23 },
	{ "7", 0x24 },
	{ "8", 0x25 },
	{ "9", 0x26 },
	{ "0", 0x27 },
	{ "Return", 0x28 },
	{ "Enter", 0x28 },
	{ "Escape", 0x29 },
	{ "Esc", 0x29 },
	{ "Backspace", 0x2a },
	{ "Tab", 0x2b },
	{ "Space", 0x2c },
	{ "Minus", 0x2d },
	{ "Equal", 0x2e },
	{ "LeftBrace", 0x2f },
	{ "RightBrace", 0x30 },
	{ "BackSlash", 0x31 },
	{ "BackSlashNonUS", 0x32 },
	{ "SemiColon", 0x33 },
	{ "Apostrophe", 0x34 },
	{ "Grave", 0x35 },
	{ "AboveTab", 0x35 },
	{ "Comma", 0x36 },
	{ "Dot", 0x37 },
	{ "Slash", 0x38 },
	{ "CapsLock", 0x39 },
	{ "F1", 0x3a },
	{ "F2", 0x3b },
	{ "F3", 0x3c },
	{ "F4", 0x3d },
	{ "F5", 0x3e },
	{ "F6", 0x3f },
	{ "F7", 0x40 },
	{ "F8", 0x41 },
	{ "F9", 0x42 },
	{ "F10", 0x43 },
	{ "F11", 0x44 },
	{ "F12", 0x45 },
	{ "PrintScreen", 0x46 },
	{ "ScrollLock", 0x47 },
	{ "Pause", 0x48 },
	{ "Insert", 0x49 },
	{ "Home", 0x4a },
	{ "PageUp", 0x4b },
	{ "Delete", 0x4c },
	{ "Del", 0x4c },
	{ "End", 0x4d },
	{ "PageDown", 0x4e },
	{ "RightArrow", 0x4f },
	{ "Right", 0x4f },
	{ "LeftArrow", 0x50 },
	{ "Left", 0x50 },
	{ "DownArrow", 0x51 },
	{ "Down", 0x51 },
	{ "UpArrow", 0x52 },
	{ "Up", 0x52 },
	{ "NumLock", 0x53 },
	{ "KeyPadSlash", 0x54 },
	{ "KeyPadDivide", 0x54 },
	{ "KeyPadAsterisk", 0x55 },
	{ "KeyPadMultiply", 0x55 },
	{ "KeyPadMinus", 0x56 },
	{ "KeyPadPlus", 0x57 },
	{ "KeyPadEnter", 0x58 },
	{ "KeyPad1", 0x59 },
	{ "KeyPad2", 0x5a },
	{ "KeyPad3", 0x5b },
	{ "KeyPad4", 0x5c },
	{ "KeyPad5", 0x5d },
	{ "KeyPad6", 0x5e },
	{ "KeyPad7", 0x5f },
	{ "KeyPad8", 0x60 },
	{ "KeyPad9", 0x61 },
	{ "KeyPad0", 0x62 },
	{ "KeyPadDot", 0x63 },
	{ "102nd", 0x64 },
	{ "Compose", 0x65 },
	{ "Power", 0x66 },
	{ "KeyPadEqual", 0x67 },
	{ "F13", 0x68 },
	{ "F14", 0x69 },
	{ "F15", 0x6a },
	{ "F16", 0x6b },
	{ "F17", 0x6c },
	{ "F18", 0x6d },
	{ "F19", 0x6e },
	{ "F20", 0x6f },
	{ "G1", 0xd0 },
	{ "G2", 0xd1 },
	{ "G3", 0xd2 },
	{ "G4", 0xd3 },
	{ "G5", 0xd4 },
	{ "G6", 0xd5 },
	{ "G7", 0xd6 },
	{ "G8", 0xd7 },
	{ "G9", 0xd8 },
	{ "G10", 0xd9 },
	{ "G11", 0xda },
	{ "G12", 0xdb },
	{ "G13", 0xdc },
	{ "G14", 0xdd },
	{ "G15", 0xde },
	{ "G16", 0xdf },
	{ "G17", 0xe8 },
	{ "G18", 0xe9 },
	{ "LeftControl", 0xe0 },
	{ "LeftShift", 0xe1 },
	{ "LeftAlt", 0xe2 },
	{ "LeftMeta", 0xe3 },
	{ "RightControl", 0xe4 },
	{ "RightShift", 0xe5 },
	{ "RightAlt", 0xe6 },
	{ "AltGr", 0xe6 },
	{ "RightMeta", 0xe7 },
};

const std::map<std::string, std::map<std::string, uint8_t>> KeyUsage::layouts = {
	{ "AZERTY-Fr", {
		{ "A", 0x14 },
		{ "Z", 0x1a },
		{ "Q", 0x04 },
		{ "M", 0x33 },
		{ "W", 0x1d },
		{ "Square", 0x35 },
		{ "Ampersand", 0x1e },
		{ "EAcute", 0x1f },
		{ "Quotes", 0x20 },
		{ "Apostrophe", 0x21 },
		{ "LeftParenthesis", 0x22 },
		{ "Minus", 0x23 },
		{ "EGrave", 0x24 },
		{ "Underscore", 0x25 },
		{ "CCedilla", 0x26 },
		{ "AGrave", 0x27 },
		{ "RightParenthesis", 0x2d },
		{ "Circumflex", 0x2f },
		{ "Dollar", 0x30 },
		{ "UGrave", 0x34 },
		{ "Asterisk", 0x32 },
		{ "Comma", 0x10 },
		{ "SemiColon", 0x36 },
		{ "Colon", 0x37 },
		{ "Exclamation", 0x38 },
		{ "LessThan", 0x64 },
	}},
};
