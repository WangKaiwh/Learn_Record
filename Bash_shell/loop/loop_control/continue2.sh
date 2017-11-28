#!/bin/bash

for ((i=0; i<5; i++)); do
	for ((j=0; j<9; j++)); do
		if [ $j -eq 3 ]; then
			continue 2
		fi
		echo "i=$i, j=$j"
	done
done
