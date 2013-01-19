#!/usr/bin/env python

def rotate(table, n):
    for ci in xrange(n):
        for ri in reversed(range(0, n-1)):
            if table[ci][ri] != '.':
                new_position = ri
                while new_position < n-1:
                    if table[ci][new_position+1] != '.':
                        break
                    else:
                        new_position += 1
                temp = table[ci][new_position]
                table[ci][new_position] = table[ci][ri]
                table[ci][ri] = temp

def check_row(table, n, color, k):
    DIRECTIONS = [(1, 0), (1, 1), (0, 1), (-1, 1),
                  (-1, 0), (-1, -1), (-1, 0), (-1, 1)]
    for ci in xrange(n):
        for ri in xrange(n):
            if table[ci][ri] == color:
                for (c_offset, r_offset) in DIRECTIONS:
                    in_a_row = True
                    for i in xrange(1, k):
                        check_ci = ci+i*c_offset
                        check_ri = ri+i*r_offset
                        # Out of table.
                        if check_ci < 0 or check_ci >= n or check_ri < 0 or check_ri >= n:
                            in_a_row = False
                            break
                        # Not the same color
                        if table[check_ci][check_ri] != color:
                            in_a_row = False
                            break
                    if in_a_row:
                        return True
    return False



def main():
    T = int(raw_input())
    for case_index in xrange(T):
        NK = [int(x) for x in raw_input().split()]
        N = NK[0]
        K = NK[1]
        table = [[c for c in raw_input()] for x in xrange(N)]
        rotate(table, N)
        # print ""
        # print ""
        red_in_a_row =  check_row(table, N, "R", K)
        blue_in_a_row = check_row(table, N, "B", K)
        if red_in_a_row and blue_in_a_row:
            result = "Both"
        elif red_in_a_row:
            result = "Red"
        elif blue_in_a_row:
            result = "Blue"
        else:
            result = "Neither"
        print "Case #{0}: {1}".format(case_index+1, result)

    pass

if __name__ == "__main__":
    main()
