#!/usr/bin/python3
#-*-coding: utf-8


class Counter:
	cnt = 0
	
	def add(self):
		self.cnt += 1

c1 = Counter()
c2 = Counter()

c1.add()

print(c1.cnt)
print(c2.cnt)

print(Counter.cnt)


