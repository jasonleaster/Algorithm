"""
Programmer  :   EOF
Date        :   2015.04.10
File        :   extended_euclid.py
E-mail      :   jasonleaster@gmail.com
"""

def extended_euclid(a, b):
    if b == 0:
        return (a, 1, 0)

    (tmp_d, tmp_x, tmp_y) = extended_euclid(b, a % b)

    (d, x, y) = (tmp_d, tmp_y, tmp_x - (a/b) * tmp_y)

    return (d, x, y)


#--------------- just for testing -------------

print "euclid(99, 78) ", extended_euclid(99, 78)
