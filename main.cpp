#include "mod.hpp"
#include <iostream>

int main (int argc, const char * argv[]) {
    if (argc < 3) {
        std::cout << "Invalid input" << std::endl;
        return -1;
    }
    
setlocale(LC_ALL, "rus");
FILE *fin = fopen(argv[1], "r");
FILE *fout = fopen(argv[2], "w");
int am, an;
double d,ch;

printf("Введите размеры матрицы\n");
scanf("%d", &an);
scanf("%d",&am);
printf("Rазмеры матрицы\n");
printf("%d ", an);
printf("%d\n", am);
printf("Введите значение, на которое надо увеличить каждый элемент матрицы\n");
scanf("%lf",&ch);
printf("Введенное значение=");
printf("%lf",ch);

Matrix x(am,an);//конструктор с двумя параматрами

Matrix nullMatrix;//вызов как будто конструктор умолчания

fprintf(fout, "Нулевая матрица: \n");

nullMatrix.outputMatrix(fout);

x.inputMatrix(fin);

fprintf(fout, "Первая матрица: \n");
x.outputMatrix(fout);


d = x;//из матрицы double (d=ср знач)
fprintf(fout, "%s %g\n", "Среднее арифметическое значений матрицы:", d);

Matrix y(x,ch); //конструктор, который создаёт новую матрицу таким образом, что все её элементы больше элементов
//другой матрицы на заданное число, и который можно использовать как конструктор копирования.

fprintf(fout, "Вторая матрица: \n");
y.outputMatrix(fout);

d = y;//d=ср знач новой матрицы
Matrix z(d);//из double в матрицу

fprintf(fout, "Из double в матрицу: \n");
z.outputMatrix(fout);

x.~Matrix();//деструктор

fclose(fin);
fclose(fout);

return 0;
}
