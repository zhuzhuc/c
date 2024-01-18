#include "Snake.h"

//设置光标的坐标
void SetPos(short x, short y)
{
    COORD pos = { x, y };
    HANDLE hOutput = NULL;
    //获取标准输出的句柄(用来标识不同设备的数值)
    hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    //设置标准输出上光标的位置为pos
    SetConsoleCursorPosition(hOutput, pos);
}

void WelcomeToGame()
{
    SetPos(40, 15);
    printf("欢迎来到贪吃蛇小游戏");
    SetPos(40, 25);//让按任意键继续的出现的位置好看点
    system("pause");
    system("cls");
    SetPos(25, 12);
    printf("用 ↑ . ↓ . ← . → 分别控制蛇的移动， F3为加速，F4为减速\n");
    SetPos(25, 13);
    printf("加速将能得到更高的分数。\n");
    SetPos(40, 25);//让按任意键继续的出现的位置好看点
    system("pause");
    system("cls");
}

void CreateMap()
{
    int i = 0;
    //上(0,0)-(56, 0)
    SetPos(0, 0);
    for (i = 0; i < 58; i += 2)
    {
        wprintf(L"%c", WALL);
    }
    //下(0,26)-(56, 26)
    SetPos(0, 26);
    for (i = 0; i < 58; i += 2)
    {
        wprintf(L"%c", WALL);
    }
    //左
    //x是0，y从1开始增长
    for (i = 1; i < 26; i++)
    {
        SetPos(0, i);
        wprintf(L"%c", WALL);
    }
    //x是56，y从1开始增长
    for (i = 1; i < 26; i++)
    {
        SetPos(56, i);
        wprintf(L"%c", WALL);
    }
}


void InitSnake(pSnake ps)
{
    pSnakeNode cur = NULL;
    int i = 0;
    //创建蛇身节点，并初始化坐标
    //头插法
    for (i = 0; i < 5; i++)
    {
        //创建蛇身的节点
        cur = (pSnakeNode)malloc(sizeof(SnakeNode));
        if (cur == NULL)
        {
            perror("InitSnake()::malloc()");
            return;
        }
        //设置坐标
        cur->next = NULL;
        cur->x = POS_X + i * 2;
        cur->y = POS_Y;

        //头插法
        if (ps->_pSnake == NULL)
        {
            ps->_pSnake = cur;
        }
        else
        {
            cur->next = ps->_pSnake;
            ps->_pSnake = cur;
        }
    }

    //打印蛇的身体
    cur = ps->_pSnake;
    while (cur)
    {
        SetPos(cur->x, cur->y);
        wprintf(L"%c", BODY);
        cur = cur->next;
    }

    //初始化贪吃蛇数据
    ps->_SleepTime = 200;
    ps->_Socre = 0;
    ps->_Status = OK;
    ps->_Dir = RIGHT;
    ps->_Add = 10;
}



void CreateFood(pSnake ps)
{
    int x = 0;
    int y = 0;

again:
    //产生的x坐标应该是2的倍数，这样才可能和蛇头坐标对齐。
    do
    {
        x = rand() % 53 + 2;
        y = rand() % 25 + 1;
    } while (x % 2 != 0);

    pSnakeNode cur = ps->_pSnake;//获取指向蛇头的指针
    //食物不能和蛇身冲突
    while (cur)
    {
        if (cur->x == x && cur->y == y)
        {
            goto again;
        }
        cur = cur->next;
    }

    pSnakeNode pFood = (pSnakeNode)malloc(sizeof(SnakeNode)); //创建食物
    if (pFood == NULL)
    {
        perror("CreateFood::malloc()");
        return;
    }
    else
    {
        pFood->x = x;
        pFood->y = y;
        SetPos(pFood->x, pFood->y);
        wprintf(L"%c", FOOD);
        ps->_pFood = pFood;
    }
}

void PrintHelpInfo()
{
    //打印提示信息
    SetPos(64, 15);
    printf("不能穿墙，不能咬到自己\n");
    SetPos(64, 16);
    printf("用↑.↓.←.→分别控制蛇的移动.");
    SetPos(64, 17);
    printf("F1 为加速，F2 为减速\n");
    SetPos(64, 18);
    printf("ESC ：退出游戏.space：暂停游戏.");
    SetPos(64, 20);
    printf("比特就业课@版权");
}

void pause()//暂停
{
    while (1)
    {
        Sleep(300);
        if (KEY_PRESS(VK_SPACE))
        {
            break;
        }
    }
}

//pSnakeNode psn 是下一个节点的地址
//pSnake ps 维护蛇的指针
int NextIsFood(pSnakeNode psn, pSnake ps)
{
    return (psn->x == ps->_pFood->x) && (psn->y == ps->_pFood->y);
}

//pSnakeNode psn 是下一个节点的地址
//pSnake ps 维护蛇的指针
void EatFood(pSnakeNode psn, pSnake ps)
{
    //头插法
    psn->next = ps->_pSnake;
    ps->_pSnake = psn;
    pSnakeNode cur = ps->_pSnake;
    //打印蛇
    while (cur)
    {
        SetPos(cur->x, cur->y);
        wprintf(L"%c", BODY);
        cur = cur->next;
    }
    ps->_Socre += ps->_Add;

    free(ps->_pFood);
    CreateFood(ps);
}

