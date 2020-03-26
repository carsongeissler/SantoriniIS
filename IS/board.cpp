//
// Created by gremo on 2/13/20.
//

#include "board.h"

#include <iostream>
using namespace std;
board::board(int max, int config, int winH) {
    maxHeight=max;
    configuration=config;
    winHeight=winH;
    if(configuration==3) {
        spaceList = new Space[25]{Space(0, maxHeight), Space(1, maxHeight), Space(2, maxHeight), Space(3, maxHeight),
                                  Space(4, maxHeight), Space(5, maxHeight), Space(6, maxHeight), Space(7, maxHeight),
                                  Space(8, maxHeight), Space(9, maxHeight), Space(10, maxHeight), Space(11, maxHeight),
                                  Space(12, maxHeight), Space(13, maxHeight), Space(14, maxHeight),
                                  Space(15, maxHeight), Space(16, maxHeight), Space(17, maxHeight),
                                  Space(18, maxHeight), Space(19, maxHeight), Space(20, maxHeight),
                                  Space(21, maxHeight), Space(22, maxHeight), Space(23, maxHeight),
                                  Space(24, maxHeight)};

        for (int i = 0; i < 25; i++) {
            spaceList[i] = Space(i, maxHeight);
        }
        //adjaceane
        spaceList[0].addAdj(1);

        spaceList[1].addAdj(0);
        spaceList[1].addAdj(2);

        spaceList[2].addAdj(1);
        spaceList[2].addAdj(3);

        spaceList[3].addAdj(2);
    }
    if(configuration==1) {
        spaceList = new Space[25]{Space(0, maxHeight), Space(1, maxHeight), Space(2, maxHeight), Space(3, maxHeight),
                                  Space(4, maxHeight), Space(5, maxHeight), Space(6, maxHeight), Space(7, maxHeight),
                                  Space(8, maxHeight), Space(9, maxHeight), Space(10, maxHeight), Space(11, maxHeight),
                                  Space(12, maxHeight), Space(13, maxHeight), Space(14, maxHeight),
                                  Space(15, maxHeight), Space(16, maxHeight), Space(17, maxHeight),
                                  Space(18, maxHeight), Space(19, maxHeight), Space(20, maxHeight),
                                  Space(21, maxHeight), Space(22, maxHeight), Space(23, maxHeight),
                                  Space(24, maxHeight)};

        for (int i = 0; i < 25; i++) {
            spaceList[i] = Space(i, maxHeight);
        }
        spaceList[0].addAdj(1);
        spaceList[0].addAdj(5);
        spaceList[0].addAdj(6);
        spaceList[1].addAdj(0);
        spaceList[1].addAdj(2);
        spaceList[1].addAdj(5);
        spaceList[1].addAdj(6);
        spaceList[1].addAdj(7);
        spaceList[2].addAdj(6);
        spaceList[2].addAdj(7);
        spaceList[2].addAdj(1);
        spaceList[2].addAdj(3);
        spaceList[2].addAdj(8);
        spaceList[3].addAdj(2);
        spaceList[3].addAdj(8);
        spaceList[3].addAdj(4);
        spaceList[3].addAdj(9);
        spaceList[3].addAdj(7);
        spaceList[4].addAdj(3);
        spaceList[4].addAdj(8);
        spaceList[4].addAdj(9);
        spaceList[5].addAdj(0);
        spaceList[5].addAdj(1);
        spaceList[5].addAdj(6);
        spaceList[5].addAdj(11);
        spaceList[5].addAdj(10);
        spaceList[6].addAdj(0);
        spaceList[6].addAdj(1);
        spaceList[6].addAdj(2);
        spaceList[6].addAdj(5);
        spaceList[6].addAdj(7);
        spaceList[6].addAdj(10);
        spaceList[6].addAdj(11);
        spaceList[6].addAdj(12);
        spaceList[7].addAdj(1);
        spaceList[7].addAdj(2);
        spaceList[7].addAdj(3);
        spaceList[7].addAdj(6);
        spaceList[7].addAdj(8);
        spaceList[7].addAdj(13);
        spaceList[7].addAdj(11);
        spaceList[7].addAdj(12);
        spaceList[8].addAdj(2);
        spaceList[8].addAdj(3);
        spaceList[8].addAdj(4);
        spaceList[8].addAdj(9);
        spaceList[8].addAdj(7);
        spaceList[8].addAdj(13);
        spaceList[8].addAdj(14);
        spaceList[8].addAdj(12);
        spaceList[9].addAdj(3);
        spaceList[9].addAdj(4);
        spaceList[9].addAdj(8);
        spaceList[9].addAdj(13);
        spaceList[9].addAdj(14);
        spaceList[10].addAdj(5);
        spaceList[10].addAdj(15);
        spaceList[10].addAdj(6);
        spaceList[10].addAdj(11);
        spaceList[10].addAdj(16);
        spaceList[11].addAdj(5);
        spaceList[11].addAdj(6);
        spaceList[11].addAdj(7);
        spaceList[11].addAdj(10);
        spaceList[11].addAdj(12);
        spaceList[11].addAdj(15);
        spaceList[11].addAdj(16);
        spaceList[11].addAdj(17);
        spaceList[12].addAdj(8);
        spaceList[12].addAdj(6);
        spaceList[12].addAdj(7);
        spaceList[12].addAdj(11);
        spaceList[12].addAdj(13);
        spaceList[12].addAdj(18);
        spaceList[12].addAdj(16);
        spaceList[12].addAdj(17);
        spaceList[13].addAdj(8);
        spaceList[13].addAdj(9);
        spaceList[13].addAdj(7);
        spaceList[13].addAdj(12);
        spaceList[13].addAdj(14);
        spaceList[13].addAdj(18);
        spaceList[13].addAdj(19);
        spaceList[13].addAdj(17);
        spaceList[14].addAdj(8);
        spaceList[14].addAdj(9);
        spaceList[14].addAdj(13);
        spaceList[14].addAdj(19);
        spaceList[14].addAdj(18);
        spaceList[15].addAdj(10);
        spaceList[15].addAdj(11);
        spaceList[15].addAdj(16);
        spaceList[15].addAdj(20);
        spaceList[15].addAdj(21);
        spaceList[16].addAdj(11);
        spaceList[16].addAdj(20);
        spaceList[16].addAdj(21);
        spaceList[16].addAdj(10);
        spaceList[16].addAdj(12);
        spaceList[16].addAdj(15);
        spaceList[16].addAdj(22);
        spaceList[16].addAdj(17);
        spaceList[17].addAdj(11);
        spaceList[17].addAdj(23);
        spaceList[17].addAdj(21);
        spaceList[17].addAdj(13);
        spaceList[17].addAdj(12);
        spaceList[17].addAdj(16);
        spaceList[17].addAdj(22);
        spaceList[17].addAdj(18);
        spaceList[18].addAdj(14);
        spaceList[18].addAdj(23);
        spaceList[18].addAdj(24);
        spaceList[18].addAdj(13);
        spaceList[18].addAdj(12);
        spaceList[18].addAdj(17);
        spaceList[18].addAdj(22);
        spaceList[18].addAdj(19);
        spaceList[19].addAdj(13);
        spaceList[19].addAdj(14);
        spaceList[19].addAdj(18);
        spaceList[19].addAdj(23);
        spaceList[19].addAdj(24);
        spaceList[20].addAdj(15);
        spaceList[20].addAdj(16);
        spaceList[20].addAdj(21);
        spaceList[21].addAdj(22);
        spaceList[21].addAdj(20);
        spaceList[21].addAdj(15);
        spaceList[21].addAdj(16);
        spaceList[21].addAdj(17);
        spaceList[22].addAdj(21);
        spaceList[22].addAdj(23);
        spaceList[22].addAdj(18);
        spaceList[22].addAdj(16);
        spaceList[22].addAdj(17);
        spaceList[23].addAdj(22);
        spaceList[23].addAdj(24);
        spaceList[23].addAdj(18);
        spaceList[23].addAdj(19);
        spaceList[23].addAdj(17);
        spaceList[24].addAdj(18);
        spaceList[24].addAdj(19);
        spaceList[24].addAdj(23);
    }
    if(configuration==2) {
        spaceList= new Space[7]{Space(0,maxHeight), Space(1,maxHeight), Space(2,maxHeight),Space(3, maxHeight),Space(4,maxHeight),Space(5,maxHeight),Space(6,maxHeight)};

        spaceList[0].addAdj(1);
        spaceList[0].addAdj(2);
        spaceList[0].addAdj(3);
        spaceList[0].addAdj(4);

        spaceList[1].addAdj(0);
        spaceList[1].addAdj(2);
        spaceList[1].addAdj(3);
        spaceList[1].addAdj(4);

        spaceList[2].addAdj(1);
        spaceList[2].addAdj(0);
        spaceList[2].addAdj(3);
        spaceList[2].addAdj(4);

        spaceList[3].addAdj(1);
        spaceList[3].addAdj(2);
        spaceList[3].addAdj(0);
        spaceList[3].addAdj(4);

        spaceList[4].addAdj(0);
        spaceList[4].addAdj(1);
        spaceList[4].addAdj(2);
        spaceList[4].addAdj(3);
    }
    unitA=-1;
    unitB=-1;
    unitX=-1;
    unitY=-1;
    turn=true;
    notOver=true;
}
board::board(const board &b1)
{
    maxHeight=b1.maxHeight;
    winHeight=b1.winHeight;
    configuration=b1.configuration;
    if(configuration==2) {
        spaceList= new Space[7]{Space(0,maxHeight), Space(1,maxHeight), Space(2,maxHeight),Space(3, maxHeight),Space(4,maxHeight),Space(5,maxHeight),Space(6,maxHeight)};

        spaceList[0].addAdj(1);
        spaceList[0].addAdj(2);
        spaceList[0].addAdj(3);
        spaceList[0].addAdj(4);

        spaceList[1].addAdj(0);
        spaceList[1].addAdj(2);
        spaceList[1].addAdj(3);
        spaceList[1].addAdj(4);

        spaceList[2].addAdj(1);
        spaceList[2].addAdj(0);
        spaceList[2].addAdj(3);
        spaceList[2].addAdj(4);

        spaceList[3].addAdj(1);
        spaceList[3].addAdj(2);
        spaceList[3].addAdj(0);
        spaceList[3].addAdj(4);

        spaceList[4].addAdj(0);
        spaceList[4].addAdj(1);
        spaceList[4].addAdj(2);
        spaceList[4].addAdj(3);

        for (int i = 0; i < 7; i++) {
            spaceList[i].setHeight(b1.spaceList[i].getHeight());
            spaceList[i].setEmpty(b1.spaceList[i].isEmpty());
        }

    }
    if(configuration==1) {
        spaceList = new Space[25]{Space(0, maxHeight), Space(1, maxHeight), Space(2, maxHeight), Space(3, maxHeight),
                                  Space(4, maxHeight), Space(5, maxHeight), Space(6, maxHeight), Space(7, maxHeight),
                                  Space(8, maxHeight), Space(9, maxHeight), Space(10, maxHeight), Space(11, maxHeight),
                                  Space(12, maxHeight), Space(13, maxHeight), Space(14, maxHeight),
                                  Space(15, maxHeight), Space(16, maxHeight), Space(17, maxHeight),
                                  Space(18, maxHeight), Space(19, maxHeight), Space(20, maxHeight),
                                  Space(21, maxHeight), Space(22, maxHeight), Space(23, maxHeight),
                                  Space(24, maxHeight)};

        for (int i = 0; i < 25; i++) {
            spaceList[i] = Space(i, maxHeight);
        }
        spaceList[0].addAdj(1);
        spaceList[0].addAdj(5);
        spaceList[0].addAdj(6);
        spaceList[1].addAdj(0);
        spaceList[1].addAdj(2);
        spaceList[1].addAdj(5);
        spaceList[1].addAdj(6);
        spaceList[1].addAdj(7);
        spaceList[2].addAdj(6);
        spaceList[2].addAdj(7);
        spaceList[2].addAdj(1);
        spaceList[2].addAdj(3);
        spaceList[2].addAdj(8);
        spaceList[3].addAdj(2);
        spaceList[3].addAdj(8);
        spaceList[3].addAdj(4);
        spaceList[3].addAdj(9);
        spaceList[3].addAdj(7);
        spaceList[4].addAdj(3);
        spaceList[4].addAdj(8);
        spaceList[4].addAdj(9);
        spaceList[5].addAdj(0);
        spaceList[5].addAdj(1);
        spaceList[5].addAdj(6);
        spaceList[5].addAdj(11);
        spaceList[5].addAdj(10);
        spaceList[6].addAdj(0);
        spaceList[6].addAdj(1);
        spaceList[6].addAdj(2);
        spaceList[6].addAdj(5);
        spaceList[6].addAdj(7);
        spaceList[6].addAdj(10);
        spaceList[6].addAdj(11);
        spaceList[6].addAdj(12);
        spaceList[7].addAdj(1);
        spaceList[7].addAdj(2);
        spaceList[7].addAdj(3);
        spaceList[7].addAdj(6);
        spaceList[7].addAdj(8);
        spaceList[7].addAdj(13);
        spaceList[7].addAdj(11);
        spaceList[7].addAdj(12);
        spaceList[8].addAdj(2);
        spaceList[8].addAdj(3);
        spaceList[8].addAdj(4);
        spaceList[8].addAdj(9);
        spaceList[8].addAdj(7);
        spaceList[8].addAdj(13);
        spaceList[8].addAdj(14);
        spaceList[8].addAdj(12);
        spaceList[9].addAdj(3);
        spaceList[9].addAdj(4);
        spaceList[9].addAdj(8);
        spaceList[9].addAdj(13);
        spaceList[9].addAdj(14);
        spaceList[10].addAdj(5);
        spaceList[10].addAdj(15);
        spaceList[10].addAdj(6);
        spaceList[10].addAdj(11);
        spaceList[10].addAdj(16);
        spaceList[11].addAdj(5);
        spaceList[11].addAdj(6);
        spaceList[11].addAdj(7);
        spaceList[11].addAdj(10);
        spaceList[11].addAdj(12);
        spaceList[11].addAdj(15);
        spaceList[11].addAdj(16);
        spaceList[11].addAdj(17);
        spaceList[12].addAdj(8);
        spaceList[12].addAdj(6);
        spaceList[12].addAdj(7);
        spaceList[12].addAdj(11);
        spaceList[12].addAdj(13);
        spaceList[12].addAdj(18);
        spaceList[12].addAdj(16);
        spaceList[12].addAdj(17);
        spaceList[13].addAdj(8);
        spaceList[13].addAdj(9);
        spaceList[13].addAdj(7);
        spaceList[13].addAdj(12);
        spaceList[13].addAdj(14);
        spaceList[13].addAdj(18);
        spaceList[13].addAdj(19);
        spaceList[13].addAdj(17);
        spaceList[14].addAdj(8);
        spaceList[14].addAdj(9);
        spaceList[14].addAdj(13);
        spaceList[14].addAdj(19);
        spaceList[14].addAdj(18);
        spaceList[15].addAdj(10);
        spaceList[15].addAdj(11);
        spaceList[15].addAdj(16);
        spaceList[15].addAdj(20);
        spaceList[15].addAdj(21);
        spaceList[16].addAdj(11);
        spaceList[16].addAdj(20);
        spaceList[16].addAdj(21);
        spaceList[16].addAdj(10);
        spaceList[16].addAdj(12);
        spaceList[16].addAdj(15);
        spaceList[16].addAdj(22);
        spaceList[16].addAdj(17);
        spaceList[17].addAdj(11);
        spaceList[17].addAdj(23);
        spaceList[17].addAdj(21);
        spaceList[17].addAdj(13);
        spaceList[17].addAdj(12);
        spaceList[17].addAdj(16);
        spaceList[17].addAdj(22);
        spaceList[17].addAdj(18);
        spaceList[18].addAdj(14);
        spaceList[18].addAdj(23);
        spaceList[18].addAdj(24);
        spaceList[18].addAdj(13);
        spaceList[18].addAdj(12);
        spaceList[18].addAdj(17);
        spaceList[18].addAdj(22);
        spaceList[18].addAdj(19);
        spaceList[19].addAdj(13);
        spaceList[19].addAdj(14);
        spaceList[19].addAdj(18);
        spaceList[19].addAdj(23);
        spaceList[19].addAdj(24);
        spaceList[20].addAdj(15);
        spaceList[20].addAdj(16);
        spaceList[20].addAdj(21);
        spaceList[21].addAdj(22);
        spaceList[21].addAdj(20);
        spaceList[21].addAdj(15);
        spaceList[21].addAdj(16);
        spaceList[21].addAdj(17);
        spaceList[22].addAdj(21);
        spaceList[22].addAdj(23);
        spaceList[22].addAdj(18);
        spaceList[22].addAdj(16);
        spaceList[22].addAdj(17);
        spaceList[23].addAdj(22);
        spaceList[23].addAdj(24);
        spaceList[23].addAdj(18);
        spaceList[23].addAdj(19);
        spaceList[23].addAdj(17);
        spaceList[24].addAdj(18);
        spaceList[24].addAdj(19);
        spaceList[24].addAdj(23);

        for (int i = 0; i < 25; i++) {
            spaceList[i].setHeight(b1.spaceList[i].getHeight());
            spaceList[i].setEmpty(b1.spaceList[i].isEmpty());
        }

    }
    if(configuration==3) {
        spaceList = new Space[25]{Space(0, maxHeight), Space(1, maxHeight), Space(2, maxHeight), Space(3, maxHeight),
                                  Space(4, maxHeight), Space(5, maxHeight), Space(6, maxHeight), Space(7, maxHeight),
                                  Space(8, maxHeight), Space(9, maxHeight), Space(10, maxHeight), Space(11, maxHeight),
                                  Space(12, maxHeight), Space(13, maxHeight), Space(14, maxHeight),
                                  Space(15, maxHeight), Space(16, maxHeight), Space(17, maxHeight),
                                  Space(18, maxHeight), Space(19, maxHeight), Space(20, maxHeight),
                                  Space(21, maxHeight), Space(22, maxHeight), Space(23, maxHeight),
                                  Space(24, maxHeight)};
        for (int i = 0; i < 25; i++) {
            spaceList[i] = Space(i, maxHeight);
        }

        //asdksajdkalsd
        spaceList[0].addAdj(1);

        spaceList[1].addAdj(0);
        spaceList[1].addAdj(2);

        spaceList[2].addAdj(1);
        spaceList[2].addAdj(3);

        spaceList[3].addAdj(2);

        for (int i = 0; i < 25; i++) {
            spaceList[i].setHeight(b1.spaceList[i].getHeight());
            spaceList[i].setEmpty(b1.spaceList[i].isEmpty());
        }
    }
    unitA=b1.unitA;
    unitB=b1.unitB;
    unitX=b1.unitX;
    unitY=b1.unitY;
    spaceList[unitA].setEmpty(false);
    spaceList[unitB].setEmpty(false);
    spaceList[unitX].setEmpty(false);
    spaceList[unitY].setEmpty(false);
    notOver=true;
    turn=b1.turn;
}
board::~board()
{
    delete[] spaceList;
}
/*
board & board::operator = (const board &b1)
{
  for(int i=0; i<25;i++)
  {
    spaceList[i].setHeight(b1.spaceList[i].getHeight());
  }
  unitA=b1.unitA;
  unitB=b1.unitB;
  unitX=b1.unitX;
  unitY=b1.unitY;
  spaceList[unitA].setEmpty(false);
  spaceList[unitB].setEmpty(false);
  spaceList[unitX].setEmpty(false);
  spaceList[unitY].setEmpty(false);
  notOver=true;
  turn=b1.turn;
}
*/
/*
bool board::move()
{
  char movingUnit;
  int moveSpace;
  int buildSpace;
  bool notMoved = true;
  if(turn){
    cout<<"Player 1 turn."<<endl;
  }
  else{
    cout<<"Player 2 turn."<<endl;
  }
  while (notMoved) {
    cout<<"Choose a unit to move."<< endl;
    cin >> movingUnit;
    if((movingUnit=='A'&&turn)) {
      while (notMoved) {
        cout<<"Select a space to move to."<<endl;
        cin>>moveSpace;
        if ((spaceList[unitA].isAdj(moveSpace))&&spaceList[moveSpace].isEmpty()&&((spaceList[unitA].getHeight()) + 1>=spaceList[moveSpace].getHeight())){
          spaceList[unitA].setEmpty(true);
          unitA=moveSpace;
          spaceList[unitA].setEmpty(false);
          if(spaceList[unitA].getHeight()==3){
            notOver=false;
          }
          cout<<"/////////////////////////////////"<<endl<<endl;
          printBoard();
          while (notMoved) {


            cout<<"Select a space to build on."<<endl;
            cin>>buildSpace;
            if (spaceList[unitA].isAdj(buildSpace)&&spaceList[buildSpace].build()){
              notMoved=false;
              turn=!turn;
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
    else if (movingUnit=='B'&&turn) {
      while (notMoved) {
        cout<<"Select a space to move to."<<endl;
        cin>>moveSpace;
        if ((spaceList[unitB].isAdj(moveSpace))&&spaceList[moveSpace].isEmpty()&&((spaceList[unitB].getHeight()) + 1>=spaceList[moveSpace].getHeight())){
          spaceList[unitB].setEmpty(true);
          unitB=moveSpace;
          spaceList[unitB].setEmpty(false);
          if(spaceList[unitB].getHeight()==3){
            notOver=false;
          }
          cout<<"/////////////////////////////////"<<endl<<endl;
          printBoard();
          while (notMoved) {


            cout<<"Select a space to build on."<<endl;
            cin>>buildSpace;
            if (spaceList[unitB].isAdj(buildSpace)&&spaceList[buildSpace].build()){

              notMoved=false;
              turn=!turn;
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
    else if (movingUnit=='X'&&(!turn)) {
      while (notMoved) {
        cout<<"Select a space to move to."<<endl;
        cin>>moveSpace;
        if ((spaceList[unitX].isAdj(moveSpace))&&spaceList[moveSpace].isEmpty()&&((spaceList[unitX].getHeight()) + 1>=spaceList[moveSpace].getHeight())){
          spaceList[unitX].setEmpty(true);
          unitX=moveSpace;
          spaceList[unitX].setEmpty(false);
          if(spaceList[unitX].getHeight()==3){
            notOver=false;
          }
          cout<<"/////////////////////////////////"<<endl<<endl;
          printBoard();
          while (notMoved) {


            cout<<"Select a space to build on."<<endl;
            cin>>buildSpace;
            if (spaceList[unitX].isAdj(buildSpace)&&spaceList[buildSpace].build()){

              notMoved=false;
              turn=!turn;
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
    else if (movingUnit=='Y'&&(!turn)) {
      while (notMoved) {
        cout<<"Select a space to move to."<<endl;
        cin>>moveSpace;
        if ((spaceList[unitY].isAdj(moveSpace))&&spaceList[moveSpace].isEmpty()&&((spaceList[unitY].getHeight()) + 1>=spaceList[moveSpace].getHeight())){
          spaceList[unitY].setEmpty(true);
          unitY=moveSpace;
          spaceList[unitY].setEmpty(false);
          if(spaceList[unitY].getHeight()==3){
            notOver=false;
          }
          cout<<"/////////////////////////////////"<<endl<<endl;
          printBoard();
          while (notMoved) {


            cout<<"Select a space to build on."<<endl;
            cin>>buildSpace;
            if (spaceList[unitY].isAdj(buildSpace)&&spaceList[buildSpace].build()){

              notMoved=false;
              turn=!turn;
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
  return !notMoved;
}
*/

