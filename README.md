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

  - 箭头运算符`->`

    把解引用和成员访问结合起来

    `iter->mem` 等价于 `(*iter).mem`

  - 迭代器类型：

    ```cpp
    vector<int>::iterator it;
    string::const_iterator it;
    auto it = v.cbegin(); // it的类型是vector<int>::const_iterator
    ```

  - 迭代器失效

    使用了迭代器的循环体，内部不要向容器添加元素

  - 迭代器比较

    如果it1的位置比it2的位置靠前，那说`it1 < it2`

    两个迭代器相减，得到二者的距离，类型是`difference_type`，可负可正

    ```cpp
    auto b = end(arr) - begin(arr);
    ```

    两个指针相减的结果的类型是`ptrdiff_t`，可正可负

  - 迭代器实现二分搜索

    ```cpp
    auto beg = v.begin(), end = v.end();
    auto mid = v.begin() + (end - beg) / 2;
    while(mid != end && *mid != target) {
        if(*mid > target) 
            end = mid;
        else
            beg = mid + 1;
        mid = beg + (end - beg) / 2;
    }
    ```

- 数组

  - 指针

    数组类型的对象其实就是一个指向该数组首元素的指针

    ```cpp
    string nums[] = {"sd", "sfds"};
    // 那么 nums 就是 &sums[0]
    
    int *p[10]; // p是含有10个整型指针的数组
    int (*p)[10]; // p指向一个含有10个整数的数组
    ```

  - 空间大小是常量

    ```cpp
    unsigned a = 42;  // 普通变量
    constexpr unsigned b = 42; // 常量表达式
    const unsigned c = 42;
    string s[a], s[b], s[c]; // 书上说s[a]是不对的，但编译通过了
    ```

  - 字符数组

    字符串末尾会有一个空字符，所以总长度比看起来多1

    ```cpp
    contst char a[6] = "abcdef"; // 错误，没有空间存放'\0'
    ```

  - size_t

    `size_t`类型是无符号类型，在遍历数组时定义下标

  - 函数begin和函数end

    ```cpp
    int ia[] = {0, 1, 2};
    int *pbeg = begin(ia);
    int *pend = end(ia);
    while(pbeg != pend) {
    	++pbeg;
    }
    ```

  - C风格字符串

    不建议使用，不安全

    ```cpp
    strcmp(p1, p2) 比较p1 p2相等性，返回正负数、0
    strcat(p1, p2) return p1 + p2
    strcpy(p1, p2) return p1 = p2
    ```

  - 与C风格的接口

    - 返回C风格的字符串： `s.c_str()`

