//
// EventArgs.h
//
// $Id: //percipio/1.4/Foundation/include/Percipio/EventArgs.h#2 $
//
// Library: Foundation
// Package: Events
// Module:  EventArgs
//
// Definition of EventArgs.
//
// Copyright (c) 2006-2011, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Foundation_EventArgs_INCLUDED
#define Foundation_EventArgs_INCLUDED


#include "Percipio/Foundation.h"


namespace Percipio {


class Foundation_API EventArgs
	/// The purpose of the EventArgs class is to be used as parameter
	/// when one doesn't want to send any data.
	///
	/// One can use EventArgs as a base class for one's own event arguments
	/// but with the arguments being a template parameter this is not
	/// necessary.
{
public:
	EventArgs();
	
	virtual ~EventArgs();
};


} // namespace Percipio


#endif
