//
// NamedMutex_VMS.h
//
// $Id: //percipio/1.4/Foundation/include/Percipio/NamedMutex_VMS.h#1 $
//
// Library: Foundation
// Package: Processes
// Module:  NamedMutex
//
// Definition of the NamedMutexImpl class for OpenVMS.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Foundation_NamedMutex_VMS_INCLUDED
#define Foundation_NamedMutex_VMS_INCLUDED


#include "Percipio/Foundation.h"
#include <descrip.h>
#include <lckdef.h>


namespace Percipio {


class Foundation_API NamedMutexImpl
{
protected:
	NamedMutexImpl(const std::string& name);
	~NamedMutexImpl();
	void lockImpl();
	bool tryLockImpl();
	void unlockImpl();
	
private:
	std::string             _name;
	struct dsc$descriptor_s _nameDesc;
	int                     _lksb[4];
};


} // namespace Percipio


#endif // Foundation_NamedMutex_VMS_INCLUDED
