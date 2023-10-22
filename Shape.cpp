//#include <stdexcept>
#include "Shape.h"

Shape::Shape() : color{"red"} {}
Shape::Shape(std::string color) {
	set_color(color);
}
std::string Shape::get_color() const {
	return color;
}
void Shape::set_color(std::string color) {
	if((color == "red") || (color == "green") || (color == "blue"))
                this->color = color;
        else
                throw std::invalid_argument("Color no válido\n");
}
