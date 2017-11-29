#!/bin/bash

if [ $# -ne 2 ]; then
	echo "$0 val1 val2"
	exit 1
fi

cmd=$(basename $0)

if [ $cmd = "add" ]; then
	echo $1 + $2: $[ $1 + $2 ]
elif [ $cmd = "by" ]; then
	echo $1 \* $2: $[ $1 * $2 ]
else 
	echo "$cmd: unknown cmd"
fi



