//
// Path_WIN32.h
//
// $Id: //percipio/1.4/Foundation/include/Percipio/Path_WIN32.h#1 $
//
// Library: Foundation
// Package: Filesystem
// Module:  Path
//
// Definition of the PathImpl class for WIN32.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Foundation_Path_WIN32_INCLUDED
#define Foundation_Path_WIN32_INCLUDED


#include "Percipio/Foundation.h"
#include <vector>


namespace Percipio {


class Foundation_API PathImpl
{
public:
	static std::string currentImpl();
	static std::string homeImpl();
	static std::string tempImpl();
	static std::string nullImpl();
	static std::string systemImpl();
	static std::string expandImpl(const std::string& path);
	static void listRootsImpl(std::vector<std::string>& roots);
};


} // namespace Percipio


#endif // Foundation_Path_WIN32_INCLUDED
