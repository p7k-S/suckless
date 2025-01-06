#!/bin/sh

mic="$(pactl list | sed -n '/^Source/,/^$/p' | grep Mute | grep yes | tail -c2)"

case "$mic" in
 "s") echo "$(pactl list | sed -n '/^Source/,/^$/p' | grep yes | wc -l) M" ;;
  *) echo "UNM" ;;
esac
