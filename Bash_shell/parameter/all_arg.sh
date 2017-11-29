#!/bin/bash
#testing $* and $@

#echo ${$#}
echo ${!#}

echo
count=1
for para in "$*"; do
	echo "\$* $count: $para"
	count=$[ $count + 1 ]	
done

echo 
count=1
for para in "$@";do
	echo "\$@ $count : $para"
	count=$[ $count + 1 ]
done
