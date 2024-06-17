# Makefile

CXX = g++
CXXFLAGS = -std=c++11 -Wall
LDFLAGS = 

OBJS = main.o Request.o RequestQueue.o WebServer.o LoadBalancer.o

all: loadbalancer

loadbalancer: $(OBJS)
	$(CXX) $(CXXFLAGS) -o loadbalancer $(OBJS) $(LDFLAGS)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Request.o: Request.cpp Request.h
	$(CXX) $(CXXFLAGS) -c Request.cpp

RequestQueue.o: RequestQueue.cpp RequestQueue.h
	$(CXX) $(CXXFLAGS) -c RequestQueue.cpp

WebServer.o: WebServer.cpp WebServer.h
	$(CXX) $(CXXFLAGS) -c WebServer.cpp

LoadBalancer.o: LoadBalancer.cpp LoadBalancer.h
	$(CXX) $(CXXFLAGS) -c LoadBalancer.cpp

clean:
	rm -f *.o loadbalancer
