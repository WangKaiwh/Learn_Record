#!/bin/bash

if read -t 3 -p "enter your name:" name; then
	echo "hello: $name"
else
	echo "read timeout warning"
fi

