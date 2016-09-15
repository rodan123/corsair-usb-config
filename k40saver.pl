#!/usr/bin/perl
use strict;

my $PATH = "/usr/local/bin";
my $NEWCOLOR = "00aa00";
my $blanked = 0;
my $color;
my $profile;

open (IN, "xscreensaver-command -watch |");
while (<IN>) {
    if (m/^(BLANK|LOCK)/) {
        if (!$blanked) { 
	    $profile=`$PATH/corsair-usb-config current-profile get`;
            $color=`$PATH/corsair-usb-config profile-color get`;
            chomp ($color);
            chomp ($profile);
            system "$PATH/corsair-usb-config profile-color set $profile $NEWCOLOR";
            system "$PATH/corsair-usb-config animation set pulse";
            $blanked = 1;
        }
    } elsif (m/^UNBLANK/) {
        system "$PATH/corsair-usb-config animation set off";
        system "$PATH/corsair-usb-config profile-color set $profile $color";
        $blanked = 0;
    }
}
