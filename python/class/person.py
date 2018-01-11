#!/usr/bin/python
#-*-coding: utf-8

# __metaclass__ = type 确定使用新式类

# self是python内置的一个量，类似C++的this.

# 类的方法必须第一个参数必须是self

# 类的成员变量，可以不定义直接用


# 结果:
#('Hello, i am ', 'wk')
#Hello, i am wk


__metaclass__ = type

class Person:
	def setName(self, name):
		self.name = name

	def getName(self):
		return self.name

	def greet(self):
		print('Hello, i am ', self.name)
		print('Hello, i am %s' % self.name)


foo = Person()

foo.setName('wk')

foo.greet()


