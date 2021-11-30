
#include "mod.hpp"

Matrix::Matrix(int mr, int nr) : m(mr), n(nr)//выделение памяти и заполнение нулями
{
x = new double*[mr];
for(int i = 0; i < m; i ++)
x[i] = new double[n];

for(int i = 0; i < m; i++)
for(int j = 0; j < n; j++)
x[i][j] = 0;
}

Matrix::Matrix(Matrix& mat, double k)// конструктор копирования + увеличение на k
{
m = mat.m;
n = mat.n;
x = new double*[m];
for(int i = 0; i < m; i++)
x[i] = new double[n];

for(int i = 0; i < m; i++)
for(int j = 0; j < n; j++)
x[i][j] = mat.x[i][j] + k;
}

Matrix::Matrix(double d)//преобразование double в матрицу
{
m = 1;
n = 1;
x = new double*[1];
x[0] = new double[1];
x[0][0] = d;
}

Matrix::operator double()
{
double s = 0;
for(int i = 0; i < m; i++)
for(int j = 0; j < n; j++)
s += x[i][j];

if(m*n)
s /= m*n;

return s;
}

Matrix::~Matrix()//деструктор(удаляет класс)
{
//delete[] x;
}


void Matrix::inputMatrix(FILE *&f)
{
for(int i = 0; i < m; i++)
for(int j = 0; j < n; j++)
fscanf(f, "%lf", &x[i][j]);
}

void Matrix::outputMatrix(FILE *&f)
{
if((m == 0) && (n == 0))
fprintf(f, "%s\n", "задана пустая матрица");
else
for(int i = 0; i < m; i++)
{
for(int j = 0; j < n; j++)
{
fprintf(f, "%g ", x[i][j]);
}
fprintf(f, "%\n");
}
}
