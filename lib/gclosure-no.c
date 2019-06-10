//
// Created by tonye on 2019-06-09.
//

#include <math.h>
#include <string.h>
#include <stdio.h>


typedef int(*Func2)(void *, void *);


static void
compare2(void *a, void *b, Func2 callback){
    int r = callback(a,b);
    if(r == -1){
        printf("a < b\n");
    }else if(r == 0){
        printf("a == b\n");
    }else{
        printf("a > b\n");
    }
}

static int
float_compare2(void *a, void *b){

    float *f1 = (float *)a; //获取指针对应的值 实参是&a
    float *f2 = (float *)b;

    g_printf("f1=%f, f2=%f\n", *f1, *f2);

    if(*f1 > *f2){
        return 1;
    }else if(fabs(*f1 - *f2) <= 10E-6){
        return 0;
    }else{
        return -1;
    }
}


static int
str_compare2(void *a, void *b){

    size_t len1 = strlen((char *)a);
    size_t len2 = strlen((char *)b);

    if(len1 > len2){
        return 1;
    }else if(len1 == len2){
        return 0;
    }else{
        return -1;
    }
}