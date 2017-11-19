#!/bin/bash

val1=1.2
val2=2.3
val3=3.4
val4=4.5

val5=$(bc << EOF
scale=4
a1=$val1 * $val2
b1=$val3 * $val4
a1 + b1
EOF
)

echo "val5 = $val5"
