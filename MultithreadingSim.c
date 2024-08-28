#include<stdio.h>
#include<time.h>
#include "/opt/homebrew/opt/libomp/include/omp.h"
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

int main(void) {
    time_t start, end;
    time(&start);
    int loops = 250000000;
    int turns = 231;
    int paras;
    int max_paras = 0;
    int num_thread = 4;
    int total_loops = loops * num_thread;

#pragma omp parallel num_threads(num_thread) private(paras) reduction(max:max_paras)
    {
        //int threadnum = omp_get_thread_num();
        srand(time(NULL) + getpid());

        for (int i = 0; i < loops; i++) {
            paras = 0;
            for (int j = 0; j < turns; j++) {
                if (rand() % 4 == 0) {
                    paras++;
                }
            }
            if (paras > max_paras) {
                max_paras = paras;
                //printf("max paras changed to %d from thread %d on loop %d\n", paras, threadnum, i);
            }
        }
    }

    printf("max turns of paralysis is %d\n", max_paras);
    printf("total # of loops = %d\n", total_loops);

    time(&end);

    long time_taken = end - start;

    printf("Time taken by program is : %ld sec\n", time_taken);

    return 0;
}
