#!/bin/sh

# echo "$(xbps-install --memory-sync --dry-run --update | grep -Fe update -e install | wc -l)"
echo $(pacman -Qu | wc -l)
echo $({ checkupdates 2>/dev/null || true; } | wc -l) # arch
