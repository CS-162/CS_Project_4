CC := g++ -std=c++11
EXE := proj4_app

SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp, %.o, $(SRCS))

$(EXE): $(OBJS)
	$(CC) $(OBJS) -o $(EXE)

%.o: %.cpp
	$(CC) -c $<

clean:
	rm -f *.out *.o $(EXE)