void board::printBoard() {
    if(configuration==2) {
        cout <<" "<<spaceList[0].id << "   ";
        cout <<" "<<spaceList[1].id << "   ";
        cout <<endl;
        for (int i = 0; i<2; i++){
            cout << " " << spaceList[i].getHeight();
            if (unitA == i) {
                cout << "A  ";
            } else if (unitB == i) {
                cout << "B  ";
            } else if (unitX == i) {
                cout << "X  ";
            } else if (unitY == i) {
                cout << "Y  ";
            } else {
                cout << "   ";
            }
        }
        cout<<endl<<endl;
        cout <<" "<<spaceList[2].id << "   ";
        cout <<" "<<spaceList[3].id << "   ";
        cout <<" "<<spaceList[4].id << "   ";
        cout <<endl;
        for (int i = 2; i<5; i++){
            cout << " " << spaceList[i].getHeight();
            if (unitA == i) {
                cout << "A  ";
            } else if (unitB == i) {
                cout << "B  ";
            } else if (unitX == i) {
                cout << "X  ";
            } else if (unitY == i) {
                cout << "Y  ";
            } else {
                cout << "   ";
            }
        }
        cout<<endl<<endl;
    }
    if (configuration==1) {
        for (int i = 0; i < 5; i++) {
            cout << " " << spaceList[i].id << "   ";

        }
        cout << endl;
        for (int i = 0; i < 5; i++) {
            cout << " " << spaceList[i].getHeight();
            if (unitA == i) {
                cout << "A  ";
            } else if (unitB == i) {
                cout << "B  ";
            } else if (unitX == i) {
                cout << "X  ";
            } else if (unitY == i) {
                cout << "Y  ";
            } else {
                cout << "   ";
            }
        }

        cout << endl << endl;

        for (int i = 5; i < 10; i++) {
            cout << " " << spaceList[i].id << "   ";
        }
        cout << endl;
        for (int i = 5; i < 10; i++) {
            cout << " " << spaceList[i].getHeight();
            if (unitA == i) {
                cout << "A  ";
            } else if (unitB == i) {
                cout << "B  ";
            } else if (unitX == i) {
                cout << "X  ";
            } else if (unitY == i) {
                cout << "Y  ";
            } else {
                cout << "   ";
            }
        }
        cout << endl << endl;

        for (int i = 10; i < 15; i++) {
            cout << spaceList[i].id << "   ";
        }
        cout << endl;
        for (int i = 10; i < 15; i++) {
            cout << " " << spaceList[i].getHeight();
            if (unitA == i) {
                cout << "A  ";
            } else if (unitB == i) {
                cout << "B  ";
            } else if (unitX == i) {
                cout << "X  ";
            } else if (unitY == i) {
                cout << "Y  ";
            } else {
                cout << "   ";
            }
        }
        cout << endl << endl;

        for (int i = 15; i < 20; i++) {
            cout << spaceList[i].id << "   ";
        }
        cout << endl;
        for (int i = 15; i < 20; i++) {
            cout << " " << spaceList[i].getHeight();
            if (unitA == i) {
                cout << "A  ";
            } else if (unitB == i) {
                cout << "B  ";
            } else if (unitX == i) {
                cout << "X  ";
            } else if (unitY == i) {
                cout << "Y  ";
            } else {
                cout << "   ";
            }
        }
        cout << endl << endl;

        for (int i = 20; i < 25; i++) {
            cout << spaceList[i].id << "   ";
        }
        cout << endl;
        for (int i = 20; i < 25; i++) {
            cout << " " << spaceList[i].getHeight();
            if (unitA == i) {
                cout << "A  ";
            } else if (unitB == i) {
                cout << "B  ";
            } else if (unitX == i) {
                cout << "X  ";
            } else if (unitY == i) {
                cout << "Y  ";
            } else {
                cout << "   ";
            }
        }
        cout << endl << endl;
    }
    if (configuration==3) {
        for (int i = 0; i < 5; i++) {
            cout << " " << spaceList[i].id << "   ";

        }
        cout << endl;
        for (int i = 0; i < 5; i++) {
            cout << " " << spaceList[i].getHeight();
            if (unitA == i) {
                cout << "A  ";
            } else if (unitB == i) {
                cout << "B  ";
            } else if (unitX == i) {
                cout << "X  ";
            } else if (unitY == i) {
                cout << "Y  ";
            } else {
                cout << "   ";
            }
        }

        cout << endl << endl;

        for (int i = 5; i < 10; i++) {
            cout << " " << spaceList[i].id << "   ";
        }
        cout << endl;
        for (int i = 5; i < 10; i++) {
            cout << " " << spaceList[i].getHeight();
            if (unitA == i) {
                cout << "A  ";
            } else if (unitB == i) {
                cout << "B  ";
            } else if (unitX == i) {
                cout << "X  ";
            } else if (unitY == i) {
                cout << "Y  ";
            } else {
                cout << "   ";
            }
        }
        cout << endl << endl;

        for (int i = 10; i < 15; i++) {
            cout << spaceList[i].id << "   ";
        }
        cout << endl;
        for (int i = 10; i < 15; i++) {
            cout << " " << spaceList[i].getHeight();
            if (unitA == i) {
                cout << "A  ";
            } else if (unitB == i) {
                cout << "B  ";
            } else if (unitX == i) {
                cout << "X  ";
            } else if (unitY == i) {
                cout << "Y  ";
            } else {
                cout << "   ";
            }
        }
        cout << endl << endl;

        for (int i = 15; i < 20; i++) {
            cout << spaceList[i].id << "   ";
        }
        cout << endl;
        for (int i = 15; i < 20; i++) {
            cout << " " << spaceList[i].getHeight();
            if (unitA == i) {
                cout << "A  ";
            } else if (unitB == i) {
                cout << "B  ";
            } else if (unitX == i) {
                cout << "X  ";
            } else if (unitY == i) {
                cout << "Y  ";
            } else {
                cout << "   ";
            }
        }
        cout << endl << endl;

        for (int i = 20; i < 25; i++) {
            cout << spaceList[i].id << "   ";
        }
        cout << endl;
        for (int i = 20; i < 25; i++) {
            cout << " " << spaceList[i].getHeight();
            if (unitA == i) {
                cout << "A  ";
            } else if (unitB == i) {
                cout << "B  ";
            } else if (unitX == i) {
                cout << "X  ";
            } else if (unitY == i) {
                cout << "Y  ";
            } else {
                cout << "   ";
            }
        }
        cout << endl << endl;
    }
}

