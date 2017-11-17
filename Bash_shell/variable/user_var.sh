#!/bin/sh

# == operator

value1=100
value2=$value1
# no $, value1 is just normal character.
value3=value1


## value2 is 100
echo "value2 is $value2"
## value3 is value1
echo "value3 is $value3"

