//
// PipeImpl_DUMMY.h
//
// $Id: //percipio/1.4/Foundation/include/Percipio/PipeImpl_DUMMY.h#1 $
//
// Library: Foundation
// Package: Processes
// Module:  PipeImpl
//
// Definition of the PipeImpl_DUMMY class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Foundation_PipeImpl_DUMMY_INCLUDED
#define Foundation_PipeImpl_DUMMY_INCLUDED


#include "Percipio/Foundation.h"
#include "Percipio/RefCountedObject.h"


namespace Percipio {


class Foundation_API PipeImpl: public RefCountedObject
	/// A dummy implementation of PipeImpl for platforms
	/// that do not support pipes.
{
public:
	typedef int Handle;

	PipeImpl();
	~PipeImpl();
	int writeBytes(const void* buffer, int length);
	int readBytes(void* buffer, int length);
	Handle readHandle() const;
	Handle writeHandle() const;
	void closeRead();
	void closeWrite();
};


} // namespace Percipio


#endif // Foundation_PipeImpl_DUMMY_INCLUDED
