"""
Programmer  :   EOF
Code date   :   2015.02.28
Code file   :   rkm.py
e-mail      :   jasonleaster@gmail.com

"""
def rabin_karp_matcher(T, P, d, q) :
    n = len(T)
    m = len(P)

    h = d**(m-1) % q
    p = 0
    t_0 = 0

    t = [0 for i in range(0, n - m + 1)]

    # preprosecessing
    for i in range(0, m) :
        p = ( d*p + ord(P[i]) ) % q
        t[0] = (d*t[0] + ord(T[i])) % q

    # matching
    for s in range(0, n-m+1) :
        match = True
        if p is t[s] :
            for i in range(0, m) :
                if P[i] is not T[s+i] :
                    match = False
                    break

            if match is True :
                print "Pattern occurs with shift", s

        if s < n-m :
            t[s+1] = (d * ( t[s] - ord(T[s]) * h ) + ord(T[s+m]) ) % q

#------------ for testing --------------------

string1 = "hello goodbye and hello"
string2 = "hello"
rabin_karp_matcher(string1, string2, 10, 13)

