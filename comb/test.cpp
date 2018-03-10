#include <cstdlib>
#include <cstdio>

using namespace std;

int main(){
    int data, num = 1, index = 0;
    
    printf("%d\n", sizeof(int));
    FILE *file = fopen("combb12.txt", "rb");
    while(fread( &data, sizeof(int), 1, file))
        printf("%d ", data);
}