//
// Created by gremo on 2/13/20.
//

#ifndef UNTITLED_PLY_H
#define UNTITLED_PLY_H

#include <cstddef>
#include <stdio.h>
#include <iostream>

class Ply
{

public:
    int moveSpace;
    int buildSpace;
    char unit;
    int value;
    Ply(int move, int build, int good, char which);
};


#endif //UNTITLED_PLY_H
