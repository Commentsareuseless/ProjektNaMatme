objs = Graph.o main.o Node.o


AstPathFinder: ${objs}
	g++  ${objs} -o TestMatmy.out

main.o:
	g++ main.cpp -c

Graph.o: Graph.hpp
	g++ Graph.cpp -c

Node.o: Node.hpp
	g++ Node.cpp -c


.PHONY : clean
clean:
	rm ${objs}