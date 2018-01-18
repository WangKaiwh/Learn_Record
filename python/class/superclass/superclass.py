#!/usr/bin/python3
#-*-coding: utf-8

class Filter:
	'定义一个Filter基类'
	def init(self):
		self.block = []

	def filter(self, sequence):
		return [ x for x in sequence if x not in self.block ]


# 以下定义一个子类
class StrFilter(Filter):
	'定义一个子类'

	# 只用重写init方法
	def init(self):
		self.block = ['ABC']


# main
af = StrFilter()

af.init()

print (af.filter(['ABC', '123', 'BCD']))


