"""
Programmer  :   EOF
Date        :   2015.04.10
File        :   euclid.py
E-mail      :   jasonleaster@gmail.com
"""

def euclid(a, b):
    if b == 0 :
        return a
    else:
        return euclid(b, a % b)

#--------------- just for testing -------------

print "euclid(99, 78) ", euclid(99, 78)
