#!/bin/bash

file=/etc/passwd

if [ -O $file ]; then
	echo "$USER are the owner of $file"
else
	echo "$USER are not the owner of $file"
fi

file=O.sh

if [ -O $file ]; then
	echo "$USER are owner of $file"
else
	echo "$USER are not owner of $file"
fi
