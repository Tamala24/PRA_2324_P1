#include "Point2D.h"
#include "Shape.h"
#include "Rectangle.h"
#include <ostream>

class Square : public Rectangle {
	public:
		static bool check(Point2D* vertices);
		Square();
		Square(std::string color, Point2D* vertices);
		friend std::ostream& operator<<(std::ostream &out, const Square &square);
		void set_vertices(Point2D* vertices) override;
		void print() override;
		double area() const override;
		double perimeter() const override;
		void translate(double incX, double incY) override;
};
