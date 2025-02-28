//
// ScopedUnlock.h
//
// $Id: //percipio/1.4/Foundation/include/Percipio/ScopedUnlock.h#1 $
//
// Library: Foundation
// Package: Threading
// Module:  Mutex
//
// Definition of the ScopedUnlock template class.
//
// Copyright (c) 2007, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Foundation_ScopedUnlock_INCLUDED
#define Foundation_ScopedUnlock_INCLUDED


#include "Percipio/Foundation.h"


namespace Percipio {


template <class M>
class ScopedUnlock
	/// A class that simplifies thread synchronization
	/// with a mutex.
	/// The constructor accepts a Mutex and unlocks it.
	/// The destructor locks the mutex.
{
public:
	inline ScopedUnlock(M& mutex, bool unlockNow = true): _mutex(mutex)
	{
		if (unlockNow)
			_mutex.unlock();
	}
	inline ~ScopedUnlock()
	{
		try
		{
			_mutex.lock();
		}
		catch (...)
		{
			percipio_unexpected();
		}
	}

private:
	M& _mutex;

	ScopedUnlock();
	ScopedUnlock(const ScopedUnlock&);
	ScopedUnlock& operator = (const ScopedUnlock&);
};


} // namespace Percipio


#endif // Foundation_ScopedUnlock_INCLUDED
