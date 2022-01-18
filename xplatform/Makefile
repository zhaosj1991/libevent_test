TARGET=xplatform

CFLAGS = `pkg-config --cflags libevent` `pkg-config --cflags protobuf`
CFLAGS += -std=c++11
LDFLAGS += `pkg-config --libs libevent`  `pkg-config --libs protobuf` -lpthread

SRC = $(wildcard *.cpp *.cc)
TMP = $(patsubst %.cc, %.o, $(SRC))
OBJ = $(patsubst %.cpp, %.o, $(TMP))

.PHONY: all proto

all: proto $(TARGET)

$(TARGET): $(OBJ)
	g++ -o $@ $^ $(CFLAGS) $(LDFLAGS)

%.o: %.cpp
	g++ -c -o $@ $^ $(CFLAGS)

%.o: %.cc
	g++ -c -o $@ $^ $(CFLAGS)

proto: 
	protoc -I=./ --cpp_out=./ xmsg_comm.proto
	protoc -I=./ --cpp_out=./ xmsg_type.proto
	
clean:
	rm -rf $(TARGET) $(OBJ)