'''
Code writer : EOF
Code date   : 2015.01.08
Code file   : bs.py
e-mail      : jasonleaster@gmail.com

Code description:
       Here is a implementation for 
how to do binary search in Python.

'''
def binary_search(array, element):

    high = len(array)
    mid = -1
    for low in range(len(array)) :
        mid = (low + high)/2

        if array[mid] < element :
             low  = mid + 1
        elif array[mid] > element :
             high = mid - 1
        else :
             return mid

    return -1
     
def main():
    number = [1,2,3,4,5]

    print number
    print number[binary_search(number,3)]

main()
