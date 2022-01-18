
CFLAGS=`pkg-config --cflags libevent` `pkg-config --libs libevent` -std=c++11

.PHONY: all clean

all:
	g++ -o server server.cpp $(CFLAGS) 
	g++ -o client client.cpp $(CFLAGS) 

clean:
	rm -rf server client