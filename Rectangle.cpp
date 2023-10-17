#include "Rectangle.h"

bool Rectangle::check(Point2D* vertices) {

}
Rectangle::Rectangle() : Shape() {
	vs[0] = new Point2D(-1, 0.5);
	vs[1] = new Point2D(1, 0.5);
	vs[2] = new Point2D(1, -0.5);
	vs[3] = new Point2D(-1, -0.5);
}
Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color) {
	if(check(vertices)) {
		vs[0] = vertices[0];
		vs[1] = vertices[1];
		vs[2] = vertices[2];
		vs[3] = vertices[3];
	} else
		throw std::invalid_argument("Vertices no forman un rectángulo");
}
Rectangle::Rectangle(const Rectangle &r) {

}
Rectangle::~Rectangle() {
	delete[] vs;
}
Point2D Rectangle::get_vertex(int ind) const {
	if(ind > -1 && ind < N_VERTICES)
		return vs[ind];
	else
		throw std::out_of_range("Índice no válido");
}
Point2D Rectangle::operator[](int ind) const {
	return get_vertex(ind);
}
void Rectangle::set_vertices(Point2D* vertices) {
	if(check(vertices)) {
                vs[0] = vertices[0];
                vs[1] = vertices[1];
                vs[2] = vertices[2];
                vs[3] = vertices[3];
        } else
                throw std::invalid_argument("Vertices no forman un rectángulo");
}
Rectangle& Rectangle::operator=(const Rectangle &r) {

}
std::ostream& operator<<(std::ostream &out, const Rectangle &r) {
	out << "[Rectangle: color = " << r.color << "; v0 = " << r.vs[0] << "; v1 = " << r.vs[1] << "; v2 = " << r.vs[2] << "; v3 = " << r.vs[3] << "]";
	return out;
}
double Rectangle::area() const {

}
double Rectangle::perimeter() const {

}
void Rectangle::translate(double incX, double incY) {

}
void Rectangle::print() {

}	
