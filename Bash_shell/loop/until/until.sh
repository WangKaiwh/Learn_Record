#!/bin/bash

var=20

until [ $var -eq 0 ]; do
	echo $var
	var=$[ $var -1 ]
done
