#!/bin/sh

cd ..
echo "dmenu:"
echo ""
cd dmenu && sudo rm config.h && sudo make clean install
echo ""
echo "st:"
echo ""
cd ../st && sudo rm config.h && sudo make clean install
echo ""
echo "devour:"
echo ""
cd ../devour && sudo make clean install
echo ""
echo "dwm:"
echo ""
cd ../dwm && sudo rm config.h && sudo make clean install
echo ""
echo "slock:"
echo ""
cd ../slock && sudo rm config.h && sudo make clean install
echo ""
echo "dwmblocks:"
echo ""
cd ../dwmblocks && sudo rm blocks.h && sudo make clean install
