/* main.c */
/* Author: Yarmolik Anastasia, group 11 */
/* Client: demonstrates all TRAIN functions */

#include <stdio.h>
#include "train.h"

/*
 * main - entry point, demonstrates all functions
 * Returns:
 *   0 on success
 */
int
main (void)
{
        TRAIN trains[MAX_TRAINS]; /* array of trains */
        int count;                /* actual number of trains */

        count = inputTrains (trains, MAX_TRAINS);

        printOver24h (trains, count);
        printCompartmentPassengers (trains, count);
        printToGrodno (trains, count);
        printMaxWagons (trains, count);

        return 0;
}
