//
// SocketNotification.h
//
// $Id: //poco/1.3/Net/include/Poco/Net/SocketNotification.h#2 $
//
// Library: Net
// Package: Reactor
// Module:  SocketNotification
//
// Definition of the SocketNotification class.
//
// Copyright (c) 2005-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef Net_SocketNotification_INCLUDED
#define Net_SocketNotification_INCLUDED


#include "Poco/Net/Net.h"
#include "Poco/Net/Socket.h"
#include "Poco/Notification.h"


namespace Poco {
namespace Net {


class SocketReactor;


class Net_API SocketNotification: public Poco::Notification
	/// The base class for all notifications generated by
	/// the SocketReactor.
{
public:
	SocketNotification(SocketReactor* pReactor);
		/// Creates the SocketNotification for the given SocketReactor.

	virtual ~SocketNotification();
		/// Destroys the SocketNotification.
		
	SocketReactor& source();
		/// Returns the SocketReactor that generated the notification.	
		
	Socket& socket();
		/// Returns the socket that caused the notification.

private:
	void setSocket(const Socket& socket);
	
	SocketReactor* _pReactor;
	Socket         _socket;
	
	friend class SocketNotifier;
};


class Net_API ReadableNotification: public SocketNotification
	/// This notification is sent if a socket has become readable.
{
public:
	ReadableNotification(SocketReactor* pReactor);
		/// Creates the ReadableNotification for the given SocketReactor.

	~ReadableNotification();
		/// Destroys the ReadableNotification.
};


class Net_API WritableNotification: public SocketNotification
	/// This notification is sent if a socket has become writable.
{
public:
	WritableNotification(SocketReactor* pReactor);
		/// Creates the WritableNotification for the given SocketReactor.

	~WritableNotification();
		/// Destroys the WritableNotification.
};


class Net_API ErrorNotification: public SocketNotification
	/// This notification is sent if a socket has signalled an error.
{
public:
	ErrorNotification(SocketReactor* pReactor);
		/// Creates the ErrorNotification for the given SocketReactor.

	~ErrorNotification();
		/// Destroys the ErrorNotification.
};


class Net_API TimeoutNotification: public SocketNotification
	/// This notification is sent if no other event has occured
	/// for a specified time.
{
public:
	TimeoutNotification(SocketReactor* pReactor);
		/// Creates the TimeoutNotification for the given SocketReactor.

	~TimeoutNotification();
		/// Destroys the TimeoutNotification.
};


class Net_API IdleNotification: public SocketNotification
	/// This notification is sent when the SocketReactor does
	/// not have any sockets to react to.
{
public:
	IdleNotification(SocketReactor* pReactor);
		/// Creates the IdleNotification for the given SocketReactor.

	~IdleNotification();
		/// Destroys the IdleNotification.
};


class Net_API ShutdownNotification: public SocketNotification
	/// This notification is sent when the SocketReactor is
	/// about to shut down.
{
public:
	ShutdownNotification(SocketReactor* pReactor);
		/// Creates the ShutdownNotification for the given SocketReactor.

	~ShutdownNotification();
		/// Destroys the ShutdownNotification.
};


//
// inlines
//
inline SocketReactor& SocketNotification::source()
{
	return *_pReactor;
}

	
inline Socket& SocketNotification::socket()
{
	return _socket;
}


} } // namespace Poco::Net


#endif // Net_SocketNotification_INCLUDED
