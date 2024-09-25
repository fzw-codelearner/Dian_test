//
// Created by fzw on 2024/9/11.
//
#include <stdio.h>
#include <windows.h>
#include <ctype.h>
#include <stdlib.h>
#define STRLEN 10

struct Channel{                                                        //通道类型
    int price;
    int num;
    char kind;
};

struct Channel channel[6] ={0,0,' '};

int Tihuan(struct Channel *xin,struct Channel *sum);

int main(){

    SetConsoleCP(CP_UTF8);                                 //设置中文编码标准
    SetConsoleOutputCP(CP_UTF8);

    char inp[STRLEN];
    char num_str[2];//初始化承载输入内容的字符串
    int flag =0,ci=3;                                                  //flag->结束条件;ci->回退次数

    struct Channel history[3][6];
    int ss=0;
    BOOL geshi;
    Tihuan(channel,history[ss]);
    printf("输入过程中输入BACK可以执行回退操作哦");
    printf("排放货物格式: 货物名称 通道 单价 数量\n");
    Bai:
        do {

            printf("请摆放货物,如果摆放完成请输入\"END\",末尾不要有空格哦否则是格式错误\n");
            fgets(inp,STRLEN,stdin);
            geshi = (isalpha(inp[0])&& isdigit(inp[2])&& isdigit(inp[4])&& isdigit(inp[6]));
            if (inp[0]=='E'&&inp[1]=='N'&&inp[2]=='D') flag=1;                //判断是否结束
            else if (geshi==0) printf("格式不对");                       //判断格式是否正确
            else if (inp[0]=='B'&&inp[1]=='A'&&inp[2]=='C'&&inp[3]=='K'){     //回退操作
                if (ci>0) {
                    ci-=1;
                    ss = (ss + 2) % 3;
                    Tihuan(history[ss], channel);
                    printf("回退成功");
                }
                else{
                    printf("不能再回退");
                }
            }
            else{                                                            //摆放货物
                if (isalpha(channel[(int )inp[2]-48].kind)) {
                    printf("该通道已经放了%c货物",channel[(int )inp[2]-48].kind);
                }
                else{
                    channel[(int) inp[2] - 48].price = (int) inp[4] - 48;
                    channel[(int) inp[2] - 48].kind = inp[0];
                    num_str[0] =inp[6];
                    num_str[1] =inp[7];
                    channel[(int) inp[2] - 48].num = atoi(num_str);
                    ss = (ss + 4) % 3;
                    Tihuan(channel, history[ss]);
                    if (ci==3) ci=3;
                    else if(ci<3) ci+=1;
                }
            }
            }
        while(flag != 1);



    int lai = 3,zai =0;
    Mai:
        flag=0;
        zai =0;
        int money0 =0,money1=0,money2=0,money3=0;
        printf("购买货物格式: 货物名 所在通道 数量,中间要以空格间隔开来哦\n");
        do {
            printf("请选取你要的货物,如果选取完成请输入\"END\"\n");
            fgets(inp,STRLEN,stdin);
            geshi = (isalpha(inp[0])&& isdigit(inp[2])&& isdigit(inp[4]));
            if (inp[0]=='E'&&inp[1]=='N'&&inp[2]=='D') {
                flag = 1;
                if (ci==3) ci=3;
                else if(ci<3) ci+=1;
            }              //判断是否结束
            else if (inp[0]=='B'&&inp[1]=='A'&&inp[2]=='C'&&inp[3]=='K'){     //回退操作
                if (ci>0 && zai>0) {
                    ci-=1;
                    ss = (ss + 2) % 3;
                    Tihuan(history[ss], channel);
                    printf("回退成功");
                    money3=money2;
                    money2 = money1;
                    money1 = money0;
                    zai-=1;
                    if (lai>=0) lai+=1;
                }
                else if(lai>=1&&zai==0) {
                    printf("回退成功");
                    goto Bai;
                }
                else{
                    printf("不能再回退");
                }
            }
            else if (geshi!=1) printf("格式不对");
            else{                                                          //选择商品
                num_str[0] = inp[4];
                num_str[1] = inp[5];

                if(channel[(int )inp[2]-48].num <= 0) {
                    printf("%c商品已经售罄\n",channel[(int )inp[2]-48].kind);
                    continue; }
                if(channel[(int )inp[2]-48].kind!=inp[0]) {
                    printf("抱歉哦,%d通道里没有%c哦\n",(int )inp[2]-48,inp[0]);
                    continue;
                }
                if (channel[(int )inp[2]-48].num <(atoi(num_str))){
                    printf(("抱歉没有那么多商品呢\n"));
                    continue;
                }
                channel[(int )inp[2]-48].num -=atoi(num_str);
                money0 = money1;
                money1 =money2;
                money2 =money3;

                money3+=(atoi(num_str))*channel[(int )inp[2]-48].price;
                ss=(ss+4)%3;
                Tihuan(channel,history[ss]);
                if (ci==3) ci=3;
                else if(ci<3) ci+=1;
                lai -=1;
                zai+=1;
            }
            int maiflag=0;
            for (int i = 1;i<6;i++){
                if (channel[i].num>0) maiflag=1;
            }
            if (maiflag==0){
                printf("商品已全部选完");
                flag =1;
            }
        }
        while(flag != 1);
    Qu:
            flag =0;
            zai=0;
            int sum =0,collect = 0,QuLai = 3,ssShu=0;
            int collectHistory[3];
            do {
                printf("还差%d元\n",money3-sum);
                fgets(inp,STRLEN,stdin);
                if(inp[0]=='B'&&inp[1]=='A'&&inp[2]=='C'&&inp[3]=='K'){
                    if (ci>0 && zai>0) {
                        ci-=1;
                        sum-=collect;
                        zai-=1;
                        ssShu =(ssShu+2)%3;
                        collect =collectHistory[ssShu];
                        if (QuLai==0) QuLai+=1;
                    }
                    else if(QuLai>=1&&zai==0) {
                        printf("回退成功");
                        goto Mai;
                    }
                    else{
                        printf("不能再回退");
                    }
                }
                else{
                    collect = atoi(inp);
                    geshi =(collect==1||collect==2||collect==5);
                    if (geshi) {
                        if (sum + collect >= money3) flag = 1;
                        else {
                            sum += collect;
                        }
                        ssShu = (ssShu + 1) % 3;
                        collectHistory[ssShu] = collect;
                        QuLai -= 1;
                        zai += 1;
                        if (ci == 3) ci = 3;
                        else if (ci < 3) ci += 1;
                    }
                    else printf("只能投1元 2元和5元硬币哦");
                }
            }
            while(flag != 1);
            printf("找零%d元",sum+collect-money3);
            int tiaoflag =0;
            for (int i = 1;i<6;i++){
                if (channel[i].num>0) tiaoflag=1;
            }
            if (tiaoflag==1) {
                printf("开始下一次购买啦");
                goto Mai;
            }
            else goto End;
    End:
        printf("所有商品已选完");
        return 0;
}


int Tihuan(struct Channel *xin,struct Channel *sum){
    for (int i =0;i<6;i++){
        sum[i].num=xin[i].num;
        sum[i].price=xin[i].price;
        sum[i].kind=xin[i].kind;
    }
    return 0;
}