#include "Rectangle.h"

bool Rectangle::check(Point2D* vertices) {
	if(Point2D::distance(vertices[0], vertices[1]) == Point2D::distance(vertices[2], vertices[3]))
	       if(Point2D::distance(vertices[0], vertices[3]) == Point2D::distance(vertices[2], vertices[1]))	
		       return true;
	return false;
}
Rectangle::Rectangle() : Shape() {
	vs = new Point2D[N_VERTICES];
	vs[0] = Point2D(-1, 0.5);
	vs[1] = Point2D(1, 0.5);
	vs[2] = Point2D(1, -0.5);
	vs[3] = Point2D(-1, -0.5);
}
Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color) {
	if(check(vertices)) {
		vs = new Point2D[N_VERTICES];
		vs[0] = vertices[0];
		vs[1] = vertices[1];
		vs[2] = vertices[2];
		vs[3] = vertices[3];
	} else
		throw std::invalid_argument("Vertices no forman un rectángulo");
}
Rectangle::Rectangle(const Rectangle &r) {
	vs = new Point2D[N_VERTICES];
	for(int i = 0; i < N_VERTICES; i++) {
		vs[i].x = r.vs[i].x;	
		vs[i].y = r.vs[i].y;
	}
}
Rectangle::~Rectangle() {
	delete[] vs;
}
Point2D Rectangle::get_vertex(int ind) const {
	if((ind > -1) && (ind < N_VERTICES))
		return vs[ind];
	else
		throw std::out_of_range("Índice no válido");
}
Point2D Rectangle::operator[](int ind) const {
	return get_vertex(ind);
}
void Rectangle::set_vertices(Point2D* vertices) {
	if(check(vertices)) {
		for(int i = 0; i < N_VERTICES; i++) {
                vs[i].x = vertices[i].x;
                vs[i].y = vertices[i].y;
		}
	//delete[] vertices;
        } else
                throw std::invalid_argument("Vertices no forman un rectángulo");
}
Rectangle& Rectangle::operator=(const Rectangle &r) {
	delete[] vs;
	vs = new Point2D[N_VERTICES];
	for(int i = 0; i < N_VERTICES; i++) {
		vs[i].x = r.vs[i].x;	
		vs[i].y = r.vs[i].y;
	}
	return *this;
}
std::ostream& operator<<(std::ostream &out, const Rectangle &r) {
	out << "[Rectangle: color = " << r.color << "; v0 = " << r.vs[0] << "; v1 = " << r.vs[1] << "; v2 = " << r.vs[2] << "; v3 = " << r.vs[3] << "]";
	return out;
}
double Rectangle::area() const {
	return (Point2D::distance(vs[0], vs[1]) * Point2D::distance(vs[2], vs[1]));
}
double Rectangle::perimeter() const {
	return ((Point2D::distance(vs[0], vs[1]) * 2) + (Point2D::distance(vs[2], vs[1]) * 2));
}
void Rectangle::translate(double incX, double incY) {
	for(int i = 0; i < N_VERTICES; i++) {
		vs[i].x += incX;	
		vs[i].y += incY;
	}
}
void Rectangle::print() {
	std::cout << *this << std::endl;
}	
