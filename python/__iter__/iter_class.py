#!/usr/bin/python3
#-*-coding: utf-8

class iter:
	def __init__(self):
		self.a = 0
		self.b = 1	

	def __iter__(self):
		return self

	def __next__(self):
		self.a, self.b = self.b, self.a + self.b
		return self.a


it = iter()

for i in it:
	if i > 1000:
		print(i)
		break



