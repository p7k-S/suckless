#!/bin/sh
cd && tmux new -s scrpad -d
tmux send-keys -t scrpad 'tmux set-option status-position top' C-m
tmux send-keys -t scrpad 'clear' C-m
# tmux set-option -g status-position top

# cd && tmux new -s term -d
# tmux send-keys -t scrpad 'iwctl' Enter
# tmux new-window
# tmux send-keys -t scrpad 'bluetoothctl' Enter
# tmux select-window -t "1"
# tmux send-keys -t scrpad 'station wlp4s0 show' Enter
# tmux new-window
# tmux send-keys -t scrpad 'btop' Enter
# tmux new-window
