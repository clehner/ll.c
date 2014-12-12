/* ll.h - simple linked list
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

#ifndef __LL_H
#define __LL_H

#include <stddef.h>

#define ll_push(ll) (typeof (ll)) _ll_push(ll, sizeof(*ll))
#define ll_pop(ll) (typeof (ll)) _ll_pop(ll)
#define ll_peek(ll) (typeof (ll)) _ll_peek(ll)
#define ll_reduce(ll, fn, val) (typeof (ll)) _ll_reduce(ll, fn, val)

#define ll_foreach(ll, item) \
    for (typeof (ll) item = ll; item; item = _ll_peek(item))

void *_ll_push(void *ll, size_t size);
void *_ll_pop(void *ll);
void *_ll_peek(void *ll);
void ll_free(void *ll);
void *_ll_reduce(void *ll, int (void *, void *), void *value);

#endif /* __LL_H */
