#include <stdio.h>
#include <stdlib.h>
#include "algo.h"
#define true 1
#define false 0

void Lee (int W, int H, int (*grid)[H], int sx, int sy, int fx, int fy){
        int wall=-1;
        int empty_cell = -2;
        int len_way;
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};

        int px[W*H], py[W*H];
        int d, x, y, k;
        char stop;
             
        d=0;
        grid[sx][sy]=0;
        do{
                stop= true;
                for(x=0; x<W;++x)
                    for(y=0;y<H;++y)
                        if(grid[x][y]==d){
                            for(k=0;k<4;++k){
                                int ix=x+dx[k], iy=y+dy[k];
                                if(iy>=0&&iy<H && ix>=0 && ix <W && grid[ix][iy]==empty_cell){
                                    stop=false;
                                    grid[ix][iy] =d+1;
                                    }
                                }
                        }
                d++;
        }while(stop==false && grid[fx][fy]==empty_cell);

        if (grid[fx][fy]== empty_cell){printf("no way");
                exit(0);}

        len_way = grid[fx][fy];
        x=fx;
        y=fy;
        d=len_way;
        while(d>0){
                px[d] = x;
                py[d] = y;                   
                d--;
                for (k = 0; k < 4; ++k){
                        int iy=y + dy[k], ix = x + dx[k];
                        if ( iy >= 0 && iy < H && ix >= 0 && ix < W && grid[ix][iy] == d){
                                x = x + dx[k];
                                y = y + dy[k];           
                                break;
                        }
                }
         }
        px[0] = sx;
        py[0] = sy;     
        printf("----------------------\n");
        for(int i =0; i<len_way;++i) printf("%2d %2d\n", px[i], py[i]);             
        printf("----------------------\n");
}