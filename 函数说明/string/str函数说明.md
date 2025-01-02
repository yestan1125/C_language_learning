1. strcpy() 复制
原型：char * strcpy(char *dest, char *src);

功能：src指向的字符 复制到dest中

返回：dest 

示例：
```c
	#include<stdio.h>
	#include<string.h>
	int main(void)
	{
		char desn[10];	
		char* source="hello world!";
		strcpy(desn,source);
		printf("源字符串  :%s\n",source);
		printf("目标字符串:%s\n",desn);
		return 0;
	}
```
2. strncpy() 复制
原型：char * strncpy(char *dest, char *src, size_t  maxsize)

功能：src指向的字符 复制到dest中，并返回dest,限制最大字符串长度 maxsize。当src中少于maxsize时，使用‘\0’填充。其中size_t是无符号整型，保证maxsize始终为正数。

返回： dest

示例：
```c
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	int main()
	{
	   char * src="hello,world!";
	   char dest[20];
	   strncpy(dest, src, 20);
	  
	   printf("源字符串  :%s\n",src);
	   printf("目标字符串:%s\n",dest);
	   system("pause");
	   return(0);
	}
```
3. strcat() 合并
原型：char *strcat(char *dest, const char *src)

功能：将字符串src 连接到dest的尾部。

返回: dest

示例：
```c
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	int main()
	{
	   char * src="world" ;
	   char  dest[50] ="hello,"; /*目标字符串必须声明足够的长度，足够连接src字符串长度*/
	  
	   strcat(dest, src);
	   printf("目标字符串:%s\n",dest);
	   system("pause");
	   return(0);
	}
```
4. strncat() 合并
原型：char *strcat(char *dest, const char *src,size_t maxsize)

功能：将字符串src 最多前maxsize个字符 连接到dest的尾部。src中必须有字符串结束符'\0'

返回: dest

示例：
```c
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	int main()
	{
	   char * src="world" ;
	   char  dest[50] ="hello,"; /*目标字符串必须声明足够的长度，足够连接src字符串长度*/
	  
	   strncat(dest, src,3);
	   printf("目标字符串:%s\n",dest);
	   system("pause");
	   return(0);
	}
```
5. strcmp() 比较
原型：int strcmp(const char *str1, const char *str2)

功能：比较字符串str1和str2

返回:  当str1<str2,返回值小于0

当str1=str2,返回值等于0

当str1>str2,返回值大于0

示例：
```c
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	int main()
	{
	   char * str1  ="hello,world!" ;
	   char * str2  ="hello,human!"; 
	  
	   int res= strcmp(str1, str2);
	   if(res<0)
		 printf("str1小于str2");
	   else if(res==0)
		 printf("str1等于str2");
	   else
		 printf("str1大于str2");
	    printf("\n");
	   system("pause");
	   return(0);
	}
```
6. strncmp() 比较
原型：int strncmp(const char *str1, const char *str2,size_t maxsize)

功能：字符串str1中至多maxsize个字符与字符串str2比较

返回:  当str1<str2,返回值小于0

当str1=str2,返回值等于0

当str1>str2,返回值大于0

示例：
```c
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	int main()
	{
	   char * str1  ="hello,world!" ;
	   char * str2  ="hello,human!"; 
	  
	   int res= strncmp(str1, str2,5);
	   if(res<0)
		 printf("str1小于str2\n");
	   else if(res==0)
		 printf("str1等于str2\n");
	   else
		 printf("str1大于str2\n");
	   printf("\n");
	   system("pause");
	   return(0);
	}
```
7. strchr() 查找
原型：char *strchr(const char * src, int c)

功能：查找字符c在src中的第一次出现的位置

返回:  字符c在src中的第一次出现位置的指针

示例：
```c
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	int main()
	{
	   char * str  ="hello,world!" ;
	  
	   char * pos;
	  
	   pos= strchr(str, 'o');
	   
	   printf("\n 字符第一次出现的位置为第%d个（从0开始），内存地址为:0x%x\n", pos-str,pos );
	 
	   system("pause");
	   return(0);
	}
```
8. strrchr() 查找
原型：char * strrchr(const char * src, int c)

功能：查找字符c在src中的最后一次出现的位置

