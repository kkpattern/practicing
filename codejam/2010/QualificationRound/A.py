#!/usr/bin/env python

def main():
    T = int(raw_input())
    for case_index in xrange(T):
        NK = [int(x) for x in raw_input().split()]
        N = NK[0]
        K = NK[1]
        alpha = 2**(N-1)
        if K % alpha == (alpha-1):
            p = True
        else:
            p = False
        if int(K/alpha) % 2 == 0:
            c = False
        else:
            c = True
        light = "OFF"
        if c and p:
            light = "ON"
        print "Case #{0}: {1}".format(case_index+1, light)



    pass

if __name__ == "__main__":
    main()
