#!/usr/bin/python3
#-*-coding: utf-8

__metoaclass__ = type


class A:
	@staticmethod
	def staticm():
		print("I am static method")

	# classmethod函数的参数是cls
	@classmethod
	def clsm(cls):
		print("I am class method")


a = A()
a.staticm()
a.clsm()

A.staticm()
A.clsm()
A.clsm2()



