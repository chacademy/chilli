CC = g++

PROGRAM = zws.exe
MAIN = zws.cpp 
OBJS = ZWebServer.o zthread.o

$(PROGRAM) : $(OBJS)
	$(CC) -g -o $(PROGRAM) $(MAIN) $(OBJS) -lpthread
	
ZWebServer.o : ZWebServer.cpp
	$(CC) -c ZWebServer.cpp

zthread.o : zthread.cpp
	$(CC) -c zthread.cpp	

clean : 
	rm -f $(OBJS) $(PROGRAM)
