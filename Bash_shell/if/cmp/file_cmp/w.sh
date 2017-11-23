#!/bin/bash

file=/etc/passwd

if [ -f $file ]; then
	echo "$file exist"
	if [ -w $file ]; then
		echo "$file is able written"
	else
		echo "$file is not able written"
	fi
else
	echo "$file not exist"
fi
