#!/usr/bin/env python
import math

def n_choose_r(n, r):
    if r > n:
        return 0
    else:
        f = math.factorial
        return f(n)/f(r)/f(n-r)

def solve_n_k(n, k):
    if k == 1:
        return 1
    count = 0
    for rank in xrange(1, k):
        count += n_choose_r(n-k-1, k-rank-1) * solve_n_k(k, rank)
    return count


def main():
    T = int(raw_input())
    for case_index in xrange(T):
        n = int(raw_input())
        count = 0
        table = [[0] * (n+1) for i in xrange(n+1)]
        for l in table:
            l[1] = 1

        for ni in xrange(2, n+1):
            for ki in xrange(2, ni):
                count = 0
                for r in xrange(1, ki):
                    count += n_choose_r(ni-ki-1, ki-r-1)*table[ki][r]
                table[ni][ki] = count
        count = 0
        print "\n".join([str(row) for row in table])
        for rank in xrange(n):
            count += table[n][rank]
        print "Case #{0}: {1}".format(case_index+1, count%100003)
    pass

if __name__ == "__main__":
    main()
