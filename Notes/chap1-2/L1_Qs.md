# SLAM 十四讲作业及答案

## Lecture 1

### Q1 SLAM 综述文献阅读

当你对某个研究领域不了解时，最好是从综述文献开始了解这个领域的整体⾯貌。SLAM 作为一个近30 年的研究领域，⾄今也存在着大量的综述、总结类的文章。请阅读本次作业 paper/⽬录下的文章 [1–3]（其中 [3] 是中文文献），了解这个领域的大致情况。如果你的时间有限，可以仅阅读每篇文章的第一章（也就是引⾔一章），然后回答下列问题：

文献链接：
链接：https://pan.baidu.com/s/11CKH9p45U8jViunUrv7qBQ 
提取码：aiic 

1. SLAM 会在哪些场合中用到？⾄少列举三个方向。
2. SLAM 中定位与建图是什么关系？为什么在定位的同时需要建图？
3. SLAM 发展历史如何？我们可以将它划分成哪⼏个阶段？
4. 列举三篇在 SLAM 领域的经典文献。

#### Q1-1

答：
* 增强现实：同时定位与地图构建作为增强现实的关键基础技术, 可以用来在未知环境中定位自身方位并同时构建环境三维地图, 从而保证叠加的虚拟物体与现实场景在几何上的一致性。
* 机器人：在一个未知的环境中实时重建环境的三维结构并同时对机器人自身进行定位。从中又可以细分为无人机和无人驾驶。
* 视觉监控系统。
* 高风险或难航行环境的救援任务。
* 行星、空中、陆地和海洋探索。
* 增强现实应用程序，其中虚拟对象包含在现实世界的场景中。

#### Q1-2

答：
定位和建图是相互依赖的关系。为了精确的定位，我们需要一张正确且精确的地图，但是为了获得一个好的地图，当各种元素添加到地图的时候又需要正确的定位。

#### Q1-3

答：
* 1985-1990年，Chatila和Laumond提出以并发的方式进行映射和定位，并给它起了一个名字：SLAM
* 2002-2009，外部感受和本体感受用于从环境构建地图。 外部感受器：声纳、激光测距、照相机、GPS。 所有这些传感器都很嘈杂，而且范围能力有限。 本体感受传感器：编码器、加速度计和陀螺仪。 它们允许实体获得速度、位置变化和加速度等测量值。 但是由于它们的固有噪声，它们不足以始终对实体的位置进行准确估计，因为误差是累积的。 洞察力。

对于纯视觉而言：
* 视觉导航的第一个作品是基于双目立体配置。(2002, 2003)
* 使用多相机装置的作品。(2010, 2011)
* 带有特殊镜头的相机，如广角（2004）或全向（2008）。
* RGB-D（彩色图像和深度图）传感器。(2011) 一个有前途的替代方案。
  
#### Q1-4

答：
* Smith, R.C. and P. Cheeseman, On the Representation and Estimation of Spatial Uncertainty. International Journal of
Robotics Research, 1986. 5
* Se, S., D. Lowe and J. Little, Mobile robot localization and mapping with uncertainty using scale­invariant visual
landmarks. The international Journal of robotics Research, 2002. 21
* Mullane, J., et al., A Random­Finite­Set Approach to Bayesian SLAM. IEEE Transactions on Robotics, 2011

### Q2 CMake 练习

cmake 是一种常用、方便的，用于组织 Linux 下 C++ 程序的工具。有许多库，例如 OpenCV、g2o、Ceres 等，都用 cmake 组织它们的工程。所以，不管是使用别⼈的库，还是编写自己的库，都需要掌握一些 cmake 的基本知识。也许你之前没有听过这个工具，但不要紧，我们准备了阅读材料“books/CmakePractice.pdf”（cmake 实践，由一位北大同学撰写）。请阅读此文的第 1 ⾄ 6 章，并完成以下工作：书写一个由 cmake 组织的 C++ 工程，要求如下：

1. include/hello.h 和 src/hello.c 构成了 libhello.so 库。hello.c 中提供一个函数 sayHello()，调用此函数时往屏幕输出一⾏“Hello SLAM”。我们已经为你准备了 hello.h 和 hello.c 这两个文件，见“code/”⽬录下。
2. 文件 useHello.c 中含有一个 main 函数，它可以编译成一个可执⾏文件，名为“sayhello”。
3. 默认用 Release 模式编译这个工程。
4. 如果用户使用 sudo make install，那么将 hello.h 放⾄/usr/local/include/下，将 libhello.so 放⾄/usr/local/lib/下。请按照上述要求组织源代码文件，并书写 CMakeLists.txt。

#### 2-1 


