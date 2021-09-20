#include <iostream>
#include <cmath>
#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace std;
using namespace Eigen;

int main(int argc, char const *argv[])
{
    // 证明1：
    cout << "证明1: " << endl;
    // 首先创建创建一个随机的四元数，并将其转变为旋转矩阵
    Vector3d q = Vector3d::Random();
    Isometry3d R = Isometry3d::Identity();                // 矩阵初始化
    R.rotate(q); 

    //证明 R*R^T = I
    auto I = R * R.inverse();
    return 0;
}


