#!/usr/bin/python3
# for else语句尝试

# for else语句中，else执行的条件是，只有当for循环中break没有执行的时候，才会执行else子句。
#以下两段程序，都会打印0到3的平方根，但是第二段代码调用了break，所有第二段代码不会执行else子句。


from math import sqrt

for i in range(0,4):
    print (i, 'sqrt = ', sqrt(i))
else:
    print ("for... else clause called")	

print ()
print ("****************************")
print ()

for i in range(0,4):
    print (i, 'sqrt = ', sqrt(i))
    if i == 3:
        break   
else:
    print ("for... else clause called")	

print ()
print ("****************************")
print ()


