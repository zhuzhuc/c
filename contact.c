#include "contact.h" 

void InitContact(struct Contact* ps)
{
    memset(ps->data, 0, sizeof(ps->data));
    ps->size = 0;//设置通讯录最初只有一个元素
}
void AddContact(struct Contact* ps)
{
    if (ps->size == MAX)
    {
        printf("contact max,add fail\n");/* code */
    }
    else
    {
        printf("enter name:>");
        scanf("%s", ps->data[ps->size].name);
        printf("enter age:>");
        scanf("%d", &(ps->data[ps->size].age));
        printf("enter sex:>");
        scanf("%s", ps->data[ps->size].sex);
        printf("enter tele:>");
        scanf("%s", ps->data[ps->size].tele);
        printf("enter addr:>");
        scanf("%s", ps->data[ps->size].addr);

        ps->size++;        
        printf("add succefully\n");

    }
    
}
void ShowContact(const struct Contact* ps)
{
    if (ps->size == 0)
    {
        printf("empty\n");
    }
    else
    {
        int i = 0;
        printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "name", "age", "sex", "tele", "addr");
        for ( i = 0; i < ps->size; i++)
        {
            printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", 
                ps->data[i].name,
                ps->data[i].age,
                ps->data[i].sex,
                ps->data[i].tele,
                ps->data[i].addr);
        }
        
    }
    
}
static int FindByNmae(const struct Contact* ps, char name[MAX_NAME])
{
    int i = 0;
    for ( i = 0; i < ps->size; i++)
    {
        if (0 == strcmp(ps->data[i].name, name))
        {
            return i;
        }
    }
    return -1;//找不到的情况
}
void DelContact(struct Contact* ps)
{
    char name[MAX_NAME];
    printf("pleasse enter the name:>");
    scanf("%s", name);
    //1.查找要删除的人在什么位置
    //找到了返回名字所在下标
    //找不到返回-1
    int pos = FindByName(ps, name);
    
    if (pos == -1)
    {
        printf("no exit\n");
    }
    else
    {
        int j = 0;
        for ( j = pos; j < ps->size-1; j++)
        {
            ps->data[j] = ps->data[j + 1];
        }
        ps->size--;
        printf("del success\n");
    }
}
void SearchContact(const struct Contact* ps)
{
    char name[MAX_NAME];
    printf("pleasse enter the name you want to look:>");
    scanf("%s", name);
    int pos = FindByName(ps, name);
    if (pos == -1)
    {
        printf("no exit\n");
    }
    else
    {
        printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "name", "age", "sex", "tele", "addr");
        printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", 
            ps->data[pos].name,
            ps->data[pos].age,
            ps->data[pos].sex,
            ps->data[pos].tele,
            ps->data[pos].addr);
    }
    
}
void ModifyContact(struct Contact* ps)
{
    char name[MAX_NAME];
    printf("please enter the name;>");
    scanf("%s", name);
    int pos = FindByName(ps, name);
    if (pos == -1)
    {
        printf("no exit\n");
    }
    else
    {
        printf("enter name:>");
        scanf("%s", ps->data[pos].name);
        printf("enter age:>");
        scanf("%d", &(ps->data[pos].age));
        printf("enter sex:>");
        scanf("%s", ps->data[pos].sex);
        printf("enter tele:>");
        scanf("%s", ps->data[pos].tele);
        printf("enter addr:>");
        scanf("%s", ps->data[pos].addr);
      
        printf("change succefully\n");
    }
    
}