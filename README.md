Corsair USB configuration tool
==============================

This is a fork of the corsair-usb-config project by Clément Vuchener (https://github.com/cvuchener/corsair-usb-config)

It is a configuration tool for Corsair gaming keyboards using the older USB protocol (not the newer Corsair keyboards using pure HID configuration, e.g. RGB keyboards, supported by [ckb](https://github.com/ccMSC/ckb)). Currently supported devices are:
 - Vengeance K90
 - Raptor K40

-------------------------------------->> See README.orig

I found that certain functions did not work properly with my Corsair K40 keyboard, so I created this fork to remedy that.


08/16/16

1) Found 'profile-color set index color' function did not work as expected. Color set was wildly incorrect. Modified code to properly set the correct color. 

2) Found 'profile-color get index' function only returned value of the currently selected profile no matter which index was specified. Could not find a way to retrieve a profile's color without switching to it. Modified program to quickly switch to the requested index, retrieve the color value, and then switch back to the original profile.

3) Program hung on the K40 using the sample default.json file to clear function keys, because the k40 only has 6 function keys. Included a default-k40.json file and also a sample k40.json.

08/17/16

4) In an attempt to make this the one application to control all of the functions of my Corsair K40 keyboard, implemented a new option to set and get the keyboard's animation mode. The "cycle" animation doesn't work properly. Seems there is more to it than just setting the mode. Since I haven't a K90, the program will return an "unimplemented" message for the animation arguments on that keyboard. 

8/18/16

5) Modified 'profile-color get' to return the color of the current profile if no index is specified.

6) Included small demo perl program (k40saver.pl) to change the color and animation of the keyboard when xscreensaver starts and then restore the original values when the screensaver stops. I use the matrix screensaver, it changes the keyboard color to green and sets the animation to pulse while the screensaver is active. Edit the file to point to your installation of corsair-usb-config.

08/19/16

7) Added code to set and get the K40 Animation rate. "Cycle" animation is still not functional.
