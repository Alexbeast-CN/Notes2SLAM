#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

#define MATRIX_SIZE 100

// 编程实现 A 为 100 × 100 随机矩阵时，⽤ QR 和 Cholesky 分解求 x 的程序
int main(int argc, char const *argv[])
{
    // 创建随机矩阵 A[100x100] 并输出
    Matrix<double, MATRIX_SIZE, MATRIX_SIZE> A
    = MatrixXd::Random(MATRIX_SIZE, MATRIX_SIZE);
    // cout << "Matrix A is: \n" << A << endl;

    // 创建随机
    Matrix<double, MATRIX_SIZE, 1> B = MatrixXd::Random(MATRIX_SIZE, 1);
    // cout << "Matrix B is: \n" << B << endl;

    // 求解 Ax = B
    // 1. QR 分解
    auto x = A.colPivHouseholderQr().solve(B);
    cout << "QR decompostion: \n x = " << x << endl << endl; 

    // 2. Cholesky 分解
    auto y = A.ldlt().solve(B);
    cout << "Cholesky decompostion: \n x = " << y << endl; 

    return 0;
}

