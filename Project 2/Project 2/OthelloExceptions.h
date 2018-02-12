#ifndef __OTHELLOEXCEPTIONS_H
#define __OTHELLOEXCEPTIONS_H
#include <string>

// Represents an exception thrown in an othello game. Generic exception class.
class OthelloException {
private:
   std::string mMessage;

public:
   // Constructs an exception object with the given message.
   OthelloException(const std::string &m) : mMessage(m) {}

   // Gets the exception message.
   inline std::string GetMessage() const {return mMessage;}
};

#endif