#!/usr/bin/python

__author__ = 'Angelo D.Amante'
__mail__ = 'angelo.damante16@gmail.com'

import sys
import re
from os import listdir


def is_feasible(computation_times, d):
    '''
    Schedulability check for task represented by input file.

    The test is to check the missing of the deadline by bcet or wcet.

        Parameters:
            computation_times (list): list of couple [bcet, wcet] (Nx2)
            d (float): deadline value

        Returns:
            feasible (bool): result of the test
    '''
    feasible = True
    log = open("Log.txt", "r+")
    log.truncate(0)
    for i in range(len(computation_times)):
        ct = computation_times[i]
        if (ct[0] <= d and ct[1] <= d):
            feasible *= True
        else:
            feasible *= False
            log.write("Trace " + str(i) + " missing deadline \n")
    # end

    log.close()
    return feasible
# end


def extract_computation_times(traces):
    '''
    Converts the tracks read from the input file into a list to be calculated.

        Parameters:
            traces (list): from input file by trace extractor with Oris1

        Returns:
            C (list): list of couple [bcet, wcet]
                C[i][0] = bcet
                C[i][1] = wcet
    '''
    C = []
    for i in range(1, len(traces)):
        # '\[([^]]+)'
        bcet = float(re.search('\[([^,]+)', traces[i]).group(1))
        wcet = float(re.search('\,([^]]+)', traces[i]).group(1))
        computation_time = [bcet, wcet]
        C.append(computation_time)
    return C
# end


def main():
    '''
    To start test for task with input file by trace extractor.

    Usage, (example)
        python3 tester.py output_tau_2_t_c21_good.txt 5
    with:
        sys.argv[0] = tester.py (not relevant)
        sys.argv[1] = output_tau_2_t_c21_good.txt (file_name.txt)
        sys.argv[2] = 5 (deadline value)

    It is essential that there are all three input parameters
    '''
    if len(sys.argv) == 3:

        # parameters
        file = str(sys.argv[1])
        d = float(sys.argv[2])

        # extract traces
        with open(file) as f:
            traces = f.readlines()

        # extract computation times
        C = extract_computation_times(traces)

        # test
        if (is_feasible(C, d)):
            print("Task feasible! \n")
        else:
            print("Task not feasible! \n")
            print("View Log file \n")
    else:
        print("missed argument \n")
# end


if __name__ == "__main__":
    main()
# end
