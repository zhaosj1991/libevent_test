TARGET=protobuf_libevent

CFLAGS = `pkg-config --cflags libevent` `pkg-config --libs libevent`
CFLAGS += `pkg-config --cflags protobuf` `pkg-config --libs protobuf`
CFLAGS += -O2 -std=c++11 
# CFLGAs += -ggdb

LDFLAGS = -lpthread

.PHONY: all proto

OBJ = $(TARGET).o xmsg_server.o xmsg_client.o xmsg_comm.pb.o
OBJ += xmsg_type.pb.o xmsg_event.o xclient_event.o xserver_event.o

all: proto $(TARGET)

$(TARGET): $(OBJ)
	g++ -o $@ $^ $(CFLAGS) $(LDFLAGS)

%.o: %.cc
	g++ -c -o $@ $^ $(CFLAGS)

%.o: %.cpp
	g++ -c -o $@ $^ $(CFLAGS)

proto:
	protoc -I=./ --cpp_out=./ xmsg_comm.proto
	protoc -I=./ --cpp_out=./ xmsg_type.proto

clean:
	@rm -rf $(TARGET) *.o