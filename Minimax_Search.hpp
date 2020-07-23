#ifndef __MinimaxSearch
#define __MinimaxSearch
#include "Global.hpp"
#include "Generator.hpp"
#include "Evaluator.hpp"
#include "Display.hpp"

inline void swap2(){
    for (int i=0; i<15; ++i){
        for (int j=0; j<15; ++j){
            if (Gobang_board[i][j]){
                Gobang_board[i][j]^=3;
                zobrist_val^=zobrist_hash[i][j][1];
                zobrist_val^=zobrist_hash[i][j][2];
            }
        }
    }
}

inline void update_board(int row, int col, int side){
    Gobang_board[row][col]=side;
    zobrist_val^=zobrist_hash[row][col][0];
    zobrist_val^=zobrist_hash[row][col][side];
}

inline void recover_board(int row, int col, int side){
    Gobang_board[row][col]=0;
    zobrist_val^=zobrist_hash[row][col][0];
    zobrist_val^=zobrist_hash[row][col][side];
}

int MMSearch(int cur_layer, int max_layer, int cur_side, int ABnum){
    bool isEnd;
    int tmpval;
    int extval;
    poin tmppoi;
    generator cur_gen(cur_side);

    if (cur_layer == max_layer)  return evaluate(cur_side);

    //opponent
    if (cur_layer&1){
        extval=inf+1;
        while (true){
            tmppoi=cur_gen.generate(isEnd);
            if (tmppoi.row == -2)  break;
            if (isEnd)  return -inf;

            update_board(tmppoi.row, tmppoi.col, cur_side);
            if (zobrist_recorder.count(zobrist_val) && zobrist_recorder[zobrist_val].depth == max_layer - cur_layer){
                tmpval = zobrist_recorder[zobrist_val].value;
            }
            else{
                hash_pair tmphas;
                tmphas.value = tmpval = MMSearch(cur_layer+1, max_layer, cur_side^3, extval);
                tmphas.depth = max_layer - cur_layer;
                zobrist_recorder[zobrist_val] = tmphas;
            }
            recover_board(tmppoi.row, tmppoi.col, cur_side);

            //attention here
            if (tmpval <= ABnum)  return tmpval;
            if (tmpval < extval)  extval=tmpval;
        }

        //special
        if (turn+cur_layer == 3 && cur_side == 2){
            swap2();
            if (zobrist_recorder.count(zobrist_val) && zobrist_recorder[zobrist_val].depth == max_layer - cur_layer){
                tmpval = zobrist_recorder[zobrist_val].value;
            }
            else{
                hash_pair tmphas;
                tmphas.value = tmpval = MMSearch(cur_layer+1, max_layer, cur_side^3, extval);
                tmphas.depth = max_layer - cur_layer;
                zobrist_recorder[zobrist_val] = tmphas;
            }
            swap2();

            //attention here
            if (tmpval <= ABnum)  return tmpval;
            if (tmpval < extval)  extval=tmpval;
        }
    }
    //AI
    else{
        extval=-inf-1;
        while (true){
            tmppoi=cur_gen.generate(isEnd);
            if (tmppoi.row == -2)  break;
            if (isEnd)  return inf;

            update_board(tmppoi.row, tmppoi.col, cur_side);
            if (zobrist_recorder.count(zobrist_val) && zobrist_recorder[zobrist_val].depth == max_layer - cur_layer){
                tmpval = zobrist_recorder[zobrist_val].value;
            }
            else{
                hash_pair tmphas;
                tmphas.value = tmpval = MMSearch(cur_layer+1, max_layer, cur_side^3, extval);
                tmphas.depth = max_layer - cur_layer;
                zobrist_recorder[zobrist_val] = tmphas;
            }
            recover_board(tmppoi.row, tmppoi.col, cur_side);

            //attention here
            if (tmpval >= ABnum)  return tmpval;
            if (tmpval > extval)  extval=tmpval;
        }

        //special
        if (turn+cur_layer == 3 && cur_side == 2){
            swap2();
            if (zobrist_recorder.count(zobrist_val) && zobrist_recorder[zobrist_val].depth == max_layer - cur_layer){
                tmpval = zobrist_recorder[zobrist_val].value;
            }
            else{
                hash_pair tmphas;
                tmphas.value = tmpval = MMSearch(cur_layer+1, max_layer, cur_side^3, extval);
                tmphas.depth = max_layer - cur_layer;
                zobrist_recorder[zobrist_val] = tmphas;
            }
            swap2();

            //attention here
            if (tmpval >= ABnum)  return tmpval;
            if (tmpval > extval)  extval=tmpval;
        }
    }

    return extval;
}



//side1: black_____side2: white
poin GetNext(int side){
    bool isEnd;
    int tmpval;
    int maxval;
    int maxdepth=6;
    poin tmppoi;
    poin maxpoi;
    generator cur_gen(side);

    //Iterative DFS
    if (turn >= 4){
        for (int maxlayer=2; maxlayer<maxdepth; maxlayer+=2){
            generator tmp_gen(side);
            maxval=-inf-1;
            while (true){
                tmppoi=tmp_gen.generate(isEnd);
                if (tmppoi.row == -2)  break;
                if (isEnd)  return tmppoi;

                update_board(tmppoi.row, tmppoi.col, side);
                tmpval=MMSearch(1, maxlayer, side^3, maxval);
                recover_board(tmppoi.row, tmppoi.col, side);

                if (tmpval == inf)  return tmppoi;
                if (tmpval > maxval)  maxval=tmpval;
            }
        }
    }

    maxval=-inf-1;
    while (true){
        tmppoi=cur_gen.generate(isEnd);
        if (tmppoi.row == -2)  break;
        if (isEnd)  return tmppoi;

        update_board(tmppoi.row, tmppoi.col, side);
        tmpval=MMSearch(1, maxdepth, side^3, maxval);
        recover_board(tmppoi.row, tmppoi.col, side);

        if (tmpval == inf)  return tmppoi;
        if (tmpval > maxval){
            maxpoi=tmppoi;
            maxval=tmpval;
        }
    }
    //special
    if (turn==2 && side == 2){
        swap2();
        tmpval=MMSearch(1, maxdepth, side^3, maxval);
        swap2();
        if (tmpval > maxval){
            maxpoi.row=-1;
            maxpoi.col=-1;
        }
    }

    return maxpoi;
}

#endif