//
// NamedEvent_WIN32.h
//
// $Id: //percipio/1.4/Foundation/include/Percipio/NamedEvent_WIN32.h#1 $
//
// Library: Foundation
// Package: Processes
// Module:  NamedEvent
//
// Definition of the NamedEventImpl class for Windows.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Foundation_NamedEvent_WIN32_INCLUDED
#define Foundation_NamedEvent_WIN32_INCLUDED


#include "Percipio/Foundation.h"
#include "Percipio/UnWindows.h"


namespace Percipio {


class Foundation_API NamedEventImpl
{
protected:
	NamedEventImpl(const std::string& name);	
	~NamedEventImpl();
	void setImpl();
	void waitImpl();
	
private:
	std::string _name;
	HANDLE      _event;	
};


} // namespace Percipio


#endif // Foundation_NamedEvent_WIN32_INCLUDED
