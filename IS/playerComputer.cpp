//
// Created by gremo on 2/13/20.
//

#include "playerComputer.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Tree.h"
using namespace std;
computer::computer(int setAbility) {
    compAbility=setAbility;
    srand(time(0));
    int fir = rand()%3;
    if(fir==0)
    {
        dH=rand()%100;
        cH=rand()%(100-dH);
        hH=100-dH-cH;
    }
    else if(fir==1)
    {
        cH=rand()%100;
        hH=rand()%(100-cH);
        dH=100-hH-cH;
    } else{
        hH=rand()%100;
        dH=rand()%(100-hH);
        cH=100-hH-dH;
    }
}
computer::computer(int setAbility, int di, int ce, int he)
{
    compAbility=setAbility;
    dH=di;
    cH=ce;
    hH=he;
}
void computer::selectStart(board &game){
    int firstUnit;
    int secondUnit;
    srand(time(0));
    if(game.turn) {
        while (game.unitA == -1) {
            firstUnit = rand() % 25;
            if (game.spaceList[firstUnit].isEmpty()) {
                game.unitA = firstUnit;
            }
        }
        game.spaceList[firstUnit].setEmpty(false);
        while (game.unitB == -1) {
            secondUnit = rand() % 25;
            if (game.spaceList[secondUnit].isEmpty()) {
                game.unitB = secondUnit;
            }
        }
        game.spaceList[secondUnit].setEmpty(false);
        game.turn=!game.turn;
    }
    else{
        while (game.unitX == -1) {
            firstUnit = rand() % 25;
            if (game.spaceList[firstUnit].isEmpty()) {
                game.unitX = firstUnit;
            }
        }
        game.spaceList[firstUnit].setEmpty(false);
        while (game.unitY == -1) {
            secondUnit = rand() % 25;
            if (game.spaceList[secondUnit].isEmpty()) {
                game.unitY = secondUnit;
            }
        }
        game.spaceList[secondUnit].setEmpty(false);
        game.turn=!game.turn;

    }

}
void computer::treeMove(board&game, bool turn, int numLook)
{
    Tree t(game, turn,*this);
    t.addLevels(numLook, turn);
    selectedMove(game, turn,t.findBestMove(numLook));
}
void computer::selectedMove(board &game, bool turn, Ply bestMove)
{
    if(!turn){
        if(bestMove.unit=='X') {
            game.spaceList[game.unitX].setEmpty(true);
            game.unitX=bestMove.moveSpace;
            game.spaceList[bestMove.buildSpace].build();
            game.spaceList[game.unitX].setEmpty(false);
            if(game.win())
            {
                game.notOver=false;
            }
            game.turn=!game.turn;
            cout<<game.unitX<<endl;
            game.printBoard();
        }
        else if(bestMove.unit=='Y') {
            game.spaceList[game.unitY].setEmpty(true);
            game.unitY=bestMove.moveSpace;
            game.spaceList[bestMove.buildSpace].build();
            game.spaceList[game.unitY].setEmpty(false);
            if(game.win())
            {
                game.notOver=false;
            }
            game.turn=!game.turn;
            cout<<game.unitY<<endl;
            game.printBoard();
        }
    }
    else if(turn){
        if(bestMove.unit=='A') {
            game.spaceList[game.unitA].setEmpty(true);
            game.unitA=bestMove.moveSpace;
            game.spaceList[bestMove.buildSpace].build();
            game.spaceList[game.unitA].setEmpty(false);
            if(game.win())
            {
                game.notOver=false;
            }
            game.turn=!game.turn;
            cout<<game.unitA<<endl;
            game.printBoard();
        }
        else if(bestMove.unit=='B') {
            game.spaceList[game.unitB].setEmpty(true);
            game.unitB=bestMove.moveSpace;
            game.spaceList[bestMove.buildSpace].build();
            game.spaceList[game.unitB].setEmpty(false);
            if(game.win())
            {
                game.notOver=false;
            }
            game.turn=!game.turn;
            cout<<game.unitB<<endl;
            game.printBoard();
        }
    }

}

