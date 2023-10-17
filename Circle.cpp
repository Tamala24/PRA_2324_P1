#include "Circle.h"
#include <cmath>
#define PI 3.141592

Circle::Circle() : Shape() {
	center.x = 0;
	center.y = 0;
	radius = 1.0;
}
Circle::Circle(std::string color, Point2D center, double radius) : Shape(color) {
	this->center.x = center.x;
	this->center.y = center.y;
	this->radius = radius;
}
Circle::Circle(Point2D center, double radius) : Shape() {
	this->center.x = center.x;
	this->center.y = center.y;
	this->radius = radius;
}
Point2D Circle::get_center() const {
	return center;
}
void Circle::set_center(Point2D p) {
	center.x = p.x;
	center.y = p.y;
}
double Circle::get_radius() const {
	return radius;
}
void Circle::set_radius(double r) {
	radius = r;
}
std::ostream& operator<<(std::ostream &out, const Circle &c) {
	out << "[Circle: color = " << c.color << "; center = " << c.center << "; radius = " << c.radius << "]";
	return out;
}
double Circle::area() const {
	return PI*radius*radius;
}
double Circle::perimeter() const {
	return 2*PI*radius;
}
void Circle::translate(double incX, double incY) {
	center.x += incX;
	center.y += incY;
}
void Circle::print() {
	std::cout << this << std::endl;
}
