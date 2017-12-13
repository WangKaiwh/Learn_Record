#!/bin/bash

for num in $(cat numfile); do
	printf "%x", $num
done

echo
