#ifndef __COMMON_H__
    #define __COMMON_H__
    #include "common.h"
#endif

Comb* comb[HINT_SIZE][BOARD_SIZE+1];
    
Comb::Comb(){
    this->num = NULL;
    this->next = NULL;
}

Comb::Comb( int boardSize){
    this->num = new char[boardSize];
    this->next = NULL;
}

void load_combination(){
    
    char fileName[1000]={0};
    sprintf( fileName, "./comb/combb%d.txt", boardSize);
    
    FILE* combFile = fopen( fileName, "rb");
    Comb* ptr = NULL;
    
    int index=0, number = 0, sum = 0;
    char data;
    while(fread( &data, sizeof(char), 1, combFile)){
        if( data == -2){
            number ++;
            sum = number;
            comb[number][sum] = new Comb(sum);
            ptr = comb[number][sum];
            index = 0;
        }
        else if( data == -1){
            sum ++;
            comb[number][sum] = new Comb(sum);
            ptr = comb[number][sum];
            index = 0;
        }
        else{
            if( index==number){
                ptr->next = new Comb(sum);
                ptr = ptr->next;
                index = 0;
            }
            ptr->num[index++] = data;
        }
    }
}

void test_combination(){
    for( int num = 1;  comb[num][num]!=NULL; num++){
        for( int run = num; run < boardSize-num; run++){
            for( Comb* ptr = comb[num][run]; ptr!=NULL; ptr = ptr->next){
                for( int i=0; i<num; i++)
                    printf("%d ", ptr->num[i]);
                printf("\n");
            }
        }
    }
}