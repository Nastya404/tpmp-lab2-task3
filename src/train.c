/* train.c */
/* Author: Yarmolik Anastasia, group 11 */
/*
 * Server: implementation of TRAIN functions.
 * Provides input, output and filtering
 * of train records.
 */

#include <stdio.h>
#include <string.h>
#include "train.h"

/*
 * printTrain - prints formatted info about one train
 */
void
printTrain (TRAIN *t)
{
        printf ("  #%d  %s  dep %02d:%02d  arr %02d:%02d  "
                "%d km  %d wagons  %s  %d pass\n",
                t->number, t->direction,
                t->departureH, t->departureM,
                t->arrivalH, t->arrivalM,
                t->distance, t->wagons,
                t->wagonType, t->passengers);
}

/*
 * inputTrains - reads train data from stdin
 * Returns number of trains read, or -1 on input error
 */
int
inputTrains (TRAIN trains[], int maxCount)
{
        int     count;          /* desired number of trains */
        int     i;              /* loop counter */

	if (trains == NULL)
        {
                fprintf (stderr, "Error: NULL array in inputTrains\n");
                return -1;
        }

        printf ("Enter number of trains (max %d): ", maxCount);
        if (scanf ("%d", &count) != 1 || count <= 0)
        {
                fprintf (stderr, "Error: expected positive integer\n");
                return -1;
        }

        if (count > maxCount)
	{
                fprintf (stderr, "Warning: count reduced to %d\n", maxCount);
		 count = maxCount;
	}
                

        for (i = 0; i < count; i++)
        {
                printf ("\n--- Train %d of %d ---\n", i + 1, count);

                /* train number */
                printf ("Number: ");
                if (scanf ("%d", &trains[i].number) != 1
                    || trains[i].number <= 0)
                {
                        fprintf (stderr,
                                 "Error: train number must be positive\n");
                        return -1;
                }

                /* direction */
                printf ("Direction: ");
                if (scanf ("%49s", trains[i].direction) != 1)
                {
                        fprintf (stderr, "Error: could not read direction\n");
                        return -1;
                }

                /* departure time */
                printf ("Departure (HH MM): ");
                if (scanf ("%d %d",
                           &trains[i].departureH,
                           &trains[i].departureM) != 2)
                {
                        fprintf (stderr, "Error: expected two integers\n");
                        return -1;
                }

                if (trains[i].departureH < 0 || trains[i].departureH > 23
                    || trains[i].departureM < 0 || trains[i].departureM > 59)
                {
                        fprintf (stderr,
                                 "Error: time must be 00:00..23:59\n");
                        return -1;
                }

                /* arrival time */
                printf ("Arrival (HH MM): ");
                if (scanf ("%d %d",
                           &trains[i].arrivalH,
                           &trains[i].arrivalM) != 2)
                {
                        fprintf (stderr, "Error: expected two integers\n");
                        return -1;
                }

                if (trains[i].arrivalH < 0 || trains[i].arrivalH > 23
                    || trains[i].arrivalM < 0 || trains[i].arrivalM > 59)
                {
                        fprintf (stderr,
                                 "Error: time must be 00:00..23:59\n");
                        return -1;
                }

                /* distance */
                printf ("Distance (km): ");
                if (scanf ("%d", &trains[i].distance) != 1
                    || trains[i].distance <= 0)
                {
                        fprintf (stderr,
                                 "Error: distance must be positive\n");
                        return -1;
                }

                /* wagons */
                printf ("Wagons: ");
                if (scanf ("%d", &trains[i].wagons) != 1
                    || trains[i].wagons <= 0)
                {
                        fprintf (stderr,
                                 "Error: wagons must be positive\n");
                        return -1;
                }

                /* wagon type */
                printf ("Type (kupejnyj/platskart/obshchij): ");
                if (scanf ("%19s", trains[i].wagonType) != 1)
                {
                        fprintf (stderr,
                                 "Error: could not read wagon type\n");
                        return -1;
                }

                if (strcmp (trains[i].wagonType, "kupejnyj") != 0
                    && strcmp (trains[i].wagonType, "platskart") != 0
                    && strcmp (trains[i].wagonType, "obshchij") != 0)
                {
                        fprintf (stderr,
                                 "Error: type must be kupejnyj, "
                                 "platskart or obshchij\n");
                        return -1;
                }

                /* passengers per wagon */
                printf ("Passengers per wagon: ");
                if (scanf ("%d", &trains[i].passengers) != 1
                    || trains[i].passengers <= 0)
                {
                        fprintf (stderr,
                                 "Error: passengers must be positive\n");
                        return -1;
                }
        }

        return count;
}

/*
 * printOver24h - prints trains with estimated travel > 24 hours
 *
 * Uses average speed of 60 km/h to estimate travel time.
 */
void
printOver24h (TRAIN trains[], int count)
{
        int     i;
        int     found = 0;     /* flag: at least one found */
        double  hours;          /* estimated travel time */

        printf ("\n=== Trains traveling more than 24 hours ===\n");

        for (i = 0; i < count; i++)
        {
                hours = (double) trains[i].distance / 60.0;

                if (hours > 24.0)
                {
                        printTrain (&trains[i]);
                        printf ("    estimated travel time: %.1f h\n",
                                hours);
                        found = 1;
                }
        }

        if (!found)
                printf ("  No such trains found.\n");
}

/*
 * printCompartmentPassengers - prints total number of passengers
 *   across all trains with kupejnyj wagon type
 */
void
printCompartmentPassengers (TRAIN trains[], int count)
{
        int     i;
        int     total = 0;     /* accumulated passengers */

        printf ("\n=== Total passengers in compartment wagons ===\n");

        for (i = 0; i < count; i++)
        {
                if (strcmp (trains[i].wagonType, "kupejnyj") == 0)
                {
                        total += trains[i].wagons * trains[i].passengers;
                        printf ("  Train #%d: %d wagons x %d = %d\n",
                                trains[i].number,
                                trains[i].wagons,
                                trains[i].passengers,
                                trains[i].wagons * trains[i].passengers);
                }
        }

        printf ("  Total: %d passengers\n", total);
}

/*
 * printToGrodno - prints all trains with direction "Grodno"
 */
void
printToGrodno (TRAIN trains[], int count)
{
        int     i;
        int     found = 0;

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
                printf ("  No trains to Grodno found.\n");
}

/*
 * printMaxWagons - finds and prints the train
 *   with the largest number of wagons
 */
void
printMaxWagons (TRAIN trains[], int count)
{
        int     i;
        int     maxIdx = 0;    /* index of max */

        printf ("\n=== Train with maximum wagons ===\n");

        for (i = 1; i < count; i++)
        {
                if (trains[i].wagons > trains[maxIdx].wagons)
                        maxIdx = i;
        }

        printTrain (&trains[maxIdx]);
}
