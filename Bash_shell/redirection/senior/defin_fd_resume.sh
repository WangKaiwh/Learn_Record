#!/bin/bash

exec 3>&1

exec 1> 1.out
echo "1 out"

exec 1>&3
echo "now back normal"
