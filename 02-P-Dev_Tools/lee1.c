#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "timer.h"
#include "algo.h"





int main(int argc, char *argv[])
{
        int W,H;
        int wall=-1;
        int empty_cell = -2;
        
        int sx, sy, fx, fy;
        

        if (argc == 1) {printf("not enter W and H");
                        exit(0);}
        if (argc == 2) {printf("not enter W");
                        exit(0);}
        if (argc >= 4) {printf("too much argument");
                        exit(0);}
	W = atoi(argv[1]);
        H = atoi(argv[2]);
        if (W <= 0 || H<=0) {printf("must 0<W && H");
                                exit(0);}

        int grid[W][H];
        time_t t;
        srand((unsigned) time(&t));
	

        printf("------Y0-Y1-Y2->-Y%d--------\n",H);
        for(int i =0; i<W;++i){
                printf("x%3d |",i);
                for(int j=0;j<H;++j){
                grid[i][j]=-1*(rand()%2+1);
                (grid[i][j]==-1)?printf("X"):printf(" ");
                }
                printf("|\n");
        }

        printf("----------------------\n");
        printf("enter start x y\n");
        if (scanf("%d %d", &sx, &sy)!=2) printf ("Must be 2 digital arfuments 'x y'");
        printf("enter finish x y\n");
        if (scanf("%d %d", &fx, &fy)!=2) printf ("Must be 2 digital arfuments 'x y'");

        if (grid[sx][sy]==wall || grid[fx][fy]==wall ) {
                printf("start poit or finish poit is a wall");
                exit(0);
        }
        
        struct timespec time_now, time_after;
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time_now);
       

        Lee(W, H, grid, sx, sy, fx,fy);

  
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time_after);

        printf("Time %g ms\n",timespec_diff(&time_after, &time_now));

        printf("------YYYY-----------\n");
        for(int i =0; i<W;++i){
                printf("x%3d |",i);
                for(int j=0;j<H;++j){
                        (grid[i][j]==-1)?printf("XX"):(grid[i][j]==-2)?printf("  "):printf("%2d", grid[i][j]);
                }
            printf("|\n");
        }
        printf("----------------------\n");


        
        return 0;
}


