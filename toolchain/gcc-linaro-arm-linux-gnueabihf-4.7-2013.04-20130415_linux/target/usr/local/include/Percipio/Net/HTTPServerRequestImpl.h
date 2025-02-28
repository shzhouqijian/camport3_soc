//
// HTTPServerRequestImpl.h
//
// $Id: //percipio/1.4/Net/include/Percipio/Net/HTTPServerRequestImpl.h#1 $
//
// Library: Net
// Package: HTTPServer
// Module:  HTTPServerRequestImpl
//
// Definition of the HTTPServerRequestImpl class.
//
// Copyright (c) 2005-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Net_HTTPServerRequestImpl_INCLUDED
#define Net_HTTPServerRequestImpl_INCLUDED


#include "Percipio/Net/Net.h"
#include "Percipio/Net/HTTPServerRequest.h"
#include "Percipio/Net/HTTPServerResponseImpl.h"
#include "Percipio/Net/SocketAddress.h"
#include "Percipio/AutoPtr.h"
#include <istream>


namespace Percipio {
namespace Net {


class HTTPServerSession;
class HTTPServerParams;
class StreamSocket;


class Net_API HTTPServerRequestImpl: public HTTPServerRequest
	/// This subclass of HTTPServerRequest is used for
	/// representing server-side HTTP requests.
	///
	/// A HTTPServerRequest is passed to the
	/// handleRequest() method of HTTPRequestHandler.
{
public:
	HTTPServerRequestImpl(HTTPServerResponseImpl& response, HTTPServerSession& session, HTTPServerParams* pParams);
		/// Creates the HTTPServerRequestImpl, using the
		/// given HTTPServerSession.

	~HTTPServerRequestImpl();
		/// Destroys the HTTPServerRequestImpl.
		
	std::istream& stream();
		/// Returns the input stream for reading
		/// the request body.
		///
		/// The stream is valid until the HTTPServerRequestImpl
		/// object is destroyed.
		
	bool expectContinue() const;
		/// Returns true if the client expects a
		/// 100 Continue response.
		
	const SocketAddress& clientAddress() const;
		/// Returns the client's address.

	const SocketAddress& serverAddress() const;
		/// Returns the server's address.
		
	const HTTPServerParams& serverParams() const;
		/// Returns a reference to the server parameters.

	HTTPServerResponse& response() const;
		/// Returns a reference to the associated response.
		
	StreamSocket& socket();
		/// Returns a reference to the underlying socket.
		
	StreamSocket detachSocket();
		/// Returns the underlying socket after detaching
		/// it from the server session.

protected:
	static const std::string EXPECT;
	
private:
	HTTPServerResponseImpl&         _response;
	HTTPServerSession&              _session;
	std::istream*                   _pStream;
	Percipio::AutoPtr<HTTPServerParams> _pParams;
	SocketAddress                   _clientAddress;
	SocketAddress                   _serverAddress;
};


//
// inlines
//
inline std::istream& HTTPServerRequestImpl::stream()
{
	percipio_check_ptr (_pStream);
	
	return *_pStream;
}


inline const SocketAddress& HTTPServerRequestImpl::clientAddress() const
{
	return _clientAddress;
}


inline const SocketAddress& HTTPServerRequestImpl::serverAddress() const
{
	return _serverAddress;
}


inline const HTTPServerParams& HTTPServerRequestImpl::serverParams() const
{
	return *_pParams;
}


inline HTTPServerResponse& HTTPServerRequestImpl::response() const
{
	return _response;
}


} } // namespace Percipio::Net


#endif // Net_HTTPServerRequestImpl_INCLUDED
