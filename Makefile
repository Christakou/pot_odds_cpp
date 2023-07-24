# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Target executable name
TARGET = poker_solver

# Source files
SRCS = src/deque.cpp src/algos.cpp

# Object files (automatically generated from source files)
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to link object files and create the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

# Rule to clean the generated object files and executable
clean:
	rm -f $(OBJS) $(TARGET)