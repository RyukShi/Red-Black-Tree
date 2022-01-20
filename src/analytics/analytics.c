/**
 * @file analytics.c
 *
 * @author     RyukShi
 * @date       2022
 * @copyright  BSD 3-Clause License
 **/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "./analytics.h"

FILE *a_begin(char *fname)
{
    FILE *fptr;
    fptr = fopen(fname, "a");

    if (fptr == NULL)
    {
        fprintf(stderr, "Error!\n");
        exit(1);
    }

    return fptr;
}

clock_t a_start_register()
{
    return clock();
}

void a_end_register(FILE *fptr, clock_t t1)
{
    clock_t t2 = clock();
    double time_taken = ((double)t2 - t1) / CLOCKS_PER_SEC;
    fprintf(fptr, "%f\n", time_taken);
}

// void new_line(FILE *fptr) {
//     fprintf(fptr,"\n");
// }

void a_stop(FILE *fptr)
{
    fclose(fptr);
}
