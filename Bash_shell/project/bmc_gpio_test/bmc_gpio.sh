#!/bin/sh
#测试BMC GPIO的值

# $0 GPIO_NUM/GPIOA7/SGPIO7 1/0

usage()
{
	echo "$0 <GPIO_NUM/GPIOxx/SGPIxx> <option> "
	echo "                            option: 1, output high"
	echo "                                    0, output low"
	echo "                                    3, reading pin"
}

if [ $# -ne 2 ]; then
	usage $0
	exit 1 
fi

option=""
if [ $2 = "1" ]; then
	gpio_cmds gpio $1 --set-dir-output
	option="--set-data-high"
elif [ $2 = "0" ]; then
	gpio_cmds gpio $1 --set-dir-output
	option="--set-data-low"
elif [ $2 = "3" ]; then
	option="--get-data"
else 
	usage $0
	exit 1
fi

## debug
echo "gpio_cmds gpio $1 $option"
gpio_cmds gpio $1 $option



