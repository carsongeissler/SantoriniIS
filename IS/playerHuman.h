//
// Created by gremo on 2/13/20.
//

#ifndef UNTITLED_PLAYERHUMAN_H
#define UNTITLED_PLAYERHUMAN_H


#include "board.h"
using namespace std;
class human
{
public:
    human();
    void selectStart(board &game, int player);
    bool move(board &game);
};
//-------------------------------

#endif //UNTITLED_PLAYERHUMAN_H
