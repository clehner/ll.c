# ll.c

ll.c is an implementation of a singly-linked list (stack) in C, featuring
a simple API, ease-of-use, and type-safety.

The API and implementation is inspired by that of
[sds](https://github.com/antirez/sds). In particular, operations return
the new value, in the style of functional programming; and the list pointers
are "hidden" by being stored before the actual data for each list item.

## Example

```c
#include <stdio.h>
#include "ll.h"

struct thing {
    char *word;
};

int main()
{
    struct thing *thing = NULL; /* list */

    thing = ll_new(thing);
    thing->word = "world";

    thing = ll_new(thing);
    thing->word = "hello";

    char *hello = thing->word;
    thing = ll_pop(thing);
    char *world = thing->word;
    printf("%s %s\n", hello, world);

    return 0;
}
```

## Creating a list

Create a list by declaring a pointer to the list item type. Any type can be
used - ints, pointers, structs, etc. Usually you will want to initialize the
list to NULL, so that you can tell where the end of the list is.

```c
int *numbers = NULL;
char **strings = NULL;
struct {
	char *foo;
} *anon = NULL;
```

## Adding to a list

```c
item *ll_new(item *ll); /* where item is the type of your list */
```

Call `ll_new` with the current list and you will get a new list with a
reference to the previous list.

`ll_new` uses a macro to figure out the size of the type you are passing to
it, so it will allocate a new item of the same size.

```c
int *numbers = NULL;
numbers = ll_new(numbers);
*numbers = 100;
numbers = ll_new(numbers);
*numbers = 200;

anon = ll_new(anon);
anon->foo = "one";
anon = ll_new(anon);
anon->foo = "two";
anon = ll_new(anon);
anon->foo = "three";
```

## Getting items from a list

```c
item *ll_pop(item *ll);
item *ll_next(item *ll);
```

`ll_pop` and `ll_next` will return the list starting from the next item
(like cdr in lisp). `ll_pop` will also free the current list pointer before
returning.

```c
int *num = ll_next(numbers);
/* *num == 100 */
num = ll_next(num);
/* num == NULL */

anon = ll_pop(anon);
/* anon->foo == "two" */
anon = ll_pop(anon);
/* anon->foo == "one" */
anon = ll_pop(anon);
/* anon == NULL */
```

## Iterating through a list

```c
ll_foreach(list, item)
```

You can use the convenience macro `ll_foreach` to iterate through item of a
list.

Since this is a singly-linked list, items will be iterated
through in the reverse order from how they were added.

```c
int *nums = NULL;
int sum = 0;
*(nums = ll_new(nums)) = 5;
*(nums = ll_new(nums)) = 10;

ll_foreach(nums, num) {
	sum += *num;
}
/* sum == 15 */
```

You could also iterate using a plain for loop. Use `ll_pop` to free the list
pointers as you go, or `ll_next` to keep the list intact.

```c
int *num;
for (num = numbers; num; num = ll_next(num)) {
	printf("%d\n", *num); /* prints 200, then 100 */
}
```

## Destroying a list

```c
void ll_free(void *ll);
```
Use the `ll_free` function to release all the list pointers in a list. This is
equivalent to popping each list item and discarding them.

## Testing

    $ make test

See the test file `test_ll.c` to find more examples of using ll.

## License

Copyright © 2014 Charles Lehner

ll is free software: you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the
Free Software Foundation, either version 3 of the License, or (at your
option) any later version.

ll is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

For more details see the files LICENSE and LICENSE.LESSER.
