#!/bin/sh

cd && pacman -Qq > Backups/installed_pkgs && pacman -Qmq >> Backups/installed_pkgs && tar czf cfg_backup_arch.tar.gz \
    Pictures/Wallpapers/gruv_leaf.jpg \
    ~/Backups/installed_pkgs \
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
    /usr/share/xsessions/dwm.desktop \
    /etc/X11/xorg.conf.d/* \
    /etc/doas.conf \
    /etc/pacman.d/mirrorlist \
    /etc/pacman.conf \
    && mv cfg_backup_arch.tar.gz Backups && cd -


    # .config/minimal/suckless.tar.gz \
    # /etc/pacman.d/mirrorlist_sorted.backup \
    
    # .fonts/JetBrains/* \
    
    # .xinitrc \
    # /etc/doas.conf \
    # /etc/pacman.conf \
    # /etc/pacman.d/mirrorlist \
    # /etc/pacman.d/mirrorlist_sorted.backup \
    # /etc/X11/xorg.conf.d/* \
