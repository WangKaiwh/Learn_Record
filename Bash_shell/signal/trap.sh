#!/bin/bash 

trap "echo 'warning: ctrl+c is found'" SIGINT

count=0
while test $count -lt 10; do
	sleep 1
	echo "loop: #$count"
	count=$[ $count + 1 ]
done

echo "This is the end of script!"


