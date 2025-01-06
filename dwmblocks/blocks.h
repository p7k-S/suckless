//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/            	            /*Command*/	                  /*Update Interval*/ 	/*Update Signal*/
	// {" ",    "/home/pavel/.config/suckless/scripts/no_col_icn/br.sh",	0,		5},
	{" ",    "xbps-install -Sun | wc -l",                                         300,	    13},
	{"",    "/home/pavel/.config/suckless/scripts/no_col_icn/uptime.sh",        60,	    0},
	// {"",    "/home/pavel/.config/suckless/scripts/no_col_icn/ker.sh",           0,	    0},
	// {"",    "/home/pavel/.config/suckless/scripts/no_col_icn/pkg_updates.sh",  300,	    13},
	{"",    "/home/pavel/.config/suckless/scripts/no_col_icn/battery.sh",      30,		9},
	{"",    "/home/pavel/.config/suckless/scripts/no_col_icn/disks.sh",	60,		0},
	{"",    "/home/pavel/.config/suckless/scripts/no_col_icn/cpu.sh",	        10,		12},
	{"",    "/home/pavel/.config/suckless/scripts/no_col_icn/mem.sh",	        10,		14},
    {"",	"/home/pavel/.config/suckless/scripts/no_col_icn/keyboard_lay.sh",   0,	    2},
    {"",	"/home/pavel/.config/suckless/scripts/no_col_icn/mic.sh",	        0,      3},
	{"",	"/home/pavel/.config/suckless/scripts/no_col_icn/volume.sh",        0,      10},
	{"",    "/home/pavel/.config/suckless/scripts/no_col_icn/bluetooth.sh",	    1,    	0}, //??? нужно каждую сек
	{"",	"/home/pavel/.config/suckless/scripts/no_col_icn/net.sh",	        1,    	0},
	{"",    "/home/pavel/.config/suckless/scripts/no_col_icn/date.sh",		    1,      0},
	{"",    "/home/pavel/.config/suckless/scripts/no_col_icn/time.sh",		    1,      0},
};

//sets delimiter between status commands. NULL character ('\0') means no delimiter.
// static char delim[] = " ¦│░⁞║";
static char delim[] = "  ";
static unsigned int delimLen = 5;
