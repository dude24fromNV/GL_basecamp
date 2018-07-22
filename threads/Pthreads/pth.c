#include "timer.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <pthread.h>


struct th_data {
        int th_id;
        long long number;
        long long s_slice;
        int **arr1;
        int **arr2;
        int **res_arr;
        pthread_mutex_t *lock;
        struct timespec start_time, end_time;
};

void *mult_matrix ( void *args ){
        struct th_data *data = args;
        printf("thread%d start \n", data->th_id);
        clock_gettime(CLOCK_REALTIME, &data->start_time);
        for(long long i = 0; i < data->s_slice; i++){
                for(long long j = 0; j < data->number; j++){
                        for(long long k = 0; k < data->number; k++){
                                data->res_arr[i][j] += data->arr1[i][k]*data->arr2[k][j];
                        };
                };
        };
        clock_gettime(CLOCK_REALTIME, &data->end_time);
        double time = timespec_diff(&data->end_time, &data->start_time);
        printf("finish thread%d time: %g\n", data->th_id, time);
        return 0;
}

void init_func(int **arr1, int **arr2, long long number){
        for(long long i = 0; i < number; i++){
                for(long long j = 0; j < number ; j++){
                arr1[i][j]=(rand()%INT_MAX);
                arr2[i][j]=(rand()%INT_MAX);
                };
        };
}

int main(int argc, char *argv[]){

        int num_thr = 0 ;
        long long N = 0; //size array

        if (argc == 1) {
                printf("not enter number threads and size array\n");
                return 0;
        }
        if (argc == 2) {
                printf("not enter size array\n");
                return 0;
        }
        if (argc >= 4) {
                printf("too much argument\n");
                return 0;
        }
        num_thr = atoi(argv[1]);
        N = atoi(argv[2]);
        if (N % num_thr) {
                printf("NUM_THREADS is not a divisor of ARRAY_SIZE\n");
                exit(EXIT_FAILURE);
        }

        int **array1 = malloc(N*sizeof(int*));
        int **array2 = malloc(N*sizeof(int*));
        int **res_array = malloc(N*sizeof(int*));
        for(int i = 0; i < N; i++){
                array1[i] = malloc(N * sizeof(int));
                array2[i] =  malloc(N * sizeof(int));
                res_array[i] =  malloc(N * sizeof(int));
        }
        if ((num_thr <= 0 || N<=0) || (num_thr >= 5 || N >= INT_MAX) ) {
                printf("number threads and size array must > 0");
                exit(EXIT_FAILURE);
        }
        
        init_func(array1, array2, N);

        pthread_t thread[num_thr];
        struct th_data  t_data[num_thr];

        pthread_attr_t thread_attrs;
        pthread_attr_init(&thread_attrs);

        struct timespec start_time, end_time;
        clock_gettime(CLOCK_REALTIME, &start_time);

        for (int i = 0; i < num_thr; i++){
                long long slice = N / num_thr;
                t_data[i].th_id = i;
                t_data[i].s_slice = slice;
                t_data[i].number = N;
                t_data[i].arr1= &array1[i*slice];
                t_data[i].arr2= array2;
                t_data[i].res_arr = &res_array[i*slice];
                pthread_create(&thread[i], &thread_attrs, &mult_matrix, &t_data[i]);
        }

        for (int i = 0; i < num_thr; i++){
                pthread_join(thread[i], NULL);
        }

        clock_gettime(CLOCK_REALTIME, &end_time);
        double global_time = timespec_diff(&end_time, &start_time);

        printf("time global %g\n", global_time);

        if (N<5){
                for(int i =0; i<N;i++){
                        for(int j=0;j<N;++j){
                        printf("%d |", array1[i][j]);
                        }
                        printf("\n");
                }
                printf("----------------------\n");
                for(int i =0; i<N;i++){
                        for(int j=0;j<N;++j){
                        printf("%d |", array2[i][j]);
                        }
                        printf("\n");
                }
                printf("----------------------\n");
                for(int i =0; i<N;i++){
                        for(int j=0;j<N;++j){
                        printf("%d |", res_array[i][j]);
                        }
                        printf("\n");
                }
        }
        free(array1);
        free(array2);
        free(res_array);
return 0;
}
