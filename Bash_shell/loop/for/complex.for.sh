#!/bin/bash

for test in I don't know if it'll work; do
	echo "current word: $test"
done
# 上面一个式子会被解释成如下:
##current word: I
##current word: dont know if itll
##current word: work
#  ''中间的字符串会被认为是一个整体的字符串的值

echo 

for test in I don\'t know if it\'ll work; do
	echo "current word: $test"
done
##current word: I
##current word: don't
##current word: know
##current word: if
##current word: it'll
##current word: work

echo 

for test in I "don't" know if "it'll" work; do
	echo "current word: $test"
done
##current word: I
##current word: don't
##current word: know
##current word: if
##current word: it'll
##current word: work


