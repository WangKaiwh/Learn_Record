#!/bin/bash

# OPTARG表示命令行中的参数
# OPTIND表示命令行中已经访问到的索引
# 在getopts中 -a -b等选项，不用加-
# 如果要忽略参数中的告警，则在optstring中最前面加上:
# 如果要带参数，则在opt后面加上:
# 用while来遍历所有的opt
while getopts :ab:cd opt ; do
	case $opt in
	a) echo "-a option";;
	b) echo "-b option, with para: $OPTARG";;
	c) echo "-c option";;
	d) echo "-d option";;
	*) echo "unknown opt: $opt";;
	esac
done

# 便宜option部分，$@只剩下参数部分
echo "OPTIND: $OPTIND"
shift $[ $OPTIND - 1 ]
echo "\$@: $@"
#

echo 
count=1

for para in $@; do
	echo "para #$count: $para"
	count=$[ $count + 1 ]
done

#wangkai@fiberserver:~/workspace/github/Bash_shell/getopts$ ./getopts.sh -a -b hello -cd world wh bj
#-a option
#-b option, with para: hello
#-c option
#-d option
#OPTIND: 5
#$@: world wh bj

#para #1: world
#para #2: wh
#para #3: bj




