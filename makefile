all: stat.o
	gcc -o stat stat.o

devran.o: stat.c
	gcc -c stat.c

clean:
	rm -f *.o *~ stat
run: all
	./stat