//pSnakeNode psn 是下一个节点的地址
//pSnake ps 维护蛇的指针
void NoFood(pSnakeNode psn, pSnake ps)
{
    //头插法
    psn->next = ps->_pSnake;
    ps->_pSnake = psn;
    pSnakeNode cur = ps->_pSnake;
    //打印蛇
    while (cur->next->next)
    {
        SetPos(cur->x, cur->y);
        wprintf(L"%c", BODY);
        cur = cur->next;
    }

    //最后一个位置打印空格，然后释放节点
    SetPos(cur->next->x, cur->next->y);
    printf("  ");
    free(cur->next);
    cur->next = NULL;
}

//pSnake ps 维护蛇的指针
int KillByWall(pSnake ps)
{
    if ((ps->_pSnake->x == 0)
        || (ps->_pSnake->x == 56)
        || (ps->_pSnake->y == 0)
        || (ps->_pSnake->y == 26))
    {
        ps->_Status = KILL_BY_WALL;
        return 1;
    }
    return 0;
}

//pSnake ps 维护蛇的指针
int KillBySelf(pSnake ps)
{
    pSnakeNode cur = ps->_pSnake->next;
    while (cur)
    {
        if ((ps->_pSnake->x == cur->x)
            && (ps->_pSnake->y == cur->y))
        {
            ps->_Status = KILL_BY_SELF;
            return 1;
        }
        cur = cur->next;
    }
    return 0;
}


void SnakeMove(pSnake ps)
{
    //创建下一个节点
    pSnakeNode pNextNode = (pSnakeNode)malloc(sizeof(SnakeNode));
    if (pNextNode == NULL)
    {
        perror("SnakeMove()::malloc()");
        return;
    }
    //确定下一个节点的坐标，下一个节点的坐标根据，蛇头的坐标和方向确定
    switch (ps->_Dir)
    {
        case UP:
        {
            pNextNode->x = ps->_pSnake->x;
            pNextNode->y = ps->_pSnake->y - 1;
        }
        break;
        case DOWN:
        {
            pNextNode->x = ps->_pSnake->x;
            pNextNode->y = ps->_pSnake->y + 1;
        }
        break;
        case LEFT:
        {
            pNextNode->x = ps->_pSnake->x - 2;
            pNextNode->y = ps->_pSnake->y;
        }
        break;
        case RIGHT:
        {
            pNextNode->x = ps->_pSnake->x + 2;
            pNextNode->y = ps->_pSnake->y;
        }
        break;
    }

    //如果下一个位置就是食物
    if (NextIsFood(pNextNode, ps))
    {
        EatFood(pNextNode, ps);
    }
    else//如果没有食物
    {
        NoFood(pNextNode, ps);
    }

    KillByWall(ps);
    KillBySelf(ps);
}



void GameStart(pSnake ps)
{
    //设置控制台窗口的大小，30行，100列
    //mode 为DOS命令
    system("mode con cols=100 lines=30");
    //设置cmd窗口名称
    system("title 贪吃蛇"); 

    //获取标准输出的句柄(用来标识不同设备的数值)
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    //影藏光标操作
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(hOutput, &CursorInfo);//获取控制台光标信息
    CursorInfo.bVisible = false; //隐藏控制台光标
    SetConsoleCursorInfo(hOutput, &CursorInfo);//设置控制台光标状态

    //打印欢迎界面
    WelcomeToGame();
    //打印地图
    CreateMap();
    //初始化蛇
    InitSnake(ps);
    //创造第一个食物
    CreateFood(ps);
}


void GameRun(pSnake ps)
{
    //打印右侧帮助信息
    PrintHelpInfo();
    do
    {
        SetPos(64, 10);
        printf("得分：%d ", ps->_Socre);
        printf("每个食物得分：%d分", ps->_Add);
        if (KEY_PRESS(VK_UP) && ps->_Dir != DOWN)
        {
            ps->_Dir = UP;
        }
        else if (KEY_PRESS(VK_DOWN) && ps->_Dir != UP)
        {
            ps->_Dir = DOWN;
        }
        else if (KEY_PRESS(VK_LEFT) && ps->_Dir != RIGHT)
        {
            ps->_Dir = LEFT;
        }
        else if (KEY_PRESS(VK_RIGHT) && ps->_Dir != LEFT)
        {
            ps->_Dir = RIGHT;
        }
        else if (KEY_PRESS(VK_SPACE))
        {
            pause();
        }
        else if (KEY_PRESS(VK_ESCAPE))
        {
            ps->_Status = END_NOMAL;
            break;
        }
        else if (KEY_PRESS(VK_F3))
        {
            if (ps->_SleepTime >= 50)
            {
                ps->_SleepTime -= 30;
                ps->_Add += 2;
            }
        }
        else if (KEY_PRESS(VK_F4))
        {
            if (ps->_SleepTime < 350)
            {
                ps->_SleepTime += 30;
                ps->_Add -= 2;
                if (ps->_SleepTime == 350)
                {
                    ps->_Add = 1;
                }
            }
        }
        //蛇每次一定之间要休眠的时间，时间短，蛇移动速度就快
        Sleep(ps->_SleepTime);
        SnakeMove(ps);

    } while (ps->_Status == OK);
}

void GameEnd(pSnake ps)
{
    pSnakeNode cur = ps->_pSnake;
    SetPos(24, 12);
    switch (ps->_Status)
    {
    case END_NOMAL:
        printf("您主动退出游戏\n");
        break;
    case KILL_BY_SELF:
        printf("您撞上自己了 ,游戏结束!\n");
        break;
    case KILL_BY_WALL:
        printf("您撞墙了,游戏结束!\n");
        break;
    }

    //释放蛇身的节点
    while (cur)
    {
        pSnakeNode del = cur;
        cur = cur->next;
        free(del);
    }
}