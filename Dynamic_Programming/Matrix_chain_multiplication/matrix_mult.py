"""
Code writer : EOF
Code date   : 2015.02.04
Code file   : matrix_mult.py
e-mail      : jasonleaster@163.com

Code description :
    
"""

def matrix_chain_order(p) :
    '''
        Don't forget that the size of @m and @s
        is smaller than that of @p by 1.
    '''
    n = len(p)-1


    p_inf = 2**32-1 # we assmue that the positive infinite is 2**32-1

    m = [ [0 for i in range(0, n)] for i in range(0, n)]
    s = [ [0 for i in range(0, n)] for i in range(0, n)]

    for l in range(1, n) : # l is the chain length
        for i in range(0, n-l) :
            j = i + l
            m[i][j] =  p_inf
            for k in range(i, j) :
                q = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1]
                if q < m[i][j] :
                    m[i][j] = q
                    s[i][j] = k

    return [m, s]

def print_optimal_parens(s, i, j) :
    '''
        Make sure that we count from zero but
        but one.

        row = column = len(A[0])

        So the index of matrix A *can not* be
        A[row][column]. Index out of range.
    '''
    if i is j :
        print "A", i ," ",
    else :
        print "(",
        print_optimal_parens(s, i,       s[i][j])
        print_optimal_parens(s, s[i][j]+1, j)
        print ")",


#-----------------for testing ------------------------------------------

p = [5, 10, 3, 12, 5, 50, 6]

[m, s] = matrix_chain_order(p)

print_optimal_parens(s, 0, len(p)-2) 
'''
    The max index of s is len(p)-2.

    Are you forget n = len(p)-1 which is 
    in function @matrix_chain_order ?
'''

