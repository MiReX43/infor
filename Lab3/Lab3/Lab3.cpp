#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Функция f(x)
double f(double x) {
    if (x == 0.0) return INFINITY; // защита от деления на ноль
    return atan(x) - 1.0 / (3 * pow(x, 3));
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

// Метод хорд
void chords(double a, double b, double eps, double& x, double& fx, int& iterations) {
    double f1 = f(a), f2 = f(b);
    iterations = 1;
    double z, h;

    cout << "\n  Итерации метода хорд [" << a << "; " << b << "]" << endl;
    cout << "  --------------------------------------------------------------------" << endl;
    cout << "  №  |       x       |       z       |       f(x)     |        h   " << endl;
    cout << "  --------------------------------------------------------------------" << endl;

    if (f1 * f2 >= 0) {
        cout << "На этом интервале нет корня (нет смены знака)." << endl;
        return;
    }

    if (f1 * f2 > 0) {
        x = b;
        z = a;
    }
    else {
        x = a;
        z = b;
    }

    do {
        double fz = f(z);
        f1 = f(x);
        h = (x - z) / (f1 - fz) * f1;
        x = x - h;

        cout << setw(3) << iterations << "    "
            << setw(9) << x << "    "
            << setw(9) << z << "    "
            << setw(9) << f1 << "    "
            << setw(9) << h << endl;

        iterations++;
    } while (fabs(h) > eps);

    fx = f(x);
    cout << "  --------------------------------------------------------------------\n";
}

// Поиск интервалов и решение
void findRoots(double a, double b, double step, double eps, int method) {
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

            if (method == 1)
                dichotomy(x1, x2, eps, x, fx, iterations);
            else
                chords(x1, x2, eps, x, fx, iterations);

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
    int choice;

    cout << "Решение уравнения: arctg(x) - 1 / (3x^3) = 0" << endl;
    cout << "Введите начальное значение интервала (a): ";
    cin >> a;
    cout << "Введите конечное значение интервала (b): ";
    cin >> b;
    cout << "Введите шаг для поиска изоляции корней: ";
    cin >> step;
    cout << "Введите точность (eps): ";
    cin >> eps;

    while (1) {
        cout << "\n========== ГЛАВНОЕ МЕНЮ ==========\n";
        cout << "\nВыберите метод решения нелинейный алгебраических уравнений\n";
        cout << "1. Метод деления отрезка попалам (дихотоммм)\n";
        cout << "2. Метод хорд\n";
        cout << "3. Метод 3\n";
        cout << "4. Метод 4\n";
        cout << "5. Метод 5\n";
        cout << "6. Метод 6\n";
        cout << "7. Выход из программы \n";
        cout << "==================================\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Метод деления отрезка попалам (дихотоммм)";

            findRoots(a, b, step, eps, choice);
            break;

        case 2:
            cout << "Метод хорд";
            findRoots(a, b, step, eps, choice);
            break;
        case 3:
            cout << "Метод 3";
            break;

        case 4:
            cout << "Метод 4";
            break;
        case 5:
            cout << "Метод 5";
            break;
        case 6:
            cout << "Метод 6";
            break;
        case 7:
            cout << "Выход из программы. До свидания!\n";
            return 0;

        default:
            cout << "Ошибка: Неверный выбор! Попробуйте снова.\n";

        }

    }

    return 0;
}
