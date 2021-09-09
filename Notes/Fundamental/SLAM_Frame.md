# SLAM 框架结构

## Preliminary Knowledge:

我们主要关注的 Slam 方法有激光 Slam 和 视觉 Slam

基于视觉的 Slam 有一个开源的项目 -- ORB-SLAM3， 这是一个可以做稀疏特征点的 VSLAM 框架。

还有 Dirct Sparse Odometry 做的 Semi-dense reconstruction ，通过直接法可以使用稠密点云的 SLAM。效果比较好，但是代码质量较差，难以修改。

## Framwork of SLAM :

两个最关键的点：

自我定位和获取地图（建图），两者不可分割。


