//
// Created by gremo on 2/13/20.
//

#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H

#include "board.h"
#include "ply.h"
#include <vector>
#include "playerComputer.h"
using namespace std;
class Node

{
private:
    // Board after move made
    //Move made to reach current board

    // vector of pointers to next nodes, all possible next board states

public:
    board currentBoard;
    Ply moveMade;
    vector<Node*> next;
    int value;
    computer maker;
    Node(const board& priorBoard, bool turn, computer player);
    Node(const board& priorBoard,Ply move, bool turn, computer player);
    int getValue();

    void setValue(int newValue);
    ~Node();
    vector<Ply> generateABMoves();
    vector<Ply> generateXYMoves();
    char chooseChar(bool t);
    /*
    void setItem(const ItemType& anItem);
    void setNext(Node<ItemType>* nextNodePtr);
    ItemType getItem() const ;
    Node<ItemType>* getNext() const ;
    */

}; // end Node




#endif //UNTITLED_NODE_H
