# Cmake 学习笔记

>本文为基于书籍《Cmake 实践》的笔记
>书籍链接：https://pan.baidu.com/s/1CDW89ZuK5NlvceU-SAMxUA 
提取码：x11y 
>Cmake官方教材：https://cmake.org/cmake/help/latest/guide/tutorial/index.html
>笔记基于 Linux 系统

## 1. 简单的CMake编译
首先创建一个练习用文件夹比如 `Cmake_Practice/t1`。

```
cd Cmake_Practice
touch main.cpp CmakeLists.txt
```

然后在`main.cpp`中写入：

```cpp
#include <iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    cout << "Hello World form t1 Main!\n";
    return 0;
}
```

在`CmakeLists.txt`中写入：

```Cmake
project(HELLO)

set(SRC_LIST main.cpp)

message(STATUS "This is BINARY dir " ${HELLO_BINARY_DOIR})
message(STATUS "This is SOURCE dir " ${HELLO_SOURCE_DOIR})

add_executable(hello ${SRC_LIST})
```

编写之后，在当前文件目录下使用：
```
cmake .
```
就会生成很多文件，其中最重要的是`MakeFile`文件，如果没有生成这个文件的话，可能是`CMakeLists.txt`中书写上有一些小错误。

没有问题之后再：

```
make
```

就会出现一个可执行文件，比如我这个这里有：`hello`

使用`./hello`就会在控制台打印：

```
Hello World form t1 Main!
```

如果想要清除构建结果（对于上面的例子而言就是`hello`可执行文件），则可以使用：

```
make clean
```

**语法讲解：**

* project 语法
    project(projectname [CXX] [C] [Java])
    后面中括号内为工程中可以使用的语言，一般情况下不写，默认值为全部。
<br>

* set 语法
    set(VAR [VALUE] [CACHE TYPE DOCSTRING [FORCE]])
    现阶段，你只需要了解 SET 指令可以用来显式的定义变量即可。
    比如我们用到的是 `SET(SRC_LIST main.c)`，如果有多个源文件，也可以定义成：`SET(SRC_LIST main.c t1.c t2.c)`
<br>

* message 语法
    message(([SEND_ERROR | STATUS | FATAL_ERROR] "message to display"
...)
    这个指令用于向终端输出用户定义的信息，包含了三种类型:
    * SEND_ERROR，产生错误，生成过程被跳过。
    * SATUS，输出前缀为`—`的信息。
    * FATAL_ERROR，立即终止所有 cmake 过程.
<br>

* add_executable 语法
    add_executable(<executable_name> 源文件)
    源文件可以是`${}`变量，也可以使用直接名称
<br>

* 基本语法规则：
    1. 变量使用${}方式取值，但是在 IF 控制语句中是直接使用变量名
    2. 指令(参数 1 参数 2...)
  
    参数使用括弧括起，参数之间使用空格或分号分开。
    以上面的 `add_executable` 指令为例，如果存在另外一个 `func.c` 源文件，就要写成：
    ```
    ADD_EXECUTABLE(hello main.c func.c)
    or
    ADD_EXECUTABLE(hello main.c;func.c)
    ```

## 2. 复杂一点的 CMake 编译

本小节的任务是让程序更像是一个工程，我们需要作的是：

* 为工程添加一个子目录 src，用来放置工程源代码；
* 添加一个子目录 doc，用来放置这个工程的文档 doc.txt；
* 在工程目录添加文本文件 COPYRIGHT, README；
* 在工程目录添加一个 run.sh 脚本，用来调用二进制文件；
* 将构建后的目标文件放入构建目录的 bin 子目录；
* 最终安装这些文件：将二进制文件 与 run.sh 安装至/usr/bin，将 doc 目录的内容以及 COPYRIGHT/README 安装到/usr/share/doc/cmake/t2。


### 2.1 外部构建

之前我们使用的`cmake`构建方式为内部构建，我们可以在目录中看到很多`cmake`产生的中间文件。为了让文件看起来更整洁一些，我们可以使用外部构建的方法。

首先在我们一开始创建文件夹下创建`build`目录，进入`build`，运行`cmake ..`（注意，之前的命令为`cmake .`，只有一个`.`的意思是在当前目录下执行`cmake`而两个`.`则是在父目录下执行`cmake`）

此时，所有的中间文件都被保存在了`build`中。

### include 和 src

在文件下创建`include`和`src`目录，分别用于存放工程的头文件和源文件。之后，在`include`中创建


