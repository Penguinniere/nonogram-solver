#ifndef __COMMON_H__
    #define __COMMON_H__
    #include "common.h"
#endif



Hint hint[2][BOARD_SIZE] = {0};

void load_hint( FILE *file){
    char text[1024];
    char tem = 0;
    memset( hint, 0, sizeof(hint));
    
    //get the board no 
    fgets(text, 1024, file);
    for( int m=0; m<2; ++m){
        for(int i=0; i<boardSize; ++i){
            fgets( text, 1024, file);
            for( int k = 0; ; k++){
                if( text[k]=='\t' || text[k]=='\n' || text[k]=='\r'){
                    hint[m][i].hint[hint[m][i].num++] = tem;
                    hint[m][i].sum += tem;
                    tem = 0;
                    if( text[k]=='\n' || text[k]=='\r')
                        break;
                }
                else{
                    tem *= 10;
                    tem += (text[k]-'0');
                }
            }
            hint[m][i].possible = biCoef[boardSize-hint[m][i].sum+1][hint[m][i].num];
        }
    }
}

void test_hint(){
    for( int m=0; m<2; ++m){
        for(int i=0; i<boardSize; ++i){
            for( int k=0; k< hint[m][i].num; ++k){
                printf("%d ", hint[m][i].hint[k]);
            }
            printf("%d", hint[m][i].possible);
            printf("\n");
        }
    }
}