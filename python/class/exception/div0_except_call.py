#!/usr/bin/python3
#-*-coding: utf-8

num = input('请输入被除数: ')


try:
	print( 1/int(num) )
except Exception:
	print('div 0 error')


