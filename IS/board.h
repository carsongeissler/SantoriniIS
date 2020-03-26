//
// Created by gremo on 2/13/20.
//

#ifndef UNTITLED_BOARD_H
#define UNTITLED_BOARD_H

#include "Space.h"
class board
{
public:
    Space *spaceList;
    int unitA,unitB,unitX,unitY;
    int configuration;
    int maxHeight;
    int winHeight;

    board(int max, int config,int winH);
    board(const board &b1);
    ~board();

    void printBoard();
    //bool move();
    bool turn;
    bool notOver;
    bool ifOppCantMove();
    bool win();
    int dist(int un1, int un2);
    int center(int un);
    int distH();
    int heightH();
    int centerH();

};




#endif //UNTITLED_BOARD_H
