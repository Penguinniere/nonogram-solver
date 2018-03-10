#ifndef __COMMON_H__
    #define __COMMON_H__
    #include "common.h"
#endif

//global variable
FILE* input;
int boardSize;
int boardNum;
void (*search)();

int main( int argc, char** argv){
    //process argument
    if(argc<4){
        perror("Usage:./solver boardSize number board_input [alg]\n");
        return 1;
    }
    if( (boardSize = atoi(argv[1]))>32 || boardSize<5){
        perror("board size (5,32\n");
        return 1;
    }
    boardNum = atoi(argv[2]);
    
    if( (input = fopen(argv[3], "r"))==0){
        perror("Open file error\n");
        return 1;
    }
    
    search = dfs_init;
    if( argc==5){
        if( !strcmp(argv[4], "simple"))
            search = dfs_init;
        else if( !strcmp(argv[4], "min"))
            search = dfs_min_init;
    }
    
    build_binomial();
    //test_binomial();
    load_combination();
    //test_combination();
    
    for( int i=0; i<boardNum; i++){
        printf("$%d\n", i+1);
        load_hint( input);
        //test_hint();
        decision_order( 0);
        search();
    }
        
}
