#!/bin/sh

# echo "$(xbps-install --memory-sync --dry-run --update | grep -Fe update -e install | wc -l)"
echo $(pacman -Qu | wc -l)
