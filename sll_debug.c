/* sll_debug.c - debug version of sll
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

#include "mock_malloc.h"

/* Wrap the memory managing functions so we can see when they get called */
#define free my_free
#define malloc my_malloc

#include "sll.c"
