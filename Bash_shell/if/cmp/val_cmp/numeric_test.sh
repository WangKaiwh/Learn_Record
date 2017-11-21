#!/bin/bash

#Using numeric test evaluations

value1=10
value2=11

# > 5 ?
if [ $value1 -gt 5 ];then
	echo "$value1 is great than 5"
else
	echo "$value1 is not great than 5"
fi

# value1 == value2 ?
if [ $value1 -eq $value2 ];then
	echo "$value1 and $value2 is equal"
else
	echo "$value1 and $value2 is different"
fi




