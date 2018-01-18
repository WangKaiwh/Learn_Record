#!/usr/bin/python3
#-*-coding:utf-8

# True False 

__metaclass__ = type # 使用新类

class Bird:
	def __init__(self):
		self.flg = True
		print("super class __init__")

	def eat(self):
		if self.flg == True:
			print("eating...")
			self.flg = False
		else:
			print("No thanks...")	


#集成于超类 Bird
class songBird(Bird):
	def __init__(self):
		super(songBird, self).__init__()
		print("child class __init__")

	def sing(self):
		print("sing...")

cjp = songBird()
cjp.sing()
cjp.eat()
cjp.eat()

# # # 结果如下 # # #
#super class __init__
#child class __init__
#sing...
#eating...
#No thanks...



