#!/bin/bash

# for中循环列表中有两个目录，其实还可以更多 
for f in `pwd`/* /home/$USER/*; do
	if [ -d "$f" ]; then
		echo "$f: is directory"
	elif [ -f "$f" ]; then
		echo "$f： is file"
	else
		echo "$f: type unknown"
	fi
done
