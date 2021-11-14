#pragma once

#include "Distance3D.h"
#include <algorithm> 

namespace mygeom
{
    class Triangle3D final
    {
        private:
            Vector3D points_[3];
            Plane3D plane_;

            void update_plane ();
        public:
            Triangle3D () {};

            Triangle3D (Vector3D A, Vector3D B, Vector3D C) : points_{A, B, C}
            {
                update_plane ();
            } 

            inline bool is_true_triangle () const
            {
                return plane_.is_valid ();
            }

            Vector3D get_vertex (int index) const;

            Vector3D operator[] (int index) const;

            Plane3D get_plane () const;

            void set_vertex (int num, Vector3D vec);

            bool operator== (Triangle3D tr) const;
    };

}