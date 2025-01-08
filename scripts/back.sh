#!/bin/sh

cd && xpkg -m > Backups/installed_pkgs && tar czf cfg_backup_void.tar.gz \
    ~/Backups/back.sh \
    ~/Backups/installed_pkgs \
    .fonts/JetBrains/* \
    .config/zathura/* \
    .Xresources \
    .gitstatus/* \
    .config/mimeapps.list \
    .config/suckless/* \
    .config/nvim \
    .config/picom \
    .aliasrc \
    .bash_profile \
    .bashrc \
    .zshrc \
    .Xresources \
    .tmux.conf \
    Pictures/Wallpapers/zdanie_minimalizm_chb_132403_1920x1080.jpg\
    Pictures/Wallpapers/zvezdnoe_nebo_derevo_noch_119989_2560x1440.jpg\
    /etc/doas.conf \
    /etc/X11/xorg.conf.d/* \
    /etc/iwd/* \
    /usr/share/xsessions/dwm.desktop \
    && mv cfg_backup_void.tar.gz Backups && cd -


    # .config/minimal/suckless.tar.gz \
    # /etc/pacman.d/mirrorlist_sorted.backup \
    
    # .xinitrc \
    # /etc/doas.conf \
    # /etc/pacman.conf \
    # /etc/pacman.d/mirrorlist \
    # /etc/pacman.d/mirrorlist_sorted.backup \
    # /etc/X11/xorg.conf.d/* \
