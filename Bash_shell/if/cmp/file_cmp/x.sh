#!/bin/bash

file=x.create.sh

echo "date" > $file

if [ -x $file ]; then
	echo "$file can be running..."
	./$file
else
	echo "$file unable to execute"
	chmod +x $file
	./$file
fi

