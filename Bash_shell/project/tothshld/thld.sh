#!/bin/bash

raw=$1

printf "%x\n" $[ $raw  + $raw * 20 / 100 ]
printf "%x\n" $[ $raw  + $raw * 10 / 100 ]
printf "%x\n" $[ $raw  + $raw * 5 / 100 ]
printf "%x\n" $[ $raw  - $raw * 20 / 100 ]
printf "%x\n" $[ $raw  - $raw * 10 / 100 ]
printf "%x\n" $[ $raw  - $raw * 5 / 100 ]












