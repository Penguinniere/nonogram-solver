struct Comb{
    char *num;
    struct Comb* next;
    Comb();
    Comb(int);
};typedef struct Comb Comb;

void load_combination();
void test_combination();