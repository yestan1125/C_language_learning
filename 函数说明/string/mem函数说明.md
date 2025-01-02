1. memcpy() 复制 //对于二维数组，memcpy的复制效果更好(连续地址)\n
原型：void *memcpy(void *dest, const void *src, size_t n);

参数解释：
dest：这是目标内存区域的指针。它指向的内存区域将接收从src复制过来的数据。这个指针可以指向任何类型的对象（如字符数组、整数数组、结构体等）的起始地址，因为memcpy是按字节进行操作的。
src：这是源内存区域的指针。它指向要被复制的数据所在的内存区域，同样可以指向任何类型的对象。由于函数内部不会修改src指向的数据，所以它被声明为const void *，以确保数据的安全性。
n：这是一个size_t类型的参数，表示要从src复制到dest的字节数。size_t通常是一个无符号整数类型，用于表示对象的大小或数组的长度等。
返回值：
memcpy函数返回一个void *类型的指针，这个指针实际上就是dest指针的副本。这样做的主要目的是方便函数调用后进行链式操作，不过在实际使用中，很多时候这个返回值可能没有被利用。例如，可以连续使用memcpy来复制多个不同的数据块到一个目标区域，通过返回值来连接这些操作。

示例：
```c
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	int main()
	{
		
	   char  str1[13]  ;
	   char * str2="hello,world!" ;
	  
	   memcpy(str1,str2,13);
		
	   printf("\n\str1中字符为：%s\n", str1);
	 
	   system("pause");
	   return(0);
	}
```
2. memcmp() 比较
原型：int  memcmp(const char * str1, const char * str2 ,int n)

功能：str1中的前n个字符和str2中的值进行比较。

返回：

        当str1<str2时，返回值<0

        当str1=bstr2时，返回值=0

        当str1>str2时，返回值>0

示例：
```c
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	int main()
	{
		
	   char * str1="hello,world!" ;
	   char * str2="helle" ;
	   char * resstr;
	   int res=memcmp(str1,str2,5);
	   if(res<0)
		  resstr="小于";
	   else if(res=0)
		   resstr="等于";
	   else 
		   resstr="大于";
	   printf("\n\str1的前5个字符%sstr2的字符\n", resstr);
	 
	   system("pause");
	   return(0);
	}
```
3. memchr() 查找
原型：char * memchr(const char * str, char  c ,int n)

功能：在str中前n个字符中查找 c的位置，返回找到的位置的指针，如果找不到返回NULL

示例:
```c
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	 
	int main()
	{
	   char * str="hello,world!" ;
	   char  c=',' ;
	   char * pos;
	   pos=(char*) memchr(str,c,10);
	  
	   printf("\n\",\"在\"hello,world\"的下标位置为：%d\n", pos-str);
	 
	   system("pause");
	   return(0);
	}
```
4. memset() 替换
原型：void * memset( void * ptr, int  value ,size_t n)

功能：此函数初始化函数，将某一块内存(参数ptr)中的内容全部设置为指定的值 value

         将ptr中的前n个数据替换为value,并返回ptr,

示例1:
```c
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	 
	int main()
	{
	   char  str []="hello,world!" ;
	   char  c='w' ;
	 
	   memset(str,c,5);
	   printf("\n\str中字符串:%s\n", str);
	 
	   system("pause");
	   return(0);
	}
```
示例2：

结构变量初始化，将结构中的变量用value初始化。
```c
	#include <stdio.h>
	#include <stdlib.h>
	 
	typedef struct manager {
		int iArr [12];
		float fArr [5];
		char ch; //整型int赋值给char,只要数组在-128到127之间就没问题
	} Manager;
	 
	//打印manager中的值
	 void  printManager(Manager manager)
	{
		int i=0;
		puts("iArr值:");
		for(; i<12; i++)   //打印数组iArr的所有元素
			printf("第%d个: %d\n",i+1, manager.iArr[i]);
		puts("\nmanager->fArr值:");
		for(i=0; i<5; i++) //打印数组fArr的所有元素
			printf("第%d个: %f\n",i+1, manager.fArr[i]);
		puts("\nmanager->ch值:");
		printf("%c\n", manager.ch);
	}
	 
	void memsetTest()
	{
		Manager  manager ;
		
	printf("使用65初始化\n");
	memset(&manager,65,sizeof(manager));
	printManager(manager);
 
	printf("\n使用0初始化\n");
	memset(&manager,0,sizeof(manager));
	printManager(manager);
 
	}
	 
	int main()
	{
 
    memsetTest();
	getchar();
	return 0;
 
	}
```
5. memmove() 替换
   
原型：void *memmove(void *dest, const void *src, size_t n);
功能：将s中的前n个字符替换为c,并返回s,功能和memcpy一样，但是可以解决linux下memcpy因为地址重叠而造成替换失败的问题。算是对memcpy的一个升级。在windows系统中没有这个问题。

示例:
```c
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	int main()
	{
	   char * src="hello,world!";
	   char dest[20];
	   memmove(dest, src, 20);
	  
	   printf("源字符串  :%s\n",src);
	   printf("目标字符串:%s\n",dest);
	   system("pause");
	   return(0);
	}
```
