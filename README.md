# 第1章 开始

- 输入输出

  cin, cout, cerr, clog

# 第2章 变量和基本类型

- 算术类型

  1字节(byte) = 8比特(bit)

  1字(word) = 4/8字节(byte) = 32/64比特(bit)

- 字面值常量

  0开头：八进制

  0x开头：十六进制

- 指定字面值类型

  前缀：u U (unicode) L u8

  后缀：u U (unsigned) L LL F

- 初始化

  extern不要显式地初始化变量

  引用必须被初始化

- &和*

  &： 1.引用  2.取地址符

  *： 1.指针  2.解引用符

  第1条都叫类型修饰符，是声明符的一部分

- void*指针能存放任意对象的地址

- const

  const对象仅在文件内有效

  当多个文件中出现了同名的const变量，等同于不同文件内分别定义了独立的变量

  如果想在多个文件之间共享const对象，需要在定义和声明之前加extern

  常量引用(对const的引用)仅对引用可参与的操作做了限定，仍可以通过改变绑定的变量来改变值（只是不能通过引用本身来改变）

- 指针和const

  指向const的指针仅仅要求不能通过该指针改变对象的值，而没有规定那个对象的值不同通过别的途径改变

  const指针：`*const`说明指针是一个常量，意味着存放在指针里的地址(而不是指向的值)是不能再改变的

- 常量表达式（const expression）

  定义：1.值不会改变 2.在编译过程中救恩那个得到结果

  constexpr : 便于编译器验证变量是否是一个常量表达式，声明时使用

- 别名

  1. `typedef a b;`  b是a的别名
  2. `using b = a; ` b是a的别名

- 显示变量类型

  ```c++
  #include <typeinfo>
  std::cou<< typeid(a).name();
  ```

- decltype

  返回操作数的数据类型

  `decltype((variable))`的结果永远是引用

- 预处理器(preprocessor)

  ```c++
  #ifndef A
  #define A
  ...
  #endif
  
  
  #ifdef A
  ...
  #endif
  ```

  

# 第3章 字符串、向量和数组

- using声明

  `using namespace：：name;`  每行声明一个name

  头文件不要包含using声明

- string

  ```c
  string s(10, 'c');  // 10个c
  ```

  | 操作           |                                           |
  | -------------- | ----------------------------------------- |
  | os<<s          | 把s写到输出流os中，返回os                 |
  | is>>s          | 从is中读取字符串赋值给s，字符串以空白分割 |
  | getline(is, s) | 从is中读取一行赋值给s，返回is             |
  | <, <=, >, >=   | 比较字典序，对大小写敏感                  |

  字符串字面值与string是不同的类型，所以计数变量的定义：

  `decltype(s.size()) cnt = 0;`

- 处理字符

  | 头文件： cctype |                    |
  | --------------- | ------------------ |
  | isalnum(c)      | 字母或数字         |
  | isalpha(c)      | 字母               |
  | isdigit(c)      | 数字               |
  | ispunct(c)      | 标点符号           |
  | isspace(c)      | 空格、制表符、回车 |
  | islower(c)      | 是小写             |
  | isupper(c)      | 是大写             |
  | tolower(c)      | 转小写             |
  | toupper(c)      | 转大写             |

- vector

  - 初始化

    ```
    vector<T> v(n, val);
    vector<T> v = {a, b, c, d};
    vector<T> v(v_copy);
    ```

- 迭代器




  