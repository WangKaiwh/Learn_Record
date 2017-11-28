#!/bin/bash

IFS_OLD=$IFS
IFS=:

for dir in $PATH; do
	echo "$dir -- excecute file "
	for file in $dir/*; do
		if [ -x $file ]; then
			echo "$file"
		fi
	done
done

IFS=$IFS_OLD
