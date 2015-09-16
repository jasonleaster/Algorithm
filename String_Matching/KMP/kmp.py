"""
Programmer  :   EOF
Code date   :   2015.02.28
Code file   :   kmp.py
e-mail      :   jasonleaster@gmail.com

Code description    :
    Here is a implementation of KMP which is a useful
algorithm for string matching.

"""

def kmp_matcher(T, P) :
    n = len(T)
    m = len(P)

    pi = compute_prefix_function(P)
    q = -1 # number of characters matched
    for i in range(0, n) : # scan the text from left to right
        while q >= 0 and P[q+1] != T[i] :
            q = pi[q]       # next character doesn't match

        if P[q+1] == T[i] :
            q += 1          # next character matches
        if (q+1) == m :         # Is all of P matched ?
            print "Pattern occurs with shift ", i-m+1
            q = pi[q]       # look for the next match


def compute_prefix_function(P) :
    m = len(P)
    pi = [-1 for i in range(0, m)]

    k = -1 # Attention !
    for q in range(1, m) :
        while k >= 0 and P[k+1] != P[q] :
            k = pi[k]
        if P[k+1] == P[q] :
            k += 1

        pi[q] = k

    return pi

#-------------for testing----------------------
#string_1 = "hello goodbye and hello"
#string_2 = "hello"
string_1 = "abcabaabcabac"
string_2 = "abacdefgh"
#string_1 = "abcabaabcabac"
#string_2 = "abcabc"
kmp_matcher(string_1, string_2)
