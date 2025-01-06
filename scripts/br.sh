#!/bin/sh

echo "$(cat /sys/class/backlight/*/brightness)" | tr -d '-'
