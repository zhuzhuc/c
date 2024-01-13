/*
实型数据：2.11e-1 表示为 2.111x10的负一次方
整型一般是4个字节，字符型1个字节，双精度型8字节 “/”两边同为整型结果就是整型，如果有一边是小数，结果就是小数，“%”取余数，两边必须是整数
复合复制表达式：a*=2+3,相当于a=a*(2+3),a % =3 , a = a % 3
++在前先加后用，++在后先用后加
逗号表达式：表达式的数值是逗号最右边的那个表达式的数值，如（2，3，4）的表达式的数值就是4；z=(2,3,4), z = 4; z=2,3,4, z = 2;
    1.空语句不可以随意执行，会导致逻辑错误
    2.注释不占用运行时间，不是C语言，没有分号，不可以嵌套
    3.强制类型转换是在类型上吗=面加（），例如（int）a，注意（int）（a+b）和（int）a+b 前是把a+b转型，后是把a转型再加b
    4.三种小数取整丢小数的情况：1）int a = 1.6；   2）b=(int)a;     3) 1/2; 3/2;
*/
/*
    字符
        1）字符数据的合法类型
           '1'是字符占一个字节。“1”是字符串占两个字节（含有一个结束符号）
           '0'的ASCII数值表示为48，此外字符可以进行算术运算，如'0'-0=48;
           大小写字母可以通过ASCII数值转换，如'A'+32='a'; 'a'的ASCII数值是97；'A'的ASCII数值是65；
           注意：大小写字母之间的ASCII数值相差一般都是32
        2）转义字符
           一般转义字符：\t--水平质表(tab键)，\n--换行，\'--单引号，\"--双引号，\\--斜杠八进制转义字符、十六进制转义字符
           八进制转义字符：‘141’ 前导的0不能写
           十六进制转义字符：‘、x6d’ 前导的0不能写，且x是小写
           注意：当%后跟#再跟数据时，结果为带前导的数据
        3）字符型和整型
        char a = 65;
        printf("%c", a); 结果：A %c表示a以z字符的形式输出 %d表示以数据整型形式输出 %f表示以小数的形式输出
        printf("%d", a); 结果：65  
*/
/*
输入输出函数
    1)、使用printf和scanf 函数时，要在最前面加上#include<stdio.h>
    2)、printf可以只有一个参数，也可以有两个参数
    3)、printf (“第一部分”，第二部分 );把第二部分的变量、表达式、常量以第一部分的形式展现出来!
  常用printf转换描述：
    %d      整型 int                   %c     字符char
    %ld     长整型 longint             %s     字符串
    %f      浮点型 float               %o     八进制
    %lf     double                    %#o    带前导的八进制
    %%      输出一个百分号              %x      十六进制
    %5d     五个整型数据                %#x    带前导的十六进制
    %md     int  输出十进制整数，m为输出最小宽度(若数据的位数小于m，则左端补空（差几位就补几个空格）；若数据位数大于m，则按实际长度输出)
    %m.nf   float.double   按带小数形式输出实数，m为最小宽度，n为小数点后位数(若数据的位数小于m，则左端补空；若数据位数大于m，按实际长度输出，小数位被截断时按四舍五入输出)
  数据输入scanf()
    scanf("%d, %d" , &a, &b); &不能掉
    注意：当指针指向一个字符的地址时不再用&符号
  putchar，getchar：

  如何实现两个变量x，y，中数值的互换：用中间值
*/
/*
    表达式和数据结构
     1）关系表达式：关系表达式数值只能为1或0，1为true 0为false
        注意：比较有优先级；“=”表示赋值，“= =”才是等号
     2）逻辑表达式：表达式的数值也只能为1或0
        有&& || ! 三种逻辑运算符号，优先级顺序：！>&&>||
        例如表示x大于0小于10:(0<x)&&(x<10)
*/
//判断一年是否为闰年
#include<stdio.h>
#include<iostream>
using namespace std;
int runnian(int);
int main(void){
    int year;
    printf("please enter a count: ");
    scanf("%d", &year);
    if (runnian(year) == 1){
        printf("%drunnian", year);
    }
    else{
        printf("%dnorunnian", year);
    }
    system("pause");
    
    return 0;
}
int runnian(int year){
    if ((year%4==0&&year%100!=0)||year%400==0){
        year = 1;
    }
    else{
        year = 0;
    }
    return year;   
}
/*
数据结构
    1）if语句
    2）条件表达式：表达式1 ？ 表达式2 ： 表达式3（真前假后）
    3）switch语句
循环结构
    1）三种循环
      for() ; while(); do-while()
      break和continue的区别
      嵌套循环
*/
//输入数字中有几个数字‘digit’
#include<stdio.h>
#include<iostream>
using namespace std;
int countdigit(int, int);
int main(){
    int a, b, t;
    printf("please enter a +word: ");
    scanf("%d", &a);
    printf("please enter a specifilcal word: ");
    scanf("%d", &b);
    t = countdigit(a, b);
    printf("%dyou%dge%d", a, t, b);
    system("pause");
    return 0;
}
int countdigit(int number, int digit){
    int i = 0;
    while (number!=0){
        if (number % 10 == digit)
        {
            i++;
        }
        number = number / 10;
    }
    return 1;
}
/*
函数
*/
//求阶乘
/*
int fun(int n){
    int p = 1;
    for ( i = 1; i <= n; i++)
    {
        p=p*i;
    }
    return p;
}
*/
//判断质数
/*
#include<stdio.h>
#include<string>
int primenumber(int);
void main(){
    int a;
    int p;
    printf("please enter a count:\n");
    scanf("%d", &a);
    if (p)
    {
        printf("this count is primenumber");
    }
    else{
        printf("this count isnot primenumber");
    }
    system("pause");
    return 0;   
}
int primenumber(int a){
    for ( i = 2; i < a/2; i++)
    {
        if (a %i == 0)
        {
            flag=0;
            break;
        }
        else{
            flag=1;
        }
        if (flag==0)
        {
            return 0;
        }
        else{
            return 1;
        }
    }
    
}
*/
/*指针*/
/*
 1）一级指针：存放变量的地址
    *p++地址会变化，取当前值，然后再移动地址
    (*p)++ 是数值会要变化，取当前值，然后再使数值增加1
 2）二级指针
    **p：存放一级指针的地址
 3）三名主义：
    数组名：表示第一个元素的地址。数组名不可以自加，他是地址常量名
    函数名：表示该函数的入口地址
    字符串常量名：表示第一个字符的地址
 4）移动指针
    char *s= "meikanshu"
    while(*s){printf("%c", *s); s++; }
 5)指针变量两种初始化
    1.int a = 2， *p=&a；--定义的时候初始化
    2.int a = 2, *p; --定义之后初始化
        p=&a;
*/
/*
数组：一次输入多次使用
*/
#include<stdio.h>
int main(){
    int score[8]={75,68,89,72,62,83,85,92};
    int sum=0,avg=0,max=0,min=100;
    int *p;
    for ( p=&(score[0]); p<=&(score[7]); p++)
    {
        sum = sum+*p;
        if (*p>max)
        {
            max=*p;
        }
        if (*p<min)
        {
            min=*p;
        }
        printf("sum=%da, vg=%f",sum,sum/8.0);
        printf("max=%d, min=%d",max,min);
    }
    return 0;
}
/*
二维数组

*/
//求二维数组对角线的和
#include<stdio.h>
int main(){
    int a[3][3];
    int i,j;
    int m = 0,n = 0;
    for ( i = 0; i <= 2; i++)
    {
        for ( j = 0; j <= 2; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for ( i = 0; i <= 2; i++)
    {
        m=m+a[i][i];
        n=n+a[i][2-i];
    }
    printf("%d%d",m,n);
    return 0;
}
// a[2] = *(a+2)  a[2][3] = *(a+2) [3] = *(*(a+2) +3)
/*
int a, b, c, d, e;
a=1;b=2;c=6;d=4;
e=f(a+b) * f(c+d);
#define f(x) (x*x) -- e=(a+b*a+b)*(c+d*c+d) = 5*34=170
#define f(x) x*x -- e=a+b*a+b*c+d*c+d=1+2+12+24+4=43
#define f(x) ((x)*(x)) -- e=((a+b)*(a+b)*(c+d)*(c+d)) = 3*3*10*10=900
*/