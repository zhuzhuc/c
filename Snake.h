#pragma once

#include <windows.h>
#include <time.h>
#include <stdio.h>

#define KEY_PRESS(VK)  ((GetAsyncKeyState(VK)&0x1) ? 1 : 0)

//方向
enum DIRECTION
{
    UP = 1,
    DOWN,
    LEFT,
    RIGHT
};

//游戏状态
enum GAME_STATUS
{
    OK,//正常运行
    KILL_BY_WALL,//撞墙
    KILL_BY_SELF,//咬到自己
    END_NOMAL//正常结束
};

#define WALL L'□'
#define BODY L'●'  //★○●◇◆□■
#define FOOD L'★'  //★○●◇◆□■

//蛇的初始位置
#define POS_X 24
#define POS_Y 5

//蛇身节点
typedef struct SnakeNode
{
    int x;
    int y;
    struct SnakeNode* next;
}SnakeNode, * pSnakeNode;

typedef struct Snake
{
    pSnakeNode _pSnake;//维护整条蛇的指针
    pSnakeNode _pFood;//维护食物的指针
    enum DIRECTION _Dir;//蛇头的方向默认是向右
    enum GAME_STATUS _Status;//游戏状态
    int _Socre;//当前获得分数
    int _Add;//默认每个食物10分
    int _SleepTime;//每走一步休眠时间
}Snake, * pSnake;



//游戏开始前的初始化
void GameStart(pSnake ps);

//游戏运行过程
void GameRun(pSnake ps);

//游戏结束
void GameEnd(pSnake ps);

//设置光标的坐标
void SetPos(short x, short y);

//欢迎界面
void WelcomeToGame();

//打印帮助信息
void PrintHelpInfo();

//创建地图
void CreateMap();

//初始化蛇
void InitSnake(pSnake ps);

//创建食物
void CreateFood(pSnake ps);

//暂停响应
void pause();

//下一个节点是食物
int NextIsFood(pSnakeNode psn, pSnake ps);

//吃食物
void EatFood(pSnakeNode psn, pSnake ps);

//不吃食物
void NoFood(pSnakeNode psn, pSnake ps);

//撞墙检测
int KillByWall(pSnake ps);

//撞自身检测
int KillBySelf(pSnake ps);

//蛇的移动
void SnakeMove(pSnake ps);

//游戏初始化
void GameStart(pSnake ps);

//游戏运行
void GameRun(pSnake ps);

//游戏结束
void GameEnd(pSnake ps);