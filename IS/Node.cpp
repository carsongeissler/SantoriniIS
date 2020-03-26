//
// Created by gremo on 2/13/20.
//

#include "Node.h"


Node::Node(const board& priorBoard, bool turn, computer player):currentBoard(priorBoard),moveMade(0,0,0,chooseChar(turn)),maker(player.compAbility,player.dH,player.cH,player.hH)
{
    value=0;
    currentBoard.turn = !turn;



}
Node::Node(const board& priorBoard,Ply move, bool turn, computer player):moveMade(move.moveSpace,move.buildSpace,move.value,move.unit),currentBoard(priorBoard),maker(player.compAbility,player.dH,player.cH,player.hH)
{

    currentBoard.turn = !priorBoard.turn;
    if(moveMade.unit=='A')
    {
        currentBoard.spaceList[currentBoard.unitA].setEmpty(true);
        currentBoard.unitA=moveMade.moveSpace;
        currentBoard.spaceList[moveMade.buildSpace].build();
        currentBoard.spaceList[currentBoard.unitA].setEmpty(false);
    }
    if(moveMade.unit=='B')
    {
        currentBoard.spaceList[currentBoard.unitB].setEmpty(true);
        currentBoard.unitB=moveMade.moveSpace;
        currentBoard.spaceList[moveMade.buildSpace].build();
        currentBoard.spaceList[currentBoard.unitB].setEmpty(false);
    }
    if(moveMade.unit=='X')
    {
        currentBoard.spaceList[currentBoard.unitX].setEmpty(true);
        currentBoard.unitX=moveMade.moveSpace;
        currentBoard.spaceList[moveMade.buildSpace].build();
        currentBoard.spaceList[currentBoard.unitX].setEmpty(false);
    }
    if(moveMade.unit=='Y')
    {
        currentBoard.spaceList[currentBoard.unitY].setEmpty(true);
        currentBoard.unitY=moveMade.moveSpace;
        currentBoard.spaceList[moveMade.buildSpace].build();
        currentBoard.spaceList[currentBoard.unitY].setEmpty(false);
    }
    if(currentBoard.turn==turn)
    {
        if(currentBoard.win()){
            value=10000;
        }
        else{
            value=(maker.dH*currentBoard.distH()+maker.cH*currentBoard.centerH()+maker.hH*currentBoard.heightH());
        }

    }
    else if(currentBoard.turn!=turn)
    {
        if(currentBoard.win()){
            value=-10000;
        }
        else{
            value=-(maker.dH*currentBoard.distH()+maker.cH*currentBoard.centerH()+maker.hH*currentBoard.heightH());
        }
    }
    else
    {
        value=0;
    }
}

Node::~Node()
{
    for (int i=next.size()-1; i>=0;i--)
    {
        delete next[i];
    }
    next.clear();

};

