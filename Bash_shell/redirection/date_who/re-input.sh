#!/bin/bash

if [ -e output ]; then
	wc < output
#  result:  3  16 129
#  3 - is "output" lines
# 16 - total words of "output"
# 129 - total bytes of "output"
else
	echo "test file not exist!"
fi
