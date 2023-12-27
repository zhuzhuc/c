#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义最大学生数量
#define MAX_STUDENTS 50
// 系统密码，用于成绩修改
char password[20] = "1234"; // 请替换为你自己设置的密码

// 学生结构体
typedef struct _Student
{
    int stunum;     /* 学生学号 */
    char name[10];  /* 学生姓名 */
    char sex[4];    /* 学生性别 */
    int chinese;    /* 语文 */
    int math;       /* 数学 */
    int english;    /* 英语 */
    float average;  /* 平均分 */
} Student;

// 链表节点结构体
typedef struct _Node
{
    Student stu;// 学生信息
    struct _Node* next;// 指向下一个节点的指针
} Node;

Node* g_pHead = NULL;// 全局链表头指针

// 显示菜单
void displayMenu()
{
    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("+                      学生成绩管理系统2.0                          +\n");
    printf("+                                                                +\n");
    printf("+                        1、成绩录入                              +\n");
    printf("+                        2、成绩显示                              +\n");
    printf("+                        3、成绩保存                              +\n");
    printf("+                        4、成绩排序                              +\n");
    printf("+                        5、成绩修改(要求先输入密码）                +\n");
    printf("+                        6、成绩统计                              +\n");
    printf("+                        (1)显示每门课程成绩最高的学生的基本信息       +\n");
    printf("+                        (2)显示每门课程的平均成绩                  +\n"); 
    printf("+                        (3)显示超过某门课程平均成绩的学生人数        +\n");
    printf("+                        7、成绩查询                              +\n");
    printf("+                        (1)按学号查询                            +\n");
    printf("+                        (2)按姓名查询                            +\n");
    printf("+                        8、退出系统                              +\n");
    printf("+                                                               +\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}

// 查找学生信息
Node* findStudent(int stunum)
{
    Node* p = g_pHead;
    while (p != NULL)
    {
        if (p->stu.stunum == stunum)
            return p;
        p = p->next;
    }
    return NULL; // 未找到
}

// 成绩录入
//成绩录入功能的实现，包括学生信息输入和链表的操作
void inputStudentScore()
{
    system("cls");
    Node* pNewNode = (Node*)malloc(sizeof(Node));
    pNewNode->next = NULL;

    printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("+                  学生成绩管理系统-成绩录入                  +\n");
    printf("请输入学生姓名：\n");
    scanf(" %[^\n]", pNewNode->stu.name);
    printf("请输入学生学号：\n");
    scanf("%d", &pNewNode->stu.stunum);
    printf("请输入学生性别（男/女）：\n");
    scanf(" %[^\n]", pNewNode->stu.sex);
    printf("请输入学生语文成绩：\n");
    scanf("%d", &pNewNode->stu.chinese);
    printf("请输入学生数学成绩：\n");
    scanf("%d", &pNewNode->stu.math);
    printf("请输入学生英语成绩：\n");
    scanf("%d", &pNewNode->stu.english);
    pNewNode->stu.average = (float)(pNewNode->stu.chinese + pNewNode->stu.math + pNewNode->stu.english) / 3.0;

    if (g_pHead == NULL)
    {
        g_pHead = pNewNode;
    }
    else
    {
        pNewNode->next = g_pHead;
        g_pHead = pNewNode;
    }
    printf("## 成绩录入成功 ##\n");
    system("pause");
    // 重新计算平均分，确保分母不为 0
    if ((pNewNode->stu.chinese + pNewNode->stu.math + pNewNode->stu.english) != 0) {
        pNewNode->stu.average = (float)(pNewNode->stu.chinese + pNewNode->stu.math + pNewNode->stu.english) / 3.0;
    } else {
    // 如果分母为 0，平均成绩设为 0 或其他默认值
        pNewNode->stu.average = 0.0;  // 或者设置为其他默认值
    }

}

// 成绩显示
//成绩显示功能的实现，遍历链表并输出学生信息
void outputStudentScore()
{
    system("cls");
    Node* p = g_pHead;

    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("# 姓名\t学号\t性别\t语文\t数学\t英语\t平均分 #\n");

    while (p != NULL)
    {
        printf("# %s\t%d\t%s\t%d\t%d\t%d\t%.2f #\n",
               p->stu.name,
               p->stu.stunum,
               p->stu.sex,
               p->stu.chinese,
               p->stu.math,
               p->stu.english,
               p->stu.average);
        p = p->next;
    }
    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    system("pause");
}
// 成绩排序
// 成绩排序功能的实现，按平均分由高到低对链表进行排序，并输出排序后的学生信息
void sortStudentScore()
{
    system("cls");
    // 对链表中的学生节点进行排序，按平均分由高到低
    Node* current = g_pHead;
    Node* nextNode = NULL;
    Node* temp = NULL;

    while (current != NULL)
    {
        nextNode = current->next;

        while (nextNode != NULL)
        {
            if (current->stu.average < nextNode->stu.average)
            {
                // 交换节点数据
                temp = (Node*)malloc(sizeof(Node));
                temp->stu = current->stu;
                current->stu = nextNode->stu;
                nextNode->stu = temp->stu;
                free(temp);
            }

            nextNode = nextNode->next;
        }

        current = current->next;
    }

    // 显示排序后的学生信息
    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("# 姓名\t学号\t性别\t语文\t数学\t英语\t平均分 #\n");

    Node* p = g_pHead;
    while (p != NULL)
    {
        printf("# %s\t%d\t%s\t%d\t%d\t%d\t%.2f #\n",
               p->stu.name,
               p->stu.stunum,
               p->stu.sex,
               p->stu.chinese,
               p->stu.math,
               p->stu.english,
               p->stu.average);
        p = p->next;
    }

    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    system("pause");
}
// 修改学生成绩
// 成绩修改功能的实现，需要密码验证，修改学生的语文、数学、英语成绩并重新计算平均分
void modifyStudentScore()
{
    system("cls");
    int stunum;
    printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("+               学生成绩管理系统-成绩修改               +\n");
    printf("请输入要修改成绩的学生学号：\n");
    scanf("%d", &stunum);

    Node* p = findStudent(stunum);
    if (p != NULL)
    {
        printf("当前学生信息：\n");
        printf("# %s\t%d\t%s\t%d\t%d\t%d\t%.2f #\n",
               p->stu.name,
               p->stu.stunum,
               p->stu.sex,
               p->stu.chinese,
               p->stu.math,
               p->stu.english,
               p->stu.average);

        printf("请输入新的语文成绩：\n");
        scanf("%d", &p->stu.chinese);
        printf("请输入新的数学成绩：\n");
        scanf("%d", &p->stu.math);
        printf("请输入新的英语成绩：\n");
        scanf("%d", &p->stu.english);

        // 重新计算平均分
        p->stu.average = (float)(p->stu.chinese + p->stu.math + p->stu.english) / 3.0;

        printf("## 成绩修改成功 ##\n");
    }
    else
    {
        printf("未找到学生学号为%d的学生。\n", stunum);
    }

    system("pause");
}

// 显示成绩统计信息
// 成绩统计功能的实现，包括计算每门课程最高分、平均分以及超过平均分的学生人数
void displayStatistics()
{
    system("cls");

    // 初始化统计数据
    int highestChineseScore = 0, highestMathScore = 0, highestEnglishScore = 0;
    int totalChineseScore = 0, totalMathScore = 0, totalEnglishScore = 0;
    int aboveAverageChineseCount = 0, aboveAverageMathCount = 0, aboveAverageEnglishCount = 0;

    Node* p = g_pHead;
    int stunum = 0;

    while (p != NULL)
    {
        // 计算每门课程成绩最高的学生的基本信息
        if (p->stu.chinese > highestChineseScore)
        {
            highestChineseScore = p->stu.chinese;
        }

        if (p->stu.math > highestMathScore)
        {
            highestMathScore = p->stu.math;
        }

        if (p->stu.english > highestEnglishScore)
        {
            highestEnglishScore = p->stu.english;
        }

        // 计算每门课程的平均成绩
        totalChineseScore += p->stu.chinese;
        totalMathScore += p->stu.math;
        totalEnglishScore += p->stu.english;

        stunum++;
        p = p->next;
        
    }

    // 计算平均成绩
    float averageChineseScore = (float)totalChineseScore / stunum;
    float averageMathScore = (float)totalMathScore / stunum;
    float averageEnglishScore = (float)totalEnglishScore / stunum;

    // 显示超过某门课程平均成绩的学生人数
    p = g_pHead;

    while (p != NULL)
    {
        if (p->stu.chinese > averageChineseScore)
        {
            aboveAverageChineseCount++;
        }

        if (p->stu.math > averageMathScore)
        {
            aboveAverageMathCount++;
        }

        if (p->stu.english > averageEnglishScore)
        {
            aboveAverageEnglishCount++;
        }

        p = p->next;
    }

    // 显示统计结果
    printf("每门课程成绩最高的学生的基本信息：\n");
    printf("语文最高分：%d\n", highestChineseScore);
    printf("数学最高分：%d\n", highestMathScore);
    printf("英语最高分：%d\n", highestEnglishScore);

    printf("\n每门课程的平均成绩:\n");
    printf("语文平均分：%.2f\n", averageChineseScore);
    printf("数学平均分：%.2f\n", averageMathScore);
    printf("英语平均分：%.2f\n", averageEnglishScore);

    printf("\n超过某门课程平均成绩的学生人数:\n");
    printf("语文超过平均分的学生人数：%d\n", aboveAverageChineseCount);
    printf("数学超过平均分的学生人数：%d\n", aboveAverageMathCount);
    printf("英语超过平均分的学生人数：%d\n", aboveAverageEnglishCount);

    printf("\n## 成绩统计完成 ##\n");
    system("pause");
}
// 成绩查询
// 成绩查询功能的实现，支持按学号和姓名查询
void queryStudentScore()
{
    system("cls");
    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("+                学生成绩管理系统-成绩查询                     +\n");
    printf("请选择查询方式：\n");
    printf("请输入查询方式(1-按学号查询,2-按姓名查询）：\n");
    int queryChoice;
    scanf("%d", &queryChoice);

    switch (queryChoice)
    {
        case 1:
        {
            int stunum;
            printf("请输入要查询成绩的学生学号：\n");
            scanf("%d", &stunum);

            Node* p = findStudent(stunum);
            if (p != NULL)
            {
                printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
                printf("# 姓名\t学号\t性别\t语文\t数学\t英语\t平均分 #\n");
                printf("# %s\t%d\t%s\t%d\t%d\t%d\t%.2f #\n",
                    p->stu.name,
                    p->stu.stunum,
                    p->stu.sex,
                    p->stu.chinese,
                    p->stu.math,
                    p->stu.english,
                    p->stu.average);
                printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
            }
            else
            {
                printf("未找到学生学号为%d的学生。\n", stunum);
            }
            break;
        }
        case 2:
        {
            char name[10];
            printf("请输入要查询成绩的学生姓名：\n");
            scanf("%s", name);

            Node* p = g_pHead;
            int found = 0;
            while (p != NULL)
            {
                if (strcmp(p->stu.name, name) == 0)
                {
                    found = 1;
                    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
                    printf("# 姓名\t学号\t性别\t语文\t数学\t英语\t平均分 #\n");
                    printf("# %s\t%d\t%s\t%d\t%d\t%d\t%.2f #\n",
                        p->stu.name,
                        p->stu.stunum,
                        p->stu.sex,
                        p->stu.chinese,
                        p->stu.math,
                        p->stu.english,
                        p->stu.average);
                    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
                    break;
                }
                p = p->next;
            }

            if (!found)
            {
                printf("未找到姓名为%s的学生。\n", name);
            }
            break;
        }
        default:
            printf("无效的选择。\n");
    }

    system("pause");
}

// 保存学生成绩到文件（文本文件）并显示表头
void saveStudentScore()
{
    system("cls");
    FILE* fp = fopen("./Student.txt", "w"); // 打开文本文件，使用写入方式
    Node* p = g_pHead;

    // 写入表头信息
    fprintf(fp, "姓名  学号  性别  语文  数学  英语  平均分\n");

    while (p != NULL)
    {
        // 将学生信息以文本格式写入文件
        fprintf(fp, "%s   %d   %s   %d   %d   %d   %.2f\n",
                p->stu.name,
                p->stu.stunum,
                p->stu.sex,
                p->stu.chinese,
                p->stu.math,
                p->stu.english,
                p->stu.average);

        p = p->next;
    }

    fclose(fp); // 关闭文件
    printf("## 成绩保存成功 ##\n");
    system("pause");
}

// 主函数，包含整体的程序逻辑，通过循环显示菜单，等待用户输入执行相应的功能
int main()
{
    int choice = 0;

    while (1)
    {
        system("cls");
        displayMenu();
        printf("\n请选择您的操作(1,2,3,4,5,6,7,8): \n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                inputStudentScore();
                break;
            }
            case 2:
            {
                outputStudentScore();
                break;
            }
            case 3:
            {
                saveStudentScore();
                break;
            }
            case 4:
            {
                sortStudentScore();
                break;
            }
            case 5:
            {
                char input_password[20];
                printf("请输入密码: ");
                scanf("%s", input_password);
                if (strcmp(input_password, password) == 0)
                {
                    modifyStudentScore();
                }
                else
                {
                    printf("密码错误，无法进行修改操作。\n");
                }
                break;
            }
            case 6:
            {
                displayStatistics();
                break;
            }
            case 7:
            {
                queryStudentScore();
                break;
            }
            case 8:
            {
                // 退出系统
                printf("退出系统。");
                exit(0);
                break;

            default:
                printf("无效的选择。\n");
            }
        }
    }

    return 0;
}
