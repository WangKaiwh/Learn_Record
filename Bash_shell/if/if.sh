#!/bin/bash

testuser=NoSuchUser

if grep $testuser /etc/passwd; then
	echo "The user $testuser exsits on this system."
elif ls -d /home/$testuser; then
	echo "User not exist, but has directory."
else
	echo "User not exsit, has not directory"
fi
