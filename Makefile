# Makefile for ll
# Copyright (C) 2014 Charles Lehner
#
# Copying and distribution of this file, with or without modification,
# are permitted in any medium without royalty provided the copyright
# notice and this notice are preserved.  This file is offered as-is,
# without any warranty.

CFLAGS = -Wall -Wextra -Werror -std=gnu99

all: ll.o test

test: test_ll
	@./$< && echo Tests passed

test_ll: ll_debug.o mock_malloc.c

ll_debug.o: ll.c

clean:
	rm -f test_ll *.o
