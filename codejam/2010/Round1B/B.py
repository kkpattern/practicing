#!/usr/bin/env python
import math

def main():
    C = int(raw_input())
    for case_index in xrange(C):
        NKBT = [int(x) for x in raw_input().split()]
        x_vector = [int(x) for x in raw_input().split()]
        v_vector = [int(x) for x in raw_input().split()]
        N = NKBT[0]
        K = NKBT[1]
        B = NKBT[2]
        T = NKBT[3]
        time_costs = [float(B-x_vector[ni])/v_vector[ni] for ni in xrange(N)]
        chicken_count = 0
        for ni in xrange(N):
            if time_costs[ni] <= T:
                chicken_count += 1
        if chicken_count < K:
            result = "IMPOSSIBLE"
        else:
            chicken_count = 0
            last_chicken = 0
            for ni in xrange(N-1, -1, -1):
                if time_costs[ni] <= T:
                    chicken_count += 1
                    if chicken_count == K:
                        last_chicken = ni
                        break


            swap_count = 0
            for ni in xrange(last_chicken+1, N):
                if time_costs[ni] > T:
                    swap_count += 1
            result = swap_count

        print "Case #{0}: {1}".format(case_index+1, result)

if __name__ == "__main__":
    main()
