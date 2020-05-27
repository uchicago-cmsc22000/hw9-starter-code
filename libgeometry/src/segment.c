/*
 * A two-dimensional segment data structure.
 *
 * See segment.h for function documentation.
 */

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include "utils.h"
#include "segment.h"


/* See segment.h */
segment_t* segment_new(point_t *p1, point_t *p2)
{
    segment_t *segment;
    int rc;

    segment = malloc(sizeof(segment_t));

    if(segment == NULL)
    {
        error("Could not allocate memory");
        return NULL;
    }

    rc = segment_init(segment, p1, p2);
    if(rc != SUCCESS)
    {
        error("Could not initialize segnent");
        return NULL;
    }

    return segment;
}

/* See segment.h */
int segment_init(segment_t *segment, point_t *p1, point_t *p2)
{
    assert(segment != NULL);
    assert(p1 != NULL);
    assert(p2 != NULL);

    segment->p1 = p1;
    segment->p2 = p2;

    return SUCCESS;
}

/* See segment.h */
int segment_free(segment_t *segment)
{
    assert(segment != NULL);

    free(segment);

    return SUCCESS;
}

/* See segment.h */
bool on_segment(segment_t *s, point_t *q)
{
    point_t *p = s->p1;
    point_t *r = s->p2;

    if (q->x == p->x && q->y == p->y)
        return false;

    if (q->x == r->x && q->y == r->y)
        return false;

    if (q->x <= max(p->x, r->x) && q->x >= min(p->x, r->x) &&
        q->y <= max(p->y, r->y) && q->y >= min(p->y, r->y))
       return true;

    return false;
}

/* Code to determine segment intersection adapted from
 * https://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/ *
 *
 * Modified to not consider connected segments to intersect (unless they overlap) */

/* See segment.h */
bool segment_intersect(segment_t *s1, segment_t *s2)
{
    point_t *p1, *q1, *p2, *q2;

    p1 = s1->p1;
    q1 = s1->p2;
    p2 = s2->p1;
    q2 = s2->p2;    

    // Find the four orientations needed for general and
    // special cases
    int o1 = point_orientation(p1, q1, p2);
    int o2 = point_orientation(p1, q1, q2);
    int o3 = point_orientation(p2, q2, p1);
    int o4 = point_orientation(p2, q2, q1);

    bool connected = (q1->x == p2->x && q1->y == p2->y);

    // General case
    if (o1 != o2 && o3 != o4 && !connected)
        return true;

    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment s1
    if (o1 == 0 && on_segment(s1, p2)) return true;

    // p1, q1 and q2 are colinear and q2 lies on segment s1
    if (o2 == 0 && on_segment(s1, q2)) return true;

    // p2, q2 and p1 are colinear and p1 lies on segment s2
    if (o3 == 0 && on_segment(s2, p1)) return true;

     // p2, q2 and q1 are colinear and q1 lies on segment s2
    if (o4 == 0 && on_segment(s2, q1)) return true;

    return false; // Doesn't fall in any of the above cases
}
