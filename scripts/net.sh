#!/bin/sh

if [ $(ip link | rg DOWN | wc -l) == 2 ]; then
    printf "$(ip -o route get to 8.8.8.8 | sed -n 's/.*src \([0-9.]\+\).*/\1/p')"
elif [ "$(pidof iwd)" ]; then
    q="$(awk 'NR>2 {print $3}' /proc/net/wireless | sed 's/.$//')"
    qp=$((q * 100 / 70))
    printf "%s %s" $qp% "$(iwctl station wlan0 show | grep "Connected network" | awk '{print $NF}')"
    # printf "%s %s" "$(tail -n1 /proc/net/wireless | cut -d" "  -f3- | awk '{print $1}' | rev | cut -c 2- | rev)%" "$(iwctl station wlan0 show | grep "Connected network" | awk '{print $NF}')"
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
