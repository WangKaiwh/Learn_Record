#!/bin/bash

exec 0<input_file

while read line; do
	echo "read: $line"
done
