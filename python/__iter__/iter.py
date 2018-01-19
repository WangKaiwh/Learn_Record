#!/usr/bin/python3

a = 0
b = 1

a, b = b, a+b

print("a = %d, b= %d" % (a, b))

a, b = b, a+b

print("a = %d, b= %d" % (a, b))

