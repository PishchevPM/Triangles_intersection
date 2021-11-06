#pragma once

#include "Vector3D.h"
#include "Plane3D.h"

namespace mygeom
{
    /**
     * distance between two points in space
     * @param vec1 vector of first point
     * @param vec2 vector of second point
     * @return double - distance between points
    **/
    double distance (const Vector3D vec1, const Vector3D vec2);

    /**
     * signed distance between from point to plane (sign depends on half-space of point)
     * @param pl plane
     * @param vec2 vector of point
     * @return double - signed distance
    **/
    double signed_distance (const Plane3D pl, const Vector3D vec);

    /**
     * unsigned distance from point to plane
    **/
    double distance (const Plane3D pl, const Vector3D vec);
}