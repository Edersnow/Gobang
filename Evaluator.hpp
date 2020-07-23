#ifndef __Evaluator
#define __Evaluator
#include "Global.hpp"

inline int evaluate_val(int type, int off){
    int total_val=0;
    //calc row
    for (int i=0; i<15; ++i){
        int cur_pos=0;
        while (cur_pos<15){
            int line[10]={0};
            int empty[10]={0};
            int line_len=0;
            int empty_len=0;
            int section_len;
            int cur_len=0;

            while (cur_pos<15 && Gobang_board[i][cur_pos] == (3^type))  ++cur_pos;
            section_len=cur_pos;

            while (cur_pos<15 && Gobang_board[i][cur_pos] == 0)  ++cur_pos, ++cur_len;
            empty[empty_len++]=cur_len;

            while (true){
                if (cur_pos == 15 || Gobang_board[i][cur_pos] == (3^type))  break;

                cur_len=0;
                while (cur_pos<15 && Gobang_board[i][cur_pos] == type)  ++cur_pos, ++cur_len;
                line[line_len++]=cur_len;

                cur_len=0;
                while (cur_pos<15 && Gobang_board[i][cur_pos] == 0)  ++cur_pos, ++cur_len;
                empty[empty_len++]=cur_len;
            }
            section_len=cur_pos-section_len;



            if (empty_len == 1 || section_len <= 4)  continue;

            if (section_len == 5){
                int total_len=0;
                for (int i=0; i<line_len; ++i){
                    total_len += line[i];
                }
                if (total_len == 4 && off)  return inf;
                else  total_val += value[total_len-1];
                continue;
            }

            for (int i=0; i<line_len; ++i){
                if (empty[i] && empty[i+1]){
                    switch (line[i]){
                        case 4:  return inf;
                        case 3:  total_val += 1000000;  break;
                        case 2:  total_val += 10000;  break;
                        case 1:  total_val += 100;  break;
                    }
                }
                else{
                    switch (line[i]){
                        case 4:
                            if(off)  return inf;
                            total_val += 1000000;
                            break;
                        case 3:  total_val += 10000;  break;
                        case 2:  total_val += 100;  break;
                    }
                }
            }

            for (int i=1; i<empty_len-1; ++i){
                if (empty[i]==1 && empty[i-1] && empty[i+1]){
                    switch (line[i-1]+line[i]){
                        case 2:  total_val+=5000;  break;
                        case 3:  total_val+=1000000;  break;
                        case 4:
                            if (off)  return inf;
                            total_val += 1000000;
                            break;
                    }
                }
            }
        }
    }

    //calc col
    for (int i=0; i<15; ++i){
        int cur_pos=0;
        while (cur_pos<15){
            int line[10]={0};
            int empty[10]={0};
            int line_len=0;
            int empty_len=0;
            int section_len;
            int cur_len=0;

            while (cur_pos<15 && Gobang_board[cur_pos][i] == (3^type))  ++cur_pos;
            section_len=cur_pos;

            while (cur_pos<15 && Gobang_board[cur_pos][i] == 0)  ++cur_pos, ++cur_len;
            empty[empty_len++]=cur_len;

            while (true){
                if (cur_pos == 15 || Gobang_board[cur_pos][i] == (3^type))  break;

                cur_len=0;
                while (cur_pos<15 && Gobang_board[cur_pos][i] == type)  ++cur_pos, ++cur_len;
                line[line_len++]=cur_len;

                cur_len=0;
                while (cur_pos<15 && Gobang_board[cur_pos][i] == 0)  ++cur_pos, ++cur_len;
                empty[empty_len++]=cur_len;
            }
            section_len=cur_pos-section_len;



            if (empty_len == 1 || section_len <= 4)  continue;

            if (section_len == 5){
                int total_len=0;
                for (int i=0; i<line_len; ++i){
                    total_len += line[i];
                }
                if (total_len == 4 && off)  return inf;
                else  total_val += value[total_len-1];
                continue;
            }

            for (int i=0; i<line_len; ++i){
                if (empty[i] && empty[i+1]){
                    switch (line[i]){
                        case 4:  return inf;
                        case 3:  total_val += 1000000;  break;
                        case 2:  total_val += 10000;  break;
                        case 1:  total_val += 100;  break;
                    }
                }
                else{
                    switch (line[i]){
                        case 4:
                            if(off)  return inf;
                            total_val += 1000000;
                            break;
                        case 3:  total_val += 10000;  break;
                        case 2:  total_val += 100;  break;
                    }
                }
            }

            for (int i=1; i<empty_len-1; ++i){
                if (empty[i]==1 && empty[i-1] && empty[i+1]){
                    switch (line[i-1]+line[i]){
                        case 2:  total_val+=5000;  break;
                        case 3:  total_val+=1000000;  break;
                        case 4:
                            if (off)  return inf;
                            total_val += 1000000;
                            break;
                    }
                }
            }
        }
    }

    //calc lef top
    for (int i=0; i<21; ++i){
        int cur_pos=0;
        int tmpr=lef_top_r[i];
        int tmpc=lef_top_c[i];
        int tmpmax = tmpr>tmpc?tmpr:tmpc;
        while (tmpmax+cur_pos<15){
            int line[10]={0};
            int empty[10]={0};
            int line_len=0;
            int empty_len=0;
            int section_len;
            int cur_len=0;

            while (tmpmax+cur_pos<15 && Gobang_board[tmpr+cur_pos][tmpc+cur_pos] == (3^type))  ++cur_pos;
            section_len=cur_pos;

            while (tmpmax+cur_pos<15 && Gobang_board[tmpr+cur_pos][tmpc+cur_pos] == 0)  ++cur_pos, ++cur_len;
            empty[empty_len++]=cur_len;

            while (true){
                if (tmpmax+cur_pos == 15 || Gobang_board[tmpr+cur_pos][tmpc+cur_pos] == (3^type))  break;

                cur_len=0;
                while (tmpmax+cur_pos<15  && Gobang_board[tmpr+cur_pos][tmpc+cur_pos] == type)  ++cur_pos, ++cur_len;
                line[line_len++]=cur_len;

                cur_len=0;
                while (tmpmax+cur_pos<15  && Gobang_board[tmpr+cur_pos][tmpc+cur_pos] == 0)  ++cur_pos, ++cur_len;
                empty[empty_len++]=cur_len;
            }
            section_len=cur_pos-section_len;



            if (empty_len == 1 || section_len <= 4)  continue;

            if (section_len == 5){
                int total_len=0;
                for (int i=0; i<line_len; ++i){
                    total_len += line[i];
                }
                if (total_len == 4 && off)  return inf;
                else  total_val += value[total_len-1];
                continue;
            }

            for (int i=0; i<line_len; ++i){
                if (empty[i] && empty[i+1]){
                    switch (line[i]){
                        case 4:  return inf;
                        case 3:  total_val += 1000000;  break;
                        case 2:  total_val += 10000;  break;
                        case 1:  total_val += 100;  break;
                    }
                }
                else{
                    switch (line[i]){
                        case 4:
                            if(off)  return inf;
                            total_val += 1000000;
                            break;
                        case 3:  total_val += 10000;  break;
                        case 2:  total_val += 100;  break;
                    }
                }
            }

            for (int i=1; i<empty_len-1; ++i){
                if (empty[i]==1 && empty[i-1] && empty[i+1]){
                    switch (line[i-1]+line[i]){
                        case 2:  total_val+=5000;  break;
                        case 3:  total_val+=1000000;  break;
                        case 4:
                            if (off)  return inf;
                            total_val += 1000000;
                            break;
                    }
                }
            }
        }
    }

    //calc rig top
    for (int i=0; i<21; ++i){
        int cur_pos=0;
        int tmpr=rig_top_r[i];
        int tmpc=rig_top_c[i];
        int tmpmax = (14-tmpr)>tmpc?(14-tmpr):tmpc;
        while (tmpmax+cur_pos<15){
            int line[10]={0};
            int empty[10]={0};
            int line_len=0;
            int empty_len=0;
            int section_len;
            int cur_len=0;

            while (tmpmax+cur_pos<15 && Gobang_board[tmpr-cur_pos][tmpc+cur_pos] == (3^type))  ++cur_pos;
            section_len=cur_pos;

            while (tmpmax+cur_pos<15 && Gobang_board[tmpr-cur_pos][tmpc+cur_pos] == 0)  ++cur_pos, ++cur_len;
            empty[empty_len++]=cur_len;

            while (true){
                if (tmpmax+cur_pos == 15 || Gobang_board[tmpr-cur_pos][tmpc+cur_pos] == (3^type))  break;

                cur_len=0;
                while (tmpmax+cur_pos<15  && Gobang_board[tmpr-cur_pos][tmpc+cur_pos] == type)  ++cur_pos, ++cur_len;
                line[line_len++]=cur_len;

                cur_len=0;
                while (tmpmax+cur_pos<15  && Gobang_board[tmpr-cur_pos][tmpc+cur_pos] == 0)  ++cur_pos, ++cur_len;
                empty[empty_len++]=cur_len;
            }
            section_len=cur_pos-section_len;



            if (empty_len == 1 || section_len <= 4)  continue;

            if (section_len == 5){
                int total_len=0;
                for (int i=0; i<line_len; ++i){
                    total_len += line[i];
                }
                if (total_len == 4 && off)  return inf;
                else  total_val += value[total_len-1];
                continue;
            }

            for (int i=0; i<line_len; ++i){
                if (empty[i] && empty[i+1]){
                    switch (line[i]){
                        case 4:  return inf;
                        case 3:  total_val += 1000000;  break;
                        case 2:  total_val += 10000;  break;
                        case 1:  total_val += 100;  break;
                    }
                }
                else{
                    switch (line[i]){
                        case 4:
                            if(off)  return inf;
                            total_val += 1000000;
                            break;
                        case 3:  total_val += 10000;  break;
                        case 2:  total_val += 100;  break;
                    }
                }
            }

            for (int i=1; i<empty_len-1; ++i){
                if (empty[i]==1 && empty[i-1] && empty[i+1]){
                    switch (line[i-1]+line[i]){
                        case 2:  total_val+=5000;  break;
                        case 3:  total_val+=1000000;  break;
                        case 4:
                            if (off)  return inf;
                            total_val += 1000000;
                            break;
                    }
                }
            }
        }
    }

    return total_val;
}

int evaluate(int side){
    int offv=evaluate_val(side, 1);
    int defv=evaluate_val(side^3, 0);
    if (offv==inf)  return inf;
    if (defv==inf)  return -inf;
    return offv-(defv<<2)/5;
}

#endif