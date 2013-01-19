#!/usr/bin/env python

def check_win(a, b):
    if a == b:
        return False
    # Make sure b > a
    if a > b:
        a, b = b, a
    alpha = b % a
    if alpha == 0:
        result = True

    elif a % alpha == 0:
        if b/a == 1:
            result = False
        else:
            result = True
    else:
        if b/a > 1 and check_win(a, alpha):
            result = True
        else:
            result = not check_win(a, alpha)
    return result

def main():
    T = int(raw_input())
    for case_index in xrange(T):
        AB = [int(x) for x in raw_input().split()]
        A1 = AB[0]
        A2 = AB[1]
        B1 = AB[2]
        B2 = AB[3]
        win_count = 0
        for a in xrange(A1, A2+1):
            for b in xrange(B1, B2+1):
                if check_win(a, b):
                    win_count += 1
        print "Case #{0}: {1}".format(case_index+1, win_count)

if __name__ == "__main__":
    main()
