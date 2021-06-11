CC = g++
CFLAGS=-std=c++11 -MMD -MP -Wall

# This is used in class
# PROGRAMS=programm
# OBJECTS=city.o street.o city_set.o

# This is more generalized solution
PROGRAMS=programm
SRC_FILES:=$(subst $(PROGRAMS:%=%.cc),, $(wildcard *.cc))
OBJECTS = $(patsubst %.cc,%.o,$(SRC_FILES))

ALLOBJECTS=$(OBJECTS) $(patsubst %,%.o,$(PROGRAMS))

default: $(PROGRAMS)

%.o: %.cc
	$(CC) $(CFLAGS) -c $<

programm: programm.o $(OBJECTS)
	$(CC) $(LFLAGS) -o $@ $^

clean:
	-rm -f $(ALLOBJECTS) $(ALLOBJECTS:%.o=%.d) $(PROGRAMS)

-include $(ALLOBJECTS:%.o=%.d)
