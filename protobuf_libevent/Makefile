TARGET=protobuf_libevent

CFLAGS = `pkg-config --cflags libevent` `pkg-config --libs libevent`
CFLAGS += -std=c++11 -lpthread -ggdb

$(TARGET): $(TARGET).cpp xmsg_server.cpp xmsg_client.cpp
	g++ -o $@ $^ $(CFLAGS)

clean:
	rm -rf $(TARGET)