1.qsort函数
一个用于排序的函数，它提供了一种通用的排序方法，可以对各种数据类型的数组进行排序。这个函数实现了快速排序（Quick Sort）算法的一个变体。

函数原型
void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
下面是对每个参数的详细解释：
base：这是指向要排序的数组的第一个元素的指针。它可以是任何数据类型的数组，例如整数数组、字符数组、结构体数组等。由于它是void *类型，这使得qsort函数能够处理不同类型的数组。
nmemb：表示数组中元素的数量。这是一个size_t类型的参数，size_t通常是无符号整数类型，用于表示内存大小或对象数量等。
size：表示数组中每个元素的大小，单位是字节。这个参数很重要，因为qsort函数需要知道每个元素的大小，才能正确地移动和比较数组中的元素。
compar：这是一个函数指针，指向一个比较函数。这个比较函数用于确定数组中两个元素的相对顺序。比较函数的原型应该是int (*compar)(const void *, const void *)，并且应该返回一个整数值来表示两个元素的大小关系。

定义比较函数：
首先需要定义一个符合qsort要求的比较函数。这个函数用于比较数组中的两个元素，并返回一个整数值来表示它们的大小关系。例如，对于一个整数数组，比较函数可以这样定义：

    int compare(const void * a, const void * b)
    {
        int arg1 = *(const int*)a; 
        int arg2 = *(const int*)b;
        if (arg1 < arg2) return -1;
        if (arg1 > arg2) return 1;
        return 0;
    }
调用 qsort 函数：
假设我们有一个整数数组int arr[] = {5, 2, 8, 1, 9};，要对这个数组进行排序，我们可以这样调用qsort函数：

    int main()
    {
        int arr[] = {5, 2, 8, 1, 9};
        int n = sizeof(arr)/sizeof(arr[0]);
        qsort(arr, n, sizeof(int), compare);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        return 0;
    }

在这个例子中，qsort函数的第一个参数&arr[0]（可以简写为arr）是数组的起始地址，第二个参数n是数组元素的个数，第三个参数sizeof(int)是每个元素的大小，第四个参数compare是前面定义的比较函数。

注意事项
数据类型的通用性：由于qsort函数使用void *指针来处理数组元素，在比较函数中需要正确地将void *指针转换为实际的数据类型指针。例如，在比较整数数组时，将void *转换为const int *然后解引用得到整数进行比较。
稳定性问题：qsort函数实现的排序算法不是稳定的排序算法。稳定排序是指在排序过程中，相等元素的相对顺序不会改变。如果需要稳定排序，可能需要考虑其他排序算法或者对qsort进行适当的包装。
比较函数的正确性：比较函数的返回值必须正确地反映两个元素的大小关系。如果返回值不符合要求，qsort函数将无法正确地排序数组。并且比较函数应该避免产生副作用，例如修改数组元素的值（除非这是有意设计的并且在可控范围内）。

example:

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
      
    // 比较函数，用于字符串字典序比较
    int compare(const void *a, const void *b) {
        const char *str1 = *(const char **)a;
        const char *str2 = *(const char **)b;
        return strcmp(str1, str2);
    }
    
    int main() {
        char *strings[] = {"banana", "apple", "cherry", "date"};
        int numStrings = sizeof(strings) / sizeof(strings[0]);
    
        // 使用qsort函数对字符串数组进行排序
        qsort(strings, numStrings, sizeof(char *), compare);
    
        // 输出排序后的字符串数组
        for (int i = 0; i < numStrings; i++) {
            printf("%s\n", strings[i]);
        }
    
        return 0;
    }
