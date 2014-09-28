/*
 * Features of libfwevt
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

#if !defined( _LIBFWEVT_FEATURES_H )
#define _LIBFWEVT_FEATURES_H

/* The libfwevt type support features
 */
#if 0 || defined( HAVE_WIDE_CHARACTER_TYPE )
#define LIBFWEVT_HAVE_WIDE_CHARACTER_TYPE		1
#endif

#if !defined( LIBFWEVT_DEPRECATED )
#if defined( __GNUC__ ) && __GNUC__ >= 3
#define LIBFWEVT_DEPRECATED	__attribute__ ((__deprecated__))
#elif defined( _MSC_VER )
#define LIBFWEVT_DEPRECATED	__declspec(deprecated)
#else
#define LIBFWEVT_DEPRECATED
#endif
#endif

#endif

