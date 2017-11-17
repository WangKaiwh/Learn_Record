#!/bin/sh -

# Kevin Wang Create file on 2017.11.6
# Description:
#  Test I2C device of board automatically.


# Interface Definition.

i2c_get()
{
	ADDR=0
	# Get i2c-3 chip addr 0x50 value of register from 
	# 0 - 100.

	while [ $ADDR -lt 100 ]
	do
		i2cget -f -y 3 0x50 $ADDR
		let "ADDR = ADDR + 1"
	done
}

i2c_set()
{
	VAL=0
	# Set i2c-3 chip addr 0x50 reg 0x2 VAL
        #  FROM 0 - 0xff
	while [ $VAL -lt 256 ];do
		i2cset -f -y 3 0x50 0x2 $VAL
		let "VAL = VAL + 1"
	done
}

# Busisness Entrance.
i2c_get
i2c_set


