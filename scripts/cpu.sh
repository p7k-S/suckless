#!/bin/sh

cpu_val=$(grep -o "^[^ ]*" /proc/loadavg)
echo "$cpu_val $(cat /sys/class/thermal/thermal_zone0/temp | sed 's/\(.\)..$/.\1°C/')"
