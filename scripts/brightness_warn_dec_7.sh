#!/bin/sh

brightness () {
    flag_file7="/tmp/battery_brightness_flag7"

    # Проверяем, существует ли файл-флаг
    if [ -f "$flag_file7" ]; then
        exit 0
    fi

    battery_capacity=$(cat /sys/class/power_supply/BAT1/capacity)

    if [ "$battery_capacity" -lt 7 ]; then
        light -S 0
        # notify-send -u critical "BAT LOW 7%" -t 5000
        touch "$flag_file7"
    fi
}

while true; do
  sleep 60 && brightness
done
