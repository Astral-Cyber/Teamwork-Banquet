#include <stdio.h>
#define N 5
int max(int a,int b);//声明寻找最大形变位置函数
int main() {
    int x,y;
    int r[N][N]={0};//初始化屋顶数组
    FILE *down=fopen("/Users/astral/CLionProjects/project3/ice/hail.txt","r");//打开文件（使用绝对路径）
    while (!feof(down)) {//获取冰雹落点
        fscanf(down,"%d %d",&x,&y);
        if (x>N||y>N)//防止用户输入溢出
            break;
        x=x-1;//行数转化为数组编号
        y=y-1;//列数转化为数组编号
        //中心位置形变
        r[x][y]+=4;
        //外圈形变循环
        //最外圈形变循环
        //调试部分
        for (int i = 0; i < N; ++i) {//输出冰雹后屋顶
            for (int j = 0; j < N; ++j) {
                printf("%d\t",r[i][j]);
            }
            printf("\n");
        }
        printf("--------------------------\n");//分界线
        //调试部分输出每一颗冰雹对数组的影响
    }
    fclose(down);//关闭文件
    printf("屋顶形变情况为：\n");
    for (int i = 0; i < N; ++i) {//输出冰雹后屋顶
        for (int j = 0; j < N; ++j) {
            printf("%d\t",r[i][j]);
        }
        printf("\n");
    }
    printf("形变最大的位置是：");
    return 0;
}
//定义寻找最大形变位置函数
int max(int a,int b){

}
