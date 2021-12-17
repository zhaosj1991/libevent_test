TARGET=first_libevent

CFLAGS=`pkg-config --cflags libevent` `pkg-config --libs libevent`

$(TARGET): $(TARGET).cpp
	g++ -o $@ $^ $(CFLAGS)

clean:
	rm -rf $(TARGET)