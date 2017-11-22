#!/bin/bash

testuser=wangkai

if [ $testuser = $USER ];then
	echo "welcome $testuser"
else
	echo "who are you"
fi

