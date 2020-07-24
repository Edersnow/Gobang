#ifndef __Generator
#define __Generator
#include "Global.hpp"

inline void update_val(int &old_val, int new_val){
    if (new_val > old_val)  old_val = new_val;
}

struct generator{
    struct pai{
        poin cur_point;
        int val;

        friend bool operator>(const pai &tmp, const pai &other) {return tmp.val>other.val;}
    };

    pai que[225];
    int que_len;
    int cnt;
    int total_val[15][15];
    int val[15][15];
    int count2[15][15];

    void producer(int type){
        //calc row
        for (int i=0; i<15; ++i){
            int cur_pos=0;
            while (cur_pos<15){
                int line[10]={0};
                int empty[10]={0};
                int lef[10]={0};
                int rig[10]={0};
                int line_len=0;
                int empty_len=0;
                int lef_len=0;
                int rig_len=0;
                int section_len;
                int cur_len=0;

                while (cur_pos<15 && Gobang_board[i][cur_pos] == (3^type))  ++cur_pos;
                section_len=cur_pos;

                while (cur_pos<15 && Gobang_board[i][cur_pos] == 0)  ++cur_pos, ++cur_len;
                empty[empty_len++]=cur_len;

                while (true){
                    if (cur_pos == 15 || Gobang_board[i][cur_pos] == (3^type))  break;

                    cur_len=0;
                    lef[lef_len++]=cur_pos;
                    while (cur_pos<15 && Gobang_board[i][cur_pos] == type)  ++cur_pos, ++cur_len;
                    rig[rig_len++]=cur_pos;
                    line[line_len++]=cur_len;

                    cur_len=0;
                    while (cur_pos<15 && Gobang_board[i][cur_pos] == 0)  ++cur_pos, ++cur_len;
                    empty[empty_len++]=cur_len;
                }
                section_len=cur_pos-section_len;



                if (empty_len == 1 || section_len <= 4)  continue;

                for (int j=0; j<line_len; ++j){
                    switch (line[j]){
                        case 1:
                            if (empty[j]>=2){
                                if (empty[j+1])  update_val(val[i][lef[j]-1], 10);
                                else  update_val(val[i][lef[j]-1], 3);
                            }
                            if (empty[j+1]>=2){
                                if (empty[j])  update_val(val[i][rig[j]], 10);
                                else  update_val(val[i][rig[j]], 3);
                            }
                            break;
                        case 2:
                            if (empty[j]>=2){
                                if (empty[j+1])  ++count2[i][lef[j]-1];
                                else  update_val(val[i][lef[j]-1], 10);
                            }
                            if (empty[j+1]>=2){
                                if (empty[j])  ++count2[i][rig[j]];
                                else  update_val(val[i][rig[j]], 10);
                            }
                            if (empty[j]>=3 && empty[j+1])  ++count2[i][lef[j]-2];
                            if (empty[j+1]>=3 && empty[j])  ++count2[i][rig[j]+1];
                            break;
                        case 3:
                            if (empty[j]>=2){
                                if (empty[j+1])  update_val(val[i][lef[j]-1], 10000);
                                else{
                                    ++count2[i][lef[j]-1];
                                    if (empty[j]>=3)  ++count2[i][lef[j]-2];
                                }
                            }
                            if (empty[j+1]>=2){
                                if (empty[j])  update_val(val[i][rig[j]], 10000);
                                else{
                                    ++count2[i][rig[j]];
                                    if (empty[j+1]>=3)  ++count2[i][rig[j]+1];
                                }
                            }
                            break;
                        case 4:
                            if (empty[j])  val[i][lef[j]-1]=100000;
                            if (empty[j+1])  val[i][rig[j]]=100000;
                            break;
                    }
                }

                for (int j=1; j<empty_len-1; ++j){
                    if (empty[j] == 1){
                        int tmp=line[j]+line[j-1];
                        if (tmp>=4){
                            val[i][rig[j-1]]=100000;
                            continue;
                        }
                        if (empty[j-1] && empty[j+1]){
                            switch (tmp){
                                case 1:  update_val(val[i][rig[j-1]], 10);  break;
                                case 2:  ++count2[i][rig[j-1]];  ++count2[i][rig[j]];  ++count2[i][lef[j-1]-1];  break;
                                case 3:  update_val(val[i][rig[j-1]], 10000);  break;
                            }
                        }
                        else{
                            switch (tmp){
                                case 2:  update_val(val[i][rig[j-1]], 10);  break;
                                case 3:
                                    ++count2[i][rig[j-1]];
                                    if (empty[j-1])  ++count2[i][lef[j-1]-1];
                                    else  ++count2[i][rig[j]];
                                    break;
                            }
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
                int lef[10]={0};
                int rig[10]={0};
                int line_len=0;
                int empty_len=0;
                int lef_len=0;
                int rig_len=0;
                int section_len;
                int cur_len=0;

                while (cur_pos<15 && Gobang_board[cur_pos][i] == (3^type))  ++cur_pos;
                section_len=cur_pos;

                while (cur_pos<15 && Gobang_board[cur_pos][i] == 0)  ++cur_pos, ++cur_len;
                empty[empty_len++]=cur_len;

                while (true){
                    if (cur_pos == 15 || Gobang_board[cur_pos][i] == (3^type))  break;

                    cur_len=0;
                    lef[lef_len++]=cur_pos;
                    while (cur_pos<15 && Gobang_board[cur_pos][i] == type)  ++cur_pos, ++cur_len;
                    rig[rig_len++]=cur_pos;
                    line[line_len++]=cur_len;

                    cur_len=0;
                    while (cur_pos<15 && Gobang_board[cur_pos][i] == 0)  ++cur_pos, ++cur_len;
                    empty[empty_len++]=cur_len;
                }
                section_len=cur_pos-section_len;



                if (empty_len == 1 || section_len <= 4)  continue;

                for (int j=0; j<line_len; ++j){
                    switch (line[j]){
                        case 1:
                            if (empty[j]>=2){
                                if (empty[j+1])  update_val(val[lef[j]-1][i], 10);
                                else  update_val(val[lef[j]-1][i], 3);
                            }
                            if (empty[j+1]>=2){
                                if (empty[j])  update_val(val[rig[j]][i], 10);
                                else  update_val(val[rig[j]][i], 3);
                            }
                            break;
                        case 2:
                            if (empty[j]>=2){
                                if (empty[j+1])  ++count2[lef[j]-1][i];
                                else  update_val(val[lef[j]-1][i], 10);
                            }
                            if (empty[j+1]>=2){
                                if (empty[j])  ++count2[rig[j]][i];
                                else  update_val(val[rig[j]][i], 10);
                            }
                            if (empty[j]>=3 && empty[j+1])  ++count2[lef[j]-2][i];
                            if (empty[j+1]>=3 && empty[j])  ++count2[rig[j]+1][i];
                            break;
                        case 3:
                            if (empty[j]>=2){
                                if (empty[j+1])  update_val(val[lef[j]-1][i], 10000);
                                else{
                                    ++count2[lef[j]-1][i];
                                    if (empty[j]>=3)  ++count2[lef[j]-2][i];
                                }
                            }
                            if (empty[j+1]>=2){
                                if (empty[j])  update_val(val[rig[j]][i], 10000);
                                else{
                                    ++count2[rig[j]][i];
                                    if (empty[j+1]>=3)  ++count2[rig[j]+1][i];
                                }
                            }
                            break;
                        case 4:
                            if (empty[j])  val[lef[j]-1][i]=100000;
                            if (empty[j+1])  val[rig[j]][i]=100000;
                            break;
                    }
                }

                for (int j=1; j<empty_len-1; ++j){
                    if (empty[j] == 1){
                        int tmp=line[j]+line[j-1];
                        if (tmp>=4){
                            val[rig[j-1]][i]=100000;
                            continue;
                        }
                        if (empty[j-1] && empty[j+1]){
                            switch (tmp){
                                case 1:  update_val(val[rig[j-1]][i], 10);  break;
                                case 2:  ++count2[rig[j-1]][i];  ++count2[rig[j]][i];  ++count2[lef[j-1]-1][i];  break;
                                case 3:  update_val(val[rig[j-1]][i], 10000);  break;
                            }
                        }
                        else{
                            switch (tmp){
                                case 2:  update_val(val[rig[j-1]][i], 10);  break;
                                case 3:
                                    ++count2[rig[j-1]][i];
                                    if (empty[j-1])  ++count2[lef[j-1]-1][i];
                                    else  ++count2[rig[j]][i];
                                    break;
                            }
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
                int lef[10]={0};
                int rig[10]={0};
                int line_len=0;
                int empty_len=0;
                int lef_len=0;
                int rig_len=0;
                int section_len;
                int cur_len=0;

                while (tmpmax+cur_pos<15 && Gobang_board[tmpr+cur_pos][tmpc+cur_pos] == (3^type))  ++cur_pos;
                section_len=cur_pos;

                while (tmpmax+cur_pos<15 && Gobang_board[tmpr+cur_pos][tmpc+cur_pos] == 0)  ++cur_pos, ++cur_len;
                empty[empty_len++]=cur_len;

                while (true){
                    if (tmpmax+cur_pos == 15 || Gobang_board[tmpr+cur_pos][tmpc+cur_pos] == (3^type))  break;

                    cur_len=0;
                    lef[lef_len++]=cur_pos;
                    while (tmpmax+cur_pos<15  && Gobang_board[tmpr+cur_pos][tmpc+cur_pos] == type)  ++cur_pos, ++cur_len;
                    rig[rig_len++]=cur_pos;
                    line[line_len++]=cur_len;

                    cur_len=0;
                    while (tmpmax+cur_pos<15  && Gobang_board[tmpr+cur_pos][tmpc+cur_pos] == 0)  ++cur_pos, ++cur_len;
                    empty[empty_len++]=cur_len;
                }
                section_len=cur_pos-section_len;



                if (empty_len == 1 || section_len <= 4)  continue;

                for (int j=0; j<line_len; ++j){
                    switch (line[j]){
                        case 1:
                            if (empty[j]>=2){
                                if (empty[j+1])  update_val(val[tmpr+lef[j]-1][tmpc+lef[j]-1], 10);
                                else  update_val(val[tmpr+lef[j]-1][tmpc+lef[j]-1], 3);
                            }
                            if (empty[j+1]>=2){
                                if (empty[j])  update_val(val[tmpr+rig[j]][tmpc+rig[j]], 10);
                                else  update_val(val[tmpr+rig[j]][tmpc+rig[j]], 3);
                            }
                            break;
                        case 2:
                            if (empty[j]>=2){
                                if (empty[j+1])  ++count2[tmpr+lef[j]-1][tmpc+lef[j]-1];
                                else  update_val(val[tmpr+lef[j]-1][tmpc+lef[j]-1], 10);
                            }
                            if (empty[j+1]>=2){
                                if (empty[j])  ++count2[tmpr+rig[j]][tmpc+rig[j]];
                                else  update_val(val[tmpr+rig[j]][tmpc+rig[j]], 10);
                            }
                            if (empty[j]>=3 && empty[j+1])  ++count2[tmpr+lef[j]-2][tmpc+lef[j]-2];
                            if (empty[j+1]>=3 && empty[j])  ++count2[tmpr+rig[j]+1][tmpc+rig[j]+1];
                            break;
                        case 3:
                            if (empty[j]>=2){
                                if (empty[j+1])  update_val(val[tmpr+lef[j]-1][tmpc+lef[j]-1], 10000);
                                else{
                                    ++count2[tmpr+lef[j]-1][tmpc+lef[j]-1];
                                    if (empty[j]>=3)  ++count2[tmpr+lef[j]-2][tmpc+lef[j]-2];
                                }
                            }
                            if (empty[j+1]>=2){
                                if (empty[j])  update_val(val[tmpr+rig[j]][tmpc+rig[j]], 10000);
                                else{
                                    ++count2[tmpr+rig[j]][tmpc+rig[j]];
                                    if (empty[j+1]>=3)  ++count2[tmpr+rig[j]+1][tmpc+rig[j]+1];
                                }
                            }
                            break;
                        case 4:
                            if (empty[j])  val[tmpr+lef[j]-1][tmpc+lef[j]-1]=100000;
                            if (empty[j+1])  val[tmpr+rig[j]][tmpc+rig[j]]=100000;
                            break;
                    }
                }

                for (int j=1; j<empty_len-1; ++j){
                    if (empty[j] == 1){
                        int tmp=line[j]+line[j-1];
                        if (tmp>=4){
                            val[tmpr+rig[j-1]][tmpc+rig[j-1]]=100000;
                            continue;
                        }
                        if (empty[j-1] && empty[j+1]){
                            switch (tmp){
                                case 1:  update_val(val[tmpr+rig[j-1]][tmpc+rig[j-1]], 10);  break;
                                case 2:  ++count2[tmpr+rig[j-1]][tmpc+rig[j-1]];  ++count2[tmpr+rig[j]][tmpc+rig[j]];  ++count2[tmpr+lef[j-1]-1][tmpc+lef[j-1]-1];  break;
                                case 3:  update_val(val[tmpr+rig[j-1]][tmpc+rig[j-1]], 10000);  break;
                            }
                        }
                        else{
                            switch (tmp){
                                case 2:  update_val(val[tmpr+rig[j-1]][tmpc+rig[j-1]], 10);  break;
                                case 3:
                                    ++count2[tmpr+rig[j-1]][tmpc+rig[j-1]];
                                    if (empty[j-1])  ++count2[tmpr+lef[j-1]-1][tmpc+lef[j-1]-1];
                                    else  ++count2[tmpr+rig[j]][tmpc+rig[j]];
                                    break;
                            }
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
                int lef[10]={0};
                int rig[10]={0};
                int line_len=0;
                int empty_len=0;
                int lef_len=0;
                int rig_len=0;
                int section_len;
                int cur_len=0;

                while (tmpmax+cur_pos<15 && Gobang_board[tmpr-cur_pos][tmpc+cur_pos] == (3^type))  ++cur_pos;
                section_len=cur_pos;

                while (tmpmax+cur_pos<15 && Gobang_board[tmpr-cur_pos][tmpc+cur_pos] == 0)  ++cur_pos, ++cur_len;
                empty[empty_len++]=cur_len;

                while (true){
                    if (tmpmax+cur_pos == 15 || Gobang_board[tmpr-cur_pos][tmpc+cur_pos] == (3^type))  break;

                    cur_len=0;
                    lef[lef_len++]=cur_pos;
                    while (tmpmax+cur_pos<15  && Gobang_board[tmpr-cur_pos][tmpc+cur_pos] == type)  ++cur_pos, ++cur_len;
                    rig[rig_len++]=cur_pos;
                    line[line_len++]=cur_len;

                    cur_len=0;
                    while (tmpmax+cur_pos<15  && Gobang_board[tmpr-cur_pos][tmpc+cur_pos] == 0)  ++cur_pos, ++cur_len;
                    empty[empty_len++]=cur_len;
                }
                section_len=cur_pos-section_len;



                if (empty_len == 1 || section_len <= 4)  continue;

                for (int j=0; j<line_len; ++j){
                    switch (line[j]){
                        case 1:
                            if (empty[j]>=2){
                                if (empty[j+1])  update_val(val[tmpr-lef[j]+1][tmpc+lef[j]-1], 10);
                                else  update_val(val[tmpr-lef[j]+1][tmpc+lef[j]-1], 3);
                            }
                            if (empty[j+1]>=2){
                                if (empty[j])  update_val(val[tmpr-rig[j]][tmpc+rig[j]], 10);
                                else  update_val(val[tmpr-rig[j]][tmpc+rig[j]], 3);
                            }
                            break;
                        case 2:
                            if (empty[j]>=2){
                                if (empty[j+1])  ++count2[tmpr-lef[j]+1][tmpc+lef[j]-1];
                                else  update_val(val[tmpr-lef[j]+1][tmpc+lef[j]-1], 10);
                            }
                            if (empty[j+1]>=2){
                                if (empty[j])  ++count2[tmpr-rig[j]][tmpc+rig[j]];
                                else  update_val(val[tmpr-rig[j]][tmpc+rig[j]], 10);
                            }
                            if (empty[j]>=3 && empty[j+1])  ++count2[tmpr-lef[j]+2][tmpc+lef[j]-2];
                            if (empty[j+1]>=3 && empty[j])  ++count2[tmpr-rig[j]-1][tmpc+rig[j]+1];
                            break;
                        case 3:
                            if (empty[j]>=2){
                                if (empty[j+1])  update_val(val[tmpr-lef[j]+1][tmpc+lef[j]-1], 10000);
                                else{
                                    ++count2[tmpr-lef[j]+1][tmpc+lef[j]-1];
                                    if (empty[j]>=3)  ++count2[tmpr-lef[j]+2][tmpc+lef[j]-2];
                                }
                            }
                            if (empty[j+1]>=2){
                                if (empty[j])  update_val(val[tmpr-rig[j]][tmpc+rig[j]], 10000);
                                else{
                                    ++count2[tmpr-rig[j]][tmpc+rig[j]];
                                    if (empty[j+1]>=3)  ++count2[tmpr-rig[j]-1][tmpc+rig[j]+1];
                                }
                            }
                            break;
                        case 4:
                            if (empty[j])  val[tmpr-lef[j]+1][tmpc+lef[j]-1]=100000;
                            if (empty[j+1])  val[tmpr-rig[j]][tmpc+rig[j]]=100000;
                            break;
                    }
                }

                for (int j=1; j<empty_len-1; ++j){
                    if (empty[j] == 1){
                        int tmp=line[j]+line[j-1];
                        if (tmp>=4){
                            val[tmpr-rig[j-1]][tmpc+rig[j-1]]=100000;
                            continue;
                        }
                        if (empty[j-1] && empty[j+1]){
                            switch (tmp){
                                case 1:  update_val(val[tmpr-rig[j-1]][tmpc+rig[j-1]], 10);  break;
                                case 2:  ++count2[tmpr-rig[j-1]][tmpc+rig[j-1]];  ++count2[tmpr-rig[j]][tmpc+rig[j]];  ++count2[tmpr-lef[j-1]+1][tmpc+lef[j-1]-1];  break;
                                case 3:  update_val(val[tmpr-rig[j-1]][tmpc+rig[j-1]], 10000);  break;
                            }
                        }
                        else{
                            switch (tmp){
                                case 2:  update_val(val[tmpr-rig[j-1]][tmpc+rig[j-1]], 10);  break;
                                case 3:
                                    ++count2[tmpr-rig[j-1]][tmpc+rig[j-1]];
                                    if (empty[j-1])  ++count2[tmpr-lef[j-1]+1][tmpc+lef[j-1]-1];
                                    else  ++count2[tmpr-rig[j]][tmpc+rig[j]];
                                    break;
                            }
                        }
                    }
                }
            }
        }

        for (int i=0; i<15; ++i){
            for (int j=0; j<15; ++j){
                if (count2[i][j]==1){
                    update_val(val[i][j], 100);
                    count2[i][j]=0;
                }
                if (count2[i][j]>=2){
                    update_val(val[i][j], 1000);
                    count2[i][j]=0;
                }
            }
        }
    }

    generator(int type){
        for (int i=0; i<15; ++i)
            for (int j=0; j<15; ++j)
                val[i][j]=total_val[i][j]=count2[i][j]=0;
        que_len=0;
        cnt=0;

        producer(type);
        for (int i=0; i<15; ++i){
            for (int j=0; j<15; ++j){
                if (val[i][j]){
                    total_val[i][j]=val[i][j];
                    val[i][j]=0;
                }
            }
        }

        producer(type^3);
        for (int i=0; i<15; ++i){
            for (int j=0; j<15; ++j){
                total_val[i][j]+=(val[i][j]<<2)/5;
                if (total_val[i][j]){
                    que[que_len].cur_point.row=i;
                    que[que_len].cur_point.col=j;
                    que[que_len++].val=total_val[i][j];
                }
            }
        }

        std::sort(que, que+que_len, std::greater<pai>());
        if (que_len>30)  que_len=30;
        while (turn>=3 && que[que_len].val<8)  --que_len;
    }

    poin generate(bool &isEnd) {
        poin res;
        if (cnt<que_len){
            res=que[cnt].cur_point;
            //note: the sum of all the others' value is 99999 
            if (que[cnt++].val >= 100000)  isEnd=true;
            else  isEnd=false;
            return res;
        }
        isEnd=false;
        res.row=-2;
        return res;
    }
};

#endif