//
// Environment_VMS.h
//
// $Id: //percipio/1.4/Foundation/include/Percipio/Environment_VMS.h#2 $
//
// Library: Foundation
// Package: Core
// Module:  Environment
//
// Definition of the EnvironmentImpl class for OpenVMS.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Foundation_Environment_VMS_INCLUDED
#define Foundation_Environment_VMS_INCLUDED


#include "Percipio/Foundation.h"
#include "Percipio/Mutex.h"


namespace Percipio {


class Foundation_API EnvironmentImpl
{
public:
	typedef UInt8 NodeId[6]; /// Ethernet address.

	static std::string getImpl(const std::string& name);	
	static bool hasImpl(const std::string& name);	
	static void setImpl(const std::string& name, const std::string& value);
	static std::string osNameImpl();
	static std::string osDisplayNameImpl();
	static std::string osVersionImpl();
	static std::string osArchitectureImpl();
	static std::string nodeNameImpl();
	static void nodeIdImpl(NodeId& id);
	static unsigned processorCountImpl();
	
	static std::string getsyi(unsigned short code);
		/// a wrapper for $GETSYIW
		
	static std::string trnlnm(const std::string& name);

private:
	static FastMutex _mutex;
};


} // namespace Percipio


#endif // Foundation_Environment_VMS_INCLUDED