int Node::getValue()
{
    return value;
}
void Node::setValue(int newValue)
{
    value=newValue;
}
vector<Ply> Node::generateXYMoves()
{
    vector<Ply> moves;
    currentBoard.spaceList[currentBoard.unitX].setEmpty(true);
    for(int i=0;i<currentBoard.spaceList[currentBoard.unitX].getNumAdj();i++)
    {
        if(currentBoard.spaceList[currentBoard.spaceList[currentBoard.unitX].adjList[i]].isEmpty()&&(currentBoard.spaceList[currentBoard.spaceList[currentBoard.unitX].adjList[i]].getHeight()<=1+currentBoard.spaceList[currentBoard.unitX].getHeight()))
        {


            //Next step
            for(int j=0;j<currentBoard.spaceList[currentBoard.spaceList[currentBoard.unitX].adjList[i]].getNumAdj();j++)
            {
                if(currentBoard.spaceList[currentBoard.spaceList[currentBoard.spaceList[currentBoard.unitX].adjList[i]].adjList[j]].isEmpty())
                {
                    moves.push_back(Ply(currentBoard.spaceList[currentBoard.unitX].adjList[i],currentBoard.spaceList[currentBoard.spaceList[currentBoard.unitX].adjList[i]].adjList[j],currentBoard.spaceList[currentBoard.spaceList[currentBoard.unitX].adjList[i]].getHeight()-currentBoard.spaceList[currentBoard.unitX].getHeight(),'X'));
                }
            }
        }
    }
    currentBoard.spaceList[currentBoard.unitX].setEmpty(false);
    currentBoard.spaceList[currentBoard.unitY].setEmpty(true);
    for(int i=0;i<currentBoard.spaceList[currentBoard.unitY].getNumAdj();i++)
    {
        if(currentBoard.spaceList[currentBoard.spaceList[currentBoard.unitY].adjList[i]].isEmpty()&&(currentBoard.spaceList[currentBoard.spaceList[currentBoard.unitY].adjList[i]].getHeight()<=1+currentBoard.spaceList[currentBoard.unitY].getHeight()))
        {


            //Next step
            for(int j=0;j<currentBoard.spaceList[currentBoard.spaceList[currentBoard.unitY].adjList[i]].getNumAdj();j++)
            {
                if(currentBoard.spaceList[currentBoard.spaceList[currentBoard.spaceList[currentBoard.unitY].adjList[i]].adjList[j]].isEmpty())
                {
                    moves.push_back(Ply(currentBoard.spaceList[currentBoard.unitY].adjList[i],currentBoard.spaceList[currentBoard.spaceList[currentBoard.unitY].adjList[i]].adjList[j],currentBoard.spaceList[currentBoard.spaceList[currentBoard.unitY].adjList[i]].getHeight()-currentBoard.spaceList[currentBoard.unitY].getHeight(),'Y'));
                }
            }
        }
    }
    currentBoard.spaceList[currentBoard.unitY].setEmpty(false);
    return moves;
}
vector<Ply> Node::generateABMoves()
{
    vector<Ply> moves;
    currentBoard.spaceList[currentBoard.unitA].setEmpty(true);
    for(int i=0;i<currentBoard.spaceList[currentBoard.unitA].getNumAdj();i++)
    {
        if(currentBoard.spaceList[currentBoard.spaceList[currentBoard.unitA].adjList[i]].isEmpty()&&(currentBoard.spaceList[currentBoard.spaceList[currentBoard.unitA].adjList[i]].getHeight()<=1+currentBoard.spaceList[currentBoard.unitA].getHeight()))
        {


            //Next step
            for(int j=0;j<currentBoard.spaceList[currentBoard.spaceList[currentBoard.unitA].adjList[i]].getNumAdj();j++)
            {
                if(currentBoard.spaceList[currentBoard.spaceList[currentBoard.spaceList[currentBoard.unitA].adjList[i]].adjList[j]].isEmpty())
                {
                    moves.push_back(Ply(currentBoard.spaceList[currentBoard.unitA].adjList[i],currentBoard.spaceList[currentBoard.spaceList[currentBoard.unitA].adjList[i]].adjList[j],currentBoard.spaceList[currentBoard.spaceList[currentBoard.unitA].adjList[i]].getHeight()-currentBoard.spaceList[currentBoard.unitA].getHeight(),'A'));
                }
            }
        }
    }
    currentBoard.spaceList[currentBoard.unitA].setEmpty(false);
    currentBoard.spaceList[currentBoard.unitB].setEmpty(true);
    for(int i=0;i<currentBoard.spaceList[currentBoard.unitB].getNumAdj();i++)
    {
        if(currentBoard.spaceList[currentBoard.spaceList[currentBoard.unitB].adjList[i]].isEmpty()&&(currentBoard.spaceList[currentBoard.spaceList[currentBoard.unitB].adjList[i]].getHeight()<=1+currentBoard.spaceList[currentBoard.unitB].getHeight()))
        {


            //Next step
            for(int j=0;j<currentBoard.spaceList[currentBoard.spaceList[currentBoard.unitB].adjList[i]].getNumAdj();j++)
            {
                if(currentBoard.spaceList[currentBoard.spaceList[currentBoard.spaceList[currentBoard.unitB].adjList[i]].adjList[j]].isEmpty())
                {
                    moves.push_back(Ply(currentBoard.spaceList[currentBoard.unitB].adjList[i],currentBoard.spaceList[currentBoard.spaceList[currentBoard.unitB].adjList[i]].adjList[j],currentBoard.spaceList[currentBoard.spaceList[currentBoard.unitB].adjList[i]].getHeight()-currentBoard.spaceList[currentBoard.unitB].getHeight(),'B'));
                }
            }
        }
    }
    currentBoard.spaceList[currentBoard.unitB].setEmpty(false);
    return moves;
}

/*
template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) :
        item(anItem), next(nextNodePtr)
{
} // end constructor

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
    item = anItem;
} // end setItem

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
    next = nextNodePtr;
} // end setNext

template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
    return item;
} // end getItem

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
    return next;
} // end getNext
*/
char Node::chooseChar(bool t)
{
    if(t)
    {
        return 'X';
    }
    else{
        return 'A';
    }
}