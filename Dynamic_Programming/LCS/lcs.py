"""
Code writer : EOF
Code date   : 2015.02.05
Code file   : lcs.py
e-mail      : jasonleaster@163.com

Code description :
    Here is a implementation for a famous DP problem
that LCS -- longest common sub-member

"""

def lcs_length(X, Y) :
    m = len(X)
    n = len(Y)

    c = [[0 for i in range(0, n+1)] for j in range(0, m+1)]
    b = [[0 for i in range(0, n+1)] for j in range(0, m+1)]

    for j in range(0, n+1) :
        c[0][j] = 0

    for i in range(0, m+1) :
        c[i][0] = 0

    for i in range(1, m+1) :
        for j in range(1, n+1) :
            if X[i-1] is Y[j-1] :
                c[i][j] = c[i-1][j-1] + 1
                b[i][j] = "+"
            elif c[i-1][j] >= c[i][j-1] :
                c[i][j] = c[i-1][j]
                b[i][j] = "|"
            else :
                c[i][j] = c[i][j-1]
                b[i][j] = "-"

    return  b


def show(c, m ,n) :
    for i in range(0, m+1) :
        for j in range(0, n+1) :
            print c[i][j],
        print 


    
def print_lcs(b, X, i, j) :
    if i is 0 or j is 0 :
        return

    if b[i][j] is "+" :
        print_lcs(b, X, i-1, j-1)
        print X[i-1],
    elif b[i][j] is "|" :
        print_lcs(b, X, i-1, j)
    else :
        print_lcs(b, X, i, j-1)

#---------------- for testing --------------------------------
X = ["A", "B", "C", "B", "D", "A", "B"]

Y = ["B", "D", "C", "A", "B", "A"]

b = lcs_length(X, Y)

print_lcs(b, X, len(X), len(Y))

