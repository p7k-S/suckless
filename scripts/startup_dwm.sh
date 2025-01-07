#!/bin/sh

# feh --bg-scale /home/pavel/Pictures/Wallpapers/zdanie_minimalizm_chb_132403_1920x1080.jpg
# feh --bg-scale /home/pavel/Pictures/Wallpapers/saso-tusar-s-k-2N90yuY.jpg
# picom --vsync --backend glx --inactive-dim 0.2 --no-fading-openclose --inactive-dim-fixed --config /dev/null --focus-exclude "x = 0 && y = 0 && override_redirect = true" &
# pgrep copyq || copyq --start-server && copyq hide
# nm-applet &
# twmnd &
setxkbmap us,ru -option 'grp:alt_shift_toggle' -option ctrl:swapcaps &
xset r rate 300 30 &
unclutter -idle 2 &
dwmblocks &
clipmenud &
# xcompmgr &
picom --config ~/.config/picom/picom.conf &
# feh --bg-scale /home/pavel/Pictures/Wallpapers/monochrome_leafs.avif &
feh --bg-scale /home/pavel/Pictures/Wallpapers/zvezdnoe_nebo_derevo_noch_119989_2560x1440.jpg &
brightness_warn_dec_15.sh &
scrpad.sh &
# xrdb -merge -I$HOME ~/.Xresources &
/usr/libexec/xfce-polkit &

telegram-desktop &
st &
thorium.AppImage &
# xrdb -merge -I$HOME ~/.Xresources &
# qutebrowser &
# firefox &


while true; do 
    dwm 2> ~/.config/suckless/logs/dwm.log
done
