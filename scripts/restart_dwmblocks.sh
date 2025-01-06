#!/bin/sh

if [ "$(pidof dwmblocks)" ]; then
    killall dwmblocks
fi
sleep 1
if ! pgrep -x dwmblocks > /dev/null; then
    dwmblocks
fi
