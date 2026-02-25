SOURCE = $(wildcard */*.c)
HEADERS = $(wildcard */*.h)

BANDERAS = -std=c99 -pedantic -Wall -Werror #-g
leak := 
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	leak += valgrind
endif
ifeq ($(UNAME_S),Darwin)
	leak += leaks --atExit --
endif

all:$(HEADERS)
	gcc $(BANDERAS) $(SOURCE) main.c sorts.c -o main
fuga: all
	$(leak) ./main