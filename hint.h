struct Hint{
    char num;
    char hint[HINT_SIZE];
    char sum;
    int possible;
};typedef struct Hint Hint;

void load_hint(FILE*);
void test_hint();