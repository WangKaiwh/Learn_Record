#!/bin/bash

var=20

while echo $var
	[ $var -gt 0 ]; do
	echo "while loop"
	var=$[ $var - 1 ]
done
