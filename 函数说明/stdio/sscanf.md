1. **函数定义与用途**
   - `sscanf`函数是C语言中的一个标准输入/输出函数，定义在`<stdio.h>`头文件中。它用于从字符串中读取格式化的数据。其基本功能类似于`scanf`函数，但`scanf`是从标准输入（如键盘输入）读取数据，而`sscanf`是从指定的字符串中读取数据。
   - 例如，当你有一个包含数字和字符的字符串，并且想要从中提取特定格式的数字或者字符时，`sscanf`就非常有用。
2. **函数原型**
   - `int sscanf(const char *str, const char *format,...);`
   - 其中`str`是要读取的字符串，`format`是格式化字符串，用于指定读取数据的格式，后面的`...`表示可变参数列表，用于存储读取到的数据。
3. **格式化字符串（`format`）说明**
   - 格式化字符串的格式和`scanf`函数中的类似。例如：
     - `%d`：用于读取十进制整数。如果字符串中有一个十进制整数序列，`sscanf`会将其转换为整数并存储到对应的参数中。例如：
       ```c
       char str[] = "123";
       int num;
       sscanf(str, "%d", &num);
       // 此时num的值为123
       ```
     - `%f`：用于读取浮点数。假设字符串中有一个浮点数表示，如`"3.14"`，可以使用`%f`来读取。
       ```c
       char str[] = "3.14";
       float f_num;
       sscanf(str, "%f", &f_num);
       // 此时f_num的值为3.14
       ```
     - `%c`：用于读取单个字符。如果想从字符串中读取一个字符，可以使用`%c`。不过要注意，`%c`会读取遇到的第一个字符。
       ```c
       char str[] = "a";
       char ch;
       sscanf(str, "%c", &ch);
       // 此时ch的值为'a'
       ```
     - `%s`：用于读取字符串。它会读取一系列非空白字符，直到遇到空白字符为止。例如：
       ```c
       char str[] = "hello world";
       char sub_str[10];
       sscanf(str, "%s", sub_str);
       // 此时sub_str的值为"hello"
       ```
     - 还可以使用宽度修饰符，如`%5d`表示读取最多5位宽度的十进制整数。例如：
       ```c
       char str[] = "123456";
       int num;
       sscanf(str, "%5d", &num);
       // 此时num的值为12345
       ```
4. **返回值**
   - `sscanf`函数返回成功读取并赋值的输入项数。例如，如果格式字符串中有三个格式说明符（如`%d %d %d`），并且成功读取并赋值了三个数据，那么返回值为3。
   - 如果在读取任何数据之前遇到文件结束（在`sscanf`中是字符串结束），则返回`EOF`（在`<stdio.h>`中定义，通常是`-1`）。如果在读取部分数据后遇到错误，返回值是已经成功读取的项数。例如：
     ```c
     char str[] = "123 a";
     int num;
     char ch;
     int result = sscanf(str, "%d %c", &num, &ch);
     // 此时result的值为2，成功读取了一个整数和一个字符
     ```
5. **应用场景示例**
   - **数据解析**：当从文件中读取一行数据存储为字符串后，需要从中提取不同类型的数据，比如从包含日期和时间的字符串`"2023-01-01 12:00:00"`中提取年、月、日、时、分、秒。
     ```c
     char str[] = "2023-01-01 12:00:00";
     int year, month, day, hour, minute, second;
     sscanf(str, "%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);
     // 此时year = 2023, month = 1, day = 1, hour = 12, minute = 0, second = 0
     ```
   - **字符串格式转换验证**：在用户输入以字符串形式存储后，验证其是否符合特定格式并提取数据。例如，验证用户输入的是否是一个合法的电话号码格式（假设电话号码格式为`xxx - xxx - xxxx`）。
     ```c
     char input_str[20];
     int area_code, prefix, line_number;
     printf("请输入电话号码（格式为xxx - xxx - xxxx）：");
     scanf("%s", input_str);
     if (sscanf(input_str, "%d - %d - %d", &area_code, &prefix, &line_number) == 3) {
         printf("电话号码格式正确，区号：%d，前缀：%d，号码：%d\n", area_code, prefix, line_number);
     } else {
         printf("电话号码格式错误\n");
     }
     ```
