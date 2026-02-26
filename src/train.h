/* train.h */
/* Author: Yarmolik Anastasia, group 11 */

#ifndef TRAIN_H
#define TRAIN_H

/*
 * Maximum number of train records
 */
#define MAX_TRAINS 12
#define MAX_STR 50
#define MAX_TYPE 20

/*
 * Structure TRAIN - stores information about a train
 */
typedef struct
{
        int     number;         /* train number */
        char    direction[MAX_STR];  /* destination */
        int     departureH;    /* departure time: hours */
        int     departureM;    /* departure time: minutes */
        int     arrivalH;      /* arrival time: hours */
        int     arrivalM;      /* arrival time: minutes */
        int     distance;       /* distance in km */
        int     wagons;         /* number of wagons */
        char    wagonType[MAX_TYPE]; /* type of wagon */
        int     passengers;     /* passengers per wagon */
} TRAIN;

/* Create array of trains, returns count */
int     inputTrains (TRAIN trains[], int maxCount);

/* Print trains traveling more than 24 hours */
void    printOver24h (TRAIN trains[], int count);

/* Print total passengers for compartment wagons */
void    printCompartmentPassengers (TRAIN trains[], int count);

/* Print trains going to Grodno */
void    printToGrodno (TRAIN trains[], int count);

/* Print train with maximum wagons */
void    printMaxWagons (TRAIN trains[], int count);

/* Print single train record */
void    printTrain (TRAIN *t);

#endif
