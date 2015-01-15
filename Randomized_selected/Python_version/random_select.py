"""
Code writer : EOF
Code date   : 2015.01.15
Code file   : random_select.py
e-mail      : jasonleaster@gmail.com

Code description :
      Here is a implementation for random-select in Python.
Function  @random_select(A, p, r, i) will return the i-th
element from the @A which's range is @p to @r.

"""
import random

def partition(A, p, r) :
    x = A[r]
    i = p-1
    for j in range(p, r) :
        if A[j] <= x :
           i += 1
           # swap A[i] and A[j]
           A[i], A[j] = A[j], A[i] 

    A[i+1], A[r] = A[r], A[i+1]
    return i+1

def random_partition(A, p, r) :
    i = random.randint(p,r+1)
    A[r], A[i] = A[i], A[r]
    return partition(A, p, r)


def random_select(A, p, r, i) :
    if p == r :
       return A[p]
    q = random_partition(A, p ,r)
    k = q - p + 1

    if i == k :
       return A[q]
    elif i < k :
       return random_select(A, p, q-1, i)
    else :
       return random_select(A, q+1, r, i-k)


#-------------------testing code---------------------------
A = [13,19,9,5,12,8,7,4,21,2,6,11]

print "Before sorting A= " , A

x = random_select(A,0,len(A)-1, 5)

print "After  sorting A= " , sorted(A), x

