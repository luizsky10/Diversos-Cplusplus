all: MDC.o Fracao.o main.o
	g++ Fracao.o MDC.o main.o -o Fracao.exe

Fracao.o: Fracao.h Fracao.cpp
	g++ -c Fracao.cpp

MDC.o: MDC.h MDC.cpp
	g++ -c MDC.cpp

main.o: Fracao.h MDC.h main.cpp
	g++ -c main.cpp

clean:
	rm *.o
	rm *.exe
