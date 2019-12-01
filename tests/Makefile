# This is a horrible Makefile, everything code by hand
# I don't know what I'm doing and was having a terrible time
# trying to get it to work otherwise.

PROGRAMS =			\
	test.assert		\
	test.logstream	\
	test.linkedlist \

CXX = g++

CXX_FLAGS = -std=c++17 -Wall -Wextra -I../ -DDEBUG

all:
	$(CXX) $(CXX_FLAGS) -o test.assert test.assert.cpp
	$(CXX) $(CXX_FLAGS) -o test.logstream test.logstream.cpp
	$(CXX) $(CXX_FLAGS) -o test.linkedlist test.linkedlist.cpp

runtests:
	./test.assert
	./test.logstream
	./test.linkedlist

clean:
	rm -f $(PROGRAMS)