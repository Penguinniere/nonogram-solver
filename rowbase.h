struct Limit{
    char idx;
    char run;
    char min;
    Limit(){ this->idx=0; this->run=0; this->min=0;};
};typedef struct Limit Limit;

void dfs_init();  //init limitation by column
void dfs_min_init();
void dfs(int, Limit*);
void generate_line(Hint&, Comb*, char*);
void test_line(char*);
void test_row(char* , int);
int validate_simple( int, char*, Limit*, Limit*);
int validate_min( int, char*, Limit*, Limit*);