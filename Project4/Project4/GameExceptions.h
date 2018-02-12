#ifndef __GAMEEXCEPTIONS_H
#define __GAMEEXCEPTIONS_H

#include <string>

class GameException {
protected:
   std::string mMessage;

public:
   GameException(const std::string &m) : mMessage(m) {}
   inline std::string GetMessage() const {return mMessage;}
};

class OthelloException : public GameException {
public:
   OthelloException(const std::string &m) : GameException(m) {}
};

class TicTacToeException : public GameException {
public:
   TicTacToeException(const std::string &m) : GameException(m) {}
};

#endif