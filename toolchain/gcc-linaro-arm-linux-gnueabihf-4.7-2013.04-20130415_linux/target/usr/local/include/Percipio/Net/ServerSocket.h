//
// ServerSocket.h
//
// $Id: //percipio/1.4/Net/include/Percipio/Net/ServerSocket.h#2 $
//
// Library: Net
// Package: Sockets
// Module:  ServerSocket
//
// Definition of the ServerSocket class.
//
// Copyright (c) 2005-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Net_ServerSocket_INCLUDED
#define Net_ServerSocket_INCLUDED


#include "Percipio/Net/Net.h"
#include "Percipio/Net/Socket.h"
#include "Percipio/Net/StreamSocket.h"


namespace Percipio {
namespace Net {


class Net_API ServerSocket: public Socket
	/// This class provides an interface to a
	/// TCP server socket.
{
public:
	ServerSocket();
		/// Creates a server socket.
		///
		/// The server socket must be bound to
		/// and address and put into listening state.

	ServerSocket(const Socket& socket);
		/// Creates the ServerSocket with the SocketImpl
		/// from another socket. The SocketImpl must be
		/// a ServerSocketImpl, otherwise an InvalidArgumentException
		/// will be thrown.

	ServerSocket(const SocketAddress& address, int backlog = 64);
		/// Creates a server socket, binds it
		/// to the given address and puts it in listening
		/// state.
		///
		/// After successful construction, the server socket
		/// is ready to accept connections.

	ServerSocket(Percipio::UInt16 port, int backlog = 64);
		/// Creates a server socket, binds it
		/// to the given port and puts it in listening
		/// state.
		///
		/// After successful construction, the server socket
		/// is ready to accept connections.

	virtual ~ServerSocket();
		/// Destroys the StreamSocket.

	ServerSocket& operator = (const Socket& socket);
		/// Assignment operator.
		///
		/// Releases the socket's SocketImpl and
		/// attaches the SocketImpl from the other socket and
		/// increments the reference count of the SocketImpl.	

	virtual void bind(const SocketAddress& address, bool reuseAddress = false);
		/// Bind a local address to the socket.
		///
		/// This is usually only done when establishing a server
		/// socket. TCP clients should not bind a socket to a
		/// specific address.
		///
		/// If reuseAddress is true, sets the SO_REUSEADDR
		/// socket option.

	virtual void bind(Percipio::UInt16 port, bool reuseAddress = false);
		/// Bind a local port to the socket.
		///
		/// This is usually only done when establishing a server
		/// socket. 
		///
		/// If reuseAddress is true, sets the SO_REUSEADDR
		/// socket option.

	virtual void bind6(const SocketAddress& address, bool reuseAddress = false, bool ipV6Only = false);
		/// Bind a local IPv6 address to the socket.
		///
		/// This is usually only done when establishing a server
		/// socket. TCP clients should not bind a socket to a
		/// specific address.
		///
		/// If reuseAddress is true, sets the SO_REUSEADDR
		/// socket option.
		///
		/// The given address must be an IPv6 address. The
		/// IPPROTO_IPV6/IPV6_V6ONLY option is set on the socket
		/// according to the ipV6Only parameter.
		///
		/// If the library has not been built with IPv6 support,
		/// a Percipio::NotImplementedException will be thrown.

	virtual void bind6(Percipio::UInt16 port, bool reuseAddress = false, bool ipV6Only = false);
		/// Bind a local IPv6 port to the socket.
		///
		/// This is usually only done when establishing a server
		/// socket. 
		///
		/// If reuseAddress is true, sets the SO_REUSEADDR
		/// socket option.
		///
		/// The given address must be an IPv6 address. The
		/// IPPROTO_IPV6/IPV6_V6ONLY option is set on the socket
		/// according to the ipV6Only parameter.
		///
		/// If the library has not been built with IPv6 support,
		/// a Percipio::NotImplementedException will be thrown.
		
	virtual void listen(int backlog = 64);
		/// Puts the socket into listening state.
		///
		/// The socket becomes a passive socket that
		/// can accept incoming connection requests.
		///
		/// The backlog argument specifies the maximum
		/// number of connections that can be queued
		/// for this socket.

	virtual StreamSocket acceptConnection(SocketAddress& clientAddr);
		/// Get the next completed connection from the
		/// socket's completed connection queue.
		///
		/// If the queue is empty, waits until a connection
		/// request completes.
		///
		/// Returns a new TCP socket for the connection
		/// with the client.
		///
		/// The client socket's address is returned in clientAddr.

	virtual StreamSocket acceptConnection();
		/// Get the next completed connection from the
		/// socket's completed connection queue.
		///
		/// If the queue is empty, waits until a connection
		/// request completes.
		///
		/// Returns a new TCP socket for the connection
		/// with the client.

protected:
	ServerSocket(SocketImpl* pImpl, bool);
		/// The bool argument is to resolve an ambiguity with
		/// another constructor (Microsoft Visual C++ 2005)
};


} } // namespace Percipio::Net


#endif // Net_ServerSocket_INCLUDED
