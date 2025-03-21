isalpha 字母判断函数
isalpha头文件：ctype.h
isalpha功能：判断字符是否是字母类的（alphabetic）。
包括：a(ASCII值: 97)-z(122) 和 A(65)-Z(90) 。
isalpha函数声明：

int isalpha ( int c );
1
c是我们输入的，需要被判断的字符。
不是字母类的，返回值0。是字母类的，返回非0值。
isalpha使用实例：
```c
	#include <stdio.h>
	#include <ctype.h>
	int main()
	{
		char str[] = "C++";
		for(int i=0;i<3;i++)
		{
			if (isalpha(str[i])) 
				printf("character %c is alphabetic\n", str[i]);
			else 
				printf("character %c is not alphabetic\n", str[i]);
		}
		return 0;
	}
```
islower 小写字母判断函数
islower头文件：ctype.h
islower功能：判断字符是否是小写字母。
包括：a(ASCII值: 97)-z(122) 。
islower函数声明：

int islower ( int c );
1
c是我们输入的，需要被判断的字符。
不是小写字母的，返回值0。是小写字母的，返回非0值。
islower使用实例：
```
	#include <stdio.h>
	#include <ctype.h>
	int main()
	{
		char str[] = "Test";
		for (int i = 0; i < 4; i++)
		{
			if (islower(str[i]))
				printf("character %c is lower.\n", str[i]);
		}
		return 0;
	}
```
isupper 大写字母判断函数
isupper头文件：ctype.h
isupper功能：判断字符是否是大写字母。
包括：A(ASCII码值: 65)-Z(90) 。
isupper函数声明：

int isupper ( int c );
1
c是我们输入的，需要被判断的字符。
不是大写字母的，返回值0。是大写字母的，返回非0值。
isupper使用实例：
```c
	#include <stdio.h>
	#include <ctype.h>
	int main()
	{
		char str[] = "Test";
		for (int i = 0; i < 4; i++)
		{
			if (isupper(str[i]))
				printf("character %c is upper.\n", str[i]);
		}
		return 0;
	}
```
tolower 大写字母转小写字母函数
tolower头文件：ctype.h
tolower功能：将大写字母转成小写字母，非大写字母不变化。
tolower函数声明：

int tolower ( int c );
1
c是输入的字符。
如果c是大写字母，返回对应小写字母的ASCII码值。如果不是，则返回c本身的ASCII码值。
tolower使用实例：
```c
	#include <stdio.h>
	#include <ctype.h>
	int main()
	{
		int i = 0;
		char str[] = "Test String.";
		while (str[i])
		{
			putchar(tolower(str[i]));
			i++;
		}
		printf("\n%s", str);
		return 0;
	}
```
toupper 小写字母转大写字母函数
toupper头文件：ctype.h
toupper功能：将小写字母转成大写字母，非小写字母不变化。
toupper函数声明：

int toupper(int c);
1
c是输入的字符。
如果c是大写字母，返回对应小写字母的ASCII码值。如果不是，则返回c本身的ASCII码值。
toupper使用实例：
```c
	#include <stdio.h>
	#include <ctype.h>
	int main()
	{
		int i = 0;
		char str[] = "Test String.";
		while (str[i])
		{
			putchar(toupper(str[i]));
			i++;
		}
		printf("\n%s", str);
		return 0;
	}
```
isdigit 十进制数字判断函数
isdigit头文件：ctype.h
isdigit功能：判断字符是否是十进制数字。
包括：0 (ASCII码值: 48)-9(57)
isdigit函数声明：

int isdigit( int c);
1
c是我们输入的，需要被判断的字符。
不是十进制数字的，返回值0。是十进制数字的，返回非0值。
isdigit使用实例：
```c
	#include <stdio.h>
	#include <ctype.h>
	int main()
	{
		char id[] = "qq:2149649773";
		int i = 0;
		while (id[i])
		{
			if (isdigit(id[i]))
				printf("%c", id[i]);
			i++;
		}
		return 0;
	}
```
isxdigit 十六进制数字判断函数
isxdigit头文件：ctype.h
isxdigit功能：判断字符是否是十六进制数字。
包括：0-9，a-f，A-F。
isxdigit函数声明：

int isxdigit ( int c );
1
c是我们输入的，需要被判断的字符。
不是十六进制数字的，返回值0。是十六进制数字的，返回非0值。
isxdigit使用实例：
```c
	#include <stdio.h>
	#include <ctype.h>
	int main()
	{
		char id[] = "qq:2149649773abcdEF";
		int i = 0;
		while (id[i])
		{
			if (isxdigit(id[i]))
				printf("%c", id[i]);
			i++;
		}
		return 0;
	}
```
isalnum 字母或数字判断函数
isxdigit头文件：ctype.h
isxdigit功能：判断字符是否是十六进制数字。
包括：0-9，a-f，A-F。
isxdigit函数声明：

int isxdigit ( int c );
1
c是我们输入的，需要被判断的字符。
不是十六进制数字的，返回值0。是十六进制数字的，返回非0值。
isxdigit使用实例：
```c
	#include <stdio.h>
	#include <ctype.h>
	int main()
	{
		char id[] = "qq:2149649773abcdEF";
		int i = 0;
		while (id[i])
		{
			if (isxdigit(id[i]))
				printf("%c", id[i]);
			i++;
		}
		return 0;
	}
```
