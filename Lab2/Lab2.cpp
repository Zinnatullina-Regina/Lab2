


#include <cstdlib> // для system
#include <iostream> 
#include <string>
 
using std::cout;
using std::cin;
using std::endl;
        double c1,c2,h,tmp; 
        int n= 25,i,j,l,k;
        double as = 0;
        double a[100][100];
        double b[100],y[100],x[100], s[100];
        double o[100], m[100];
        double xbeg,xend;
        void gauss();
        double f(double);
        double p(double);
        double q(double);

        int main()
        {
            setlocale(0, "");
            n = 21;
            xbeg = 0;
            xend = 1;


            h = (xend - xbeg) / (n - 1);

            for (i = 0; i < n; i++)
            {
                m[i] = 0;
                b[i] = 0;
                y[i] = 0;
                x[i] = xbeg + i * h;
                s[i] = sqrt( pow(x[i] + 1, 3));
            }

            //Инициализация двумерного динамического массива
            for (i = 0; i < 100; i++){
                for (j = 0; j < i + 1; j++) {
                    a[i][j] = 0;
                }
            }
            //Граничные условия
            c1 = 1;
            c2 = 2.828427;
            // Правые части системы
            for (i = 0; i < n - 2; i++) {
                b[i] = f(x[i]);
            }
            //Граничные условия
            b[n - 2] = c1;
            b[n - 1] = c2;
            // Коэффициенты системы
            for (i = 0;i <= n - 3;i++)
            {
                a[i][i] = 1 / (h * h);
                a[i][i + 1] = -(2 / (h * h) + 2 * p(x[i]) / (2 * h) - q(x[i]));
                a[i][i + 2] = 1 / (h * h) + 2 * p(x[i]) / (2 * h);
            }


            //Граничный условия
            a[n - 2][0] = 1;
            a[n - 1][n - 1] = 1;
            gauss();
            for (i = 0;i < n;i++) {
                if (i == 0 || i == n - 1 ) {
                    as = 0;
                }
                else
                {
                    as = abs(y[i] - s[i]);
                }
                m[i] = ( 1 / (c1 - c2)) * ( ((2.828427 - c2) * y [i]) +( y [i] * (c1 - 2.828427)));
                o[i] = 0;
                cout << "x(" << i << ")= " << x[i] << "     " << "y(" << i << ")=" << y[i] <<  "     " << "u(x) =" << s[i] <<  "     " << "e1 =" << as <<  "     " << "shoot(x) =" << m[i] << "     " << "e3 =" << o[i] << "     " << "e1 =" << as << endl;
            }
                //Проверка решения на граничные условия
                cout << "Проверка решения на граничные условия" << endl;
                cout << y[0] << " " << y[n - 1] << endl;
            

                



            system("pause");
        }
            void gauss()
            {
                //Прямой проход
                for (k = 0;k <= n - 2;k++)
                {
                    for (i = k + 1;i <= n - 1;i++)
                    {
                        tmp = a[i][k];
                        b[i] = b[i] - b[k] * tmp / a[k][k];
                        for (j = 0;j <= n - 1;j++)
                            a[i][j] = a[i][j] - a[k][j] * tmp / a[k][k];
                    }
                }
                //Обратный проход
                y[n - 1] = b[n - 1] / a[n - 1][n - 1];
                for (i = n - 2;i >= 0;i = i - 1)
                {
                    y[i] = b[i];
                    for (j = i + 1;j <= n - 1;j++)
                        y[i] = y[i] - a[i][j] * y[j];
                    y[i] = y[i] / a[i][i];
                }
            }

            double f(double x)
            {
                x = -2 * (pow(x + 1, 2));
                return x;
            }

            double p(double x)
            {
                x = -0.5 / (x + 1);
                return x;
            }

            double q(double x)
            {
                x = -2 * sqrt(x + 1);
                return x;
            }
        
         
