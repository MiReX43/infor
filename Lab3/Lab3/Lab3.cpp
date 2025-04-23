#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


// Функция f(x)
double f(double x) {
    if (x == 0.0) return INFINITY; // защита от деления на ноль
    return atan(x) - 1.0 / (3 * pow(x, 3));
}

// Производная функции f(x)
double df(double x) {
    if (x == 0.0) return INFINITY;
    return 1.0 / (1 + x * x) + 1.0 / pow(x, 4);
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

// Метод Ньютона (метод касательных)
void newtonMethod(double a, double b, double eps, double& x, double& fx, int& iterations) {
    iterations = 1;
    x = (a + b) / 2.0; // начальное приближение

    cout << "\n  Итерации метода Ньютона (касательных) [" << a << "; " << b << "]" << endl;
    cout << "  --------------------------------------------------------------------" << endl;
    cout << "  №  |       x      |      f(x)     |      f'(x)     |    delta x" << endl;
    cout << "  --------------------------------------------------------------------" << endl;

    double h;
    do {
        fx = f(x);
        double dfx = df(x);
        h = fx / dfx;
        cout << setw(3) << iterations << "   "
            << setw(9) << x << "    "
            << setw(9) << fx << "    "
            << setw(9) << dfx << "    "
            << setw(9) << h << endl;

        x = x - h;
        iterations++;
    } while (fabs(h) > eps);

    fx = f(x);
    cout << "  ---------------------------------------------------------------------\n";
}

// Метод простых итераций (с коррекцией λ и защитой от расходимости)
void simpleIterations(double a, double b, double eps, double& x, double& fx, int& iterations) {
    const int N = 100;        // Максимум итераций
    double x0 = (a + b) / 2;

    // Оценка максимальной производной на отрезке
    double max_df = 0;
    for (double xi = a; xi <= b; xi += (b - a) / 1000) {
        if (fabs(xi) < 1e-4) continue; // избегаем деления на 0
        double dfx = 1 / (1 + xi * xi) + 3 / (xi * xi * xi * xi);
        if (dfx > max_df) max_df = dfx;
    }

    // Безопасный выбор лямды
    double lambda = 0.8 / max_df;

    iterations = 1;
    cout << "\n  Итерации метода простых итераций [" << a << "; " << b << "]" << endl;
    cout << "  -----------------------------------------------" << endl;
    cout << "  №  |      x      |      f(x)     |   delta x" << endl;
    cout << "  -----------------------------------------------" << endl;

    while (iterations <= N) {
        x = x0 - lambda * f(x0);
        fx = f(x);
        double delta = fabs(x - x0);

        cout << setw(3) << iterations << " | "
            << setw(9) << x << " | "
            << setw(9) << fx << " | "
            << setw(9) << delta << endl;

        if (delta <= eps)
            break;

        x0 = x;
        iterations++;
    }

    cout << "  -----------------------------------------------\n";
}

// Метод секущих
void secantMethod(double a, double b, double eps, double& x, double& fx, int& iterations) {
    iterations = 1;

    cout << "\n  Итерации метода секущих [" << a << "; " << b << "]" << endl;
    cout << "  -----------------------------------------------" << endl;
    cout << "  №  |      x      |     f(x)     |   |F(x)|" << endl;
    cout << "  -----------------------------------------------" << endl;

    double fa = f(a);
    double fb = f(b);

    while (true) {
        x = a - fa * (b - a) / (fb - fa);  // Формула секущих
        fx = f(x);

        cout << setw(3) << iterations << " | "
            << setw(9) << x << " | "
            << setw(9) << fx << " | "
            << setw(9) << fabs(fx) << endl;

        if (fabs(fx) <= eps)
            break;

        // Обновляем границы интервала
        if (fa * fx > 0) {
            a = x;
            fa = fx;
        }
        else {
            b = x;
            fb = fx;
        }

        iterations++;
    }

    cout << "  -----------------------------------------------\n";
}

// Комбинированный метод хорд и касательных
void combinedMethod(double a, double b, double eps, double& x, double& fx, int& iterations) {
    const int N = 100; // максимум итераций
    iterations = 0;
    double x0 = a;
    double x1 = b;

    cout << "\n  Итерации комбинированного метода [" << a << "; " << b << "]" << endl;
    cout << "  --------------------------------------------------" << endl;
    cout << "  №  |      x      |     f(x)     |   delta x" << endl;
    cout << "  --------------------------------------------------" << endl;

    do {
        double fx0 = f(x0);
        double fx1 = f(x1);
        double dfx1 = df(x1);

        double x_chord = x0 - (x1 - x0) * fx0 / (fx1 - fx0); // метод хорд
        double x_newton = x1 - fx1 / dfx1;                   // метод Ньютона

        double x_prev = x;
        x = (x_chord + x_newton) / 2.0;                      // комбинированное приближение
        fx = f(x);

        double delta = fabs(x - x1);

        iterations++;
        cout << setw(3) << iterations << " | "
            << setw(9) << x << " | "
            << setw(9) << fx << " | "
            << setw(9) << delta << endl;

        // Обновление границ для следующего шага
        if (f(x0) * fx < 0)
            x1 = x;
        else
            x0 = x;

        if (delta <= eps || iterations >= N)
            break;

    } while (true);

    cout << "  --------------------------------------------------\n";
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
            else if (method == 2)
                chords(x1, x2, eps, x, fx, iterations);
            else if (method == 3)
                newtonMethod(x1, x2, eps, x, fx, iterations);
            else if (method == 4)
                simpleIterations(x1, x2, eps, x, fx, iterations);
            else if (method == 5)
                secantMethod(x1, x2, eps, x, fx, iterations);
            else if (method == 6)
                combinedMethod(x1, x2, eps, x, fx, iterations);
          


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
        cout << "1. Метод Деления отрезка попалам (Дихотоммм)\n";
        cout << "2. Метод Хорд\n";
        cout << "3. Метод Касательных (метод Ньютона)\n";
        cout << "4. Метод Последовательных приближений (метод Простых итераций)\n";
        cout << "5. Метод Ceкущих\n";
        cout << "6. Комбинированный метод Хорд и Касательных\n";
        cout << "7. Выход из программы \n";
        cout << "\n==================================\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nМетод деления отрезка попалам (дихотоммм)\n";

            findRoots(a, b, step, eps, choice);
            break;

        case 2:
            cout << "\nМетод Хорд\n";
            findRoots(a, b, step, eps, choice);
            break;
        case 3:
            cout << "\nМетод Касательных (метод Ньютона)\n";
            findRoots(a, b, step, eps, choice);
            break;
        case 4:
            cout << "\nМетод Последовательных приближений (метод Простых итераций)\n";
            findRoots(a, b, step, eps, choice);
            break;
        case 5:
            cout << "Метод Секущих";
            findRoots(a, b, step, eps, choice);
            break;
        case 6:
            cout << "Комбинированный метод Хорд и Касательных";
            findRoots(a, b, step, eps, choice);
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
