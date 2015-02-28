"""
Programmer  :   EOF
Date        :   2015.02.28
Code file   :   nsm.py

"""

def naive_string_matcher(T, P) :
    if (T or P) is None :
        return 

    n = len(T)
    m = len(P)


    for s in range(0, n-m+1) :
        match = True
        for i in range(0, m) :
            if P[i] is not T[s+i] :
                match = False
                break

        if match is True :
            print "Pattern occurs with shift", s

#------------ for testing --------------------

string1 = "hello goodbye and hello"
string2 = "hello"
naive_string_matcher(string1, string2)
