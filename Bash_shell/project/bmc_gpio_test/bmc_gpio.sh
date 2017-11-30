#!/bin/sh
#测试BMC GPIO的值

# $0 GPIO_NUM/GPIOA7/SGPIO7 1/0

usage()
{
	echo "$0 <GPIO_NUM/GPIOxx/SGPIxx> <option> "
	echo "                            option: 1, high"
	echo "                                    0, low"
}

if [ $# -ne 2 ]; then
	usage $0
	exit 1 
fi

option=""
if [ $2 = "1" ]; then
	option="--set-data-high"
elif [ $2 = "0" ]; then
	option="--set-data-low"
else
	usage $0
	exit 1
fi

## debug
echo "gpio_cmds gpio $1 $option"
gpio_cmds gpio $1 $option



