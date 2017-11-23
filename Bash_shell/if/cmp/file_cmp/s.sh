#!/bin/bash

dir=`pwd`
file=$dir/test

if [ -f $file ]; then
	echo "$file exist"
	if [ -s $file ]; then
		echo "$file exist and has data in it"
	else
		echo "$file exist but hasn't data in it"
	fi
else
	echo "Sorry, $file not exist"
fi


