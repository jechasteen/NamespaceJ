# This is a horrible Makefile, everything code by hand
# I don't know what I'm doing and was having a terrible time
# trying to get it to work otherwise.

PROGRAMS =			\
	test.assert		\
	test.logstream	\

CXX = g++

CXX_FLAGS = -std=c++17 -Wall -Wextra -I../ -DDEBUG

all:
	$(CXX) $(CXX_FLAGS) -o test.assert test.assert.cpp
	$(CXX) $(CXX_FLAGS) -o test.logstream test.logstream.cpp

runtests:
	./test.assert
	./test.logstream

clean:
	rm -f $(PROGRAMS)