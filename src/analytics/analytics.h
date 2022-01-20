/**
 * @file analytics.h
 *
 * @author     RyukShi
 * @date       2022
 * @copyright  BSD 3-Clause License
 **/

#ifndef _ANALYTICS_H_
#define _ANALYTICS_H_

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

extern FILE *a_begin(char *fname);

extern clock_t a_start_register();

extern void a_end_register(FILE *fptr, clock_t t1);

extern void a_stop(FILE *fptr);

#endif // _ANALYTICS_H_