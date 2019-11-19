CC = g++
CFLAGS = -c -Wall

regressor.o: regressor.cpp
	$(CC) $(CFLAGS) regressor.cpp

regressorTests.o: regressorTests.cpp
	$(CC) $(CFLAGS) regressorTests.cpp

regr: regressor.o regressorTests.o
	$(CC) *.o -o regr

clean:
	rm -rf *.o

delete:
	rm -rf regr
