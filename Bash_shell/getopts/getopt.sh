#!/bin/bash

set -- $(getopt ab:cd "$@")
echo $@

echo

para=
while [ -n "$1" ]; do
	case "$1" in
	-a) echo "-a opt";;
	-b) para=$2
	    echo "-b opt, para=$para"
	    shift;;
   	-c) echo "-c opt";;
	-d) echo "-d opt";;
	--) shift
	    break;;
	*)  echo "$1 is not an opt";;
	esac
	shift
done

count=1
for para in "$@"; do
	echo "para #$count: $para"
	count=$[ $count + 1 ]
done
