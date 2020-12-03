#include <stdio.h>

int main() {
    char name[20];
    FILE *enemies = fopen("../Name-list/Enemies.txt", "r");//打开文件
    
    while (!feof(enemies)){
        fscanf(enemies,"%s",name);
        printf("%s\n",name);
    }
    return 0;
}
