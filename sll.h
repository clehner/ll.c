/* sll.h - simple linked list
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

#ifndef __SLL_H
#define __SLL_H

#include <stddef.h>

#define sll_push(sll) \
    _sll_push(sll, sizeof(*sll))

void *_sll_push(void *sll, size_t size);
void *sll_pop(void *sll);
void *sll_peek(void *sll);
void sll_free(void *sll);

#endif /* __SLL_H */
