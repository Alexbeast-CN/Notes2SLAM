
# SLAM 十四讲作业及答案 - 2

## Lecture 2

### Q1 熟悉 Eigen 矩阵运算

Eigen（http://eigen.tuxfamily.org）是常⽤的 C++ 矩阵运算库，具有很⾼的运算效率。⼤部分需要在 C++ 中使⽤矩阵运算的库，都会选⽤ Eigen 作为基本代数库，例如 Google Tensorflow，GoogleCeres，GTSAM 等。本次习题，你需要使⽤ Eigen 库，编写程序，求解⼀个线性⽅程组。为此，你需要先了解⼀些有关线性⽅程组数值解法的原理。
设线性⽅程 Ax = b，在 A 为⽅阵的前提下，请回答以下问题：
1. 在什么条件下，x 有解且唯⼀？     
答： 
非齐次线性方程在A的秩与[A|B]的秩相同时方程有解，当R(A)=R(A,B)=n时方程有唯一解。
<br>

2. ⾼斯消元法的原理是什么？         
答：
[高斯消元法入门](https://blog.csdn.net/pengwill97/article/details/77200372)
[高斯消元的可视化视频](https://www.bilibili.com/video/BV1Ub411U767?from=search&seid=11274721862767203625&spm_id_from=333.337.0.0)
<br>

3. QR 分解的原理是什么？
答：
[QR 分解的解释](https://zhuanlan.zhihu.com/p/84415000)
<br>

4. Cholesky 分解的原理是什么？
<br>

5. 编程实现 A 为 100 × 100 随机矩阵时，⽤ QR 和 Cholesky 分解求 x 的程序。你可以参考本次课⽤到的 useEigen 例程。
提⽰：你可能需要参考相关的数学书籍或⽂章。请善⽤搜索引擎。Eigen 固定⼤⼩矩阵最⼤⽀持到 50，所以你会⽤到动态⼤⼩的矩阵。


