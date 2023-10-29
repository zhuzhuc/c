#include <stdio.h>
#include <stdlib.h>

// 定义包含柔性数组的结构体
struct flex_array_struct {
    int length;
    int data[]; // 柔性数组，结构体末尾的数组没有指定长度
};

// 创建包含柔性数组的结构体的实例并初始化
struct flex_array_struct* create_flex_array(int length) {
    struct flex_array_struct* arr = malloc(sizeof(struct flex_array_struct) + length * sizeof(int));
    if (arr != NULL) {
        arr->length = length;
        // 对柔性数组进行初始化
        for (int i = 0; i < length; i++) {
            arr->data[i] = i + 1;
        }
    }
    return arr;
}

// 使用包含柔性数组的结构体
void use_flex_array(struct flex_array_struct* arr) {
    if (arr != NULL) {
        printf("Length: %d\n", arr->length);
        printf("Array elements: ");
        for (int i = 0; i < arr->length; i++) {
            printf("%d ", arr->data[i]);
        }
        printf("\n");
    }
}

// 释放包含柔性数组的结构体的内存
void free_flex_array(struct flex_array_struct* arr) {
    free(arr);
}

int main() {
    struct flex_array_struct* flex_arr = create_flex_array(5);
    use_flex_array(flex_arr);
    free_flex_array(flex_arr);
    
    return 0;
}
/*
    在上面的示例代码中，我们首先定义了一个包含柔性数组的结构体 flex_array_struct，
    其中有一个整数类型的 length 成员变量和一个柔性数组 data。
    我们通过调用 malloc 函数来分配内存空间，确保足够容纳结构体的大小加上柔性数组的大小。
        然后，我们可以使用 -> 运算符访问结构体的成员。
    在 create_flex_array 函数中，我们通过计算结构体的大小和柔性数组的大小来正确地分配内存，
        并对柔性数组进行初始化。
    use_flex_array 函数用于访问和打印柔性数组的元素，
    free_flex_array 函数用于释放分配的内存
*/
