#ifndef TIMER_H
#define TIMER_H

#include <stdio.h>
#include <time.h>

static clock_t timer;

static inline void start_timer(){
    timer = clock();
}

static inline void stop_timer(){
    clock_t end = clock();
    double times = (double)(end - timer) * 1000.0 / CLOCKS_PER_SEC;  
    printf("Times: %.3f ms\n", times);
}

#endif