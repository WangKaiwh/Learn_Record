#!/bin/bash

val=''

if test $val;then
	echo "val='' return true"
else
	echo "val='' return false"
fi

val='124'
if test $val;then
	echo "val='124' return true"
else
	echo "val='124' return false"
fi

# result
# val='' return false
# val='124' return true

