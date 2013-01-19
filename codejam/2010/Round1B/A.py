#!/usr/bin/env python

def compare_dir(a, b, length):
    if a[:length] == b[:length]:
        return True
    else:
        return False

def main():
    T = int(raw_input())
    for case_index in xrange(T):
        NM = [int(x) for x in raw_input().split()]
        N = NM[0]
        M = NM[1]
        exists_dirs = set()
        # wanted_dir = [raw_input() for mi in xrange(M)]
        for ni in xrange(N):
            home = ""
            d = raw_input().split('/')[1:]
            for one in d:
                home += ("/"+one)
                exists_dirs.add(home)
        new_dirs = 0
        for mi in xrange(M):
            home = ""
            d = raw_input().split('/')[1:]
            for one in d:
                home += ("/"+one)
                if home not in exists_dirs:
                    new_dirs += 1
                    exists_dirs.add(home)
        print "Case #{0}: {1}".format(case_index+1, new_dirs)



    pass

if __name__ == "__main__":
    main()
