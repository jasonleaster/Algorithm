"""
code writer	:	EOF
code date	:	2015.01.15
code file	:	quick_sort2.py
e-mail		:	jasonleaster@gmail.com

Code description:
               Quick Sort is implemented in Python.
      In this method, we try to use a technology which named
as "tail-recursion" to replace the part of quick_sort(A, q+1, r).

      I just only changed the @quick_sort and the other code is
the same as the old version which is in file quick_sort.py

"""

#****************************
def quick_sort(A, p, r) :
    while p < r :
       q = partition(A, p, r)
       quick_sort(A, p, q-1)
       p = q + 1
#*****************************

# resorting in place 
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

#-------------------testing code---------------------------
A = [13,19,9,5,12,8,7,4,21,2,6,11]

print "Before sorting A= " , A, "\n"

quick_sort(A,0,len(A)-1)

print "After  sorting A= " , A, "\n"

