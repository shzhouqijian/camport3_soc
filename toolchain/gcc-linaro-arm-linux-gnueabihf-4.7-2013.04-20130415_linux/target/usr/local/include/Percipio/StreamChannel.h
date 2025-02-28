//
// StreamChannel.h
//
// $Id: //percipio/1.4/Foundation/include/Percipio/StreamChannel.h#1 $
//
// Library: Foundation
// Package: Logging
// Module:  StreamChannel
//
// Definition of the StreamChannel class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Foundation_StreamChannel_INCLUDED
#define Foundation_StreamChannel_INCLUDED


#include "Percipio/Foundation.h"
#include "Percipio/Channel.h"
#include "Percipio/Mutex.h"
#include <ostream>


namespace Percipio {


class Foundation_API StreamChannel: public Channel
	/// A channel that writes to an ostream.
	///
	/// Only the message's text is written, followed
	/// by a newline.
	///
	/// Chain this channel to a FormattingChannel with an
	/// appropriate Formatter to control what is contained 
	/// in the text.
{
public:
	StreamChannel(std::ostream& str);
		/// Creates the channel.

	void log(const Message& msg);
		/// Logs the given message to the channel's stream.
		
protected:
	virtual ~StreamChannel();

private:
	std::ostream& _str;
	FastMutex     _mutex;
};


} // namespace Percipio


#endif // Foundation_StreamChannel_INCLUDED
