#define _CRT_SECURE_NO_WARNINGS 1
#include "Snake.h"
#include <locale.h>

void test()
{
    int ch = 0;
    srand((unsigned int)time(NULL));

    do
    {
        Snake snake = { 0 };
        GameStart(&snake);
        GameRun(&snake);
        GameEnd(&snake);
        SetPos(20, 15);
        printf("再来一局吗？(Y/N):");
        ch = getchar();
        getchar();//清理\n

    } while (ch == 'Y');
    SetPos(0, 27);
}

int main()
{
    //修改当前地区为本地模式，为了支持中文宽字符的打印
    setlocale(LC_ALL, "");
    //测试逻辑
    test();
    return 0;
}