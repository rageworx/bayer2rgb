CXX      = g++
CXXFLAGS = -std=c++11
LDFLAGS  = -lm

ifdef DEBUG
  CXXFLAGS += -ggdb -Wall -DDEBUG
else
  CXXFLAGS += -O3 -Wall
endif

ifdef RELEASE
  CXXFLAGS += -s
endif

ifdef MINGW_PREFIX
  LDFLAGS += -lmman
endif

TARGET = bin/bayer2rgb

all: prepare $(TARGET)

prepare:
	@mkdir -p bin
	@mkdir -p obj
	
$(TARGET): src/bayer2rgb.cpp obj/bayer.o
	$(CXX) $(CXXFLAGS) $< obj/*.o $(LDFLAGS) -o $@

obj/bayer.o: src/bayer.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(TARGET)
	@rm -rf obj/*.o
