#ifndef INCLUDE_POINT_H_
#define INCLUDE_POINT_H_

#include "common.h"

/**
 * \brief A point in two-dimensional space 
 */
typedef struct {
    double x; ///< x coordinate
    double y; ///< y coordinate
} point_t;


/**
 * \memberof point_t
 * \brief Allocates a new point in the heap.
 *
 * \param x: The x coordinate
 * \param y: The y coordinate
 * \return A pointer to the point, or NULL if a point cannot be allocated
 */
point_t* point_new(double x, double y);


/**
 * \memberof point_t
 * \brief Initializes the coordinates of a point
 *
 * \param p: A point. Must point to already allocated memory.
 * \param x: x coordinate of the point
 * \param y: y coordinate of point
 * \return 0 on success, 1 if an error occurs.
 */
int point_init(point_t *p, double x, double y);


/**
 * \memberof point_t
 * \brief Frees the resources associated with a point
 *
 * \param p: A point. Must point to a point allocated with point_new
 *
 * \return  Always returns 0.
 */
int point_free(point_t *p);


/**
 * \memberof point_t
 * \brief Computes the distance between two points
 *
 * \param p1: first point
 * \param p2: second point  
 *
 * \return The euclidean distance between p1 and p2
 */
double point_distance(point_t *p1, point_t *p2);


/**
 * \memberof point_t
 * \brief Finds the orientation of the ordered triplet (p, q, r)
 *
 * \param p: first point
 * \param q: second point  
 * \param r: third point  
 *
 * \return 0 if p, q and r are colinear,1 if p, q, and r are clockwise, 2 if p, q, and r are counterclockwise
 */
int point_orientation(point_t *p, point_t *q, point_t *r);


#endif /* INCLUDE_POINT_H_ */
