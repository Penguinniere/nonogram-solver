#ifndef __COMMON_H__
    #define __COMMON_H__
    #include "common.h"
#endif

Board board;
bool nonSolve = true;
int (*validate)( int, char*, Limit*, Limit*);

void dfs_init(){
    Limit limit[boardSize];
    for( int i=0; i<boardSize; ++i)
        limit[i].min = hint[COL][i].sum + hint[COL][i].num -1; 
    board.reset();
    nonSolve = true;
    validate = validate_simple;
    dfs(0, limit);
}

void dfs_min_init(){
    Limit limit[boardSize];
    for( int i=0; i<boardSize; ++i)
        limit[i].min = hint[COL][i].sum + hint[COL][i].num -1; 
    board.reset();
    nonSolve = true;
    validate = validate_min;
    dfs(0, limit);
}

void dfs(int row, Limit* limit){
    if(row >= boardSize){
        board.print();
        nonSolve = false;
        return;
    }
    //printf("row %d\n", row);
    
    Limit newLimit[boardSize];
    char line[LINE_SIZE]={0};
    int num = hint[ROW][row].num-1; //how many white between black
    
    if( num==-1){ //empty row
        if(validate( row, line, limit, newLimit)){
            memset( board.grid[row], GRID_WHI, sizeof(char)*BOARD_SIZE);
            //test_row( line, 0);
            dfs( row+1, newLimit);
        }
    }
    else if( num == 0){ //only one hint
        generate_line( hint[ROW][row] , NULL, line);
        //test_line( line);
        for( int i=0;  nonSolve && i <= boardSize-hint[ROW][row].sum; ++i){
            //test_row( line, i);
            if(validate( row, &(line[31-i]), limit, newLimit)){
                memcpy( board.grid[row], &(line[31-i]), sizeof(char)*BOARD_SIZE);
                dfs( row+1, newLimit);
            }                
        }
    }
    else{
        for( int len = num; nonSolve && len <= boardSize-hint[ROW][row].sum; ++len){
            for( Comb* ptr = comb[num][len]; nonSolve && ptr; ptr = ptr->next){
                generate_line( hint[ROW][row] , ptr, line);
                //test_line( line);
                for( int i=0; nonSolve && i <= boardSize-hint[ROW][row].sum-len; ++i){
                    //test_row( line, i);
                    if( validate( row, &(line[31-i]),limit, newLimit)){
                        memcpy( board.grid[row], &(line[31-i]), sizeof(char)*BOARD_SIZE);
                        dfs(row+1, newLimit);
                    }
                }
            }
        }
    }
    //printf("return\n");
    memset( board.grid[row], GRID_UND, sizeof(char)*BOARD_SIZE);
}

void generate_line( Hint &hint, Comb* ptr, char* line){
    memset( line, GRID_WHI, sizeof(char)*LINE_SIZE);
    int lidx = 31;
    
    for( int hidx=0; hidx < hint.num; hidx++){
        for( int i=0; i < hint.hint[hidx]; ++i, lidx++)
            line[lidx] = GRID_BLA;
        if( hidx < hint.num-1)
            lidx += (ptr->num[hidx]);
    }
}

void test_line(char* line){
    printf("#");
    for( int i=31; i<31+boardSize; ++i)
        printf("%d ", line[i]);
    printf("\n");
}

void test_row(char* line, int k){
    for(int i=0; i<boardSize; ++i)
        printf("%d ", line[31-k+i]);
    printf("\n");
}

int validate_simple( int row, char* line, Limit* oldL, Limit* newL){
    for( int i=0; i < boardSize; ++i){
        
        memcpy( &newL[i], &oldL[i], sizeof(Limit));
        
        int run = hint[COL][i].hint[newL[i].idx];
        if(line[i]){ //grid is black
            newL[i].run ++;  
            if( newL[i].run > run)
                return 0;
            //newL[i].min --;
        }
        else{ //grid is white
            if( newL[i].run){ //pre grid is black
                if( newL[i].run < run)
                    return 0;
                newL[i].run = 0;
                newL[i].idx ++;
                //newL[i].min --;
            }
        }
        //if( newL[i].min > boardSize-(row+1))
            //return 0;
    }
    if( row+1 >=boardSize){
        for( int i=0; i<boardSize; ++i){
            if( (newL[i].idx == hint[COL][i].num) && (newL[i].run==0))
                {continue;}
            else if( newL[i].idx+1 == hint[COL][i].num && 
                (newL[i].run == hint[COL][i].hint[newL[i].idx]))
                {continue;}
            else
                return 0;
        }
    }
    
    return 1;
}


int validate_min( int row, char* line, Limit* oldL, Limit* newL){
    for( int i=0; i < boardSize; ++i){
        
        memcpy( &newL[i], &oldL[i], sizeof(Limit));
        
        int run = hint[COL][i].hint[newL[i].idx];
        if(line[i]){ //grid is black
            newL[i].run ++;  
            if( newL[i].run > run)
                return 0;
            newL[i].min --;
        }
        else{ //grid is white
            if( newL[i].run){ //pre grid is black
                if( newL[i].run < run)
                    return 0;
                newL[i].run = 0;
                newL[i].idx ++;
                newL[i].min --;
            }
        }
        if( newL[i].min > boardSize-(row+1))
            return 0;
    }
    return 1;
}