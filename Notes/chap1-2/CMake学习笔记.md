# CMake 学习笔记

> 基于 [CMake官方文档](https://cmake.org/cmake/help/latest/guide/tutorial/index.html#)的学习笔记

## Step1 : 起点

对于任何工程来说，最基础，最重要的事情就是要创建一个可执行文件，这需要我们创建一个`CMakeLists.txt`，并在其中写入：

```c
# 设置可执行次文件的最低版本
cmake_minimum_required(VERSION 3.10)

# 设置工程名
project(Tutorial)

# 创建可执行文件
add_executable(Tutorial tutorial.cxx)
```

上面是为工程中创建一个可执行文件的最小`CMakeLists.txt`。下面我们会让这个`CMakeLists.txt`变得"fancy"一点

```c
# 设置可执行次文件的最低版本
cmake_minimum_required(VERSION 3.10)

# 设置工程名和版本号
project(Tutorial VERSION 1.0)

#配置一个头文件将版本号传递给源代码：
configure_file(TutorialConfig.h.in TutorialConfig.h)

# 创建可执行文件
add_executable(Tutorial tutorial.cxx)

#由于配置的文件将写入二叉树，我们必须将该目录添加到路径列表中以搜索包含文件
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
```


