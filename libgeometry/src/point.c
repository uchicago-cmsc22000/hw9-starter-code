/*
 * A two-dimensional point data structure.
 *
 * See point.h for function documentation.
 */

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include "utils.h"
#include "point.h"

/* See point.h */
point_t* point_new(double x, double y)
{
    point_t *p;
    int rc;

    p = malloc(sizeof(point_t));

    if(p == NULL)
    {
        error("Could not allocate memory");
        return NULL;
    }

    rc = point_init(p, x, y);
    if(rc != SUCCESS)
    {
        error("Could not initialize point with (%.2f, %.2f)", x, y);
        return NULL;
    }

    return p;
}

/* See point.h */
int point_init(point_t *p, double x, double y)
{
    assert(p != NULL);

    p->x = x;
    p->y = y;

    return SUCCESS;
}

/* See point.h */
int point_free(point_t *p)
{
    assert(p != NULL);

    free(p);

    return SUCCESS;
}

/* See point.h */
double point_distance(point_t *p1, point_t *p2)
{
    assert(p1 != NULL);
    assert(p2 != NULL);

    return sqrt( pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2) );
}

/* See point.h */
int point_orientation(point_t *p, point_t *q, point_t *r)
{
    // See https://www.geeksforgeeks.org/orientation-3-ordered-points/
    // for details of below formula.
    double val = (q->y - p->y) * (r->x - q->x) -
                 (q->x - p->x) * (r->y - q->y);

    if (val == 0.0) return 0;  // colinear

    return (val > 0.0)? 1: 2; // clock or counterclock wise
}
