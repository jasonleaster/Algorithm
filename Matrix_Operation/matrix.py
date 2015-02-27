"""
Programmer  :   EOF
Code date   :   2015.02.28
Code file   :   matrix.py

Code description :

    @transpose          : return a matrix @A_T which is tranposed matrix of @A

    @lu_decomposition   : return matrix @L and @U which are decomposed from matrix @A

    @plu_decomposition  : return matrix @P, @L and @U which are decomposed from matrix @A

"""
class mat() :

    def transpose(self, A) :
        row = len(A)
        col = len(A[0])

        A_T = [[0 for i in range(0, row)] for j in range(0, col)]

        for i in range(0, row) :
            for j in range(0, col) :
                A_T[j][i] = A[i][j]

        return A_T


    def lup_solve(self, L, U, pi, b) :
        n = len(self.L)
        x = [0 for i in range(0, n)]
        y = [0 for i in range(0, n)]
        for i in range(0, n) :
            tmp = 0
            for j in range(0, i-1) :
                tmp += L[i][j] * y[j]

            y[i] = b[ pi[i] ] - tmp

        for i in range(n-1, -1, -1) :
            tmp = 0
            for j in range(i+1, n) :
                tmp += U[i][j] * x[j]
            x[i] = (y[i] - tmp)/u[i][i]

        return x

    

    def lu_decomposition(self, A) :
        n = len(A)
        a = A

        self.L = [[0 for i in range(0, n)] for j in range(0, n)]
        self.U = [[0 for i in range(0, n)] for j in range(0, n)]

        for k in range(0, n) :
            self.U[k][k] = a[k][k]

            for i in range(k+1, n) :
                self.L[i][k] = a[i][k]/self.U[k][k]
                self.U[k][i] = a[k][i]

            for i in range(k+1, n) :
                for j in range(k+1, n) :
                    a[i][j] = a[i][j] - self.L[i][k]*self.U[k][j]

        return (self.L, self.U)


    def lup_decomposition(self, A) :
        n = len(A)
        a = A

        pi = [i for i in range(0, n)]

        for k in range(0, n) :
            p = 0
            for i in range(k, n) :
                if abs(a[i][k]) > p :
                    p = abs(a[i][k])
                    k_prime = i

            if p is 0 :
                print "singular matrix"
                return 

            pi[k], pi[k_prime]  = pi[k_prime], pi[k]

            for i in range(0, n) :
                a[k][i], a[k_prime][i] = a[k_prime][i], a[k][i]

            for i in range(k+1, n) :
                a[i][k] /= (a[k][k] * 1.0)
                for j in range(k+1, n) :
                    a[i][j] -= a[i][k] * a[k][j]

        self.P = [[ 0 for i in range(0, len(pi))] for j in range(0, len(pi))]
        for i in range(0, len(pi)) :
            self.P[i][ pi[i] ] = 1

        self.L = [[0 for i in range(0, n)] for j in range(0, n)]
        self.U = [[0 for i in range(0, n)] for j in range(0, n)]

        row = len(self.L)
        col = len(self.L[0])
        for i in range(0, row) :
            for j in range(0, col) :
                if j < i :
                    self.L[i][j] = a[i][j]
                elif j == i :
                    self.L[i][j] = 1
                    self.U[i][j] = a[i][j]
                else :
                    self.U[i][j] = a[i][j]

        return (self.P, self.L, self.U)


    def show(self, matrix) :

        if matrix is None :
            return 

        row = len(matrix)
        col = len(matrix[0])
        
        for i in range(0, row) :
            for j in range(0, col) :
                print "\t%1.2f" % matrix[i][j],
            print

        print "\n\n"


#-----------------for testing------------------------------------

#matrix = [[2,3,1,5], [6,13,5,19], [2,19,10,23],[4,10,11,31]]
matrix = [[2,0,2,0.6], [3,3,4,-2], [5,5,4,2], [-1,-2,3.4,-1]]

m = mat()

print "The input matrix is \n"
m.show(matrix)

print "After transpose\n"
m.show(m.transpose(matrix))

(P, L, U) = m.lup_decomposition(matrix)

print "After PLU decomposition, we got matrixes"

print "P:"
m.show(P)

print "L:"
m.show(L)

print "U:"
m.show(U)
