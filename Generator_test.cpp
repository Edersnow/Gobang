#include "Generator.hpp"
#include "Display.hpp"

void run_test(){
    bool a;
    int i=1;
    poin tmp;
    generator cur_gen(2);
    while (true){
        tmp=cur_gen.generate(a);
        if (tmp.row==-2 || a)  break;
        Gobang_board[tmp.row][tmp.col]='0';
        display_board(Gobang_board);
    }
}

int main(){
    /*
    Gobang_board[7][7]=Gobang_board[7][5]=Gobang_board[7][6]=Gobang_board[6][7]=
    Gobang_board[8][5]=Gobang_board[5][8]=Gobang_board[7][4]=Gobang_board[7][10]=
    Gobang_board[6][5]=Gobang_board[10][5]=1;
    Gobang_board[6][6]=Gobang_board[6][8]=Gobang_board[7][4]=Gobang_board[8][7]=
    Gobang_board[9][4]=Gobang_board[4][9]=Gobang_board[3][7]=Gobang_board[6][9]=
    Gobang_board[5][5]=Gobang_board[9][5]=2;
    */

    /*
    Gobang_board[7][7]=Gobang_board[5][7]=Gobang_board[6][8]=1;
    Gobang_board[8][6]=Gobang_board[8][7]=Gobang_board[8][8]=2;
    */

    /*
    Gobang_board[7][7]=Gobang_board[6][8]=Gobang_board[5][9]=1;
    Gobang_board[5][10]=Gobang_board[6][9]=Gobang_board[8][7]=2;
    */

    /*
    Gobang_board[0][0]=Gobang_board[5][7]=Gobang_board[7][8]=Gobang_board[6][9]=Gobang_board[4][11]=1;
    Gobang_board[7][7]=Gobang_board[6][7]=Gobang_board[6][8]=Gobang_board[6][6]=Gobang_board[3][12]=Gobang_board[9][6]=2;
    */

    Gobang_board[0][0]=Gobang_board[1][2]=2;
    Gobang_board[7][7]=Gobang_board[8][8]=Gobang_board[0][1]=1;

    display_board(Gobang_board);

    run_test();
    return 0;
}