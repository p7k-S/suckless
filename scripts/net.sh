#!/bin/sh

if [ "$(pidof dhcpcd)" ]; then
    printf "$(ip -o route get to 8.8.8.8 | sed -n 's/.*src \([0-9.]\+\).*/\1/p')"
elif [ "$(pidof iwd)" ]; then
    printf "%s %s" "$(tail -n1 /proc/net/wireless | cut -d" "  -f3- | awk '{print $1}' | rev | cut -c 2- | rev)%" "$(iwctl station wlp4s0 show | grep "Connected network" | awk '{print $NF}')"
else
    printf "DOWN"
fi

update() {
    sum=0
    for arg; do
        read -r i < "$arg"
        sum=$(( sum + i ))
    done
    cache=/tmp/${1##*/}
    [ -f "$cache" ] && read -r old < "$cache" || old=0
    printf %d\\n "$sum" > "$cache"
    printf %d\\n $(( sum - old ))
}

rx=$(update /sys/class/net/[ew]*/statistics/rx_bytes)
tx=$(update /sys/class/net/[ew]*/statistics/tx_bytes)

printf " %4sB/%4sB\\n" $(numfmt --to=iec $rx $tx)
