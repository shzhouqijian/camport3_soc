//
// Windows1252Encoding.h
//
// $Id: //percipio/1.4/Foundation/include/Percipio/Windows1252Encoding.h#1 $
//
// Library: Foundation
// Package: Text
// Module:  Windows1252Encoding
//
// Definition of the Windows1252Encoding class.
//
// Copyright (c) 2005-2007, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Foundation_Windows1252Encoding_INCLUDED
#define Foundation_Windows1252Encoding_INCLUDED


#include "Percipio/Foundation.h"
#include "Percipio/TextEncoding.h"


namespace Percipio {


class Foundation_API Windows1252Encoding: public TextEncoding
	/// Windows Codepage 1252 text encoding.
{
public:
	Windows1252Encoding();
	~Windows1252Encoding();
	const char* canonicalName() const;
	bool isA(const std::string& encodingName) const;
	const CharacterMap& characterMap() const;
	int convert(const unsigned char* bytes) const;
	int convert(int ch, unsigned char* bytes, int length) const;
	int queryConvert(const unsigned char* bytes, int length) const;
	int sequenceLength(const unsigned char* bytes, int length) const;
	
private:
	static const char* _names[];
	static const CharacterMap _charMap;
};


} // namespace Percipio


#endif // Foundation_Windows1252Encoding_INCLUDED
