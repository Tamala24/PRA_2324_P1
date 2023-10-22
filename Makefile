bin/testListArray: testListArray.cpp listArray.h list.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp listArray.h
bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp Node.h
bin/testListLinked: testListLinked.cpp ListLinked.h list.h
	mkdir -p bin
	g++ -o bin/testListLinked testListLinked.cpp ListLinked.h
Point2D.o: Point2D.h Point2D.cpp
	g++ -c Point2D.cpp
bin/testPoint2D: testPoint2D.cpp Point2D.o
	g++ -c testPoint2D.cpp
	mkdir -p bin
	g++ -o bin/testPoint2D testPoint2D.o Point2D.o
Shape.o: Shape.h Shape.cpp
	g++ -c Shape.cpp
Circle.o: Circle.h Circle.cpp Shape.h
	g++ -c Circle.cpp
bin/testCircle: testCircle.cpp Circle.o Shape.o Point2D.o
	g++ -c testCircle.cpp
	mkdir -p bin
	g++ -o bin/testCircle testCircle.o Circle.o Shape.o Point2D.o
Rectangle.o: Rectangle.cpp Rectangle.h 
	g++ -c Rectangle.cpp
bin/testRectangle: testRectangle.cpp Rectangle.o Shape.o Point2D.o
	g++ -c testRectangle.cpp
	mkdir -p bin
	g++ -o bin/testRectangle testRectangle.o Rectangle.o Shape.o Point2D.o 
Square.o: Square.h Square.cpp
	g++ -c Square.cpp
bin/testSquare: Square.o Rectangle.o Point2D.o Shape.o testSquare.cpp
	g++ -c testSquare.cpp
	mkdir -p bin
	g++ -o bin/testSquare testSquare.o Point2D.o Shape.o Rectangle.o Square.o
Drawing.o: Drawing.h Drawing.cpp
	g++ -c Drawing.cpp
bin/testDrawing: testDrawing.cpp Drawing.o Square.o Rectangle.o Circle.o Shape.o Point2D.o
	mkdir -p bin
	g++ -o bin/testDrawing testDrawing.cpp Drawing.o Square.o Rectangle.o Circle.o Shape.o Point2D.o
clean:
	rm -r *.o *.gch bin
