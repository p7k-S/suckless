#!/bin/sh

layout=$(xset -q | grep LED | awk '{ print $10 }')

case "$layout" in
 "00000000"|"00000001") out="US" ;;
 "00001000"|"00001001") out="RU" ;;
  *) out="??" ;;
esac

echo "$out"
