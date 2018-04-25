# Justin Choi (jc8mc) 
# CS 2150 - 106 
# April 18th 2017 

CXX=clang++
CXXFLAGS=-Wall -g  
ENCODE=heap.o huffmanNode.o huffmanenc.o huffTree.o
DECODE=huffmanNode.o huffmandec.o
.SUFFIXES: .o .cpp

main: $(ENCODE) $(DECODE)
	$(CXX) $(CXXFLAGS) -o encoder $(ENCODE)
	$(CXX) $(CXXFLAGS) -o decoder $(DECODE)

clean: 
	-rm -f *.o encoder 
	-rm -f *.o decoder