//
// Environment_WIN32U.h
//
// $Id: //percipio/1.4/Foundation/include/Percipio/Environment_WIN32U.h#2 $
//
// Library: Foundation
// Package: Core
// Module:  Environment
//
// Definition of the EnvironmentImpl class for WIN32.
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Foundation_Environment_WIN32U_INCLUDED
#define Foundation_Environment_WIN32U_INCLUDED


#include "Percipio/Foundation.h"


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
};


} // namespace Percipio


#endif // Foundation_Environment_WIN32U_INCLUDED
