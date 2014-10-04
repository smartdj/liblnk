/*
 * The internal definitions
 *
 * Copyright (c) 2009-2014, Joachim Metz <joachim.metz@gmail.com>
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

#if !defined( _LIBLNK_INTERNAL_DEFINITIONS_H )
#define _LIBLNK_INTERNAL_DEFINITIONS_H

#include <common.h>
#include <byte_stream.h>

#define LIBLNK_ENDIAN_BIG							_BYTE_STREAM_ENDIAN_BIG
#define LIBLNK_ENDIAN_LITTLE							_BYTE_STREAM_ENDIAN_LITTLE

/* Define HAVE_LOCAL_LIBLNK for local use of liblnk
 */
#if !defined( HAVE_LOCAL_LIBLNK )
#include <liblnk/definitions.h>

/* The definitions in <liblnk/definitions.h> are copied here
 * for local use of liblnk
 */
#else
#define LIBLNK_VERSION								20141004

/* The liblnk version string
 */
#define LIBLNK_VERSION_STRING							"20141004"

/* The liblnk file access
 * bit 1        set to 1 for read access
 * bit 2        set to 1 for write access
 * bit 3-8      not used
 */
enum LIBLNK_ACCESS_FLAGS
{
	LIBLNK_ACCESS_FLAG_READ							= 0x01,
/* Reserved: not supported yet */
	LIBLNK_ACCESS_FLAG_WRITE						= 0x02
};

/* The liblnk file access macros
 */
#define LIBLNK_OPEN_READ							( LIBLNK_ACCESS_FLAG_READ )
/* Reserved: not supported yet */
#define LIBLNK_OPEN_WRITE							( LIBLNK_ACCESS_FLAG_WRITE )
/* Reserved: not supported yet */
#define LIBLNK_OPEN_READ_WRITE							( LIBLNK_ACCESS_FLAG_READ | LIBLNK_ACCESS_FLAG_WRITE )

/* The data flags
 */
enum LIBLNK_DATA_FLAGS
{
	LIBLNK_DATA_FLAG_HAS_LINK_TARGET_IDENTIFIER				= 0x00000001UL,
	LIBLNK_DATA_FLAG_HAS_LOCATION_INFORMATION				= 0x00000002UL,
	LIBLNK_DATA_FLAG_HAS_DESCRIPTION_STRING					= 0x00000004UL,
	LIBLNK_DATA_FLAG_HAS_RELATIVE_PATH_STRING				= 0x00000008UL,
	LIBLNK_DATA_FLAG_HAS_WORKING_DIRECTORY_STRING				= 0x00000010UL,
	LIBLNK_DATA_FLAG_HAS_COMMAND_LINE_ARGUMENTS_STRING			= 0x00000020UL,
	LIBLNK_DATA_FLAG_HAS_ICON_LOCATION_STRING				= 0x00000040UL,
	LIBLNK_DATA_FLAG_IS_UNICODE						= 0x00000080UL,
	LIBLNK_DATA_FLAG_FORCE_NO_LOCATION_INFORMATION				= 0x00000100UL,
	LIBLNK_DATA_FLAG_HAS_ENVIRONMENT_VARIABLES_LOCATION_BLOCK		= 0x00000200UL,
	LIBLNK_DATA_FLAG_RUN_IN_SEPARATE_PROCESS				= 0x00000400UL,

	LIBLNK_DATA_FLAG_HAS_DARWIN_IDENTIFIER					= 0x00001000UL,
	LIBLNK_DATA_FLAG_RUN_AS_USER						= 0x00002000UL,
	LIBLNK_DATA_FLAG_HAS_ICON_LOCATION_BLOCK				= 0x00004000UL,
	LIBLNK_DATA_FLAG_NO_PIDL_ALIAS						= 0x00008000UL,

	LIBLNK_DATA_FLAG_RUN_WITH_SHIM_LAYER					= 0x00020000UL,
	LIBLNK_DATA_FLAG_NO_DISTRIBUTED_LINK_TRACKING_DATA_BLOCK		= 0x00040000UL,
	LIBLNK_DATA_FLAG_HAS_METADATA_PROPERTY_STORE_DATA_BLOCK			= 0x00080000UL
};

/* The file attribute flags
 */
enum LIBLNK_FILE_ATTRIBUTE_FLAGS
{
	LIBLNK_FILE_ATTRIBUTE_FLAG_READ_ONLY					= 0x00000001UL,
	LIBLNK_FILE_ATTRIBUTE_FLAG_HIDDEN					= 0x00000002UL,
	LIBLNK_FILE_ATTRIBUTE_FLAG_SYSTEM					= 0x00000004UL,

