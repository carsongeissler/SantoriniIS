//
// Created by gremo on 2/13/20.
//

#include "ply.h"

Ply::Ply(int move, int build, int good, char which) {
    moveSpace=move;
    buildSpace=build;
    value=good;
    unit=which;
}