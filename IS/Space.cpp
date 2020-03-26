//
// Created by gremo on 2/13/20.
//

#include "Space.h"
Space::Space(int newId,int max) {
    height=0;
    maxHeight=max;
    open=true;
    id=newId;
    numAdj=0;
    adjList=new int[8];

}

int Space::getHeight()
{
    return height;
}

void Space::setHeight(int newHeight) {
    height=newHeight;
}
int Space::getMaxHeight()
{
    return maxHeight;
}

void Space::setMaxHeight(int newHeight) {
    maxHeight=newHeight;
}

int Space::getNumAdj()
{
    return numAdj;
}

void Space::setNumAdj(int newNumAdj)
{
    numAdj=newNumAdj;
}
bool Space::isEmpty()
{
    return open;
}

void Space::setEmpty(bool empty)
{
    open=empty;
}


Space::~Space()
{

}

bool Space::build()
{
    if (open) {
        height++;
        if (height==maxHeight) {
            setEmpty(false);
        }
        return true;
    }
    else {
        return false;
    }
}

bool Space::unbuild()
{
    height--;
    if(height<maxHeight) {
        setEmpty(true);
    }

    return true;
}

bool Space::addAdj(int addId)
{
    if (numAdj<8) {
        adjList[numAdj]=addId;
        numAdj++;
        return true;
    }
    else {
        return false;
    }
}
bool Space::isAdj(int spaceId)
{
    bool result=false;
    for (int i=0;i<numAdj;i++) {
        if(spaceId==adjList[i]) {
            result=true;
        }
    }
    return result;
}
