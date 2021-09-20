#include <iostream>
#include <cmath>
#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace std;
using namespace Eigen;

int main(int argc, char const *argv[])
{
    // 创建两个四元数(首位是实数)，并归一化
    Quaterniond q1 = {0.55,0.3,0.2,0.2};
    Quaterniond q2(-0.1,0.3,-0.7,0.2);
    // 归一化可以使四元数生成正交矩阵(注意没有d)
    q1.normalize();
    q2.normalize();

    // 创建两个位移向量
    Vector3d t1(0.7,1.1,0.2);
    Vector3d t2(-0.1,0.4,0.8);

    // 创建 点 p_1
    Vector3d p_1(0.5,-0.1,0.2);

    // 旋转矩阵1
    Isometry3d T1 = Isometry3d::Identity();                // 矩阵初始化
    T1.rotate(q1);                                     
    T1.pretranslate(t1);     

    // 旋转矩阵2
    Isometry3d T2 = Isometry3d::Identity();                // 矩阵初始化      
    T2.rotate(q2);                                     
    T2.pretranslate(t2); 

    // 通过一次变换得到 p 点的世界坐标
    // 第二次变换得到 p 点在 2 号的坐标
    Vector3d p_2 =T2 * T1.inverse() * p_1;


    cout << p_2.transpose() << endl;
    return 0;
}
