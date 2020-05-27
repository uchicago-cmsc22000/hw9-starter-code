#ifndef INCLUDE_POLYGON_H_
#define INCLUDE_POLYGON_H_

#include "common.h"
#include "point.h"

/**
 * \brief  A polygon in two-dimensional space 
 */
typedef struct {
    point_t *points; ///< array of points in the polygon

    unsigned int n_points; ///< number of points in the polygon

    unsigned int n_alloc; ///< space allocated for points (in number of points)
} polygon_t;


/**
 * \memberof polygon_t
 * \brief Allocates an empty polygon in the heap.
 *
 * \return A pointer to the polygon, or NULL if a point cannot be allocated
 */
polygon_t* polygon_new();


/**
 * \memberof polygon_t
 * \brief Initializes a polygon (as an empty polygon(
 *
 * \param poly: A polygon. Must point to already allocated memory.
 *
 * \return 0 on success, 1 if an error occurs.
 */
int polygon_init(polygon_t *poly);


/**
 * \memberof polygon_t
 * \brief Frees the resources associated with a polygon
 *
 * \param poly: A polygon. Must point to a polygon allocated with polygon_new
 *
 * \return  Always returns 0.
 */
int polygon_free(polygon_t *poly);


/**
 * \memberof polygon_t
 * \brief Adds a point (expressed as x, y coordinates) to a polygon
 *
 * \param poly: The polygon
 * \param x: x coordinate of the point to add
 * \param y: y coordinate of the point to add
 *
 * \return 0 on success, 1 if an error occurs.
 */
int polygon_add_xy(polygon_t *poly, double x, double y);


/**
 * \memberof polygon_t
 * \brief Adds a point (expressed as x, y coordinates) to a polygon
 *
 * \param poly: The polygon
 * \param  p: The point to add
 *
 * \return 0 on success, 1 if an error occurs.
 */
int polygon_add_point(polygon_t *poly, point_t *p);


/**
 * \memberof polygon_t
 * \brief Computes the perimeter of a polygon
 *
 * \param poly: The polygon
 *
 * \return The perimeter of the polygon, or 0.0 if the polygon currently only has two points
 */
double polygon_perimeter(polygon_t *poly);


/**
 * \memberof polygon_t
 * \brief Computes the area of a polygon
 *
 * \param poly: The polygon
 *
 * \return The area of the polygon, or 0.0 if the polygon currently only has two points
 */
double polygon_area(polygon_t *poly);


#endif /* INCLUDE_POLYGON_H_ */
