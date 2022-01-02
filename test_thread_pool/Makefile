TARGET=test_thread_pool

CFLAGS = `pkg-config --cflags libevent`
CFLAGS += -std=c++11
LDFLAGS += `pkg-config --libs libevent` -lpthread

OBJ = test_thread_pool.o XThreadPool.o Thread.o FtpServerCmd.o

$(TARGET): $(OBJ)
	g++ -o $@ $^ $(CFLAGS) $(LDFLAGS)

%.o: %.cpp
	g++ -c -o $@ $^ $(CFLAGS)

clean:
	rm -rf $(TARGET) $(OBJ)