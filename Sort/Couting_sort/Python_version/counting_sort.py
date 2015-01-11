"""
 Code writer : EOF
 Code date   : 2014.01.11
 Code file   : counting_sort.py
 e-mail      : jasonleaster@gmail.com

 Code description:
   Here is a implementation for counting sort.

   If you find something wrong with my code, please touch
me by e-mail.
"""

def counting_sort(array) :
    array_size = len(array)

    max_value = 0

    for i in range(0,array_size) :
        if max_value < array[i] :
           max_value = array[i]

    buf_size = max_value + 1

    buf  = [0] * buf_size
    ret  = [0] * array_size

    for i in range(0, array_size) :
        buf[array[i]] += 1
     
    for i in range(1, buf_size) :
        buf[i] += buf[i-1]

    for i in range(array_size - 1, -1, -1) :
        ret[buf[array[i]] - 1] = array[i]
        buf[array[i]] -= 1

    return ret

array = [1,3,4,3,2,7,4,0]

print "Befor sorting" ,array

sorted_ary = counting_sort(array)

print "After sorting", sorted_ary

