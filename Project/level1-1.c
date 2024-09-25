//
// Created by fzw on 2024/9/23.
//
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#define STRLEN 10

int main(){
    SetConsoleCP(CP_UTF8);                                 //设置中文编码标准
    SetConsoleOutputCP(CP_UTF8);
    printf("排放货物格式: 货物名称 通道 单价 数量\n");
    char inp[STRLEN];
    char num_str[2];
    int num;
    BOOL geshi;
    printf("请摆放货物,如果摆放完成请输入\"END\",末尾不要有空格哦否则是格式错误\n");
    fgets(inp,STRLEN,stdin);
    geshi = (isalpha(inp[0])&& isdigit(inp[2])&& isdigit(inp[4])&& isdigit(inp[6]));
    if (geshi==0) printf("格式错误");
    else{
        printf("%c: ",inp[2]);
        num_str[0] =inp[6];
        num_str[1] =inp[7];
        num = atoi(num_str);
        for (int i =0;i<num;i++) printf("%c",inp[0]);
        printf(" %c",inp[4]);
    }
    system("pause");
    return 0;
}