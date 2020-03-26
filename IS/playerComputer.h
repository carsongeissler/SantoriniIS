//
// Created by gremo on 2/13/20.
//

#ifndef UNTITLED_PLAYERCOMPUTER_H
#define UNTITLED_PLAYERCOMPUTER_H


#include "board.h"
#include "ply.h"
#include <vector>
using namespace std;
class computer
{
public:
    computer(int setAbility);
    computer(int setAbility, int di, int ce, int he);
    int compAbility;
    int dH;
    int cH;
    int hH;
    void selectStart(board &game);
    Ply selectBestMove(board game);
    void move(board &game, bool turn);
    void selectedMove(board &game, bool turn, Ply bestMove);
    void printBestMove(Ply bestMove);
    int checkIfOppWin(board &game, Ply propMove, int recurse);
    int checkIfWin(board &game, Ply propMove, int recurse);
    vector<Ply> generateMoves(board &game);
    vector<Ply> generateOppMoves(board &game);
    Ply actualSelect(vector<Ply>moves);
    void onePlyLookAhead(board &game, bool turn);
    void twoPlyLookAhead(board &game, bool turn);
    void threePlyLookAhead(board &game, bool turn);
    void fourPlyLookAhead(board &game, bool turn);
    void treeMove(board&game, bool turn, int numLook);
};


#endif //UNTITLED_PLAYERCOMPUTER_H
