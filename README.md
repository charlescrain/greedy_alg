# greedy_alg
Greedy scheduling algorithm for jobs that have a start and end time.

Input information:
The first line is the positive number n - the total number of jobs. The next n input lines contain the information for the job. The ith line defines job ai. Each line contains three integers i,ti,si, separated by tabs. Here, i is the index of the job; ti is the release time of the job; si is the size of the job. There are no trailing white spaces or blank lines.

Example input file and respective outputs:

  Input File:       std output:   std error:

  3                 19            3
  1 0 5                           2
  2 3 3                           2
  3 1 2                           2
                                  1
                                  1
                                  1
                                  1



Running the program:

  1. compile
  2. a.out < input_file
