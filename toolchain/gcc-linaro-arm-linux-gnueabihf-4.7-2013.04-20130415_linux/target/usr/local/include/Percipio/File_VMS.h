//
// File_VMS.h
//
// $Id: //percipio/1.4/Foundation/include/Percipio/File_VMS.h#1 $
//
// Library: Foundation
// Package: Filesystem
// Module:  File
//
// Definition of the FileImpl class for OpenVMS.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Foundation_File_VMS_INCLUDED
#define Foundation_File_VMS_INCLUDED


#include "Percipio/Foundation.h"


namespace Percipio {


class FileImpl
{
protected:
	typedef UInt64 FileSizeImpl;

	FileImpl();
	FileImpl(const std::string& path);
	virtual ~FileImpl();
	void setPath(const std::string& path);
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
	static void handleLastError(const std::string& path);
	
private:
	std::string _path;
};


//
// inlines
//
inline const std::string& FileImpl::getPathImpl() const
{
	return _path;
}


} // namespace Percipio


#endif // Foundation_File_VMS_INCLUDED
