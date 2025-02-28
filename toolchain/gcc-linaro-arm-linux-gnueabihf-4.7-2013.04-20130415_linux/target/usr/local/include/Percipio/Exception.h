//
// Exception.h
//
// $Id: //percipio/1.4/Foundation/include/Percipio/Exception.h#2 $
//
// Library: Foundation
// Package: Core
// Module:  Exception
//
// Definition of various Percipio exception classes.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Foundation_Exception_INCLUDED
#define Foundation_Exception_INCLUDED


#include "Percipio/Foundation.h"
#include <stdexcept>


namespace Percipio {


class Foundation_API Exception: public std::exception
	/// This is the base class for all exceptions defined
	/// in the Percipio class library.
{
public:
	Exception(const std::string& msg, int code = 0);
		/// Creates an exception.

	Exception(const std::string& msg, const std::string& arg, int code = 0);
		/// Creates an exception.

	Exception(const std::string& msg, const Exception& nested, int code = 0);
		/// Creates an exception and stores a clone
		/// of the nested exception.

	Exception(const Exception& exc);
		/// Copy constructor.
		
	~Exception() throw();
		/// Destroys the exception and deletes the nested exception.

	Exception& operator = (const Exception& exc);
		/// Assignment operator.

	virtual const char* name() const throw();
		/// Returns a static string describing the exception.
		
	virtual const char* className() const throw();
		/// Returns the name of the exception class.
		
	virtual const char* what() const throw();
		/// Returns a static string describing the exception.
		///
		/// Same as name(), but for compatibility with std::exception.
		
	const Exception* nested() const;
		/// Returns a pointer to the nested exception, or
		/// null if no nested exception exists.
			
	const std::string& message() const;
		/// Returns the message text.
			
	int code() const;
		/// Returns the exception code if defined.
		
	std::string displayText() const;
		/// Returns a string consisting of the
		/// message name and the message text.

	virtual Exception* clone() const;
		/// Creates an exact copy of the exception.
		///
		/// The copy can later be thrown again by
		/// invoking rethrow() on it.
		
	virtual void rethrow() const;
		/// (Re)Throws the exception.
		///
		/// This is useful for temporarily storing a
		/// copy of an exception (see clone()), then
		/// throwing it again.

protected:
	Exception(int code = 0);
		/// Standard constructor.

	void message(const std::string& msg);
		/// Sets the message for the exception.

	void extendedMessage(const std::string& arg);
		/// Sets the extended message for the exception.
		
private:
	std::string _msg;
	Exception*  _pNested;
	int			_code;
};


//
// inlines
//
inline const Exception* Exception::nested() const
{
	return _pNested;
}


inline const std::string& Exception::message() const
{
	return _msg;
}


inline void Exception::message(const std::string& msg)
{
	_msg = msg;
}


inline int Exception::code() const
{
	return _code;
}


//
// Macros for quickly declaring and implementing exception classes.
// Unfortunately, we cannot use a template here because character
// pointers (which we need for specifying the exception name)
// are not allowed as template arguments.
//
#define PERCIPIO_DECLARE_EXCEPTION_CODE(API, CLS, BASE, CODE) \
	class API CLS: public BASE														\
	{																				\
	public:																			\
		CLS(int code = CODE);														\
		CLS(const std::string& msg, int code = CODE);								\
		CLS(const std::string& msg, const std::string& arg, int code = CODE);		\
		CLS(const std::string& msg, const Percipio::Exception& exc, int code = CODE);	\
		CLS(const CLS& exc);														\
		~CLS() throw();																\
		CLS& operator = (const CLS& exc);											\
		const char* name() const throw();											\
		const char* className() const throw();										\
		Percipio::Exception* clone() const;												\
		void rethrow() const;														\
	};

#define PERCIPIO_DECLARE_EXCEPTION(API, CLS, BASE) \
	PERCIPIO_DECLARE_EXCEPTION_CODE(API, CLS, BASE, 0)

#define PERCIPIO_IMPLEMENT_EXCEPTION(CLS, BASE, NAME)													\
	CLS::CLS(int code): BASE(code)																	\
	{																								\
	}																								\
	CLS::CLS(const std::string& msg, int code): BASE(msg, code)										\
	{																								\
	}																								\
	CLS::CLS(const std::string& msg, const std::string& arg, int code): BASE(msg, arg, code)		\
	{																								\
	}																								\
	CLS::CLS(const std::string& msg, const Percipio::Exception& exc, int code): BASE(msg, exc, code)	\
	{																								\
	}																								\
	CLS::CLS(const CLS& exc): BASE(exc)																\
	{																								\
	}																								\
	CLS::~CLS() throw()																				\
	{																								\
	}																								\
	CLS& CLS::operator = (const CLS& exc)															\
	{																								\
		BASE::operator = (exc);																		\
		return *this;																				\
	}																								\
	const char* CLS::name() const throw()															\
	{																								\
		return NAME;																				\
	}																								\
	const char* CLS::className() const throw()														\
	{																								\
		return typeid(*this).name();																\
	}																								\
	Percipio::Exception* CLS::clone() const																\
	{																								\
		return new CLS(*this);																		\
	}																								\
	void CLS::rethrow() const																		\
	{																								\
		throw *this;																				\
	}


//
// Standard exception classes
//
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, LogicException, Exception)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, AssertionViolationException, LogicException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, NullPointerException, LogicException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, NullValueException, LogicException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, BugcheckException, LogicException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, InvalidArgumentException, LogicException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, NotImplementedException, LogicException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, RangeException, LogicException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, IllegalStateException, LogicException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, InvalidAccessException, LogicException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, SignalException, LogicException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, UnhandledException, LogicException)

PERCIPIO_DECLARE_EXCEPTION(Foundation_API, RuntimeException, Exception)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, NotFoundException, RuntimeException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, ExistsException, RuntimeException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, TimeoutException, RuntimeException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, SystemException, RuntimeException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, RegularExpressionException, RuntimeException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, LibraryLoadException, RuntimeException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, LibraryAlreadyLoadedException, RuntimeException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, NoThreadAvailableException, RuntimeException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, PropertyNotSupportedException, RuntimeException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, PoolOverflowException, RuntimeException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, NoPermissionException, RuntimeException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, OutOfMemoryException, RuntimeException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, DataException, RuntimeException)

PERCIPIO_DECLARE_EXCEPTION(Foundation_API, DataFormatException, DataException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, SyntaxException, DataException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, CircularReferenceException, DataException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, PathSyntaxException, SyntaxException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, IOException, RuntimeException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, ProtocolException, IOException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, FileException, IOException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, FileExistsException, FileException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, FileNotFoundException, FileException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, PathNotFoundException, FileException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, FileReadOnlyException, FileException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, FileAccessDeniedException, FileException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, CreateFileException, FileException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, OpenFileException, FileException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, WriteFileException, FileException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, ReadFileException, FileException)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, UnknownURISchemeException, RuntimeException)

PERCIPIO_DECLARE_EXCEPTION(Foundation_API, ApplicationException, Exception)
PERCIPIO_DECLARE_EXCEPTION(Foundation_API, BadCastException, RuntimeException)


} // namespace Percipio


#endif // Foundation_Exception_INCLUDED
