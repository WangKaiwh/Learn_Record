#!/bin/bash

usage()
{
	echo "$0 normalval_decimal"
	exit
}

if [ $# != 1 ]; then usage; fi


raw=$1

printf "UNR: %x\n" $[ $raw  + $raw * 20 / 100 ]
printf "UCT: %x\n" $[ $raw  + $raw * 10 / 100 ]
printf "UNC: %x\n" $[ $raw  + $raw * 5 / 100 ]
printf "LNR: %x\n" $[ $raw  - $raw * 20 / 100 ]
printf "LCT: %x\n" $[ $raw  - $raw * 10 / 100 ]
printf "LNC: %x\n" $[ $raw  - $raw * 5 / 100 ]












