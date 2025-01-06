#!/bin/sh

partition="/dev/nvme0n1p6"; #root
if mountpoint -q $(df --output=target $partition | tail -n +2); then
    usage=$(df -h | grep "$partition")
    size=$(echo "$usage" | awk '{print $2}')
    used=$(echo "$usage" | awk '{print $3}')
    # avail=$(echo "$usage" | awk '{print $4}')
    # percent=$(echo "$usage" | awk '{print $5}')

    # echo "Drive: $partition"
    printf "$used/$size "
    # echo "  Used: $used"
    # echo "  Available: $avail"
    # echo "  Usage: $percent"
    # echo
fi

partition="/dev/nvme0n1p7"; #home
if mountpoint -q $(df --output=target $partition | tail -n +2); then
    usage=$(df -h | grep "$partition")
    size=$(echo "$usage" | awk '{print $2}')
    used=$(echo "$usage" | awk '{print $3}')
    # avail=$(echo "$usage" | awk '{print $4}')
    # percent=$(echo "$usage" | awk '{print $5}')

    echo "$used/$size"
fi
