#pragma once

#include "Plane3D.h"

namespace mygeom
{
    /**
     * distance between two points in space
     * @param vec1 vector of first point
     * @param vec2 vector of second point
     * @return double - distance between points
    **/
    inline double distance (const Vector3D vec1, const Vector3D vec2)
    {
        return sqrt((vec1 - vec2).sqr());
    }

    /**
     * signed distance between from point to plane (sign depends on half-space of point)
     * @param pl plane
     * @param vec2 vector of point
     * @return double - signed distance
    **/
    inline double signed_distance (const Plane3D pl, const Vector3D vec)
    {
        return dotprod (vec, pl.get_normal()) + pl.D_;
    }

    /**
     * unsigned distance from point to plane
    **/
    inline double distance (const Plane3D pl, const Vector3D vec)
    {
        return std::abs (signed_distance (pl, vec));
    }
}