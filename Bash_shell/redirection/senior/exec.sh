#!/bin/bash

exec 2> oerr

echo "1111111111"
echo "2222222222"

exec 1> oout

echo "output stdout: oout"
echo "output stderr: oerr" >&2



