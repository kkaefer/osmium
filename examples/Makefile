#------------------------------------------------------------------------------
#
#  Makefile for Osmium examples.
#
#------------------------------------------------------------------------------

CXX = g++

CXXFLAGS = -g
#CXXFLAGS = -O3

CXXFLAGS += -std=c++0x -Wall -Wextra -Wredundant-decls -Wdisabled-optimization -pedantic
#CXXFLAGS += -Wpadded -Winline

# uncomment this if you want information on how long it took to build the multipolygons
#CXXFLAGS += -DOSMIUM_WITH_MULTIPOLYGON_PROFILING

CXXFLAGS += -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64

CXXFLAGS += -I../include

LDFLAGS = -L/usr/local/lib -lexpat -lpthread

LIB_GD       = -lgd -lz -lm
LIB_SQLITE   = -lsqlite3
LIB_V8       = -lv8
LIB_SHAPE    = -lshp
LIB_PROTOBUF = -lz -lprotobuf-lite -losmpbf

PROGRAMS = osmium_sizeof osmium_debug osmium_stats osmium_find_bbox osmium_time nodedensity

.PHONY: all clean

all: $(PROGRAMS)

osmium_sizeof: osmium_sizeof.cpp
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS) $(LIB_PROTOBUF)

osmium_debug: osmium_debug.cpp
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS) $(LIB_PROTOBUF)

osmium_stats: osmium_stats.cpp
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS) $(LIB_PROTOBUF) $(LIB_SQLITE)

osmium_find_bbox: osmium_find_bbox.cpp
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS) $(LIB_PROTOBUF)

osmium_time: osmium_time.cpp
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS) $(LIB_PROTOBUF)

nodedensity: nodedensity.cpp handler_nodedensity.hpp
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS) $(LIB_PROTOBUF) $(LIB_GD)

install:

clean:
	rm -f *.o core $(PROGRAMS)
