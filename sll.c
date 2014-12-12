/* sll.c - simple linked list
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

#include <stdlib.h>
#include "sll.h"

struct sll {
    struct sll *next;
    void *value[];
};

void *
_sll_push(void *next, size_t size)
{
    struct sll *sll = malloc(sizeof(struct sll) + size);
    if (!sll)
        return NULL;
    sll->next = next;
    return &sll->value;
}

void *
sll_peek(void *_sll)
{
    struct sll *sll;
    if (!_sll)
        return NULL;
    sll = _sll;
    sll--;
    return sll->next;
    //return ((struct sll *)sll)[-1].next;
}

void *
sll_pop(void *_sll)
{
    struct sll *sll, *next;
    if (!_sll)
        return NULL;
    sll = _sll;
    sll--;
    next = sll->next;
    free(sll);
    return next;
}

void
sll_free(void *_sll)
{
    struct sll *sll, *next;
    for (sll = _sll; sll; sll = next) {
        sll--;
        next = sll->next;
        free(sll);
    }
}
