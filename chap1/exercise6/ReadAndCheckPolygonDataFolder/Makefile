CC = g++
TARGET = ReadAndCheckPolygonData
SRCS = $(wildcard ./*.cpp) $(wildcard ../PolygonFormulaFolder/*.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
HEADERS = $(wildcard ./*.h) $(wildcard ../PolygonFormulaFolder/*.h)

all: build test

build: $(SRCS) $(HEADERS)
	$(CC) -g -o $(TARGET) $^

test:
	./$(TARGET)

clean:
	rm -rf $(TARGET)

