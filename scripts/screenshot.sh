#!/bin/sh

if [ !"$(pidof screenshot.sh)" ]; then
    if [ "$(pidof dwmblocks)" ]; then
        killall dwmblocks
    fi
    if [ $(ps -u $USER | rg unclutter | awk {'print $1'}) ]; then
        kill $(ps -u $USER | rg unclutter | awk {'print $1'}) 
    fi

    scrot -s -f '/tmp/%F_%T_$wx$h.png' -e 'xclip -selection clipboard -target image/png -i $f'
    xsetroot -name ' screenshot copied to clipboard '
    unclutter -idle 2 &

    # sleep 2
    if ! pgrep -x dwmblocks > /dev/null; then
        dwmblocks
    fi
fi
