# - комментарий
# цель: реквизиты
	# команда 1
	# команда 2...
CC=gcc
CFLAGS=-c -wall

all: hellomake

hellomake: main.o apresentation.o menu.o student.o utilitarian.o
	$(CC) main.o apresentation.o menu.o student.o utilitarian.o -o mainTest

main.o: main.c
	$(CC) -c main.c

apresentation.o: apresentation.c
	$(CC) -c apresentation.c

menu.o: menu.c
	$(CC) -c menu.c

student.o: student.c
	$(CC) -c student.c

utilitarian.o: utilitarian.c
	$(CC) -c utilitarian.c

clean:
	rm -rf *.o test

install:
	install ./test /usr/bin/

uninstall:
	rm -rf /usr/bin/test
