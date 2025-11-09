CXX = g++
CXXFLAGS = -Wall -O2

OBJS = main.o proc_reader.o
TARGET = sysmon

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp proc_reader.h
	$(CXX) $(CXXFLAGS) -c main.cpp

proc_reader.o: proc_reader.cpp proc_reader.h
	$(CXX) $(CXXFLAGS) -c proc_reader.cpp

clean:
	rm -f $(OBJS) $(TARGET)

