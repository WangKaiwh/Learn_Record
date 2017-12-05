#!/bin/bash 

trap "echo 'goodbye...'" EXIT

count=0
while test $count -lt 3; do
	sleep 1
	echo "loop: #$count"
	count=$[ $count + 1 ]
done

echo "This is the end of script!"


