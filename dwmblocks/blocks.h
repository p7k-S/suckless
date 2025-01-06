//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/            	            /*Command*/	                  /*Update Interval*/ 	/*Update Signal*/
	// {" ",    "/home/pavel/.config/suckless/scripts/br.sh",	0,		5},
	{" ",    "xbps-install -Sun | wc -l",                                         300,	    13},
	{"",    "/home/pavel/.config/suckless/scripts/uptime.sh",        60,	    0},
	// {"",    "/home/pavel/.config/suckless/scripts/ker.sh",           0,	    0},
	// {"",    "/home/pavel/.config/suckless/scripts/pkg_updates.sh",  300,	    13},
	{"",    "/home/pavel/.config/suckless/scripts/battery.sh",      30,		9},
	{"",    "/home/pavel/.config/suckless/scripts/disks.sh",	60,		0},
	{"",    "/home/pavel/.config/suckless/scripts/cpu.sh",	        10,		12},
	{"",    "/home/pavel/.config/suckless/scripts/mem.sh",	        10,		14},
    {"",	"/home/pavel/.config/suckless/scripts/keyboard_lay.sh",   0,	    2},
    {"",	"/home/pavel/.config/suckless/scripts/mic.sh",	        0,      3},
	{"",	"/home/pavel/.config/suckless/scripts/volume.sh",        0,      10},
	{"",    "/home/pavel/.config/suckless/scripts/bluetooth.sh",	    1,    	0}, //??? нужно каждую сек
	{"",	"/home/pavel/.config/suckless/scripts/net.sh",	        1,    	0},
	{"",    "/home/pavel/.config/suckless/scripts/date.sh",		    1,      0},
	{"",    "/home/pavel/.config/suckless/scripts/time.sh",		    1,      0},
};

//sets delimiter between status commands. NULL character ('\0') means no delimiter.
// static char delim[] = " ¦│░⁞║";
static char delim[] = "  ";
static unsigned int delimLen = 5;
