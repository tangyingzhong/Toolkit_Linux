///************************************************************************
/// <copyrigth>2018-2019 Corporation.All Rights Reserved</copyrigth>
/// <author>tangyingzhong</author>
/// <contact>tangyz114987@outlook.com</contact>
/// <version>v1.0.0</version>
/// <describe>
/// Basic type of the system on windows
///</describe>
/// <date>2019/7/16</date>
///***********************************************************************
#ifndef SYSTEMTYPE_H
#define SYSTEMTYPE_H

// Close the warning of c4312 which is a smaller size changed to be a bigger one
#pragma warning(disable:4312)

// Close the c4996 warning which is tip you that you should use a safe function not an old one
#pragma warning(disable:4996)

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sstream>
#include <string>

namespace System
{
	// True or False
	typedef bool Boolean;			

	// Nothing
	typedef void None;

	// Universal pointer : any type pointer or NULL (4 bytes in memory)
	typedef None* Object;

	// One byte: 0-255
	typedef unsigned char Byte;		

	// Byte pointer : 4 bytes in memory	
	typedef unsigned char* ByteArray;

	// Signed byte with the range from -127-128
	typedef char SByte;					

	// Signed byte array which is 4 bytes in memory
	typedef SByte* SByteArray;			

	// Wide byte that can contain the unicode string
	typedef wchar_t WByte;				

	// Wide byte array which is 4 bytes in memory
	typedef WByte* WByteArray;															

	// Short integer : -2 ^ 16 / 2 - 2 ^ 16 / 2 - 1
	typedef short Int16;							

	// Short integer : 0 - 2 ^ 16 - 1
	typedef unsigned short UInt16;		

	// Integer : -2 ^ 32 / 2 - 2 ^ 32 / 2 - 1
	typedef int Int32;					

	// Integer : 0 - 2 ^ 32 - 1
	typedef unsigned int UInt32;					

	// Long integer :  -2 ^ 32 / 2 - 2 ^ 32 / 2 - 1
	typedef long FixedInt32;

	// Long integer :0 - 2 ^ 32 - 1
	typedef unsigned long FixedUInt32;

	// Long integer : -2 ^ 64 / 2 - 2 ^ 64 / 2 - 1
	typedef long long Int64;						

	// Long integer : 0 - 2 ^ 64 - 1
	typedef unsigned long long UInt64;	

	// Single real: 4 bytes in memory
	typedef float Single;				

	// Double real: 8 bytes in memory
	typedef double Real;	

	// The way to open the file
	enum FILE_MODE_ENUM
	{
		// File exist and open it or create it and write at the end
		APPEND = O_APPEND,						

		// Create a file whatever it is existed or not."w" "w+"
		CREATE = O_CREAT,

		// File must be not exist and it can create file or error happends 
		CREATENEW = CREATE | O_EXCL ,

		// File must be exist or error happends . "r"  "r+"
		OPEN = 8,					

		// File exist and open it or create it.
		OPENORCREATE = OPEN | CREATE,										

		// Make current file's length to be 0
		TRUNC = O_TRUNC,											
	};

	// The way to operate the file
	enum FILE_ACCESS_ENUM
	{
		// Read allowed only
		READ = O_RDONLY,			

		// Write allowed only
		WRITE = O_WRONLY,								

		// Read and Write allowed
		READWRITE = O_RDWR					
	};

	// Operate the file's data in which position
	enum SEEK_ORIGIN_ENUM
	{
		// Seek from the beginning 
		BEGIN = SEEK_SET,			

		// Seek from the current position
		CURRENT = SEEK_CUR,		

		// Seek from the end position
		END = SEEK_END																		
	};

	// File's type enum
	enum FILE_TYPE_ENUM
	{
		// Common file
		NORMAL = S_IFREG,

		// Directory
		DIRECTORY = S_IFDIR,

		// Block device file
		BLOCK_DEV_FILE = S_IFBLK,

		// Char device file
		CHAR_DEV_FILE = S_IFCHR,

		// Symbolic link file
		LINK_FILE = S_IFLNK,

		// Pipe file
		PIPE_FILE = S_IFIFO,

		// Socket file
		SOCKET_FILE = S_IFSOCK
	};
}

#endif // SYSTEMTYPE_H