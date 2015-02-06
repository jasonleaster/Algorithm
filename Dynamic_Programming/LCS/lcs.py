"""
Code writer : EOF
Code date   : 2015.02.05
Code file   : lcs.py
e-mail      : jasonleaster@163.com

Code description :


"""

def lcs_length(X, Y) :
    m = len[X]
    n = len[Y]

    for i in range(0, m) :
        c[i][0] = 0

    for j in range(0, n) :
        c[0][j] = 0

    for i in range(0, m) :
        for j in range(0, n) :
            if x[i] = y[j] :
                c[i][j] = c[i-1, j-1]+1
                b[i][j] = '^\\'
            else if c[i-1][j] >= c[i][j-1] :
                c[i][j] = c[j-1][j]
                b[i][j] = '^|'
            else :
                c[i][j] = c[i][j-1]
                b[i][j] = '<-'

    return [c, b]

    
def print_lcs(b, X, i, j) :
    if i is 0 and j is 0 :
        return

    if b[i][j] is '^\\' :
        print_lcs(b, X, i-1, j-1)
        print x[i]
    elif b[i][j] = '^|' :
        print_lcs(b, X, i-1, j)
    else :
        print_lcs(b, X, i, j-1)

#---------------- for testing --------------------------------
