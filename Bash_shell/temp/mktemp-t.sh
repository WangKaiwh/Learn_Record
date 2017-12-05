#!/bin/bash

# usage: mktemp name.XXXXXX

tempfile=$(mktemp -t test.XXXXXX)

exec 3> $tempfile

echo "This is test into tempfile" >&3
echo "Second line of tempfile" >&3

exec 3>&-


echo "Tempfile location: $tempfile"

cat $tempfile

rm $tempfile 2> /dev/null



