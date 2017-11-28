#!/bin/bash

file=/etc/passwd

IFS_OLD=$IFS
IFS=$'\n'

for entry in $(cat $file); do
	echo " $entry -"
	for key in $entry; do
		IFS=:
		echo "       $key"
	done
done 

