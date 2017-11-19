#!/bin/bash

val1=$(echo "scale=4; 1/3" | bc)

echo "1 / 3, scale=4, result: $val1"
