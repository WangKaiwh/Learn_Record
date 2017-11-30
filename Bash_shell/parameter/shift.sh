#!/bin/bash

# -n 后面字符串一定要用双引号括起来
while [ -n "$1" ]; do
	case "$1" in 
	-a) echo "-a option";;
	-b) echo "-b option";;
	-c) echo "-c option";;
	*) echo "$1 is not an option"
	esac
	shift
done
