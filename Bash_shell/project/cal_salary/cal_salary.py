#!/bin/sh -

if [ $# != 2 ]; then printf "%s base_salary increasing_rate\n" ${0} && exit 1; fi


base=${1}
rate=${2}

printf "below is salary in future 10 years:\n"

for ((i=1; i<11; i++)); do
	cur=$[ ${base} + ${base} * ${rate} / 100 ]
	printf "year: %d， salary: %d\n" ${i} ${cur} 
	base=cur
done





