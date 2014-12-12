/* ll.c - simple linked list
 *
 * Copyright (C) 2014 Charles Lehner
 * This file is part of ll.
 *
 * ll is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * ll is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include "ll.h"

struct ll {
    struct ll *next;
    void *value[];
};

void *
_ll_push(void *next, size_t size)
{
    struct ll *ll = malloc(sizeof(struct ll) + size);
    if (!ll)
        return NULL;
    ll->next = next;
    return &ll->value;
}

void *
ll_peek(void *ll)
{
    return ll ? ((struct ll *)ll)[-1].next : NULL;
}

void *
ll_pop(void *_ll)
{
    struct ll *ll, *next;
    if (!_ll)
        return NULL;
    ll = _ll;
    ll--;
    next = ll->next;
    free(ll);
    return next;
}

void
ll_free(void *_ll)
{
    struct ll *ll, *next;
    for (ll = _ll; ll; ll = next) {
        ll--;
        next = ll->next;
        free(ll);
    }
}

void *
ll_reduce(void *_ll, void (fn)(void *target, void *other))
{
    struct ll *ll, *next, *value = _ll;
    if (!value)
        return NULL;
    value--;
    next = value->next;
    if (!next)
        return &value->value;
    for (ll = next; ll; ll = next) {
        ll--;
        next = ll->next;
        fn(value->value, &ll->value);
        if (next)
            free(ll);
    }
    return &value->value;
}
