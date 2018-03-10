#ifndef __COMMON_H__
    #define __COMMON_H__
    #include "common.h"
#endif


int biCoef[BICOEF_SIZE][BICOEF_SIZE];
int order[2][BOARD_SIZE];

void build_binomial(){
    for( int n=0; n<BICOEF_SIZE; ++n)
        biCoef[n][0] = 1;
    for( int n=0; n<BICOEF_SIZE; ++n)
        for( int k=1; k<=n; ++k)
            biCoef[n][k] = biCoef[n-1][k] + biCoef[n-1][k-1];
}

void test_binomial(){
    for( int n=0; n < BICOEF_SIZE; ++n){
        for( int k=0; k < BICOEF_SIZE; ++k)
            printf("%d ", biCoef[n][k]);
        printf("\n");
    }
}

void decision_order( int change){
    int posibble[BOARD_SIZE];
    for(int m=0; m<2; ++m){
        for( int i=0; i<boardSize; ++i){
            posibble[i] = hint[m][i].possible; //H(m,n)
            order[m][i] = i;
        }
        
        if( !change)
            continue;
        
        for( int i=0; i<boardSize; ++i){
            int min = INT_MAX;
            int arg = -1;
            for( int k=i; k<boardSize; ++k){
                if( posibble[k] < min){
                    min = posibble[k];
                    arg = k;
                }
            }
            std::swap( posibble[i], posibble[arg]);
            std::swap( order[m][i], order[m][arg]);
        }
    }
}