#!/bin/bash

read -n1 -p "entery [y/n]: " opt;

case $opt in
y | Y)  echo
	echo "You enter yes"	
	;;
n | N)  echo
	echo "You enter no"
	;;
*)      echo
	echo "I don't know what to do"
	;;
esac
