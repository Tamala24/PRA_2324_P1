#include "Square.h"
bool Square::check(Point2D* vertices) {
	return ((Point2D::distance(vertices[0], vertices[1])) == (Point2D::distance(vertices[1], vertices[2]))) == ((Point2D::distance(vertices[2], vertices[3])) == (Point2D::distance(vertices[0], vertices[3])));
}
Square::Square() : Rectangle(){
	Point2D *ver = new Point2D[N_VERTICES];
	ver[0] = Point2D(-1,1);
	ver[1] = Point2D(1,1);
	ver[2] = Point2D(1,-1);
	ver[3] = Point2D(-1,-1);
	set_vertices(ver);
	delete[] ver;
}
Square::Square(std::string color, Point2D* vertices) : Rectangle() {
	set_color(color);
	set_vertices(vertices);
}
void Square::set_vertices(Point2D* vertices) {
	if(!check(vertices))
		throw std::invalid_argument("Vertices no forman un cuadrado");
	//delete[] vs;
	//vs = new Point2D[N_VERTICES];
	for(int i = 0; i < N_VERTICES; i++) {
		vs[i].x = vertices[i].x;
		vs[i].y = vertices[i].y; 
	}
}
std::ostream& operator<<(std::ostream &out, const Square &square) {
	out << "[Square: color = " << square.color << "; v0 = " << square.vs[0] << "; v1 = " << square.vs[1] << "; v2 = " << square.vs[2] << "; v3 = " << square.vs[3] << "]";
	return out;
}
void Square::print() {
	std::cout << *this << std::endl;
}
double Square::area() const {
	return Point2D::distance(vs[0], vs[1]) * Point2D::distance(vs[1], vs[2]);
}
double Square::perimeter() const {
	return 4 * Point2D::distance(vs[0], vs[1]);
}
void Square::translate(double incX, double incY) {
	for(int i = 0; i < N_VERTICES; i++) {
		vs[i].x += incX;
		vs[i].y += incY;
	}
}
