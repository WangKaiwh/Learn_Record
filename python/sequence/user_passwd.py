#!/usr/bin/python3

database = [
	['wk', '123456'],
	['my', '1']
]

user = input("input username: ")
pin = input("input pin: ")

print ([user, pin])

if [user, pin] in database:
	print ("Access granted")
else:
	print ("unkonwn username or error passwd")

