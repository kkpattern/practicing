#!/usr/bin/env python
import fractions

def main():
    C = int(raw_input())
    for case_index in xrange(C):
        case_input = [int(x) for x in raw_input().split()]
        vector_length = case_input[0]
        t_vector = sorted(case_input[1:], reverse=True)
        numbers = []
        for x in xrange(vector_length-1):
            for y in xrange(x+1, vector_length):
                numbers.append(t_vector[x]-t_vector[y])
        numbers = sorted(numbers)
        gcd = numbers[0]
        for n in numbers:
            gcd = fractions.gcd(gcd, n)
        # print t_vector
        # print numbers
        # print gcd
        if t_vector[0] % gcd == 0:
            coefficient = t_vector[0]/gcd
        else:
            coefficient = t_vector[0]/gcd+1
        while True:
            y = coefficient*gcd - t_vector[0]
            found = True
            for n in t_vector[1:]:
                if (n+y) % gcd != 0:
                    found = False
                    break
            if found:
                break
            else:
                coefficient += 1
        print "Case #{0}: {1}".format(case_index+1, y)


if __name__ == "__main__":
    main()
