CC=g++
CFLAGS=-c -Wall
LDFLAGS=

SOURCES= logic/KWIC.cpp app.cpp
OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=app

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(SOURCES) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf logic/*.o *.o core
