/* main.c */
/* Author: Yarmolik Anastasia, group 11 */
/*
 * Client: demonstrates all TRAIN functions.
 * Reads train data, then calls each filter/report function.
 */

#include <stdio.h>
#include "train.h"

int
main (void)
{
        TRAIN   trains[MAX_TRAINS];
        int     count;

        count = inputTrains (trains, MAX_TRAINS);

        if (count <= 0)
        {
                fprintf (stderr, "No valid train data entered.\n");
                return 1;
        }

        printOver24h (trains, count);
        printCompartmentPassengers (trains, count);
        printToGrodno (trains, count);
        printMaxWagons (trains, count);

        return 0;
}
