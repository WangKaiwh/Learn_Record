#!/bin/bash

trap "echo 'first sigint trap type'" SIGINT

count=0
while [ $count -lt 3 ]; do
	sleep 1
	echo "#$count"
	count=$[ $count + 1 ]
done

trap "echo 'second sigint trap type'" SIGINT
count=0
while [ $count -lt 3 ]; do
	sleep 1
	echo "#$count"
	count=$[ $count + 1 ]
done

trap --
echo "sigint trap cancel"
count=0
while [ $count -lt 3 ]; do
	sleep 1
	echo "#$count"
	count=$[ $count + 1 ]
done

