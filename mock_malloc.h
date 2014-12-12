/* mock_malloc.h - debug wrapper for malloc
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

#ifndef __MOCK_MALLOC_H
#define __MOCK_MALLOC_H

#include <stddef.h>

unsigned int free_calls;
unsigned int malloc_calls;

void *my_malloc(size_t);
void my_free(void *);

#endif /* __MOCK_MALLOC_H */
