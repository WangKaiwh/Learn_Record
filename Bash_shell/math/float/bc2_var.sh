#!/bin/bash

val1=10
val2=3
val3=$(echo "scale=4; $val1 / $val2" | bc)

echo "val3 is $val3"
