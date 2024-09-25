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

    char inp[STRLEN];
    int sum=0,money3=0,flag=0;
    int collect;
    BOOL geshi;
    fgets(inp, STRLEN, stdin);
    money3 = atoi(inp);
    do{
        fgets(inp, STRLEN, stdin);
        collect = atoi(inp);
        geshi = (collect == 1 || collect == 2 || collect == 5);
        if (geshi) {
            if (sum + collect >= money3) flag = 1;
            else {
                sum += collect;
                printf("还差%d元\n",money3-sum);
            }
        } else printf("只能投1元 2元和5元硬币哦\n");
    } while (flag!=1);
    printf("%d(找零)",sum+collect-money3);
    system("pause");
    return 0;
}