//
// Created by gremo on 2/13/20.
//

#include "Tree.h"
#include<stdlib.h>
using namespace std;
Tree::Tree(const board &b1, bool turn,computer player):maker(player.compAbility,player.dH,player.cH,player.hH)
{
    headPtr=new Node(b1, turn,maker);

    levels=1;
}

Tree::~Tree()
{
    delete headPtr;
}

void Tree::addLevel(Node* cursor, bool turn)
{
    if(!cursor->next.empty())
    {
        for(int i=0;i<cursor->next.size();i++)
        {
            addLevel(cursor->next[i],turn);
        }
    }
    else
    {

        if(cursor->moveMade.unit=='A' || cursor->moveMade.unit=='B')
        {
            vector<Ply>possMoves=cursor->generateXYMoves();
            Node* nextNode;
            for(int j=0;j<possMoves.size();j++)
            {
                nextNode=new Node(cursor->currentBoard,possMoves[j],turn,maker);
                cursor->next.push_back(nextNode);
            }
        }
        if(cursor->moveMade.unit=='X' || cursor->moveMade.unit=='Y')
        {
            vector<Ply>possMoves=cursor->generateABMoves();
            Node* nextNode;
            for(int j=0;j<possMoves.size();j++)
            {
                nextNode=new Node(cursor->currentBoard,possMoves[j],turn,maker);
                cursor->next.push_back(nextNode);
            }
        }
    }
    levels +=1;
}
void Tree::addLevels(int numLookAhead, bool turn)
{
    for(int i=0;i<numLookAhead;i++)
    {
        addLevel(headPtr, turn);
    }
}
Ply Tree::findBestMove(int depth)
{
    int best=-200000;
    vector<Ply>bestMoves;
    headPtr->value=maxMove(headPtr,depth,2000000,-2000000);
    for(int i=0;i<headPtr->next.size();i++)
    {
        if(headPtr->next[i]->value>best)
        {
            bestMoves.clear();
            bestMoves.push_back(headPtr->next[i]->moveMade);
            best=headPtr->next[i]->value;
        }
        else if(headPtr->next[i]->value==best)
        {
            bestMoves.push_back(headPtr->next[i]->moveMade);
        }

    }
    srand(time(0));
    return bestMoves[rand()%bestMoves.size()];
}
int Tree::minMove(Node* cursor,int depth,int alpha, int beta)
{
    //int minM=beta;
    int minM=200000;
    for(int i=0;i<cursor->next.size();i++)
    {
        if(abs(cursor->next[i]->value)!=10000&&depth-1>0)
        {
            cursor->next[i]->value=maxMove(cursor->next[i],depth-1,alpha,minM);
        }
        if(cursor->next[i]->value<minM)
        {
            minM=cursor->next[i]->value;
        }
        if(minM<alpha)
        {
            //return alpha;
        }
    }
    return minM;
}
int Tree::maxMove(Node* cursor,int depth, int alpha, int beta)
{
    //int maxM=alpha;
    int maxM=-200000;
    for(int i=0;i<cursor->next.size();i++)
    {
        if(abs(cursor->next[i]->value)!=10000&&depth-1>0)
        {
            cursor->next[i]->value=minMove(cursor->next[i],depth-1,maxM,beta);
        }
        if(cursor->next[i]->value>maxM)
        {
            maxM=cursor->next[i]->value;

        }
        if (maxM > beta)
        {
            //return beta;
        }
    }
    return maxM;
}