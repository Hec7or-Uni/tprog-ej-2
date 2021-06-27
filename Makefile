PROG:=main
SRCS:=cuenta.cc main.cc

CXX:= g++ -std=c++17 -march=native -O3

OBJS:=$(SRCS:.cc=.o)

all: $(PROG)

$(PROG): $(OBJS)
	$(CXX) -o $@ $(OBJS)

.cc.o:
	$(CXX) -c $<

.cc.s:
	$(CXX) -c -S $<

edit:
	geany -s *.h *.cc &

clean:
	@rm -f $(PROG) $(OBJS) core *.s

cuenta.o: cuenta.cc cuenta.h
main.o: main.cc cuenta.h
