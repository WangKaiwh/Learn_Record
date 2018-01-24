#!/bin/sh

# Kevin Wang, 2018.1.24

# 将aspeed cpu ast2500的port_pin分别解析成port和pin

if [ $# != 1 ]; then
	echo "$0 portpin"
	exit 1
fi

portpin=$1

printf "PORT: %d\n" $[ $portpin>>3 ]
printf "PIN: %d\n" $[ $portpin & 0x7 ]

