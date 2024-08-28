#include<stdio.h>
#include<time.h>
#include<signal.h>
#include<stdlib.h>

int main(void) {
    time_t start, end;
    time(&start);
    srand(time(NULL));
    int loops = 1000000000;
    int turns = 231;
    int paras = 0;
    int max_paras = 0;

    for(int i=0; i<loops; i++) {
        paras = 0;
        for(int j=0; j<turns; j++) {
            if(rand() % 4 == 0) {
                paras++;
            }
        }
        if (paras > max_paras) {
            max_paras = paras;
        }
    }
    printf("max turns of paralysis is %d\n", max_paras);

    time(&end);

    long time_taken = end - start;

    printf("Time taken by program is : %ld sec\n", time_taken);



    return 0;
}
