#!/bin/bash

kill $(ps -u $USER | rg startup_dwm.sh | awk {'print $1'})
kill $(ps -u $USER | rg .xinitrc | awk {'print $1'})
