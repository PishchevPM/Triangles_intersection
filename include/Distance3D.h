#pragma once

#include "Vector3D.h"
#include "Plane3D.h"
#include "Intersection3D.h"

namespace mygeom
{
    double distance (const Vector3D vec1, const Vector3D vec2);

    double signed_distance (const Plane3D pl, const Vector3D vec);

    double distance (const Plane3D pl, const Vector3D vec);
}