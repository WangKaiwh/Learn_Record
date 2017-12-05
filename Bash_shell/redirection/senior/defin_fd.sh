#!/bin/bash

exec 3> 3.output

echo "output fd 3" >&3
