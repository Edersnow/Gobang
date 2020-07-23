#include "Evaluator.hpp"
#include "Display.hpp"

void basic(){
    Gobang_board[5][5]=Gobang_board[5][6]=Gobang_board[5][7]=1;
    Gobang_board[5][4]=Gobang_board[4][4]=Gobang_board[3][4]=2;
    display_board(Gobang_board);
    printf("test1: %d %d\n", evaluate(1), evaluate(2));

    /*
    Gobang_board[5][5]=Gobang_board[6][6]=Gobang_board[7][5]=1;
    Gobang_board[5][6]=Gobang_board[5][7]=Gobang_board[7][7]=2;
    display_board(Gobang_board);
    printf("test2: %d %d\n", evaluate(1), evaluate(2));
    */

    /*
    Gobang_board[7][7]=Gobang_board[5][7]=Gobang_board[6][7]=Gobang_board[6][6]=Gobang_board[8][8]=Gobang_board[10][10]=Gobang_board[6][4]=Gobang_board[6][5]=Gobang_board[7][5]=Gobang_board[4][5]=1;
    Gobang_board[6][8]=Gobang_board[4][6]=Gobang_board[8][7]=Gobang_board[4][8]=Gobang_board[5][5]=Gobang_board[9][9]=Gobang_board[6][9]=Gobang_board[6][3]=Gobang_board[4][7]=Gobang_board[7][8]=2;
    display_board(Gobang_board);
    printf("test3: %d %d\n", evaluate(1), evaluate(2));
    */


    /*
    //An special test ...
    Gobang_board[7][7]=Gobang_board[7][5]=Gobang_board[7][6]=Gobang_board[6][7]=Gobang_board[8][5]=Gobang_board[5][8]=Gobang_board[7][4]=Gobang_board[7][10]=Gobang_board[6][5]=Gobang_board[10][5]=1;
    Gobang_board[6][6]=Gobang_board[6][8]=Gobang_board[7][4]=Gobang_board[8][7]=Gobang_board[9][4]=Gobang_board[4][9]=Gobang_board[3][7]=Gobang_board[6][9]=Gobang_board[5][5]=Gobang_board[9][5]=2;
    display_board(Gobang_board);
    printf("test4: %d %d\n", evaluate(1), evaluate(2));
    */
}

int main(){
    basic();

    return 0;
}