#!/bin/bash

val1=testing
val2=''

if [ -n $val1 ]; then
	echo "$val1 is not empty"
else
	echo "$val1 is empty"
fi

if [ -z $val2 ]; then
	echo "$val2 is empty"
else
	echo "$val2 is not empty"
fi

if [ -z $val3 ]; then
	echo "$val3 is empty"
else
	echo "$val3 is not empty"
fi

