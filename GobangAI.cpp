#include "AIController.h"
#include "Minimax_Search.hpp"
#include <utility>
#include <cstring>

extern int ai_side; //0: black, 1: white
std::string ai_name = "Edersnow's AI";

//init function is called once at the beginning
void init() {
    memset(Gobang_board, 0, sizeof(Gobang_board));
    turn=0;
    if (ai_side)  side=2;
    else  side=1;
}

// loc is the action of your opponent
// Initially, loc being (-1,-1) means it's your first move
// If this is the third step(with 2 black ), where you can use the swap rule, your output could be either (-1, -1) to indicate that you choose a swap, or a coordinate (x,y) as normal.

std::pair<int, int> action(std::pair<int, int> loc) {
    turn++;
    if (turn == 1 && loc.first == -1){
        std::pair<int, int> tmp;
        tmp.first=7;
        tmp.second=7;
        Gobang_board[7][7]=side;
        return tmp;
    }

    if (loc.first == -1){
        poin tmp;
        std::pair<int, int> cur;
        for (int i=0; i<15; ++i){
            for (int j=0; j<15; ++j){
                if (Gobang_board[i][j])  Gobang_board[i][j]^=3;
            }
        }
        tmp=GetNext(side);
        cur.first=tmp.row;
        cur.second=tmp.col;
        return cur;
    }

    poin tmp;
    std::pair<int, int> cur;
    Gobang_board[loc.first][loc.second]=(side^3);
    tmp=GetNext(side);
    cur.first=tmp.row;
    cur.second=tmp.col;

    return cur;
}