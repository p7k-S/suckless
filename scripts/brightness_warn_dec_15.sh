#!/bin/sh

brightness () {
    flag_file15="/tmp/battery_brightness_flag15"

    # Проверяем, существует ли файл-флаг
    if [ -f "$flag_file15" ]; then
        exit 0
    fi

    battery_capacity=$(cat /sys/class/power_supply/BAT1/capacity)

    if [ "$battery_capacity" -lt 15 ]; then
        light -S 20
        # notify-send -u critical "BAT LOW 15%" -t 5000
        touch "$flag_file15"
        ~/.config/suckless/scripts/no_col_icn/brightness_warn_dec_7.sh
    fi
}

while true; do
  sleep 60 && brightness
done