void computer::move(board &game, bool turn)
{
    int moveSpace=game.unitX;
    int buildSpace;
    int tempSpace;

    if (!turn)
    {
        game.spaceList[game.unitX].setEmpty(true);
        for(int i=0;i<game.spaceList[game.unitX].getNumAdj();i++)
        {
            if(game.spaceList[game.spaceList[game.unitX].adjList[i]].isEmpty()&&(game.spaceList[game.spaceList[game.unitX].adjList[i]].getHeight()<=1+game.spaceList[game.unitX].getHeight()))
            {
                tempSpace=game.spaceList[game.spaceList[game.unitX].adjList[i]].id;
                if(game.spaceList[tempSpace].getHeight()>game.spaceList[game.unitX].getHeight())
                {
                    moveSpace=tempSpace;
                }
            }
        }
        if(moveSpace==game.unitX)
        {
            game.unitX=tempSpace;
        }
        else{
            game.unitX=moveSpace;
        }
        if(game.spaceList[game.unitX].getHeight()==3)
        {
            game.notOver=false;
        }
        for(int i=0;i<game.spaceList[game.unitX].getNumAdj();i++)
        {
            if(game.spaceList[game.spaceList[game.unitX].adjList[i]].isEmpty())
            {
                buildSpace=game.spaceList[game.spaceList[game.unitX].adjList[i]].id;
            }

        }
        game.spaceList[buildSpace].build();
    }

    game.spaceList[game.unitX].setEmpty(false);
    game.turn=!game.turn;
    cout<<game.unitX<<endl;
    game.printBoard();
    //else
    //{

    //}
}

