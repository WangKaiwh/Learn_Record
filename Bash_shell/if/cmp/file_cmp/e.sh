#!/bin/bash

loc=$HOME
file="test"

if [ -e $loc ]; then
	echo "loc:$loc exists"
	if [ -e $loc/$file ]; then
		echo "Ok on the file"
		echo "Updating Current file"
		date >> $loc/$file
	else
		echo "File not exists"
		echo "Nothing to update"
	fi
else
	echo "loc: $loc not exists"
fi

