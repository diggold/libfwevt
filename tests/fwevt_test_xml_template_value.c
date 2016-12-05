/*
 * Library xml_template_value type testing program
 *
 * Copyright (C) 2011-2016, Joachim Metz <joachim.metz@gmail.com>
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

#include <common.h>
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "fwevt_test_libcerror.h"
#include "fwevt_test_libfwevt.h"
#include "fwevt_test_macros.h"
#include "fwevt_test_memory.h"
#include "fwevt_test_unused.h"

#include "../libfwevt/libfwevt_xml_template_value.h"

#if defined( __GNUC__ )

/* Tests the libfwevt_xml_template_value_initialize function
 * Returns 1 if successful or 0 if not
 */
int fwevt_test_xml_template_value_initialize(
     void )
{
	libcerror_error_t *error                          = NULL;
	libfwevt_xml_template_value_t *xml_template_value = NULL;
	int result                                        = 0;

#if defined( HAVE_FWEVT_TEST_MEMORY )
	int number_of_malloc_fail_tests                   = 1;
	int number_of_memset_fail_tests                   = 1;
	int test_number                                   = 0;
#endif

	/* Test regular cases
	 */
	result = libfwevt_xml_template_value_initialize(
	          &xml_template_value,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWEVT_TEST_ASSERT_IS_NOT_NULL(
         "xml_template_value",
         xml_template_value );

        FWEVT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfwevt_xml_template_value_free(
	          &xml_template_value,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWEVT_TEST_ASSERT_IS_NULL(
         "xml_template_value",
         xml_template_value );

        FWEVT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfwevt_xml_template_value_initialize(
	          NULL,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWEVT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	xml_template_value = (libfwevt_xml_template_value_t *) 0x12345678UL;

	result = libfwevt_xml_template_value_initialize(
	          &xml_template_value,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWEVT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	xml_template_value = NULL;

#if defined( HAVE_FWEVT_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libfwevt_xml_template_value_initialize with malloc failing
		 */
		fwevt_test_malloc_attempts_before_fail = test_number;

		result = libfwevt_xml_template_value_initialize(
		          &xml_template_value,
		          &error );

		if( fwevt_test_malloc_attempts_before_fail != -1 )
		{
			fwevt_test_malloc_attempts_before_fail = -1;

			if( xml_template_value != NULL )
			{
				libfwevt_xml_template_value_free(
				 &xml_template_value,
				 NULL );
			}
		}
		else
		{
			FWEVT_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			FWEVT_TEST_ASSERT_IS_NULL(
			 "xml_template_value",
			 xml_template_value );

			FWEVT_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
	for( test_number = 0;
	     test_number < number_of_memset_fail_tests;
	     test_number++ )
	{
		/* Test libfwevt_xml_template_value_initialize with memset failing
		 */
		fwevt_test_memset_attempts_before_fail = test_number;

		result = libfwevt_xml_template_value_initialize(
		          &xml_template_value,
		          &error );

		if( fwevt_test_memset_attempts_before_fail != -1 )
		{
			fwevt_test_memset_attempts_before_fail = -1;

			if( xml_template_value != NULL )
			{
				libfwevt_xml_template_value_free(
				 &xml_template_value,
				 NULL );
			}
		}
		else
		{
			FWEVT_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			FWEVT_TEST_ASSERT_IS_NULL(
			 "xml_template_value",
			 xml_template_value );

			FWEVT_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
#endif /* defined( HAVE_FWEVT_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( xml_template_value != NULL )
	{
		libfwevt_xml_template_value_free(
		 &xml_template_value,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwevt_xml_template_value_free function
 * Returns 1 if successful or 0 if not
 */
int fwevt_test_xml_template_value_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfwevt_xml_template_value_free(
	          NULL,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWEVT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfwevt_xml_template_value_get_type function
 * Returns 1 if successful or 0 if not
 */
int fwevt_test_xml_template_value_get_type(
     void )
{
	libcerror_error_t *error                          = NULL;
	libfwevt_xml_template_value_t *xml_template_value = NULL;
	uint8_t type                                      = 0;
	int result                                        = 0;
	int type_is_set                                   = 0;

	/* Initialize test
	 */
	result = libfwevt_xml_template_value_initialize(
	          &xml_template_value,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "xml_template_value",
	 xml_template_value );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfwevt_xml_template_value_get_type(
	          xml_template_value,
	          &type,
	          &error );

	FWEVT_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	type_is_set = result;

	/* Test error cases
	 */
	result = libfwevt_xml_template_value_get_type(
	          NULL,
	          &type,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	if( type_is_set != 0 )
	{
		result = libfwevt_xml_template_value_get_type(
		          xml_template_value,
		          NULL,
		          &error );

		FWEVT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FWEVT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Clean up
	 */
	result = libfwevt_xml_template_value_free(
	          &xml_template_value,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "xml_template_value",
	 xml_template_value );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( xml_template_value != NULL )
	{
		libfwevt_xml_template_value_free(
		 &xml_template_value,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwevt_xml_template_value_get_offset function
 * Returns 1 if successful or 0 if not
 */
int fwevt_test_xml_template_value_get_offset(
     void )
{
	libcerror_error_t *error                          = NULL;
	libfwevt_xml_template_value_t *xml_template_value = NULL;
	size_t offset                                     = 0;
	int offset_is_set                                 = 0;
	int result                                        = 0;

	/* Initialize test
	 */
	result = libfwevt_xml_template_value_initialize(
	          &xml_template_value,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "xml_template_value",
	 xml_template_value );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfwevt_xml_template_value_get_offset(
	          xml_template_value,
	          &offset,
	          &error );

	FWEVT_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	offset_is_set = result;

	/* Test error cases
	 */
	result = libfwevt_xml_template_value_get_offset(
	          NULL,
	          &offset,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	if( offset_is_set != 0 )
	{
		result = libfwevt_xml_template_value_get_offset(
		          xml_template_value,
		          NULL,
		          &error );

		FWEVT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FWEVT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Clean up
	 */
	result = libfwevt_xml_template_value_free(
	          &xml_template_value,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "xml_template_value",
	 xml_template_value );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( xml_template_value != NULL )
	{
		libfwevt_xml_template_value_free(
		 &xml_template_value,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwevt_xml_template_value_get_size function
 * Returns 1 if successful or 0 if not
 */
int fwevt_test_xml_template_value_get_size(
     void )
{
	libcerror_error_t *error                          = NULL;
	libfwevt_xml_template_value_t *xml_template_value = NULL;
	uint16_t size                                     = 0;
	int result                                        = 0;
	int size_is_set                                   = 0;

	/* Initialize test
	 */
	result = libfwevt_xml_template_value_initialize(
	          &xml_template_value,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "xml_template_value",
	 xml_template_value );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfwevt_xml_template_value_get_size(
	          xml_template_value,
	          &size,
	          &error );

	FWEVT_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	size_is_set = result;

	/* Test error cases
	 */
	result = libfwevt_xml_template_value_get_size(
	          NULL,
	          &size,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	if( size_is_set != 0 )
	{
		result = libfwevt_xml_template_value_get_size(
		          xml_template_value,
		          NULL,
		          &error );

		FWEVT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FWEVT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Clean up
	 */
	result = libfwevt_xml_template_value_free(
	          &xml_template_value,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "xml_template_value",
	 xml_template_value );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( xml_template_value != NULL )
	{
		libfwevt_xml_template_value_free(
		 &xml_template_value,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwevt_xml_template_value_get_flags function
 * Returns 1 if successful or 0 if not
 */
int fwevt_test_xml_template_value_get_flags(
     void )
{
	libcerror_error_t *error                          = NULL;
	libfwevt_xml_template_value_t *xml_template_value = NULL;
	uint8_t flags                                     = 0;
	int flags_is_set                                  = 0;
	int result                                        = 0;

	/* Initialize test
	 */
	result = libfwevt_xml_template_value_initialize(
	          &xml_template_value,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "xml_template_value",
	 xml_template_value );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfwevt_xml_template_value_get_flags(
	          xml_template_value,
	          &flags,
	          &error );

	FWEVT_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	flags_is_set = result;

	/* Test error cases
	 */
	result = libfwevt_xml_template_value_get_flags(
	          NULL,
	          &flags,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	if( flags_is_set != 0 )
	{
		result = libfwevt_xml_template_value_get_flags(
		          xml_template_value,
		          NULL,
		          &error );

		FWEVT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FWEVT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Clean up
	 */
	result = libfwevt_xml_template_value_free(
	          &xml_template_value,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "xml_template_value",
	 xml_template_value );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( xml_template_value != NULL )
	{
		libfwevt_xml_template_value_free(
		 &xml_template_value,
		 NULL );
	}
	return( 0 );
}

#endif /* defined( __GNUC__ ) */

/* The main program
 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc FWEVT_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] FWEVT_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc FWEVT_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] FWEVT_TEST_ATTRIBUTE_UNUSED )
#endif
{
	FWEVT_TEST_UNREFERENCED_PARAMETER( argc )
	FWEVT_TEST_UNREFERENCED_PARAMETER( argv )

#if defined( __GNUC__ )

	FWEVT_TEST_RUN(
	 "libfwevt_xml_template_value_initialize",
	 fwevt_test_xml_template_value_initialize );

	FWEVT_TEST_RUN(
	 "libfwevt_xml_template_value_free",
	 fwevt_test_xml_template_value_free );

	FWEVT_TEST_RUN(
	 "libfwevt_xml_template_value_get_type",
	 fwevt_test_xml_template_value_get_type );

	/* TODO: add tests for libfwevt_xml_template_value_set_type */

	FWEVT_TEST_RUN(
	 "libfwevt_xml_template_value_get_offset",
	 fwevt_test_xml_template_value_get_offset );

	/* TODO: add tests for libfwevt_xml_template_value_set_offset */

	FWEVT_TEST_RUN(
	 "libfwevt_xml_template_value_get_size",
	 fwevt_test_xml_template_value_get_size );

	/* TODO: add tests for libfwevt_xml_template_value_set_size */

	FWEVT_TEST_RUN(
	 "libfwevt_xml_template_value_get_flags",
	 fwevt_test_xml_template_value_get_flags );

	/* TODO: add tests for libfwevt_xml_template_value_set_flags */

#endif /* defined( __GNUC__ ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}
