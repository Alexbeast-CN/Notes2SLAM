#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

#define MATRIX_SIZE 100

// 编程实现 A 为 100 × 100 随机矩阵时，⽤ QR 和 Cholesky 分解求 x 的程序
int main(int argc, char const *argv[])
{
    // 创建矩阵 A[100x100]
    Matrix<double, MATRIX_SIZE, MATRIX_SIZE> A
    = MatrixXd::Random(MATRIX_SIZE, MATRIX_SIZE);

    // QR 分解
    auto B = A.colPivHouseholderQr();

    // Cholesky 分解
    auto C = A.ldlt();

    // 输出结果
    cout << "The result of QR decomposition is \n" << B << endl;
    cout << "The result of Cholesky decomposition is \n" << C << endl; 

    return 0;
}

