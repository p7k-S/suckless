#!/bin/sh


br=$(echo "$(cat /sys/class/backlight/*/brightness)" | tr -d '-')
if [ "$br" -eq 0 ] || [ "$br" -eq 255 ]; then
    if [ "$(pidof dwmblocks)" ]; then
        killall dwmblocks
    fi
    # xsetroot -name " LIMIT OF BRIGHTNESS                                                                                                 "
    xsetroot -name " LIMIT OF BRIGHTNESS "
    sleep 1
    if ! pgrep -x dwmblocks > /dev/null; then
        dwmblocks
    fi
fi
