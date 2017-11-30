#!/bin/bash

set -- $(getopt ab:cd "$@")
echo $@

#	wangkai@fiberserver:~/workspace/github/Bash_shell/getopts$ ./set.sh -ab hello -cd
#	-a -b hello -c -d --

