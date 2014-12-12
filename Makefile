CFLAGS = -Wall -Wextra -Werror

all: sll.o test

test: test_sll
	./$<

test_sll: sll_debug.o mock_malloc.o

clean:
	rm -f test_sll *.o
