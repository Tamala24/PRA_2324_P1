#include "Drawing.h"

Drawing::Drawing() {
	shapes = new ListLinked<Shape*>();
}
Drawing::~Drawing() {
	delete[] shapes;
}
void Drawing::add_front(Shape* shape) {
	shapes->prepend(shape);
}
void Drawing::add_back(Shape* shape) {
	shapes->append(shape);
}
void Drawing::print_all() {
	if(!shapes->empty()) {
		int n = shapes->size();
		for(int i = 0; i < n; i++) 
			(shapes->get(i))->print();
	}
}
double Drawing::get_area_all_circles() {
	if(!shapes->empty()) {
		double T_area = 0.0;
		Circle* c;
		int i = 0, n = shapes->size();
		for (i = 0; i < n; i++) 
			if(c = dynamic_cast<Circle*>(shapes->get(i)))
				T_area += c->area();
		return T_area;
	}
		//Shape* s = new Circle(); 
		//int p = shapes->search(s*);
		//delete s;
		//if (p != -1) 
		//	return (shapes->get(p))->area();
		//else 
	return -1;
		/*int n = shapes->size();
		for(int i = 0; i < n; i++) 
			std::cout << shapes->get(i);*/
}
void Drawing::move_squares(double incX, double incY) {
	if(!shapes->empty()) {
		Square* sq;
		int i = 0, n = shapes->size();
		for (i = 0; i < n; i++) 
			if(sq = dynamic_cast<Square*>(shapes->get(i)))
				sq->translate(incX, incY);
	}
}
