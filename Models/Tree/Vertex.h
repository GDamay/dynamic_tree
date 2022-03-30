//Represents a vertex of the tree
#ifndef VERTEX_H_INCLUDED
#define VERTEX_H_INCLUDED

#include "../PointSet/PointSet.h"
#include "../PointSet/Point.h"

class Vertex {
	private:
		bool is_leaf;
		bool is_root;
		bool is_built;
		size_t split_parameter;
		unsigned int remaining_high;
		unsigned int updates_since_last_build;
		//not owned
		Vertex* parent;
		//owned
		Vertex* under_child;
		//owned
		Vertex* over_child;
		//owned
		PointSet* pointset;

	public:
		//Takes ownership of pointset, not of parent
		Vertex(PointSet* pointset, Vertex* parent, unsigned int remaining_high, bool is_root = false);
		~Vertex();
		void build();
		void add_point(Point* new_point);
		
		//Does not take ownership
		bool decision(const float* features);
};
#endif // VERTEX_H_INCLUDED
