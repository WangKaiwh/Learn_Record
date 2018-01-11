#!/usr/bin/python3
#-*-coding: utf-8

# 定义 类的私有成员只需要在类的成员前面加上__

class A:
	def __b(self):
		print("__b called")

	def c(self):
		self.__b()

	def _d(self):
		print("_d called")

	__m_a = 0

	def e(self):
		self.__m_a = 1

	def f(self):
		print(self.__m_a)

a = A()

a.c()
a.e()
a._d()
a.f()

