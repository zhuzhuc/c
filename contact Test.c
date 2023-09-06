#include "contact.h" 
void menu()
{
    printf("****************************\n");
    printf("****1. add        2. del****\n");
    printf("****3. search  4. modify****\n");
    printf("****5. show      6. sort****\n");
    printf("****0. exit                 \n");
    printf("****************************\n");

}
int main()
{
    int input = 0;
    //create a contacyt
    struct Contact con;//Con就是通讯录包含1000个人的数组
    //初始化通讯录
    InitContact(&con);
    do
    {
        menu();
        printf("please select;>");
        scanf("%d", &input);
        switch (input)
        {
        case ADD:
            AddContact(&con);
            break;
        case DEL:
            DelContact(&con);
            break;
        case SEARCH:
            SearchContact(&con);
            break;
        case MODIFY:
            ModifyContact(&con);
            break;
        case SHOW:
            ShowContact(&con);
            break;
        case SORT:
            SortContact(&con);
            break;
        case 0:
            printf("exit contact\n");
            break;
        default:
            printf("select fail\n");
            break;
        }
    } while(input);
    
    return 0;
}