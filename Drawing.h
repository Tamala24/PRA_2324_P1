//#include <iostream>
#include "ListLinked.h"
#include "listArray.h"
#include "Square.h"
#include "Circle.h"

class Drawing {
	private:
		List<Shape*>* shapes;
	public:
		Drawing();
		virtual ~Drawing(); // virtual por si usamos ListArray o ListLinked
		void add_front(Shape* shape);
		void add_back(Shape* shape);
		void print_all();
		double get_area_all_circles();
		void move_squares(double incX, double incY);
};
