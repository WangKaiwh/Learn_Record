#!/bin/bash

val1=baseball
val2=hockey

if [ $val1 \> $val2 ]; then
	echo "$val1 is great than $val2"
else
	echo "$val1 is less than $val2"
fi