	LIBLNK_FILE_ATTRIBUTE_FLAG_DIRECTORY					= 0x00000010UL,
	LIBLNK_FILE_ATTRIBUTE_FLAG_ARCHIVE					= 0x00000020UL,
	LIBLNK_FILE_ATTRIBUTE_FLAG_DEVICE					= 0x00000040UL,
	LIBLNK_FILE_ATTRIBUTE_FLAG_NORMAL					= 0x00000080UL,
	LIBLNK_FILE_ATTRIBUTE_FLAG_TEMPORARY					= 0x00000100UL,
	LIBLNK_FILE_ATTRIBUTE_FLAG_SPARSE_FILE					= 0x00000200UL,
	LIBLNK_FILE_ATTRIBUTE_FLAG_REPARSE_POINT				= 0x00000400UL,
	LIBLNK_FILE_ATTRIBUTE_FLAG_COMPRESSED					= 0x00000800UL,
	LIBLNK_FILE_ATTRIBUTE_FLAG_OFFLINE					= 0x00001000UL,
	LIBLNK_FILE_ATTRIBUTE_FLAG_NOT_CONTENT_INDEXED				= 0x00002000UL,
	LIBLNK_FILE_ATTRIBUTE_FLAG_ENCRYPTED					= 0x00004000UL,

	LIBLNK_FILE_ATTRIBUTE_FLAG_VIRTUAL					= 0x00010000UL
};

/* The drive type definitions
 */
enum LIBLNK_DRIVE_TYPE
{
	LIBLNK_DRIVE_TYPE_UNKNOWN						= 0,
	LIBLNK_DRIVE_TYPE_NO_ROOT_DIR						= 1,
	LIBLNK_DRIVE_TYPE_REMOVABLE						= 2,
	LIBLNK_DRIVE_TYPE_FIXED							= 3,
	LIBLNK_DRIVE_TYPE_REMOTE						= 4,
	LIBLNK_DRIVE_TYPE_CDROM							= 5,
	LIBLNK_DRIVE_TYPE_RAMDISK						= 6
};

#endif

/* The location flags
 */
enum LIBLNK_LOCATION_FLAGS
{
	LIBLNK_LOCATION_FLAG_HAS_VOLUME_INFORMATION				= 0x00000001UL,
	LIBLNK_LOCATION_FLAG_HAS_NETWORK_SHARE_INFORMATION			= 0x00000002UL
};

/* The data block signatures definitions
 */
enum LIBLNK_DATA_BLOCK_SIGNATURES
{
	LIBLNK_DATA_BLOCK_SIGNATURE_ENVIRONMENT_VARIABLES_LOCATION		= 0xa0000001UL,
	LIBLNK_DATA_BLOCK_SIGNATURE_CONSOLE_PROPERTIES				= 0xa0000002UL,
	LIBLNK_DATA_BLOCK_SIGNATURE_DISTRIBUTED_LINK_TRACKER_PROPERTIES		= 0xa0000003UL,
	LIBLNK_DATA_BLOCK_SIGNATURE_CONSOLE_CODEPAGE				= 0xa0000004UL,
	LIBLNK_DATA_BLOCK_SIGNATURE_SPECIAL_FOLDER_LOCATION			= 0xa0000005UL,
	LIBLNK_DATA_BLOCK_SIGNATURE_DARWIN_PROPERTIES				= 0xa0000006UL,
	LIBLNK_DATA_BLOCK_SIGNATURE_ICON_LOCATION				= 0xa0000007UL,
	LIBLNK_DATA_BLOCK_SIGNATURE_SHIM_LAYER_PROPERTIES			= 0xa0000008UL,
	LIBLNK_DATA_BLOCK_SIGNATURE_METADATA_PROPERTY_STORE			= 0xa0000009UL,

	LIBLNK_DATA_BLOCK_SIGNATURE_KNOWN_FOLDER_LOCATION			= 0xa000000bUL,
	LIBLNK_DATA_BLOCK_SIGNATURE_SHELL_ITEMS_IDENTIFIERS_LIST		= 0xa000000cUL
};

/* The location information string flags
 */
enum LIBLNK_LOCATION_INFORMATION_STRING_FLAGS
{
	LIBLNK_LOCATION_INFORMATION_STRING_FLAG_VOLUME_LABEL_IS_UNICODE		= 0x01,
	LIBLNK_LOCATION_INFORMATION_STRING_FLAG_LOCAL_PATH_IS_UNICODE		= 0x02,
	LIBLNK_LOCATION_INFORMATION_STRING_FLAG_NETWORK_SHARE_NAME_IS_UNICODE	= 0x04,
	LIBLNK_LOCATION_INFORMATION_STRING_FLAG_DEVICE_NAME_IS_UNICODE		= 0x08,
	LIBLNK_LOCATION_INFORMATION_STRING_FLAG_COMMON_PATH_IS_UNICODE		= 0x10
};

#endif

