#pragma once

#include <cassert>
#include "Vector3D.h"
#include <iostream>

namespace mygeom
{

    class Plane3D final
    {
        private:
            Vector3D norm_;

        public:
            double D_ = 0;

            Plane3D () {};

            Plane3D (double A, double B, double C, double D = 0);

            Plane3D (Vector3D normal, double D = 0);

            Plane3D (Vector3D p1, Vector3D p2, Vector3D p3);

            bool is_valid () const;

            Vector3D get_normal () const;

            void set_normal (Vector3D vec);
    };
}