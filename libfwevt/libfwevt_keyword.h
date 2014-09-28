/*
 * Keyword functions
 *
 * Copyright (c) 2011-2014, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#if !defined( _LIBFWEVT_INTERNAL_KEYWORD_H )
#define _LIBFWEVT_INTERNAL_KEYWORD_H

#include <common.h>
#include <types.h>

#include "libfwevt_extern.h"
#include "libfwevt_libcerror.h"
#include "libfwevt_types.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct libfwevt_internal_keyword libfwevt_internal_keyword_t;

struct libfwevt_internal_keyword
{
	/* The identifier
	 */
	uint16_t identifier;
};

LIBFWEVT_EXTERN \
int libfwevt_keyword_initialize(
     libfwevt_keyword_t **keyword,
     libcerror_error_t **error );

LIBFWEVT_EXTERN \
int libfwevt_keyword_free(
     libfwevt_keyword_t **keyword,
     libcerror_error_t **error );

LIBFWEVT_EXTERN \
int libfwevt_keyword_read(
     libfwevt_keyword_t *keyword,
     const uint8_t *data,
     size_t data_size,
     size_t data_offset,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif

