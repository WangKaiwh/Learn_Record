#!/bin/bash

pwfile=/etc/shadow

if [ -f $pwfile ]; then
	# exist, then check if can read
	if [ -r $pwfile ]; then
		tail $pwfile
	else
		echo "I am unable to read $pwfile"
	fi
else
	echo "Sorry, $pwfile not exists"
fi