bool board::ifOppCantMove() {
    if(turn)
    {
        for(int i=0;i<spaceList[unitX].getNumAdj();i++)
        {
            if(spaceList[spaceList[unitX].adjList[i]].isEmpty()&&(spaceList[spaceList[unitX].adjList[i]].getHeight()<=1+spaceList[unitX].getHeight()))
            {
                return false;
            }
        }
        for(int i=0;i<spaceList[unitY].getNumAdj();i++)
        {
            if(spaceList[spaceList[unitY].adjList[i]].isEmpty()&&(spaceList[spaceList[unitY].adjList[i]].getHeight()<=1+spaceList[unitY].getHeight()))
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        for(int i=0;i<spaceList[unitA].getNumAdj();i++)
        {
            if(spaceList[spaceList[unitA].adjList[i]].isEmpty()&&(spaceList[spaceList[unitA].adjList[i]].getHeight()<=1+spaceList[unitA].getHeight()))
            {
                return false;
            }
        }
        for(int i=0;i<spaceList[unitB].getNumAdj();i++)
        {
            if(spaceList[spaceList[unitB].adjList[i]].isEmpty()&&(spaceList[spaceList[unitB].adjList[i]].getHeight()<=1+spaceList[unitB].getHeight()))
            {
                return false;
            }
        }
        return true;
    }
}
bool board::win()
{
    if(turn)
    {
        return spaceList[unitA].getHeight()==winHeight || spaceList[unitB].getHeight()==winHeight || ifOppCantMove();
    }
    else
    {
        return spaceList[unitX].getHeight()==winHeight || spaceList[unitY].getHeight()==winHeight || ifOppCantMove();
    }
}
int board::dist(int un1, int un2)
{
    int x1=un1 % 5;
    int x2=un2 % 5;
    int y1=un1 / 5;
    int y2=un2 / 5;
    return max(abs(x1-x2),abs(y1-y2));
}
int board::center(int un)
{
    int x = un%5;
    int y = un/5;
    int cen = 0;
    if (0<x && x<4 && 0<y && y<4)
    {
        cen++;
    }
    if (x==2&&y==2)
    {
        cen++;
    }
    return cen;
}
int board::distH()
{
    int sum=10;
    if(!turn)
    {
        sum = min(dist(unitA,unitX), dist(unitB,unitX)) + min(dist(unitA,unitY), dist(unitB,unitY));

    }
    else {
        sum = min(dist(unitA,unitX), dist(unitA,unitY)) + min(dist(unitB,unitY), dist(unitB,unitX));

    }
    return 10-sum;
}
int board::heightH()
{
    int sum = 0;
    if(!turn)
    {
        sum = spaceList[unitA].getHeight()+spaceList[unitB].getHeight();
    }
    else {
        sum = spaceList[unitX].getHeight()+spaceList[unitY].getHeight();
    }
    return sum;
}
int board::centerH()
{
    int sum = 0;
    if(!turn)
    {
        sum = center(unitA)+center(unitB);
    }
    else {
        sum = center(unitX)+center(unitY);
    }
    return sum;
}