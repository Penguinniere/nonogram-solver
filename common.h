#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>

#define BOARD_SIZE 32
#define HINT_SIZE (BOARD_SIZE+1)/2
#define BICOEF_SIZE BOARD_SIZE+2
#define LINE_SIZE BOARD_SIZE<<1
 
#define COL 0
#define ROW 1

#include "comb.h"
#include "hint.h"
#include "board.h"
#include "rowbase.h"

void build_binomial();
void test_binomial();
void decision_order(int);

extern int boardSize;
extern int biCoef[BICOEF_SIZE][BICOEF_SIZE];
extern int order[2][BOARD_SIZE];
extern Comb* comb[HINT_SIZE][BOARD_SIZE+1];
extern Hint hint[2][BOARD_SIZE];
extern bool solve;
extern void (*search)();