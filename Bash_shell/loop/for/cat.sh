#!/bin/bash

file=cat.sh
#file=basic.for.sh

# 遍历脚本自身的文件
for line in $(cat $file); do
	echo "$line"
done




