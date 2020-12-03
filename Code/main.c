#include <stdio.h>
#include <string.h>

int main() {
    char name[20], name1[20], name2[20], name3[20], user[20];
    FILE *list;
    FILE *list1;
    FILE *list2;
    FILE *enemies;//打开文件
    printf("请输入宴会名单文件名称：");
    scanf("%s", user);//得到用户输入
    if (!strcmp(user, "A.txt"))//判断用户输入
        list = fopen("../Name-list/A.txt", "r");
    else
        list = fopen("../Name-list/B.txt", "r");
    int flag = 1;
    while (!feof(list)) {
        fscanf(list, "%s", name);//获取每一行邀请名单，储存为name
        //测试输出
        printf("%s\n", name);
        enemies = fopen("../Name-list/Enemies.txt", "r");
        while (!feof(enemies)) {//每一次循环获取一行的两个名字，分别储存为name1和name2
            fscanf(enemies, "%s %s", name1, name2);
            if (!strcmp(name, name1)) {//比较name和name1
                if (!strcmp(user, "A.txt"))//重新打开
                    list1 = fopen("../Name-list/A.txt", "r");
                else
                    list1 = fopen("../Name-list/B.txt", "r");
                while (!feof(list1)) {
                    fscanf(list1, "%s", name3);
                    if (!strcmp(name3, name2)) {//比较列表中有没有和敌人名字
                        flag = 0;
                        fclose(list1);//关闭文件刷新流上数据
                        break;
                    }
                }
                fclose(list1);//关闭文件刷新流上数据
            }
            if (!strcmp(name, name2)) {//比较name和name2
                if (!strcmp(user, "A.txt"))//重新打开
                    list2 = fopen("../Name-list/A.txt", "r");
                else
                    list2 = fopen("../Name-list/B.txt", "r");
                while (!feof(list2)) {
                    fscanf(list2, "%s", name3);
                    if (!strcmp(name3, name1)) {//比较列表中有没有敌人的名字
                        flag = 0;
                        fclose(list2);//关闭文件刷新流上数据
                        break;
                    }
                }
                fclose(list2);//关闭文件刷新流上数据
            }
            //测试输出
            printf("%s %s\n", name1, name2);
        }
        fclose(enemies);
        //测试分割线
        printf("-----------\n");
    }
    if (flag == 1)//用flag判断输出
        printf("yes");
    else
        printf("no");
    return 0;
}