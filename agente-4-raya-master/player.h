#ifndef PLAYER_H
#define PLAYER_H

#include "environment.h"

class Player{
    public:
      Player(int jug);
      Environment::ActionType Think();
      void Perceive(const Environment &env);
      double minimax(const Environment &env,int jugador, int depth,double a,double b,bool maxormin);

    private:
      int jugador_;
      Environment actual_;
};
#endif
