#!/bin/bash

expr 2 + 3
#  because * is a special character, it's used by "\*" in expr expression.
expr 2 \* 3
expr 2 - 3
expr 2 / 1

value1=20
value2=4
value3=$(expr $value1 / $value2)
echo "value3 is $value3"