Ply computer::selectBestMove(board game)
{
    int val=0;
    vector<Ply> allMoves;
    vector<Ply> bestMoves;
    for(int i=0;i<game.spaceList[game.unitX].getNumAdj();i++)
    {
        if(game.spaceList[game.spaceList[game.unitX].adjList[i]].isEmpty()&&(game.spaceList[game.spaceList[game.unitX].adjList[i]].getHeight()<=1+game.spaceList[game.unitX].getHeight()))
        {
            for(int j=0;j<game.spaceList[game.spaceList[game.unitX].adjList[i]].getNumAdj();j++)
            {
                if(game.spaceList[game.spaceList[game.spaceList[game.unitX].adjList[i]].adjList[j]].isEmpty())
                {
                    allMoves.push_back(Ply(game.spaceList[game.unitX].adjList[i],game.spaceList[game.spaceList[game.unitX].adjList[i]].adjList[j],game.spaceList[game.spaceList[game.unitX].adjList[i]].getHeight()-game.spaceList[game.unitX].getHeight(),'X'));
                }
            }
        }
    }
    for(int i=0;i<game.spaceList[game.unitY].getNumAdj();i++)
    {
        if(game.spaceList[game.spaceList[game.unitY].adjList[i]].isEmpty()&&(game.spaceList[game.spaceList[game.unitY].adjList[i]].getHeight()<=1+game.spaceList[game.unitY].getHeight()))
        {
            for(int j=0;j<game.spaceList[game.spaceList[game.unitY].adjList[i]].getNumAdj();j++)
            {
                if(game.spaceList[game.spaceList[game.spaceList[game.unitY].adjList[i]].adjList[j]].isEmpty())
                {
                    allMoves.push_back(Ply(game.spaceList[game.unitY].adjList[i],game.spaceList[game.spaceList[game.unitY].adjList[i]].adjList[j],game.spaceList[game.spaceList[game.unitY].adjList[i]].getHeight()-game.spaceList[game.unitY].getHeight(),'Y'));
                }
            }
        }
    }
    for(int i=0;i<allMoves.size();i++)
    {
        allMoves[i].value=allMoves[i].value-checkIfOppWin(game,allMoves[i],compAbility);

    }
    val=-10000;
    for(int i=0;i<allMoves.size();i++)
    {

        if(allMoves[i].value>val)
        {
            bestMoves.clear();
            val=allMoves[i].value;
            bestMoves.push_back(allMoves[i]);
        }
        if(allMoves[i].value==val)
        {
            bestMoves.push_back(allMoves[i]);
        }
    }
    srand(time(0));
    return bestMoves[rand()%bestMoves.size()];
}
void computer::printBestMove(Ply bestMove){
    cout<<"Move To: "<<bestMove.moveSpace<<". Build at: "<<bestMove.buildSpace<<endl;
}
int computer::checkIfOppWin(board &game, Ply propMove, int recurse)
{
    int canWin=0;
    int numMoves=0;
    int originalSpace;
    vector<Ply>oppMoves;
    if(propMove.unit=='X')

    {
        //Move
        originalSpace=game.unitX;
        game.spaceList[game.unitX].setEmpty(true);
        game.unitX=propMove.moveSpace;
        game.spaceList[propMove.buildSpace].build();
        game.spaceList[game.unitX].setEmpty(false);
        //Necessary check if opp wins
        for(int i=0;i<game.spaceList[game.unitA].getNumAdj();i++)
        {
            if(game.spaceList[game.spaceList[game.unitA].adjList[i]].isEmpty()&&(game.spaceList[game.spaceList[game.unitA].adjList[i]].getHeight()<=1+game.spaceList[game.unitA].getHeight()))
            {
                numMoves++;
                if(game.spaceList[game.spaceList[game.unitA].adjList[i]].getHeight()==3)
                {
                    canWin=1000*(recurse+2);
                }

                //Next step
                for(int j=0;j<game.spaceList[game.spaceList[game.unitA].adjList[i]].getNumAdj();j++)
                {
                    if(game.spaceList[game.spaceList[game.spaceList[game.unitA].adjList[i]].adjList[j]].isEmpty())
                    {
                        oppMoves.push_back(Ply(game.spaceList[game.unitA].adjList[i],game.spaceList[game.spaceList[game.unitA].adjList[i]].adjList[j],game.spaceList[game.spaceList[game.unitA].adjList[i]].getHeight()-game.spaceList[game.unitA].getHeight(),'A'));
                    }
                }
            }
        }
        for(int i=0;i<game.spaceList[game.unitB].getNumAdj();i++)
        {
            if(game.spaceList[game.spaceList[game.unitB].adjList[i]].isEmpty()&&(game.spaceList[game.spaceList[game.unitB].adjList[i]].getHeight()<=1+game.spaceList[game.unitB].getHeight()))
            {
                numMoves++;
                if(game.spaceList[game.spaceList[game.unitB].adjList[i]].getHeight()==3)
                {
                    canWin=1000*(recurse+2);
                }


                //Next step
                for(int j=0;j<game.spaceList[game.spaceList[game.unitB].adjList[i]].getNumAdj();j++)
                {
                    if(game.spaceList[game.spaceList[game.spaceList[game.unitB].adjList[i]].adjList[j]].isEmpty())
                    {
                        oppMoves.push_back(Ply(game.spaceList[game.unitB].adjList[i],game.spaceList[game.spaceList[game.unitB].adjList[i]].adjList[j],game.spaceList[game.spaceList[game.unitB].adjList[i]].getHeight()-game.spaceList[game.unitB].getHeight(),'B'));
                    }
                }
            }
        }
        if(recurse==true)
        {
            for(int i=0;i<oppMoves.size();i++)
            {
                if(checkIfWin(game,oppMoves[i],recurse-1)==true)
                {
                    canWin=canWin-(1000*recurse+1);
                    i=oppMoves.size();
                }

            }
        }
        //Move back
        game.spaceList[game.unitX].setEmpty(true);
        game.spaceList[propMove.buildSpace].unbuild();
        game.unitX=originalSpace;
        game.spaceList[game.unitX].setEmpty(false);

    }
    else if(propMove.unit=='Y')
    {
        //Move happens here
        originalSpace=game.unitY;
        game.spaceList[game.unitY].setEmpty(true);
        game.unitX=propMove.moveSpace;
        game.spaceList[propMove.buildSpace].build();
        game.spaceList[game.unitY].setEmpty(false);
        //check if opp wins
        for(int i=0;i<game.spaceList[game.unitA].getNumAdj();i++)
        {
            if(game.spaceList[game.spaceList[game.unitA].adjList[i]].isEmpty()&&(game.spaceList[game.spaceList[game.unitA].adjList[i]].getHeight()<=1+game.spaceList[game.unitA].getHeight()))
            {
                numMoves++;
                if(game.spaceList[game.spaceList[game.unitA].adjList[i]].getHeight()==3)
                {
                    canWin=1000*(recurse+2);
                }
                //next step
                for(int j=0;j<game.spaceList[game.spaceList[game.unitA].adjList[i]].getNumAdj();j++)
                {
                    if(game.spaceList[game.spaceList[game.spaceList[game.unitA].adjList[i]].adjList[j]].isEmpty())
                    {
                        oppMoves.push_back(Ply(game.spaceList[game.unitA].adjList[i],game.spaceList[game.spaceList[game.unitA].adjList[i]].adjList[j],game.spaceList[game.spaceList[game.unitA].adjList[i]].getHeight()-game.spaceList[game.unitA].getHeight(),'A'));
                    }
                }
            }
        }
        for(int i=0;i<game.spaceList[game.unitB].getNumAdj();i++)
        {
            if(game.spaceList[game.spaceList[game.unitB].adjList[i]].isEmpty()&&(game.spaceList[game.spaceList[game.unitB].adjList[i]].getHeight()<=1+game.spaceList[game.unitB].getHeight()))
            {
                numMoves++;
                if(game.spaceList[game.spaceList[game.unitB].adjList[i]].getHeight()==3)
                {
                    canWin=1000*(recurse+2);
                }
                //next
                //Next step
                for(int j=0;j<game.spaceList[game.spaceList[game.unitB].adjList[i]].getNumAdj();j++)
                {
                    if(game.spaceList[game.spaceList[game.spaceList[game.unitB].adjList[i]].adjList[j]].isEmpty())
                    {
                        oppMoves.push_back(Ply(game.spaceList[game.unitB].adjList[i],game.spaceList[game.spaceList[game.unitB].adjList[i]].adjList[j],game.spaceList[game.spaceList[game.unitB].adjList[i]].getHeight()-game.spaceList[game.unitB].getHeight(),'B'));
                    }
                }
            }
        }
        if(recurse==true)
        {
            for(int i=0;i<oppMoves.size();i++)
            {
                if(checkIfWin(game,oppMoves[i],recurse-1)==true)
                {
                    canWin=canWin-(1000*recurse+1);
                    i=oppMoves.size();
                }

            }
        }
        //Move back
        game.spaceList[game.unitY].setEmpty(true);
        game.spaceList[propMove.buildSpace].unbuild();
        game.unitY=originalSpace;
        game.spaceList[game.unitY].setEmpty(false);
    }
    return canWin;
}
int computer::checkIfWin(board &game, Ply propMove, int recurse) {
    int canWin=0;
    int numMoves=0;
    int originalSpace;
    vector<Ply>oppMoves;
    if(propMove.unit=='A')
    {
        //Move

        originalSpace=game.unitA;
        game.spaceList[game.unitA].setEmpty(true);
        game.unitA=propMove.moveSpace;
        game.spaceList[propMove.buildSpace].build();
        game.spaceList[game.unitA].setEmpty(false);

        //Necessary check if opp wins
        for(int i=0;i<game.spaceList[game.unitX].getNumAdj();i++)
        {
            if(game.spaceList[game.spaceList[game.unitX].adjList[i]].isEmpty()&&(game.spaceList[game.spaceList[game.unitX].adjList[i]].getHeight()<=1+game.spaceList[game.unitX].getHeight()))
            {
                numMoves++;
                if(game.spaceList[game.spaceList[game.unitX].adjList[i]].getHeight()==3)
                {
                    canWin=1000*(recurse+2);
                }

                //Next step
                for(int j=0;j<game.spaceList[game.spaceList[game.unitX].adjList[i]].getNumAdj();j++)
                {
                    if(game.spaceList[game.spaceList[game.spaceList[game.unitX].adjList[i]].adjList[j]].isEmpty())
                    {
                        oppMoves.push_back(Ply(game.spaceList[game.unitX].adjList[i],game.spaceList[game.spaceList[game.unitX].adjList[i]].adjList[j],game.spaceList[game.spaceList[game.unitX].adjList[i]].getHeight()-game.spaceList[game.unitX].getHeight(),'X'));
                    }
                }
            }
        }
        for(int i=0;i<game.spaceList[game.unitY].getNumAdj();i++)
        {
            if(game.spaceList[game.spaceList[game.unitY].adjList[i]].isEmpty()&&(game.spaceList[game.spaceList[game.unitY].adjList[i]].getHeight()<=1+game.spaceList[game.unitY].getHeight()))
            {
                numMoves++;
                if(game.spaceList[game.spaceList[game.unitY].adjList[i]].getHeight()==3)
                {
                    canWin=1000*(recurse+2);
                }


                //Next step
                for(int j=0;j<game.spaceList[game.spaceList[game.unitY].adjList[i]].getNumAdj();j++)
                {
                    if(game.spaceList[game.spaceList[game.spaceList[game.unitY].adjList[i]].adjList[j]].isEmpty())
                    {
                        oppMoves.push_back(Ply(game.spaceList[game.unitY].adjList[i],game.spaceList[game.spaceList[game.unitY].adjList[i]].adjList[j],game.spaceList[game.spaceList[game.unitY].adjList[i]].getHeight()-game.spaceList[game.unitY].getHeight(),'Y'));
                    }
                }
            }
        }
        if(recurse==true)
        {
            for(int i=0;i<oppMoves.size();i++)
            {
                if(checkIfOppWin(game,oppMoves[i],recurse-1)==true)
                {
                    canWin=canWin-(1000*recurse+1);
                    i=oppMoves.size();
                }

            }
        }
        //Move back

        game.spaceList[game.unitA].setEmpty(true);
        game.spaceList[propMove.buildSpace].unbuild();
        game.unitA=originalSpace;
        game.spaceList[game.unitA].setEmpty(false);

    }
    else if(propMove.unit=='B')
    {
        //Move

        originalSpace=game.unitB;
        game.spaceList[game.unitB].setEmpty(true);
        game.unitB=propMove.moveSpace;
        game.spaceList[propMove.buildSpace].build();
        game.spaceList[game.unitB].setEmpty(false);

        //Necessary check if opp wins
        for(int i=0;i<game.spaceList[game.unitX].getNumAdj();i++)
        {
            if(game.spaceList[game.spaceList[game.unitX].adjList[i]].isEmpty()&&(game.spaceList[game.spaceList[game.unitX].adjList[i]].getHeight()<=1+game.spaceList[game.unitX].getHeight()))
            {
                numMoves++;
                if(game.spaceList[game.spaceList[game.unitX].adjList[i]].getHeight()==3)
                {
                    canWin=1000*(recurse+2);
                }

                //Next step
                for(int j=0;j<game.spaceList[game.spaceList[game.unitX].adjList[i]].getNumAdj();j++)
                {
                    if(game.spaceList[game.spaceList[game.spaceList[game.unitX].adjList[i]].adjList[j]].isEmpty())
                    {
                        oppMoves.push_back(Ply(game.spaceList[game.unitX].adjList[i],game.spaceList[game.spaceList[game.unitX].adjList[i]].adjList[j],game.spaceList[game.spaceList[game.unitX].adjList[i]].getHeight()-game.spaceList[game.unitX].getHeight(),'X'));
                    }
                }
            }
        }
        for(int i=0;i<game.spaceList[game.unitY].getNumAdj();i++)
        {
            if(game.spaceList[game.spaceList[game.unitY].adjList[i]].isEmpty()&&(game.spaceList[game.spaceList[game.unitY].adjList[i]].getHeight()<=1+game.spaceList[game.unitY].getHeight()))
            {
                numMoves++;
                if(game.spaceList[game.spaceList[game.unitY].adjList[i]].getHeight()==3)
                {
                    canWin=1000*(recurse+2);
                }


                //Next step
                for(int j=0;j<game.spaceList[game.spaceList[game.unitY].adjList[i]].getNumAdj();j++)
                {
                    if(game.spaceList[game.spaceList[game.spaceList[game.unitY].adjList[i]].adjList[j]].isEmpty())
                    {
                        oppMoves.push_back(Ply(game.spaceList[game.unitY].adjList[i],game.spaceList[game.spaceList[game.unitY].adjList[i]].adjList[j],game.spaceList[game.spaceList[game.unitY].adjList[i]].getHeight()-game.spaceList[game.unitY].getHeight(),'Y'));
                    }
                }
            }
        }
        if(recurse==true)
        {
            for(int i=0;i<oppMoves.size();i++)
            {
                if(checkIfOppWin(game,oppMoves[i],recurse-1)==true)
                {
                    canWin=canWin-(1000*recurse+1);
                    i=oppMoves.size();
                }

            }
        }
        //Move back

        game.spaceList[game.unitB].setEmpty(true);
        game.spaceList[propMove.buildSpace].unbuild();
        game.unitB=originalSpace;
        game.spaceList[game.unitB].setEmpty(false);

    }

    return canWin;
}

