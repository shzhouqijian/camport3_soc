//
// Version.h
//
// $Id: //percipio/1.4/Foundation/include/Percipio/Version.h#10 $
//
// Library: Foundation
// Package: Core
// Module:  Version
//
// Version information for the PERCIPIO C++ Libraries.
//
// Copyright (c) 2004-2016, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Foundation_Version_INCLUDED
#define Foundation_Version_INCLUDED


//
// Version Information
//
// Since 1.6.0, we're using Semantic Versioning 2.0
// (http://semver.org/spec/v2.0.0.html)
//
// Version format is 0xAABBCCDD, where
//    - AA is the major version number,
//    - BB is the minor version number,
//    - CC is the patch	version number, and
//    - DD is the pre-release designation/number.
//      The pre-release designation hex digits have a special meaning:
//      00: final/stable releases
//      Dx: development releases
//      Ax: alpha releases
//      Bx: beta releases
//
//#define PERCIPIO_VERSION 0x01010000
#define PERCIPIO_DEV_VERSION_MAJOR      1
#define PERCIPIO_DEV_VERSION_MINOR      2
#define PERCIPIO_DEV_VERSION_PATCH      0

#endif // Foundation_Version_INCLUDED
