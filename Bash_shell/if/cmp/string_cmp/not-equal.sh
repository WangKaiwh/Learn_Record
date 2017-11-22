#!/bin/bash

testuser=unknown

if [ $USER != $testuser ]; then
	echo "who are you: $testuser"
else
	echo "welcome $testuser"
fi