vector<Ply> computer::generateMoves(board &game){
    vector<Ply>moves;
    for(int i=0;i<game.spaceList[game.unitX].getNumAdj();i++)
    {
        if(game.spaceList[game.spaceList[game.unitX].adjList[i]].isEmpty()&&(game.spaceList[game.spaceList[game.unitX].adjList[i]].getHeight()<=1+game.spaceList[game.unitX].getHeight()))
        {


            //Next step
            for(int j=0;j<game.spaceList[game.spaceList[game.unitX].adjList[i]].getNumAdj();j++)
            {
                if(game.spaceList[game.spaceList[game.spaceList[game.unitX].adjList[i]].adjList[j]].isEmpty())
                {
                    moves.push_back(Ply(game.spaceList[game.unitX].adjList[i],game.spaceList[game.spaceList[game.unitX].adjList[i]].adjList[j],game.spaceList[game.spaceList[game.unitX].adjList[i]].getHeight()-game.spaceList[game.unitX].getHeight(),'X'));
                }
            }
        }
    }
    for(int i=0;i<game.spaceList[game.unitY].getNumAdj();i++)
    {
        if(game.spaceList[game.spaceList[game.unitY].adjList[i]].isEmpty()&&(game.spaceList[game.spaceList[game.unitY].adjList[i]].getHeight()<=1+game.spaceList[game.unitY].getHeight()))
        {



            //Next step
            for(int j=0;j<game.spaceList[game.spaceList[game.unitY].adjList[i]].getNumAdj();j++)
            {
                if(game.spaceList[game.spaceList[game.spaceList[game.unitY].adjList[i]].adjList[j]].isEmpty())
                {
                    moves.push_back(Ply(game.spaceList[game.unitY].adjList[i],game.spaceList[game.spaceList[game.unitY].adjList[i]].adjList[j],game.spaceList[game.spaceList[game.unitY].adjList[i]].getHeight()-game.spaceList[game.unitY].getHeight(),'Y'));
                }
            }
        }
    }
    return moves;
}
vector<Ply> computer::generateOppMoves(board &game){
    vector<Ply> moves;
    for(int i=0;i<game.spaceList[game.unitA].getNumAdj();i++)
    {
        if(game.spaceList[game.spaceList[game.unitA].adjList[i]].isEmpty()&&(game.spaceList[game.spaceList[game.unitA].adjList[i]].getHeight()<=1+game.spaceList[game.unitA].getHeight()))
        {


            //Next step
            for(int j=0;j<game.spaceList[game.spaceList[game.unitA].adjList[i]].getNumAdj();j++)
            {
                if(game.spaceList[game.spaceList[game.spaceList[game.unitA].adjList[i]].adjList[j]].isEmpty())
                {
                    moves.push_back(Ply(game.spaceList[game.unitA].adjList[i],game.spaceList[game.spaceList[game.unitA].adjList[i]].adjList[j],game.spaceList[game.spaceList[game.unitA].adjList[i]].getHeight()-game.spaceList[game.unitA].getHeight(),'A'));
                }
            }
        }
    }
    for(int i=0;i<game.spaceList[game.unitB].getNumAdj();i++)
    {
        if(game.spaceList[game.spaceList[game.unitB].adjList[i]].isEmpty()&&(game.spaceList[game.spaceList[game.unitB].adjList[i]].getHeight()<=1+game.spaceList[game.unitB].getHeight()))
        {

            //next
            //Next step
            for(int j=0;j<game.spaceList[game.spaceList[game.unitB].adjList[i]].getNumAdj();j++)
            {
                if(game.spaceList[game.spaceList[game.spaceList[game.unitB].adjList[i]].adjList[j]].isEmpty())
                {
                    moves.push_back(Ply(game.spaceList[game.unitB].adjList[i],game.spaceList[game.spaceList[game.unitB].adjList[i]].adjList[j],game.spaceList[game.spaceList[game.unitB].adjList[i]].getHeight()-game.spaceList[game.unitB].getHeight(),'B'));
                }
            }
        }
    }
    return moves;
}


