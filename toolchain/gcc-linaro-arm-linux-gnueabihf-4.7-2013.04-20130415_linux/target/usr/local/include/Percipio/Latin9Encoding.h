//
// Latin9Encoding.h
//
// $Id: //percipio/1.4/Foundation/include/Percipio/Latin9Encoding.h#1 $
//
// Library: Foundation
// Package: Text
// Module:  Latin9Encoding
//
// Definition of the Latin9Encoding class.
//
// Copyright (c) 2004-2007, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Foundation_Latin9Encoding_INCLUDED
#define Foundation_Latin9Encoding_INCLUDED


#include "Percipio/Foundation.h"
#include "Percipio/TextEncoding.h"


namespace Percipio {


class Foundation_API Latin9Encoding: public TextEncoding
	/// ISO Latin-9 (8859-15) text encoding.
	///
	/// Latin-9 is basically Latin-1 with the EURO sign plus
	/// some other minor changes.
{
public:
	Latin9Encoding();
	~Latin9Encoding();
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


#endif // Foundation_Latin9Encoding_INCLUDED
