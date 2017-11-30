#!/bin/bash

echo "\$@: $@"
while [ -n "$1" ]; do
	case "$1" in
	-a) echo "-a opt";;
   	-b) echo "-b opt";;
	--) shift
	    break;;
	*) echo "$1 is not an opt";;
	esac

	shift
done

echo "\$@: $@"
for para in $@; do
	echo "para: $para"
done

