bin/testListArray: testListArray.cpp listArray.h list.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp listArray.h

clean:
	rm -r *.o *.gch bin
