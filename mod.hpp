#ifndef _mod_h
#define _mod_h
#include <stdio.h>
#include <fstream>

class Matrix
{
private:
double **x;
int m,n;
public:
Matrix(int mr=0, int nr=0);// конструктор с параметрами
Matrix(Matrix& mat, double k);//копирование
Matrix(double d);//преобразование
operator double();//
~Matrix();
void inputMatrix(FILE *&f);
void outputMatrix(FILE *&f);
double*& operator[] (int i){return x[i];};//перегрузка оператора индексации( так мы получаем доступ к элементам матрицы, которая объявлена в private)
int getSize_m() {return m;};
int getSize_n() {return n;};
};

#endif
