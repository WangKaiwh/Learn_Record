#!/bin/sh

list=$(find . -name "*.o")

for l in $list; do
	len=${#l}
	len=$[len - 1]
	ass=${l:0:len}"S"
	if [ -e $ass ]; then
		echo $ass
	fi
done
