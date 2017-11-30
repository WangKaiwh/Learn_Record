#!/bin/bash

for line in $(cat $1); do
	echo "First 4 letters: ${line:0:4}"
done



