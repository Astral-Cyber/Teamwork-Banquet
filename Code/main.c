#include <stdio.h>

int main() {
    char name1[20],name2[20];
    FILE *enemies = fopen("../Name-list/Enemies.txt", "r");//打开文件
    while (!feof(enemies)){//获取每一行的两个名字，分别储存为name1和name2
        fscanf(enemies,"%s %s",name1,name2);
        printf("%s %s\n",name1,name2);
    }
    return 0;
}
