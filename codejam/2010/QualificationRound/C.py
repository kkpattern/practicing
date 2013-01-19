#!/usr/bin/env python
import collections

def main():
    T = int(raw_input())
    for case_index in xrange(T):
        RkN = [int(x) for x in raw_input().split()]
        R = RkN[0]
        k = RkN[1]
        N = RkN[2]
        groups = [int(x) for x in raw_input().split()]
        queue_head_table = [-1] * N
        income_table = []
        income = 0
        ni = 0
        cycle_start = R+1
        cycle_end = R+1
        for ri in xrange(R):
            new_group_head = ni
            passenager_count = 0
            for gi in xrange(N):
                next_group_index = (ni+gi) % N
                next_group = groups[next_group_index]

                if passenager_count+next_group > k:
                    new_group_head = next_group_index
                    break
                else:
                    income += next_group
                    passenager_count += next_group

            income_table.append(income)
            queue_head_table[new_group_head] = ri
            if new_group_head <= ni and queue_head_table[ni] != -1:
                cycle_start = queue_head_table[new_group_head]
                cycle_end = ri
                break
            else:
                ni = new_group_head
        # For income_table[-1]
        income_table.append(0)
        if R < cycle_start:
            total_income = income_table[R-1]
        else:
            cycles = int(R/(cycle_end-cycle_start+1))
            rest_rounds = R % (cycle_end-cycle_start+1)
            total_income = income_table[cycle_start-1]
            total_income += cycles*(income_table[cycle_end]-income_table[cycle_start-1])
            total_income += (income_table[cycle_start+rest_rounds-1]-income_table[cycle_start-1])

        print "Case #{0}: {1}".format(case_index+1, total_income)


    pass

if __name__ == "__main__":
    main()
