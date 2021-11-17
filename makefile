CC = g++
CFLAGS = -std=c++11 -g -O2 -Wall -I include
BASEOBJECTS = Intersection3D.o Plane3D.o Triangle3D.o Vector3D.o
OTHEROBJECTS = vector_test.o vector_test triangle_test.o triangle_test triangles.o triangles

all: triangles

Vector3D.o: include/Vector3D.h source/Vector3D.cpp
	$(CC) $(CFLAGS) source/Vector3D.cpp -c -o Vector3D.o

Intersection3D.o: include/Intersection3D.h source/Intersection3D.cpp
	$(CC) $(CFLAGS) source/Intersection3D.cpp -c -o Intersection3D.o

Plane3D.o: include/Plane3D.h source/Plane3D.cpp
	$(CC) $(CFLAGS) source/Plane3D.cpp -c -o Plane3D.o

Triangle3D.o: include/Triangle3D.h source/Triangle3D.cpp
	$(CC) $(CFLAGS) source/Triangle3D.cpp -c -o Triangle3D.o

vector_test.o: $(BASEOBJECTS) source/vector_test.cpp
	$(CC) $(CFLAGS) source/vector_test.cpp -c -o vector_test.o

vector_test: $(BASEOBJECTS) vector_test.o
	$(CC) $(CFLAGS) $(BASEOBJECTS) vector_test.o -o vector_test

triangle_test.o: $(BASEOBJECTS) source/triangle_test.cpp
	$(CC) $(CFLAGS) source/triangle_test.cpp -c -o triangle_test.o

triangle_test: $(BASEOBJECTS) triangle_test.o
	$(CC) $(CFLAGS) $(BASEOBJECTS) triangle_test.o -o triangle_test

triangles.o: $(BASEOBJECTS) source/triangles.cpp
	$(CC) $(CFLAGS) source/triangles.cpp -c -o triangles.o

triangles: $(BASEOBJECTS) triangles.o
	$(CC) $(CFLAGS) $(BASEOBJECTS) triangles.o -o triangles

clean:
	rm -r -f $(BASEOBJECTS) $(OTHEROBJECTS)