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

            /**
             * build plane by his equation
            **/
            Plane3D (double A, double B, double C, double D = 0);

            /**
             * build plane by normal vector and param D
            **/
            Plane3D (Vector3D normal, double D = 0);

            /**
             * build plane by three points
            **/
            Plane3D (Vector3D p1, Vector3D p2, Vector3D p3);

            /**
             * is plane valid? (non-degenerate)
            **/
            bool is_valid () const;

            /**
             * get normal vector of plane
             * @return normal, if plane is valid or something scary if plane isn't valid
            **/
            Vector3D get_normal () const;

            /**
             * set normal vector
            **/
            void set_normal (Vector3D vec);
    };
}