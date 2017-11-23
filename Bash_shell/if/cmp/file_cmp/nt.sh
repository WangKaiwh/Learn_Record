#!/bin/bash

if [ d.sh -nt e.sh ]; then
	echo "d.sh is newer than e.sh"
else
	echo "d.sh isn't newer than e.sh"
fi
