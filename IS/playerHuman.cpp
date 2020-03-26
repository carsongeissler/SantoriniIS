//
// Created by gremo on 2/13/20.
//

#include "playerHuman.h"
#include <iostream>
using namespace std;
human::human() {
}
void human::selectStart(board &game, int player) {
    if(player==1) {
        int firstUnit;
        int secondUnit;
        cout << "Select starting position for unit A: ";
        cin >> firstUnit;
        game.unitA = firstUnit;
        game.spaceList[firstUnit].setEmpty(false);
        while (game.unitB == -1) {
            cout << "Select starting position for unit B: ";
            cin >> secondUnit;
            if (game.spaceList[secondUnit].isEmpty()) {
                game.unitB = secondUnit;
            }

        }
        game.spaceList[secondUnit].setEmpty(false);
    }
    if(player==2) {
        int firstUnit;
        int secondUnit;
        while(game.unitX==-1)
        {
            cout << "Select starting position for unit X: ";
            cin >> firstUnit;
            if(game.spaceList[firstUnit].isEmpty()){
                game.unitX=firstUnit;
            }
        }
        game.spaceList[firstUnit].setEmpty(false);
        while(game.unitY==-1)
        {
            cout << "Select starting position for unit Y: ";
            cin >> secondUnit;
            if(game.spaceList[secondUnit].isEmpty()){
                game.unitY=secondUnit;
            }
        }
        game.spaceList[secondUnit].setEmpty(false);
    }

}
bool human::move(board &game) {
    char movingUnit;
    int moveSpace;
    int buildSpace;
    bool notMoved = true;
    if(game.turn){
        cout<<"Player 1 turn."<<endl;
    }
    else{
        cout<<"Player 2 turn."<<endl;
    }
    while (notMoved) {
        cout<<"Choose a unit to move."<< endl;
        cin >> movingUnit;
        if((movingUnit=='A'&&game.turn)) {
            while (notMoved) {
                cout<<"Select a space to move to."<<endl;
                cin>>moveSpace;
                if ((game.spaceList[game.unitA].isAdj(moveSpace))&&game.spaceList[moveSpace].isEmpty()&&((game.spaceList[game.unitA].getHeight()) + 1>=game.spaceList[moveSpace].getHeight())){
                    game.spaceList[game.unitA].setEmpty(true);
                    game.unitA=moveSpace;
                    game.spaceList[game.unitA].setEmpty(false);

                    cout<<"/////////////////////////////////"<<endl<<endl;
                    game.printBoard();
                    while (notMoved) {


                        cout<<"Select a space to build on."<<endl;
                        cin>>buildSpace;
                        if (game.spaceList[game.unitA].isAdj(buildSpace)&&game.spaceList[buildSpace].build()){
                            if(game.win())
                            {
                                game.notOver=false;
                            }
                            notMoved=false;
                            game.turn=!(game.turn);
                        }
                        else {
                            cout<<"Invalid build space. Ensure the space is adjacent to the worker, is not of max height, and does not contain another worker."<<endl;
                        }
                    }
                }
                else{
                    cout<<"Invalid move. Make sure the space is adjacent and has height no more than 1 greater than current height."<<endl;
                }
            }

        }
        else if (movingUnit=='B'&&game.turn) {
            while (notMoved) {
                cout<<"Select a space to move to."<<endl;
                cin>>moveSpace;
                if ((game.spaceList[game.unitB].isAdj(moveSpace))&&game.spaceList[moveSpace].isEmpty()&&((game.spaceList[game.unitB].getHeight()) + 1>=game.spaceList[moveSpace].getHeight())){
                    game.spaceList[game.unitB].setEmpty(true);
                    game.unitB=moveSpace;
                    game.spaceList[game.unitB].setEmpty(false);

                    cout<<"/////////////////////////////////"<<endl<<endl;
                    game.printBoard();
                    while (notMoved) {


                        cout<<"Select a space to build on."<<endl;
                        cin>>buildSpace;
                        if (game.spaceList[game.unitB].isAdj(buildSpace)&&game.spaceList[buildSpace].build()){
                            if(game.win())
                            {
                                game.notOver=false;
                            }
                            notMoved=false;
                            game.turn=!(game.turn);
                        }
                        else {
                            cout<<"Invalid build space. Ensure the space is adjacent to the worker, is not of max height, and does not contain another worker."<<endl;
                        }
                    }
                }
                else{
                    cout<<"Invalid move. Make sure the space is adjacent and has height no more than 1 greater than current height."<<endl;
                }
            }
        }
        else if (movingUnit=='X'&&(!game.turn)) {
            while (notMoved) {
                cout<<"Select a space to move to."<<endl;
                cin>>moveSpace;
                if ((game.spaceList[game.unitX].isAdj(moveSpace))&&game.spaceList[moveSpace].isEmpty()&&((game.spaceList[game.unitX].getHeight()) + 1>=game.spaceList[moveSpace].getHeight())){
                    game.spaceList[game.unitX].setEmpty(true);
                    game.unitX=moveSpace;
                    game.spaceList[game.unitX].setEmpty(false);

                    cout<<"/////////////////////////////////"<<endl<<endl;
                    game.printBoard();
                    while (notMoved) {


                        cout<<"Select a space to build on."<<endl;
                        cin>>buildSpace;
                        if (game.spaceList[game.unitX].isAdj(buildSpace)&&game.spaceList[buildSpace].build()){
                            if(game.win())
                            {
                                game.notOver=false;
                            }
                            notMoved=false;
                            game.turn=!(game.turn);
                        }
                        else {
                            cout<<"Invalid build space. Ensure the space is adjacent to the worker, is not of max height, and does not contain another worker."<<endl;
                        }
                    }
                }
                else{
                    cout<<"Invalid move. Make sure the space is adjacent and has height no more than 1 greater than current height."<<endl;
                }
            }
        }
        else if (movingUnit=='Y'&&(!game.turn)) {
            while (notMoved) {
                cout<<"Select a space to move to."<<endl;
                cin>>moveSpace;
                if ((game.spaceList[game.unitY].isAdj(moveSpace))&&game.spaceList[moveSpace].isEmpty()&&((game.spaceList[game.unitY].getHeight()) + 1>=game.spaceList[moveSpace].getHeight())){
                    game.spaceList[game.unitY].setEmpty(true);
                    game.unitY=moveSpace;
                    game.spaceList[game.unitY].setEmpty(false);

                    cout<<"/////////////////////////////////"<<endl<<endl;
                    game.printBoard();
                    while (notMoved) {


                        cout<<"Select a space to build on."<<endl;
                        cin>>buildSpace;
                        if (game.spaceList[game.unitY].isAdj(buildSpace)&&game.spaceList[buildSpace].build()){
                            if(game.win())
                            {
                                game.notOver=false;
                            }
                            notMoved=false;
                            game.turn=!(game.turn);
                        }
                        else {
                            cout<<"Invalid build space. Ensure the space is adjacent to the worker, is not of max height, and does not contain another worker."<<endl;
                        }
                    }
                }
                else{
                    cout<<"Invalid move. Make sure the space is adjacent and has height no more than 1 greater than current height."<<endl;
                }
            }
        }
        else{
            cout<<"Invalid unit choice. Select 'A' or 'B' if player 1, and 'X' or 'Y' if player 2."<<endl;
        }
    }
    game.printBoard();
    return !notMoved;
    cout<<game.unitX<<endl;
}