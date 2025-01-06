#!/bin/sh

started="$(ps -e | grep 'bluetoothd' | tail -c2)"

if [ "$started" = 'd' ]; then
    echo "B:$(bluetoothctl info | grep Name: | sed 's/^[[:space:]]*//g' | sed -e "s/ //g" | sed 's/Name://g')$(bluetoothctl info | rg Battery | tail --bytes 6)"
fi
