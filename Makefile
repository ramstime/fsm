

CC=gcc
CXX=g++
RM=rm -f
#CPPFLAGS=-g $(shell root-config --cflags)
CPPFLAGS= -g -std=c++11
#LDFLAGS=-g $(shell root-config --ldflags)
LDFLAGS=
#LDLIBS=$(shell root-config --libs)
LDLIBS=

SRCS=Motor.cc StateMachine.cc
OBJS=$(subst .cc,.o,$(SRCS))

all:fsmEngine

fsmEngine: $(OBJS)
	$(CXX) $(LDFLAGS) -o fsmEngine $(OBJS) $(LDLIBS)

depend: .depend

.depend: $(SRCS)
	$(RM) ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) *~ .depend

include .depend
