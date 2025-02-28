//
// Mutex_WIN32.h
//
// $Id: //percipio/1.4/Foundation/include/Percipio/Mutex_WIN32.h#1 $
//
// Library: Foundation
// Package: Threading
// Module:  Mutex
//
// Definition of the MutexImpl and FastMutexImpl classes for WIN32.
//
// Copyright (c) 2004-2008, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Foundation_Mutex_WIN32_INCLUDED
#define Foundation_Mutex_WIN32_INCLUDED


#include "Percipio/Foundation.h"
#include "Percipio/Exception.h"
#include "Percipio/UnWindows.h"


namespace Percipio {


class Foundation_API MutexImpl
{
protected:
	MutexImpl();
	~MutexImpl();
	void lockImpl();
	bool tryLockImpl();
	bool tryLockImpl(long milliseconds);
	void unlockImpl();
	
private:
	CRITICAL_SECTION _cs;
};


typedef MutexImpl FastMutexImpl;


//
// inlines
//
inline void MutexImpl::lockImpl()
{
	try
	{
		EnterCriticalSection(&_cs);
	}
	catch (...)
	{
		throw SystemException("cannot lock mutex");
	}
}


inline bool MutexImpl::tryLockImpl()
{
	try
	{
		return TryEnterCriticalSection(&_cs) != 0;
	}
	catch (...)
	{
	}
	throw SystemException("cannot lock mutex");
}


inline void MutexImpl::unlockImpl()
{
	LeaveCriticalSection(&_cs);
}


} // namespace Percipio


#endif // Foundation_Mutex_WIN32_INCLUDED
