//Modify this file to change what commands output to your statusbar, and recompile using the make command.

static const Block blocks[] = {
	/*Icon*/    /*Command*/	/*Update Interval*/ /*Update Signal*/
	// {"",    "ker.sh",        0,	    0},
	// {" ",   "br.sh",	0,		5},
	{" ",  "updates.sh",       300,	13},
	{"",    "uptime.sh",        60,	    0},
	{"",    "battery.sh",       30,		9},
	{"",    "disks.sh",	        60,		0},
	{"",    "cpu.sh",	        10,		12},
	{"",    "mem.sh",	        10,		14},
    {"",	"keyboard_lay.sh",  0,	    2},
    {"",	"mic.sh",	        0,      3},
	{"",	"volume.sh",        0,      10},
	{"",    "bluetooth.sh",	    1,    	0},
	{"",	"net.sh",	        1,    	0},
	{"",    "date.sh",		    1,      0},
	{"",    "time.sh",		    1,      0},
};

static char delim[] = "  ";
static unsigned int delimLen = 5;
//sets delimiter between status commands. NULL character ('\0') means no delimiter.
// static char delim[] = " ¦│░⁞║";
