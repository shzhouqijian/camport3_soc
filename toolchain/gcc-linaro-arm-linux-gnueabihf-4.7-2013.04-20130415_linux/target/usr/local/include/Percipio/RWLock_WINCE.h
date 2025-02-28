//
// RWLock_WINCE.h
//
// $Id: //percipio/1.4/Foundation/include/Percipio/RWLock_WINCE.h#1 $
//
// Library: Foundation
// Package: Threading
// Module:  RWLock
//
// Definition of the RWLockImpl class for WINCE.
//
// Copyright (c) 2009-2010, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Foundation_RWLock_WINCE_INCLUDED
#define Foundation_RWLock_WINCE_INCLUDED


#include "Percipio/Foundation.h"
#include "Percipio/Exception.h"
#include "Percipio/UnWindows.h"


namespace Percipio {


class Foundation_API RWLockImpl
	/// This implementation is based on the one from Stone Steps Inc,
	/// licensed under the BSD license.
	/// http://forums.stonesteps.ca/thread.asp?t=105
	///
	/// Note that with this implementation, writers always take
	/// precedence over readers.
{
protected:
	RWLockImpl();
	~RWLockImpl();
	void readLockImpl();
	bool tryReadLockImpl(DWORD timeout = 1);
	void writeLockImpl();
	bool tryWriteLockImpl(DWORD timeout = 1);
	void unlockImpl();
	
private:
	DWORD _readerCount;
	DWORD _readerWaiting;
	DWORD _writerCount;
	DWORD _writerWaiting;
	HANDLE _readerGreen;
	HANDLE _writerGreen;
	CRITICAL_SECTION _cs;
	bool _writeLock;
};


} // namespace Percipio


#endif // Foundation_RWLock_WINCE_INCLUDED
