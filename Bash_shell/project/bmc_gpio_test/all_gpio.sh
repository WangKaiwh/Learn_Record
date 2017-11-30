#!/bin/sh

usage()
{
	echo "$0 <option>"
	echo "    option: 1, output high"
	echo "            0, output low"
	echo "            3, reading pin"
}

judge_para()
{
	echo "total parameters: $#"
	if [ $# -ne 1 ]; then
		usage $@
		exit 1
	fi
	
	if [ "$1" != "1" ] && [ "$1" != "0" ] && [ "$1" != "3" ]; then
		usage $@
		exit 1
	fi
}

work()
{
	IFS_OLD=$IFS
	IFS=$'\n'
	file=$(cat gpio)
	for line in $file ; do
		IFS='/'
		for word in $line; do
			if [ ${word:0:3} = "GPI" ]; then
				echo
				./bmc_gpio.sh $word  $1		
				if [ $? -ne 0 ]; then
					exit 1
				fi
			fi
		done
	done 
	IFS=$IFS_OLD
}

judge_para $@
work $@



