#ifndef __Display
#define __Display
#include "Global.hpp"

inline void display_board (int cur_board[15][15]){
    for (int i=0; i<15; ++i){
        for (int j=0; j<15; ++j){
            switch (cur_board[i][j]){
                case 0:  std::cout<<"+ ";  break;
                case 1:  std::cout<<"@ ";  break;
                case 2:  std::cout<<"O ";  break;
                default:  std::cout<<"X ";  break;
            }
        }
        putchar('\n');
    }
    putchar('\n');
}

#endif