Ply computer::actualSelect(vector<Ply>moves){
    vector<Ply> bestMoves;

    int val=-10000;
    for(int i=0;i<moves.size();i++)
    {

        if(moves[i].value>val)
        {
            bestMoves.clear();
            val=moves[i].value;
            bestMoves.push_back(moves[i]);
        }
        if(moves[i].value==val)
        {
            bestMoves.push_back(moves[i]);
        }
    }
    srand(time(0));
    return bestMoves[rand()%bestMoves.size()];
}
void computer::onePlyLookAhead(board &game, bool turn)
{
    vector<Ply>bestMoves;
    vector<Ply>possMoves=generateMoves(game);
    for(int i=0;i<possMoves.size();i++)
    {
        if(game.spaceList[possMoves[i].moveSpace].getHeight()==3)
        {
            bestMoves.push_back(possMoves[i]);
        }
    }

    selectedMove(game, turn, actualSelect(bestMoves));
}

void computer::twoPlyLookAhead(board &game, bool turn)
{
    int originalSpace;

    vector<Ply>bestMoves;
    vector<Ply>possMoves=generateMoves(game);
    for(int i=0;i<possMoves.size();i++)
    {
        if(game.spaceList[possMoves[i].moveSpace].getHeight()==3)
        {
            bestMoves.push_back(possMoves[i]);
        }
    }
    if(bestMoves.empty())
    {

        for(int i=0;i<possMoves.size();i++)
        {
            bestMoves.push_back(possMoves[i]);
            if(possMoves[i].unit=='X')
            {
                originalSpace=game.unitX;
                game.spaceList[game.unitX].setEmpty(true);
                game.unitX=possMoves[i].moveSpace;
                game.spaceList[possMoves[i].buildSpace].build();
                game.spaceList[game.unitX].setEmpty(false);
                vector<Ply>oppMoves=generateOppMoves(game);
                for(int j=0;j<oppMoves.size();j++)
                {
                    if(game.spaceList[oppMoves[j].moveSpace].getHeight()==3)
                    {
                        bestMoves.erase(bestMoves.end());
                        j=oppMoves.size();
                    }
                }
                game.spaceList[game.unitX].setEmpty(true);
                game.spaceList[possMoves[i].buildSpace].unbuild();
                game.unitX=originalSpace;
                game.spaceList[game.unitX].setEmpty(false);
            }
            if(possMoves[i].unit=='Y')
            {
                originalSpace=game.unitY;
                game.spaceList[game.unitY].setEmpty(true);
                game.unitY=possMoves[i].moveSpace;
                game.spaceList[possMoves[i].buildSpace].build();
                game.spaceList[game.unitY].setEmpty(false);
                vector<Ply>oppMoves=generateOppMoves(game);
                for(int j=0;j<oppMoves.size();j++)
                {
                    if(game.spaceList[oppMoves[j].moveSpace].getHeight()==3)
                    {
                        bestMoves.erase(bestMoves.end());
                        j=oppMoves.size();
                    }
                }
                game.spaceList[game.unitY].setEmpty(true);
                game.spaceList[possMoves[i].buildSpace].unbuild();
                game.unitY=originalSpace;
                game.spaceList[game.unitY].setEmpty(false);
            }
        }


    }

    selectedMove(game, turn, actualSelect(bestMoves));
}
void computer::threePlyLookAhead(board &game, bool turn)
{
    int originalSpace;
    vector<Ply>betterMoves;
    vector<Ply>bestMoves;
    vector<Ply>possMoves=generateMoves(game);
    vector<Ply>possMoves2;
    for(int i=0;i<possMoves.size();i++)
    {
        if(game.spaceList[possMoves[i].moveSpace].getHeight()==3)
        {
            bestMoves.push_back(possMoves[i]);
        }
    }
    if(bestMoves.empty())
    {

        for(int i=0;i<possMoves.size();i++)
        {
            bestMoves.push_back(possMoves[i]);
            if(possMoves[i].unit=='X')
            {
                originalSpace=game.unitX;
                game.spaceList[game.unitX].setEmpty(true);
                game.unitX=possMoves[i].moveSpace;
                game.spaceList[possMoves[i].buildSpace].build();
                game.spaceList[game.unitX].setEmpty(false);
                vector<Ply>oppMoves=generateOppMoves(game);

                for(int j=0;j<oppMoves.size();j++)
                {
                    if(game.spaceList[oppMoves[j].moveSpace].getHeight()==3)
                    {
                        bestMoves.erase(bestMoves.end());
                        j=oppMoves.size();
                    }
                }

                game.spaceList[game.unitX].setEmpty(true);
                game.spaceList[possMoves[i].buildSpace].unbuild();
                game.unitX=originalSpace;
                game.spaceList[game.unitX].setEmpty(false);
            }
            if(possMoves[i].unit=='Y')
            {
                originalSpace=game.unitY;
                game.spaceList[game.unitY].setEmpty(true);
                game.unitY=possMoves[i].moveSpace;
                game.spaceList[possMoves[i].buildSpace].build();
                game.spaceList[game.unitY].setEmpty(false);
                vector<Ply>oppMoves=generateOppMoves(game);
                for(int j=0;j<oppMoves.size();j++)
                {
                    if(game.spaceList[oppMoves[j].moveSpace].getHeight()==3)
                    {
                        bestMoves.erase(bestMoves.end());
                        j=oppMoves.size();
                    }
                }

                game.spaceList[game.unitY].setEmpty(true);
                game.spaceList[possMoves[i].buildSpace].unbuild();
                game.unitY=originalSpace;
                game.spaceList[game.unitY].setEmpty(false);
            }
        }
        for(int i=0;i<bestMoves.size();i++)
        {
            if(bestMoves[i].unit=='X')
            {
                originalSpace=game.unitX;
                game.spaceList[game.unitX].setEmpty(true);
                game.unitX=bestMoves[i].moveSpace;
                game.spaceList[bestMoves[i].buildSpace].build();
                game.spaceList[game.unitX].setEmpty(false);
                possMoves2=generateMoves(game);

                for(int j=0; j<possMoves2.size();j++)
                {
                    if(game.spaceList[possMoves2[j].moveSpace].getHeight()==3)
                    {
                        betterMoves.push_back(bestMoves[i]);
                    }
                }

                game.spaceList[game.unitX].setEmpty(true);
                game.spaceList[bestMoves[i].buildSpace].unbuild();
                game.unitX=originalSpace;
                game.spaceList[game.unitX].setEmpty(false);
            }
            if(bestMoves[i].unit=='Y')
            {
                originalSpace=game.unitY;
                game.spaceList[game.unitY].setEmpty(true);
                game.unitY=bestMoves[i].moveSpace;
                game.spaceList[bestMoves[i].buildSpace].build();
                game.spaceList[game.unitY].setEmpty(false);
                possMoves2=generateMoves(game);

                for(int j=0; j<possMoves2.size();j++)
                {
                    if(game.spaceList[possMoves2[j].moveSpace].getHeight()==3)
                    {
                        betterMoves.push_back(bestMoves[i]);
                    }
                }

                game.spaceList[game.unitY].setEmpty(true);
                game.spaceList[bestMoves[i].buildSpace].unbuild();
                game.unitY=originalSpace;
                game.spaceList[game.unitY].setEmpty(false);
            }
        }



    }
    if(!betterMoves.empty()){
        selectedMove(game, turn, actualSelect(betterMoves));
    }
    else{
        selectedMove(game, turn, actualSelect(bestMoves));
    }
}
void computer::fourPlyLookAhead(board &game, bool turn)
{
    int originalSpace;
    vector<Ply>betterMoves;
    vector<Ply>bestMoves;
    vector<Ply>possMoves=generateMoves(game);
    vector<Ply>possMoves2;
    for(int i=0;i<possMoves.size();i++)
    {
        if(game.spaceList[possMoves[i].moveSpace].getHeight()==3)
        {
            bestMoves.push_back(possMoves[i]);
        }
    }
    if(bestMoves.empty())
    {

        for(int i=0;i<possMoves.size();i++)
        {
            bestMoves.push_back(possMoves[i]);
            if(possMoves[i].unit=='X')
            {
                originalSpace=game.unitX;
                game.spaceList[game.unitX].setEmpty(true);
                game.unitX=possMoves[i].moveSpace;
                game.spaceList[possMoves[i].buildSpace].build();
                game.spaceList[game.unitX].setEmpty(false);
                vector<Ply>oppMoves=generateOppMoves(game);

                for(int j=0;j<oppMoves.size();j++)
                {
                    if(game.spaceList[oppMoves[j].moveSpace].getHeight()==3)
                    {
                        bestMoves.erase(bestMoves.end());
                        j=oppMoves.size();
                    }
                }

                game.spaceList[game.unitX].setEmpty(true);
                game.spaceList[possMoves[i].buildSpace].unbuild();
                game.unitX=originalSpace;
                game.spaceList[game.unitX].setEmpty(false);
            }
            if(possMoves[i].unit=='Y')
            {
                originalSpace=game.unitY;
                game.spaceList[game.unitY].setEmpty(true);
                game.unitY=possMoves[i].moveSpace;
                game.spaceList[possMoves[i].buildSpace].build();
                game.spaceList[game.unitY].setEmpty(false);
                vector<Ply>oppMoves=generateOppMoves(game);
                for(int j=0;j<oppMoves.size();j++)
                {
                    if(game.spaceList[oppMoves[j].moveSpace].getHeight()==3)
                    {
                        bestMoves.erase(bestMoves.end());
                        j=oppMoves.size();
                    }
                }

                game.spaceList[game.unitY].setEmpty(true);
                game.spaceList[possMoves[i].buildSpace].unbuild();
                game.unitY=originalSpace;
                game.spaceList[game.unitY].setEmpty(false);
            }
        }
        for(int i=0;i<bestMoves.size();i++)
        {
            if(bestMoves[i].unit=='X')
            {
                originalSpace=game.unitX;
                game.spaceList[game.unitX].setEmpty(true);
                game.unitX=bestMoves[i].moveSpace;
                game.spaceList[bestMoves[i].buildSpace].build();
                game.spaceList[game.unitX].setEmpty(false);
                possMoves2=generateMoves(game);

                for(int j=0; j<possMoves2.size();j++)
                {
                    if(game.spaceList[possMoves2[j].moveSpace].getHeight()==3)
                    {
                        betterMoves.push_back(bestMoves[i]);
                    }
                }

                game.spaceList[game.unitX].setEmpty(true);
                game.spaceList[bestMoves[i].buildSpace].unbuild();
                game.unitX=originalSpace;
                game.spaceList[game.unitX].setEmpty(false);
            }
            if(bestMoves[i].unit=='Y')
            {
                originalSpace=game.unitY;
                game.spaceList[game.unitY].setEmpty(true);
                game.unitY=bestMoves[i].moveSpace;
                game.spaceList[bestMoves[i].buildSpace].build();
                game.spaceList[game.unitY].setEmpty(false);
                possMoves2=generateMoves(game);

                for(int j=0; j<possMoves2.size();j++)
                {
                    if(game.spaceList[possMoves2[j].moveSpace].getHeight()==3)
                    {
                        betterMoves.push_back(bestMoves[i]);
                    }
                }

                game.spaceList[game.unitY].setEmpty(true);
                game.spaceList[bestMoves[i].buildSpace].unbuild();
                game.unitY=originalSpace;
                game.spaceList[game.unitY].setEmpty(false);
            }
        }



    }
    if(!betterMoves.empty()){
        selectedMove(game, turn, actualSelect(betterMoves));
    }
    else{
        selectedMove(game, turn, actualSelect(bestMoves));
    }
}