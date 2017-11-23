#!/bin/bash

touch test
dir=`pwd`

if [ -d $dir ] && [ -w ${dir}/test ]; then
	echo " ${dir}/test is writable"
else
	echo " not writable or not exist"
fi
