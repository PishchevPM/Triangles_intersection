#pragma once

#include "Vector3D.h"
#include "Plane3D.h"
#include "Distance3D.h"
#include <algorithm> 

namespace mygeom
{
    class Triangle3D final
    {
        private:
            Vector3D points_[3] = {Vector3D(), Vector3D(), Vector3D()};
            Plane3D plane_;

            void update_plane ();
        public:
            Triangle3D () {};

            Triangle3D (Vector3D A, Vector3D B, Vector3D C);

            bool is_true_triangle () const;

            Vector3D get_vertex (int index) const;

            Vector3D operator[] (int index) const;

            Plane3D get_plane () const;

            void set_vertex (int num, Vector3D vec);

            bool operator== (Triangle3D tr) const;
    };

}