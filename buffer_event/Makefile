TARGET=buffer_event

CFLAGS=`pkg-config --cflags libevent` `pkg-config --libs libevent`

$(TARGET): $(TARGET).cpp
	g++ -o $@ $^ $(CFLAGS)

clean:
	rm -rf $(TARGET)