#!/bin/sh

ass=$(find . -name "*.S")

for s in $ass;do
	f=$(echo $s | awk -F '/' '{print $NF}')		
	
	len=${#f}
	fs=${f:0:$[len-1]}"o"
	echo $fs

	if find . -name $fs 1> /dev/null; then
		echo $s
	fi
done
