#define GRID_UND -1
#define GRID_WHI 0
#define GRID_BLA 1


struct Board{
    char grid[BOARD_SIZE][BOARD_SIZE];
    Board(){memset(  this->grid, GRID_UND, sizeof(this->grid));};
    void copy(Board &newBoard){memcpy ( newBoard.grid, this->grid, sizeof(this->grid));};
    void reset(){memset(  this->grid, GRID_UND, sizeof(this->grid));};
    void print();
   
};typedef struct Board Board;

