#!/bin/bash -

# Create By: Kevin Wang
# Date: 2017.11.7

usage()
{
	printf "Usage: $0 xxx.csv\n"
	printf "Caution: xxx.csv file is created by 'Total Phase Data Center'\n"
}

isValNull()
{
	VAL=`echo $1 | awk -F ',' '{print $9}'`
	
	if [ $VAL ];then  # not NULL
		echo $VAL
		return 1
	else # NULL
		return 0
	fi
}

printVal2File()
{
	echo $1
	echo $1 >> $2
}

main_f()
{
	if [ ! $# -eq 1 ];then
		usage && exit
	fi

	LINES=`cat $1`
	FILE="/tmp/xxxiiiii"

	# Must remove the FILE.
	if [ -e $FILE ]; then rm $FILE; fi 

	for line in $LINES; do
		echo $line
		#VAL=$(isValNull $line)
		#if [ $? -eq 1 ]; then
		#	printVal2File $VAL $FILE
		#fi
	done
}

main_f $1






