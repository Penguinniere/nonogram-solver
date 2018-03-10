#ifndef __COMMON_H__
    #define __COMMON_H__
    #include "common.h"
#endif

void Board::print(){
    for( int i=0; i<boardSize; i++)
        for( int k=0; k<boardSize; k++){
            if( k==boardSize-1)
                printf("%d\n", this->grid[i][k]);
            else
                printf("%d\t", this->grid[i][k]);
        }
}