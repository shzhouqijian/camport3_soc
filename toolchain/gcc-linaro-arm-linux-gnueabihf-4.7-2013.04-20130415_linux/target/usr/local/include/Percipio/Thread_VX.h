//
// Thread_VX.h
//
// $Id: //percipio/1.4/Foundation/include/Percipio/Thread_VX.h#3 $
//
// Library: Foundation
// Package: Threading
// Module:  Thread
//
// Definition of the ThreadImpl class for VxWorks tasks.
//
// Copyright (c) 2004-2011, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Foundation_Thread_VX_INCLUDED
#define Foundation_Thread_VX_INCLUDED


#include "Percipio/Foundation.h"
#include "Percipio/Runnable.h"
#include "Percipio/SignalHandler.h"
#include "Percipio/Event.h"
#include "Percipio/RefCountedObject.h"
#include "Percipio/AutoPtr.h"
#include <taskLib.h>
#include <taskVarLib.h>


namespace Percipio {


class Foundation_API ThreadImpl
{
public:	
	typedef int TIDImpl;
	typedef void (*Callable)(void*);

	enum Priority
	{
		PRIO_LOWEST_IMPL,
		PRIO_LOW_IMPL,
		PRIO_NORMAL_IMPL,
		PRIO_HIGH_IMPL,
		PRIO_HIGHEST_IMPL
	};

	enum Policy
	{
		POLICY_DEFAULT_IMPL = 0
	};

	enum
	{
		DEFAULT_THREAD_STACK_SIZE = 65536
	};

	struct CallbackData: public RefCountedObject
	{
		CallbackData(): callback(0), pData(0)
		{
		}

		Callable  callback;
		void*     pData; 
	};

	ThreadImpl();
	~ThreadImpl();

	TIDImpl tidImpl() const;
	void setPriorityImpl(int prio);
	int getPriorityImpl() const;
	void setOSPriorityImpl(int prio, int policy = 0);
	int getOSPriorityImpl() const;
	static int getMinOSPriorityImpl(int policy);
	static int getMaxOSPriorityImpl(int policy);
	void setStackSizeImpl(int size);
	int getStackSizeImpl() const;
	void startImpl(Runnable& target);
	void startImpl(Callable target, void* pData = 0);

	void joinImpl();
	bool joinImpl(long milliseconds);
	bool isRunningImpl() const;
	static void sleepImpl(long milliseconds);
	static void yieldImpl();
	static ThreadImpl* currentImpl();
	static TIDImpl currentTidImpl();

protected:
	static void runnableEntry(void* pThread, int, int, int, int, int, int, int, int, int);
	static void callableEntry(void* pThread, int, int, int, int, int, int, int, int, int);
	static int mapPrio(int prio);
	static int reverseMapPrio(int osPrio);

	struct ThreadData: public RefCountedObject
	{
		ThreadData():
			pRunnableTarget(0),
			pCallbackTarget(0),
			task(0),
			prio(PRIO_NORMAL_IMPL),
			osPrio(127),
			done(false),
			stackSize(PERCIPIO_THREAD_STACK_SIZE)
		{
		}

		Runnable* pRunnableTarget;
		AutoPtr<CallbackData> pCallbackTarget;
		int       task;
		int       prio;
		int       osPrio;
		Event     done;
		int       stackSize;
	};

private:
	AutoPtr<ThreadData> _pData;
	static ThreadImpl* _pCurrent;
};


//
// inlines
//
inline int ThreadImpl::getPriorityImpl() const
{
	return _pData->prio;
}


inline int ThreadImpl::getOSPriorityImpl() const
{
	return _pData->osPrio;
}


inline bool ThreadImpl::isRunningImpl() const
{
	return _pData->pRunnableTarget != 0 ||
		(_pData->pCallbackTarget.get() != 0 && _pData->pCallbackTarget->callback != 0);
}


inline void ThreadImpl::yieldImpl()
{
	taskDelay(0);
}


inline int ThreadImpl::getStackSizeImpl() const
{
	return _pData->stackSize;
}


inline ThreadImpl::TIDImpl ThreadImpl::tidImpl() const
{
	return _pData->task;
}


} // namespace Percipio


#endif // Foundation_Thread_VX_INCLUDED
