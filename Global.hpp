#ifndef __Global
#define __Global
#include <bits/stdc++.h>

struct poin{
    int row;
    int col;
};

struct hash_pair{
    int value;
    int depth;
};

//MUST win
const int inf=100000000;

//set value
int value[]={0, 100, 10000, 1000000, inf};

//start_pos
int lef_top_r[]={10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int lef_top_c[]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int rig_top_r[]={4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14};
int rig_top_c[]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

//0:empty______1:black______2:white
int Gobang_board[15][15];

int turn;
int side;

//for Zobrist
//0:blank_____1:black_____2:white
int zobrist_hash[15][15][3];
int zobrist_val;
std::map<int, hash_pair> zobrist_recorder;

#endif