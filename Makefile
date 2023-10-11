bin/testListArray: testListArray.cpp listArray.h list.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp listArray.h
bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp Node.h
clean:
	rm -r *.o *.gch bin
