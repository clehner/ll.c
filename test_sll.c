/* test_sll.c - test driver for sll
 *
 * Copyright (C) 2014 Charles Lehner
 * This file is part of sll.
 *
 * sll is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * sll is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "sll.h"
#include "mock_malloc.h"

#include <stddef.h>
#include <assert.h>

/* some strings to use */
static char
    *str1 = "apple",
    *str2 = "pie",
    *str3 = "sauce";

void test_strings()
{
    char **strs = NULL;
    char **strs_read;

    malloc_calls = 0;
    free_calls = 0;

    /* appending strings to list */
    strs = sll_push(strs);
    assert(strs);
    *strs = str1;
    strs = sll_push(strs);
    assert(strs);
    *strs = str2;
    strs = sll_push(strs);
    assert(strs);
    *strs = str3;

    assert(malloc_calls == 3);

    /* peeking at strings in list */
    strs_read = strs;
    strs_read = sll_peek(strs_read);
    assert(strs_read && *strs_read == str2);
    strs_read = sll_peek(strs_read);
    assert(strs_read && *strs_read == str1);
    strs_read = sll_peek(strs_read);
    assert(strs_read == NULL);

    assert(free_calls == 0);

    /* popping strings off list */
    strs = sll_pop(strs);
    assert(strs && *strs == str2);
    strs = sll_pop(strs);
    assert(strs && *strs == str1);
    strs = sll_pop(strs);
    assert(strs == NULL);

    assert(free_calls == 3);
}

void test_ints()
{
    int *ints = NULL;

    /* appending ints to list */
    ints = sll_push(ints);
    assert(ints);
    *ints = 100;
    ints = sll_push(ints);
    assert(ints);
    *ints = 200;
    ints = sll_push(ints);
    assert(ints);
    *ints = 300;

    /* popping ints off list */
    ints = sll_pop(ints);
    assert(ints && *ints == 200);
    ints = sll_pop(ints);
    assert(ints && *ints == 100);
    ints = sll_pop(ints);
    assert(!ints);
}

void test_structs()
{
    struct {
        int bar;
        char *str;
    } *foo = NULL;

    /* append items */
    foo = sll_push(foo);
    assert(foo);
    foo->bar = 11;
    foo->str = str1;

    foo = sll_push(foo);
    assert(foo);
    foo->bar = 7;
    foo->str = str2;

    foo = sll_push(foo);
    assert(foo);
    foo->bar = 5;
    foo->str = str3;

    /* pop items */
    foo = sll_pop(foo);
    assert(foo && foo->bar == 7 && foo->str == str2);
    foo = sll_pop(foo);
    assert(foo && foo->bar == 11 && foo->str == str1);
    foo = sll_pop(foo);
    assert(!foo);
}

void test_iteration()
{
    int i, *num, *nums = NULL;

    /* put numbers in list */
    for (i = 0; i < 20; i += 2) {
        nums = sll_push(nums);
        assert(nums);
        *nums = i;
    }

    /* read back the numbers */
    for (num = nums; num; num = sll_pop(num)) {
        i -= 2;
        assert(*num == i);
    }
}

void test_free()
{
    int i, *nums = NULL;
    free_calls = 0;

    /* make a list */
    for (i = 0; i < 10; i++) {
        *(nums = sll_push(nums)) = i;
    }

    /* free the list */
    sll_free(nums);
    assert(free_calls == 10);
}

int main()
{
    test_strings();
    test_ints();
    test_structs();
    test_iteration();
    test_free();
    return 0;
}

