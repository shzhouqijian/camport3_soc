//
// PipeImpl_WIN32.h
//
// $Id: //percipio/1.4/Foundation/include/Percipio/PipeImpl_WIN32.h#1 $
//
// Library: Foundation
// Package: Processes
// Module:  PipeImpl
//
// Definition of the PipeImpl class for WIN32.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Foundation_PipeImpl_WIN32_INCLUDED
#define Foundation_PipeImpl_WIN32_INCLUDED


#include "Percipio/Foundation.h"
#include "Percipio/RefCountedObject.h"
#include "Percipio/UnWindows.h"


namespace Percipio {


class Foundation_API PipeImpl: public RefCountedObject
	/// A dummy implementation of PipeImpl for platforms
	/// that do not support pipes.
{
public:
	typedef HANDLE Handle;

	PipeImpl();
	~PipeImpl();
	int writeBytes(const void* buffer, int length);
	int readBytes(void* buffer, int length);
	Handle readHandle() const;
	Handle writeHandle() const;
	void closeRead();
	void closeWrite();
	
private:
	HANDLE _readHandle;
	HANDLE _writeHandle;
};


} // namespace Percipio


#endif // Foundation_PipeImpl_WIN32_INCLUDED
