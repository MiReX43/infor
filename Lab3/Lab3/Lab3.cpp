#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Функция f(x)
double f(double x) {
    if (x == 0.0) return INFINITY; // защита от деления на ноль
    return atan(x) - 1.0 / pow(x, 3);
}

// Метод дихотомии с выводом всех итераций
void dichotomy(double a, double b, double eps, double& x, double& fx, int& iterations) {
    double f1 = f(a);
    iterations = 1;

    cout << "\n  Итерации для интервала [" << a << "; " << b << "]" << endl;
    cout << "  --------------------------------------------------------------------" << endl;
    cout << "  № |       a        |       b        |       x       |     f(x)" << endl;
    cout << "  --------------------------------------------------------------------" << endl;

    while (fabs(b - a) > eps) {
        double t = (a + b) / 2.0;
        double f2 = f(t);

        cout << setw(3) << iterations << "    "
            << setw(9) << a << "    "
            << setw(9) << b << "    "
            << setw(9) << t << "    "
            << setw(9) << f2 << endl;

        if (f1 * f2 < 0) {
            b = t;
        }
        else {
            a = t;
            f1 = f2;
        }
        iterations++;
    }

    x = (a + b) / 2.0;
    fx = f(x);

    cout << "  --------------------------------------------------------------------\n";
}

// Поиск интервалов и решение
void findRoots(double a, double b, double step, double eps) {
    cout << fixed << setprecision(10);
    double x1 = a, x2;
    bool rootFound = false;

    while (x1 < b) {
        x2 = x1 + step;

        // Исключаем область около x = 0
        if (fabs(x1) < 1e-3 || fabs(x2) < 1e-3) {
            x1 = x2;
            continue;
        }

        // Проверка на смену знака
        if (f(x1) * f(x2) < 0) {
            rootFound = true;
            double x, fx;
            int iterations;
            dichotomy(x1, x2, eps, x, fx, iterations);
            cout << "\nНайден корень на интервале: [" << x1 << "; " << x2 << "]" << endl;
            cout << "Корень: x = " << x << ", f(x) = " << fx << ", итераций: " << iterations << endl << endl;
        }

        x1 = x2;
    }

    if (!rootFound) {
        cout << "Корни не найдены на данном интервале." << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RUS");

    double a, b, step, eps;

    cout << "Решение уравнения: arctg(x) - 1 / x^3 = 0" << endl;
    cout << "Введите начальное значение интервала (a): ";
    cin >> a;
    cout << "Введите конечное значение интервала (b): ";
    cin >> b;
    cout << "Введите шаг для поиска изоляции корней: ";
    cin >> step;
    cout << "Введите точность (eps): ";
    cin >> eps;

    findRoots(a, b, step, eps);

    return 0;
}
