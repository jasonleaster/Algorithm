"""
Code writer : EOF
Code date   : 2015.02.03
e-mail      : jasonleaster@163.com

Code description :
    Here is a implementation in Python as a solution
for Colonel-problem which is in <CLRS> second edition 
chapter 15.

"""

def fastest_way(a, t, e, x, n) :

    f1 = []
    f2 = []
    path = [[],[]]
    # when j == 0
    f1 += [ e[0] + a[0][0] ]
    f2 += [ e[1] + a[1][0] ]

    for j in range(1, n) :
        if (f1[j-1] + a[0][j]) <= (f2[j-1] + t[1][j-1] + a[0][j]) :
            f1 += [ f1[j-1] + a[0][j] ]
            path[0] += [0]
        else :
            f1 += [ f2[j-1] + t[1][j-1] + a[0][j] ]
            path[0] += [1]

        if (f2[j-1] + a[1][j]) <= (f1[j-1] + t[0][j-1] + a[1][j]) :
            f2 += [ f2[j-1] + a[1][j] ]
            path[1] += [1]
        else :
            f2 += [ f1[j-1] + t[0][j-1] + a[1][j] ]
            path[1] += [0]

    if f1[n-1] + x[0] <= f2[n-1] + x[1] :
        smallest_cost = f1[n-1] + x[0]
        path[0] += [0]
        path[1] += [0]
    else :
        smallest_cost = f2[n-1] + x[1]
        path[0] += [1]
        path[1] += [1]

    return path

def print_stations(path) :

    n = len(path[0])
    i = path[0][n-1]
    print "line ", i, ", station", n

    for j in range(n-1, -1, -1) :
        i = path[i][j]
        print "line ", i, ", station", j

#---------------- for testing -----------------------------------------
a = [[7,9,3,4,8,4],[8,5,6,4,5,7]]
t = [[2,3,1,3,4]  ,[2,1,2,2,1]  ]

e = [2,4]
x = [3,2]
n = len(a[0])


path = fastest_way(a, t, e, x, n)
print_stations(path)
