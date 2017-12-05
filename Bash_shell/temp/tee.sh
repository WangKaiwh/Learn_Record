#!/bin/bash

temp=$(mktemp -t tee.XXXXXX)
date | tee $temp

echo "Will cat $temp"
cat $temp

rm $temp 2> /dev/null
