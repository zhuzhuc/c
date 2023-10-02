int main()
{
//一维数组
//数字名是首元素的地址
//1.sizeof(数组名) - 表示整个数组
//2. &数组名 - 数组名表示整个数组
    int a[] = {1,2,3,4};
    printf("%d\n",sizeof(a));//sizeof(数组名)- 计算数组大小-16
    printf("%d\n",sizeof(a+0));//4/8 - 数组名这里表示首元素的值a+0 还是首元素地址，地址的大小就是4/8个字节
    printf("%d\n",sizeof(*a));//4 - 表示首元素地址 *a就是首元素
    printf("%d\n",sizeof(a+1));//4/8 表示首元素地址， a+1是第二个元素的地址
    printf("%d\n",sizeof(a[1]));//4 - 第二个元素大小
    printf("%d\n",sizeof(&a));//4 - &a取数组的地址，4/8
    printf("%d\n",sizeof(*&a));//16 - 先取地址再解引用 - 计算数组大小
    printf("%d\n",sizeof(&a+1));//4/8 - 都是取地址
    printf("%d\n",sizeof(&a[0]));//4/8 - 取第一个元素的地址
    printf("%d\n",sizeof(&a[0]+1));//4/8 - 取第二个元素的地址

    return 0;
}
//字符数组
int main()
{
    char arr[] = {'a','b','c','d','e','f'};
    printf("%d\n", sizeof(arr));//6 - 计算数组大小， 6*1=6
    printf("%d\n", sizeof(arr+0));//4/8 - arr+0 -是首元素地址- 4/8 bit
    printf("%d\n", sizeof(*arr));//1 - arr是首元素地址 *arr是首元素
    printf("%d\n", sizeof(arr[1]));//1 - 计算第二个元素大小
    printf("%d\n", sizeof(&arr));//4/8 - &arr虽然是数组地址但也是地址就是4/8bit
    printf("%d\n", sizeof(&arr+1));//4/8  +1跳过数组但还是取地址
    printf("%d\n", sizeof(&arr[0]+1));//4/8 第二个元素地址 
    printf("%d\n", strlen(arr));//随机值 - 
    printf("%d\n", strlen(arr+0));//随机值 - 地址的字符串长度是随机值
    printf("%d\n", strlen(*arr));// - 编译错误 不可用数字做地址
    printf("%d\n", strlen(arr[1]));// - error
    printf("%d\n", strlen(&arr));//随机值
    printf("%d\n", strlen(&arr+1));//随机值-6
    printf("%d\n", strlen(&arr[0]+1));//随机值-1

    return 0;
}
int main()
{
    char arr[] = "abcdef";
    printf("%d\n", sizeof(arr));//sizeof(arr)计算数组大小7
    printf("%d\n", sizeof(arr+0));//4/8 计算地址大小， arr+0 是首元素地址
    printf("%d\n", sizeof(*arr));//1 - 计算首元素大小
    printf("%d\n", sizeof(arr[1]));//1 arr[1]是第二个元素，计算第二个元素的大小
    printf("%d\n", sizeof(&arr));//4/8 &arr是数组的地址计算的是地址大小
    printf("%d\n", sizeof(&arr+1));//4/8 &arr+1是跳过整个数组后的地址
    printf("%d\n", sizeof(&arr[0]+1));//4/8 &arr[0]+1 是第二个元素的地址
    printf("%d\n", strlen(arr));//6 计算数组长度
    printf("%d\n", strlen(arr+0));//6 
    printf("%d\n", strlen(*arr));// error
    printf("%d\n", strlen(arr[1]));//error
    printf("%d\n", strlen(&arr));//6 arr - 数组的地址 - 数组指针 char(*p)[7] = &arr;
    printf("%d\n", strlen(&arr+1));//随机值
    printf("%d\n", strlen(&arr[0]+1));//5

    return 0;
}
int main()
{
    char *p = "abcdef";
    printf("%d\n", sizeof(p));//4/8 计算指针变量p的大小
    printf("%d\n", sizeof(p+1));// p+1 得到的是字符b的地址
    printf("%d\n", sizeof(*p));//1 *P是字符串第一个字符
    printf("%d\n", sizeof(p[0]));//1 p[0] = *(p+0) == 'a'
    printf("%d\n", sizeof(&p));//4/8 
    printf("%d\n", sizeof(&p+1));//4/8
    printf("%d\n", sizeof(&p[0]+1));//4/8
    printf("%d\n", strlen(p));//6
    printf("%d\n", strlen(p+1));//5
    printf("%d\n", strlen(*p));//error
    printf("%d\n", strlen(p[0]));//error
    printf("%d\n", strlen(&p));//随机值
    printf("%d\n", strlen(&p+1));//随机值
    printf("%d\n", strlen(&p[0]+1));//5

    return 0;
}
//二维数组
int main()
{
    int a[3][4] = {0};
    printf("%d\n",sizeof(a));//3*4*4=48
    printf("%d\n",sizeof(a[0][0]));//4
    printf("%d\n",sizeof(a[0]));//16 a[0]相当于一维数组数组名，sizeof(arr[0])把数组名单独放在sizeof内，计算的是第一行的大小
    printf("%d\n",sizeof(a[0]+1));//4 -a[0]是第一行的数组名，数组名此时是首元素地址，其实就是第一行第1个元素地址，+1就是第一行第二个元素地址
    printf("%d\n",sizeof(*(a[0]+1)));//4 *(a[0]+1)第一个第二个元素
    printf("%d\n",sizeof(a+1));//4 a是二维数组名，没有sizeof(数组名)，也没有&（数组名），所以a是首元素地址，而二维数组首元素是他的第一行，a就是第一行（首元素）的地址，a+1就是第二行地址
    printf("%d\n",sizeof(*(a+1)));//16 sizeof(a[1]) 计算第二行的大小
    printf("%d\n",sizeof(&a[0]+1));//4 第二行的地址
    printf("%d\n",sizeof(*(&a[0]+1)));//16 计算第二行的大小
    printf("%d\n",sizeof(*a));1//16  *a就是第一行，sizeof(*a)就是计算第一行的大小
    printf("%d\n",sizeof(a[3]));//16

    return 0;
}