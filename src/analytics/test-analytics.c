/**
 * @file test-analytics.c
 *
 * @author     RyukShi
 * @date       2022
 * @copyright  BSD 3-Clause License
 **/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#include "./analytics.h"

static bool is_prime(int number)
{
    if (number <= 1)
    {
        return false;
    }
    if (number % 2 == 0 && number > 2)
    {
        return false;
    }
    for (size_t i = 3; i < number / 2; i += 2)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}

static int random_data(void)
{
    return rand();
}

int main(int argc, char const *argv[])
{
    FILE *fptr = a_begin("primes");
    clock_t t1;

    t1 = a_start_register();

    for (size_t i = 0; i < 100; i++)
    {
        int number = random_data();
        if (is_prime(number) == true)
        {
            printf("number : %d is prime\n", number);
        }
    }

    a_end_register(fptr, t1);

    a_stop(fptr); // close file

    return EXIT_SUCCESS;
}
