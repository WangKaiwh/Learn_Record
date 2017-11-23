#!/bin/bash

case $1 in
wk )
	echo hello wk;;
wangkai)
	echo hello wangkai;;
kevin | Kevin)
	echo hello kevin;;
*)
	echo "i don't know you";;
esac