返回:  字符c在src中的最后一次出现位置的指针

示例：
```c
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	int main()
	{
	   char * str  ="hello,world!" ;
	   char * pos;
	 
	   pos= strrchr(str, 'o');
	   printf("\n 字符最后一次出现的位置为第%d个（从0开始），内存地址为:0x%x\n", pos-str,pos );
	 
	   system("pause");
	   return(0);
	}
```
9. strcspn() 查找
原型：size_t strcspn(const char * str1, const char * str2)

功能：返回字符串 str1 中包含str2中字符的前缀的长度。或者可以理解为字符串 str1 中第一个在字符串 str2 中出现的字符下标 。直接看代码和运行结果，看完就明白了。

示例：
```c
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	int main()
	{
	   char * str1  ="world!" ;
	   char * str2="jbgar"; 
	 
	   int len;
	   len = strcspn(str1, str2);/*world中r在ar中出现了，它的下标是2*/
	 
	   printf("\nstr1中找到第一个在str2中出现的字母，它的下标为:%d\n", len);
	 
	   system("pause");
	   return(0);
	}
```
10. strspn() 查找
原型：size_t strspn(const char * str1, const char * str2)

功能：返回字符串 str1 中不包含str2中字符的前缀的长度。或者可以理解为 查找字符串 str1 中第一个没有在字符串 str2 中出现的字符下标 。直接看代码和运行结果，看完就明白了。这个容易和strcspn()函数搞反，得格外注意。

示例：
```c
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	int main()
	{
	   char * str1  ="world!" ;
	   char * str2="dewor"; 
	 
	   int len;
	   len = strspn(str1, str2);/*world中l在是第一个没有在dewor中出现，它的下标是3*/
	 
	   printf("\nstr1中找到第一个没有在str2中出现的字母，它的下标为:%d\n", len);
	 
	   system("pause");
	   return(0);
	}
```
11. strpbrk() 查找
原型：char  *  strpbrk(const char * str1, const char * str2)

功能：查找str2的任意字符在str1中第一次出现的位置，并返回指向这个位置的指针

返回:  字符指针
```c
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	int main()
	{
	   char * str1  ="world!" ;
	   char * str2="glar"; 
	   char * pos;
	 
	   pos = strpbrk(str1, str2);/*glar中的r是第一个在world中出现，将返回r的位置，
								 虽然glar中的l在world中也出现，但是它不是第一个在world中出现的*/
	 
	   printf("\nstr2的字符在str1中第一个出现的字母是%c,它在str1的下标为%d\n", *pos,pos-str1);
	 
	   system("pause");
	   return(0);
	}
```
12. strstr() 查找
原型：char  *  strstr(const char * str1, const char * str2)

功能：查找str2在在str1中第一次出现的位置，并返回指向这个位置的指针

返回:  字符指针
```c
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	int main()
	{
	   char * str1  ="wohello,world!" ;
	   char * str2="wor"; 
	   char * pos;
	 
	   pos = strstr(str1, str2);
	 
	   printf("\n\"wor\"在\"wohello,world\"中第一个出现的位置下标为%d\n", pos-str1);
	 
	   system("pause");
	   return(0);
	}
```
13. strlen() 计算长度
原型：size_t  strstr(const char * str)

功能：返回str的长度

示例:
```c
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	int main()
	{
	   char * str1  ="hello,world!" ;
	  
	   int len = strlen(str1);
	 
	   printf("\n\str1的长度：%d\n", len);
	 
	   system("pause");
	   return(0);
	}
```
15. strtok() 截取
原型：char * strtok(char* str1,const char* str2)

功能：使用str2,对str1字符串进行分隔截取，返回截取的部分字符串

示例:
```c
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	 
	int main()
	{
	   char  str [] ="hello@world@coffee@tea!" ;
	   char * c="@" ;
	 
	  
	   printf("\n第一个:%s\n", strtok(str,c));
	   printf("\n第二个:%s\n", strtok(NULL,c));
	   printf("\n第三个:%s\n", strtok(NULL,c));
	   printf("\n第四个:%s\n", strtok(NULL,c));
	 
	   printf("\n再重新开始:%s\n", strtok(str,c));
	   system("pause");
	   return(0);
	}
```
