"""**************************************************
Code writer : EOF
Code date   : 2015.01.10
Code file   : heap_demo.py
e-mail      : jasonleaster@gmail.com

Code purpose:
	There is a implementation of ADT-Heap which
is in Python.
        If you find something error with my code, 
please touch me by e-mail. Thank you.

*****************************************************"""

import sys

"""
These function are used for searching the 
index of parent, left child and right child
"""
def parent(i):
    return i/2

def left(i):
    return i*2

def right(i):
    return (i*2 + 1)

"""
    We store the size of heap as the first
element of Heap.
"""
def heap_size(A) :
    return A[0]

def init_input(A) :
    size = len(A)
    A = [size] + A

    return A

def max_heapify(A, i) :
    l = left(i)
    r = right(i)

    if l < heap_size(A) and A[l] > A[i] :
      largest = l
    else :
      largest = i

    if r < heap_size(A) and A[r] > A[largest] :
      largest = r

    if largest != i :
      tmp        = A[i]
      A[i]       = A[largest]
      A[largest] = tmp       
      max_heapify(A,largest)

    return A

def build_max_heap(A) :
    hs = heap_size(A)
    for i in range(hs/2,0,-1) :
        A = max_heapify(A,i)

    return A

def show_heap(A) :
    depth = 0

    depth_up_bound = 0
    tmp = heap_size(A)
    while tmp > 0:
        depth_up_bound += 1
        tmp >>= 1

    for i in range(1,heap_size(A)+1) :
        if i == (1<<depth) :
           blank = depth_up_bound - depth
           sys.stdout.write('\n' + 2*(blank)*' ')
           depth += 1

        sys.stdout.write(" %s " % A[i])

    print ""

def heap_sort(A) :

    for i in range(len(A)-1,0,-1) :
        tmp  = A[1]
        A[1] = A[i]
        A[i] = tmp
        
        """ heap size minus 1, Attention that we store 
        the value of the heap size into the A[0] """

        A[0] -= 1
        max_heapify(A,1)

    return A

#----up this line is implementation of funcs. Below this is testing code---

A = [27,17,3,16,13,10,1,5,7,12,4,8,9,0]

A = init_input(A)

print "The inputed data A = ", A

Sorted_A = build_max_heap(A)

show_heap(Sorted_A)

print "Aha! Attention the node which's value is 1," + \
      " this node has only one child."

print "After heap sorting"
print heap_sort(A)
