#!/bin/bash

input="user.csv"

while IFS=:',' read userid name ; do
    if [ ! -z $userid ] && [  ! -z $name ]; then
	echo "userid: $userid, name: $name"
#	useradd -c "$userid" -m $name
    fi
done < $input
