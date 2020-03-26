//
// Created by gremo on 2/13/20.
//

#ifndef UNTITLED_TREE_H
#define UNTITLED_TREE_H

#include "board.h"
#include "ply.h"
#include "Node.h"
#include <vector>
using namespace std;
class Tree

{
private:
    Node* headPtr; // Board after move made
    int levels; //Move made to reach current board

    // vector of pointers to next nodes, all possible next board states

public:
    Tree(const board& b1, bool turn, computer player);
    computer maker;
    ~Tree();
    void addLevel(Node* cursor, bool turn);
    void addLevels(int numLookAhead, bool turn);
    Ply findBestMove(int depth);
    int minMove(Node* cursor,int depth, int alpha, int beta);
    int maxMove(Node* cursor,int depth, int alpha, int beta);
    /*
    void setItem(const ItemType& anItem);
    void setNext(Node<ItemType>* nextNodePtr);
    ItemType getItem() const ;
    Node<ItemType>* getNext() const ;
    */

}; // end Node


#endif //UNTITLED_TREE_H
