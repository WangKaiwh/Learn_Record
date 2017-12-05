#!/bin/bash

# create temp dir

dir=$(mktemp -t -d test.XXXXXX)

cd $dir

echo "now $(pwd)"
cd - 1> /dev/null

rmdir $dir
