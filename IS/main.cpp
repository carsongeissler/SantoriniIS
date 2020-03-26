#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#include "board.h"
#include "playerHuman.h"
#include "playerComputer.h"
#include "Tree.h"

int playGame(computer p1, computer p2){
    board game(4,1,3);

    p1.selectStart(game);
    p2.selectStart(game);
    game.printBoard();
    while (game.notOver) {
        p1.treeMove(game, game.turn, p1.compAbility);
        //p0.move(game);
        if(!(game.notOver)){
            cout<< "Player 1 wins!";
            return 1;
        }
        else{


            //p2.selectedMove(game, game.turn, p2.selectBestMove(game));
            //p2.threePlyLookAhead(game, game.turn);
            p2.treeMove(game, game.turn, p2.compAbility);
        }
    }
    if (game.turn) {
        cout<< "Player 2 wins!";
        return 0;
    }

}
int play10(computer p1, computer p2){
    int sum=0;
    for(int i=0;i<10;i++){
        sum+=playGame(p1,p2);
    }
    return sum;
}

int main() {
    cout<<"Santorini Game!!!"<<endl;
/*
    int bestD=0;
    int bestC=0;
    int bestH=0;
    computer p1(3);
    computer p2(3);
    if(playGame(p1,p2))
    {
        bestD=p1.dH;
        bestC=p1.cH;
        bestH=p1.hH;
    }
    else {
        bestD=p2.dH;
        bestC=p2.cH;
        bestH=p2.hH;
    }
    cout<< endl<< bestD <<" "<<bestC<<" "<<bestH;
     */

    human p0;
    cout<<"Choose number of plys for computer to look ahead: "<<endl;
    int ability;
    cin>>ability;
    computer p1(ability,20,30,50);
    computer p2(ability,0,25,75);
    cout<<"Choose a maximum height for the game: "<<endl;
    int max;
    cin>>max;
    int config;
    cout<<"Choose a winning height for the game: "<<endl;
    int winH;
    cin>>winH;
    cout<<"Choose a configuration: "<<endl;
    cin>>config;
    board game(max,config,winH);

    p0.selectStart(game,1);
    p0.selectStart(game,2);
    game.printBoard();
    while (game.notOver) {
        //p1.treeMove(game, game.turn, ability);
        p0.move(game);
        if(!(game.notOver)){
            cout<< "Player 1 wins!";
        }
        else{


            //p2.selectedMove(game, game.turn, p2.selectBestMove(game));
            //p2.threePlyLookAhead(game, game.turn);
            p2.treeMove(game, game.turn, ability);
            //p0.move(game);
        }
    }
    if (game.turn) {
        cout<< "Player 2 wins!";
    }





    return 0;
}
