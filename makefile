CC=g++
SRC_DIR=src
INCLUDE=-I /usr/local/include/eigen3
OBJS=utilities.o metrics.o gradient_descent.o linear_regression.o


all: | $(OBJS)
	$(CC) -o linear_regression $(OBJS) $(INCLUDE)

utilities.o:
	$(CC) -c $(SRC_DIR)/utilities.cpp $(INCLUDE) 

metrics.o:
	$(CC) -c $(SRC_DIR)/metrics.cpp $(INCLUDE) 

gradient_descent.o: metrics.o
	$(CC) -c $(SRC_DIR)/gradient_descent.cpp $(INCLUDE) 

linear_regression.o: gradient_descent.o metrics.o utilities.o
	$(CC) -c $(SRC_DIR)/linear_regression.cpp $(INCLUDE)

clean:
	rm *.o