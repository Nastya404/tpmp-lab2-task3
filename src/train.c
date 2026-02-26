/* train.c */
/* Author: Yarmolik Anastasia, group 11 */
/* Implementation of TRAIN functions */

#include <stdio.h>
#include <string.h>
#include "train.h"

/*
 * printTrain - prints information about a single train
 * Parameters:
 *   t - pointer to TRAIN structure
 */
void
printTrain (TRAIN *t)
{
        printf ("Train #%d | Direction: %s | "
                "Departure: %02d:%02d | Arrival: %02d:%02d | "
                "Distance: %d km | Wagons: %d | "
                "Type: %s | Passengers/wagon: %d\n",
                t->number, t->direction,
                t->departure_h, t->departure_m,
                t->arrival_h, t->arrival_m,
                t->distance, t->wagons,
                t->wagon_type, t->passengers);
}

/*
 * inputTrains - reads train data from keyboard
 * Parameters:
 *   trains    - array of TRAIN structures
 *   maxCount - maximum number of records
 * Returns:
 *   actual number of trains entered
 */
int
inputTrains (TRAIN trains[], int maxCount)
{
        int count;
        int i;

        printf ("Enter number of trains (max %d): ", maxCount);
        scanf ("%d", &count);

        if (count > maxCount)
                count = maxCount;

        for (i = 0; i < count; i++)
        {
                printf ("\n--- Train %d ---\n", i + 1);

                printf ("Train number: ");
                scanf ("%d", &trains[i].number);

                printf ("Direction: ");
                scanf ("%s", trains[i].direction);

                printf ("Departure time (hours minutes): ");
                scanf ("%d %d",
                       &trains[i].departure_h,
                       &trains[i].departure_m);

                printf ("Arrival time (hours minutes): ");
                scanf ("%d %d",
                       &trains[i].arrival_h,
                       &trains[i].arrival_m);

                printf ("Distance (km): ");
                scanf ("%d", &trains[i].distance);

                printf ("Number of wagons: ");
                scanf ("%d", &trains[i].wagons);

                printf ("Wagon type (compartment/reserved seat/general): ");
                scanf ("%s", trains[i].wagon_type);

                printf ("Passengers per wagon: ");
                scanf ("%d", &trains[i].passengers);
        }

        return count;
}

/*
 * printOver24h - prints trains traveling more than 24 hours
 * Travel time is estimated as distance / average speed (60 km/h)
 * Parameters:
 *   trains - array of TRAIN structures
 *   count  - number of trains
 */
void
printOver24h (TRAIN trains[], int count)
{
        int i;
        int found = 0;
        double travelTime;     /* travel time in hours */

        printf ("\n=== Trains traveling more than 24 hours ===\n");

        for (i = 0; i < count; i++)
        {
                travelTime = (double)trains[i].distance / 60.0;

                if (travelTime > 24.0)
                {
                        printTrain (&trains[i]);
                        found = 1;
                }
        }

        if (!found)
                printf ("No trains found.\n");
}

/*
 * printCompartmentPassengers - prints total passengers
 *   for trains with compartment wagons
 * Parameters:
 *   trains - array of TRAIN structures
 *   count  - number of trains
 */
void
printCompartmentPassengers (TRAIN trains[], int count)
{
        int i;
        int total = 0;  /* total passengers */

        printf ("\n=== Passengers in compartment wagons ===\n");

        for (i = 0; i < count; i++)
        {
                if (strcmp (trains[i].wagon_type, "compartment") == 0)
                        total += trains[i].wagons
                                 * trains[i].passengers;
        }

        printf ("Total passengers: %d\n", total);
}

/*
 * printToGrodno - prints all trains going to Grodno
 * Parameters:
 *   trains - array of TRAIN structures
 *   count  - number of trains
 */
void
printToGrodno (TRAIN trains[], int count)
{
        int i;
        int found = 0;

        printf ("\n=== Trains to Grodno ===\n");

        for (i = 0; i < count; i++)
        {
                if (strcmp (trains[i].direction, "Grodno") == 0)
                {
                        printTrain (&trains[i]);
                        found = 1;
                }
        }

        if (!found)
                printf ("No trains to Grodno found.\n");
}

/*
 * print_max_wagons - prints train with maximum number of wagons
 * Parameters:
 *   trains - array of TRAIN structures
 *   count  - number of trains
 */
void
printMaxWagons (TRAIN trains[], int count)
{
        int i;
        int maxIdx = 0; /* index of train with max wagons */

        printf ("\n=== Train with maximum wagons ===\n");

        if (count == 0)
        {
                printf ("No trains.\n");
                return;
        }

        for (i = 1; i < count; i++)
        {
                if (trains[i].wagons > trains[maxIdx].wagons)
                        maxIdx = i;
        }

        printTrain (&trains[maxIdx]);
}

