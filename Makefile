# Makefile for sll
# Copyright (C) 2014 Charles Lehner
#
# Copying and distribution of this file, with or without modification,
# are permitted in any medium without royalty provided the copyright
# notice and this notice are preserved.  This file is offered as-is,
# without any warranty.

CFLAGS = -Wall -Wextra -Werror

all: sll.o test

test: test_sll
	./$<

test_sll: sll_debug.o mock_malloc.c

sll_debug.o: sll.c

clean:
	rm -f test_sll *.o
