/*
 * A two-dimensional segment data structure
 */

#ifndef INCLUDE_SEGMENT_H_
#define INCLUDE_SEGMENT_H_

#include "common.h"
#include "point.h"

/* A segment in two-dimensional space */
typedef struct {
    // The two points that define the segment
    point_t *p1, *p2;
} segment_t;


/*
 * Allocates a segment in the heap.
 *
 * Parameters:
 *  - p1, p2: The points that define the segment.
 * 
 * Note: This does not create a deep copy of the points.
 *       The segment will point to the provided points.
 *
 * Returns:
 *  - A pointer to the segment, or NULL if a point
 *    cannot be allocated
 */
segment_t* segment_new(point_t *p1, point_t *p2);


/*
 * Initializes a segment
 *
 * Parameters:
 *  - segment: A segment. Must point to already allocated memory.
 *  - p1, p2: The points that define the segment.
 *
 * Note: This does not create a deep copy of the points.
 *       The segment will point to the provided points.
 * 
 * Returns:
 *  - 0 on success, 1 if an error occurs.
 */
int segment_init(segment_t *segment, point_t *p1, point_t *p2);


/*
 * Frees the resources associated with a segment
 * 
 * Note: It will not free the points associated with the segment.
 *
 * Parameters:
 *  - segment: A segment. Must point to a segment allocated with segment_new
 *
 * Returns:
 *  - Always returns 0.
 */
int segment_free(segment_t *segment);


/*
 * Determines whether a point lies on a segment
 *
 * Parameters:
 *  - s: A segment
 *  - q: A point
 *
 * Returns:
 *  - true if q is on segment s, false otherwise
 */   
bool on_segment(segment_t *s, point_t *q);


/*
 * Determines whether two segments intersect
 *
 * Parameters:
 *  - s1, s2: The two segments
 *
 * Returns:
 *  - true if they intersect, false otherwise
 */
bool segment_intersect(segment_t *s1, segment_t *s2);

#endif /* INCLUDE_SEGMENT_H_ */
