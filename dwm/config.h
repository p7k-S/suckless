#include <X11/XF86keysym.h>

static const unsigned int borderpx  = 1;
static const unsigned int snap      = 32;
static const int showbar            = 1;
static const int topbar             = 1;
static const char *fonts[]          = { "JetBrainsMono Nerd Font :size=11" };
static const char col_gray1[]       = "#111111";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#ebdbb2";
static const char col_gray4[]       = "#b8bb26";
static const char col_cyan[]        = "#1a1b1c";
static const char bord_inac[]       = "#000000";

static const char *colors[][3]      = {
	[SchemeNorm] = { col_gray3, col_gray1, col_gray1 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_gray2 },
};

static const char *tags[] = { "α", "β", "ɣ", "δ", "ε" };

const char *calc[]              = {"st", "-n", "calculator", "-g", "50x25",  "-e", "python3", "-ic", "from math import *",   NULL };
const char *st_scrpad[]         = {"st", "-n", "task_1",     "-g", "160x20", "-e", "tmux", "attach", "-d", "-t", "scrpad",   NULL };
const char *st_pulsemixer[]     = {"st", "-n", "pulsemixer", "-g", "100x20", "-e", "pulsemixer",                             NULL };

static const Rule rules[] = {
	{ "Gimp",               NULL,               NULL,           1 << 3,         0,              -1 },
	{ "mtpaint",            NULL,               NULL,           1 << 3,         0,              -1 },
	{ "Firefox",            NULL,               NULL,           1 << 1,         0,              -1 },
    { "Thorium-browser",    NULL,               NULL,           1 << 1,         0,              -1 },
    { "qutebrowser",        NULL,               NULL,           1 << 1,         0,              -1 },
    { "TelegramDesktop",    NULL,               NULL,           1 << 2,         0,              -1 },
    { "Pcmanfm",            NULL,               NULL,           0,              1,              -1 },
	{ "St",                 NULL,               NULL,           0,              0,              -1 },
    { "St",                 "stfloat",          NULL,           0,              1,              -1 },
    { "st-256color",        "calculator",       NULL,           0,              1,              -1 },
    { "st-256color",        "task_1",           NULL,           0,              1,              -1 },
    { "st-256color",        "pulsemixer",       NULL,           0,              1,              -1 },
	{ NULL,                 NULL,               "Event Tester",                 0,              -1 },
};

static const float mfact     = 0.55;
static const int nmaster        = 1;
static const int resizehints    = 1;
static const int lockfullscreen = 1;

static const Layout layouts[] = {
	{ "[]=",         tile },
	{ "><>",         NULL },
	{ "[M]",      monocle },
};

#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

static char dmenumon[2] = "0";
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static const char *termcmd[]        = { "st", NULL };
static const char *file_manager[]   = { "pcmanfm", NULL };
static const char *paint[]          = { "mtpaint", NULL };
static const char *browser[]        = { "thorium.AppImage", NULL };
static const char *Telegram[]       = { "telegram-desktop", NULL };
static const char *dmenucmd[]       = { "dmenu_run", "-p", "run:", NULL };
static const char *clipboard[]      = { "clipmenu", "-p", "coppy:", NULL };

static const Key keys[] = {
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
    { MODKEY,			            XK_grave,  spawn,          {.v = st_scrpad}  },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_p,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_n,      zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	{ MODKEY|ShiftMask,             XK_r,      quit,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      spawn,          SHCMD("/home/pavel/.config/suckless/scripts/logout.sh") },
	{ MODKEY|ShiftMask,             XK_k,      spawn,          SHCMD("/home/pavel/.config/suckless/scripts/dmenu-kill") },
    TAGKEYS(                        XK_w,                      1)
    TAGKEYS(                        XK_c,                      2)
    TAGKEYS(                        XK_g,                      3)
    { 0,                            XK_Print,  spawn,          SHCMD("/home/pavel/.config/suckless/scripts/screenshot.sh") },
    { ShiftMask,                    XK_Print,  spawn,          SHCMD("scrot ~/Pictures/Screenshots/%y-%m-%d_%h-%m-%s_$wx$h.png && xsetroot -name ' screenshot saved in ~/Pictures/Screenshots '") },
    { MODKEY,                       XK_v,      spawn, 	       {.v = clipboard} },
    { MODKEY,                       XK_w,      spawn,          {.v = browser} },
    { MODKEY,                       XK_c,      spawn,          {.v = Telegram} },
    { MODKEY,                       XK_e,      spawn,          {.v = file_manager} },
    { MODKEY,                       XK_x,      spawn,          {.v = st_pulsemixer} },
    { MODKEY,                       XK_g,      spawn,          {.v = paint} },
    { 0, XF86XK_Calculator,                    spawn,          {.v = calc} },
    { 0, XF86XK_AudioRaiseVolume,              spawn,          SHCMD("pactl set-sink-volume @DEFAULT_SINK@ +5% && pkill -RTMIN+10 dwmblocks") },
    { 0, XF86XK_AudioLowerVolume,              spawn,          SHCMD("pactl set-sink-volume @DEFAULT_SINK@ -5% && pkill -RTMIN+10 dwmblocks") },
    { 0, XF86XK_AudioMute,                     spawn,          SHCMD("pactl set-sink-volume @DEFAULT_SINK@  0% && pkill -RTMIN+10 dwmblocks") },
    { 0, XF86XK_AudioMicMute,                  spawn,          SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle && pkill -RTMIN+3 dwmblocks") },
    { 0, XF86XK_MonBrightnessUp,               spawn,          SHCMD("light -A 5 && ~/.config/suckless/scripts/brightness.sh") },
    { 0, XF86XK_MonBrightnessDown,             spawn,          SHCMD("light -U 5 && ~/.config/suckless/scripts/brightness.sh") },
    { ShiftMask,          		XK_Alt_L,      spawn,          SHCMD("pkill -RTMIN+2 dwmblocks") },
    { Mod1Mask,                 XK_Shift_L,    spawn,          SHCMD("pkill -RTMIN+2 dwmblocks") },

};

static const Button buttons[] = {
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
