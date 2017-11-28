#!/bin/bash

var=20

while [ $var -gt 0 ]; do
	echo "$var"
	var=$[ $var - 1 ] 
done
