mytest:main.o randnumgeneration.o
	g++ -g -Wall -o mytest main.o randnumgeneration.o
main.o:main.cpp randnumgeneration.h
	gcc -g -Wall -c  main.cpp 
randnumgeneration.o: randnumgeneration.cpp randnumgeneration.h
	gcc -g -Wall -c randnumgeneration.cpp

clean:
	rm *.o &&echo "make clean success!"	
