#!/bin/bash

dir=$HOME

if [ -d $dir ]; then
	echo "$dir is exists"
	ls
else
	echo "$dir is not exists"
fi
