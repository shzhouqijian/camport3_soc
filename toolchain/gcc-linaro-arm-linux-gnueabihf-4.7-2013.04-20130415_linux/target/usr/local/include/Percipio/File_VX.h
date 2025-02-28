//
// File_VX.h
//
// $Id: //percipio/1.4/Foundation/include/Percipio/File_VX.h#1 $
//
// Library: Foundation
// Package: Filesystem
// Module:  File
//
// Definition of the FileImpl class for VxWorks.
//
// Copyright (c) 2004-2011, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Foundation_File_VX_INCLUDED
#define Foundation_File_VX_INCLUDED


#include "Percipio/Foundation.h"


namespace Percipio {


class FileImpl
{
protected:
	typedef UInt64 FileSizeImpl;

	FileImpl();
	FileImpl(const std::string& path);
	virtual ~FileImpl();
	void swapImpl(FileImpl& file);
	void setPathImpl(const std::string& path);
	const std::string& getPathImpl() const;
	bool existsImpl() const;
	bool canReadImpl() const;
	bool canWriteImpl() const;
	bool canExecuteImpl() const;
	bool isFileImpl() const;
	bool isDirectoryImpl() const;
	bool isLinkImpl() const;
	bool isDeviceImpl() const;
	bool isHiddenImpl() const;
	Timestamp createdImpl() const;
	Timestamp getLastModifiedImpl() const;
	void setLastModifiedImpl(const Timestamp& ts);
	FileSizeImpl getSizeImpl() const;
	void setSizeImpl(FileSizeImpl size);
	void setWriteableImpl(bool flag = true);		
	void setExecutableImpl(bool flag = true);		
	void copyToImpl(const std::string& path) const;
	void renameToImpl(const std::string& path);
	void removeImpl();
	bool createFileImpl();
	bool createDirectoryImpl();
	static void handleLastErrorImpl(const std::string& path);
	
private:
	std::string _path;
	
	friend class DirectoryIteratorImpl;
};


//
// inlines
//
inline const std::string& FileImpl::getPathImpl() const
{
	return _path;
}


} // namespace Percipio


#endif // Foundation_File_VX_INCLUDED
