#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Функция под интегралом
double f(double x) {
    return (x - 0.5) / sqrt(x * x - 1);
}

// Первообразная для точного значения (формула Ньютона–Лейбница)
double F(double x) {
    return sqrt(x * x - 1) - 0.5 * log(x + sqrt(x * x - 1));
}

// Метод левых прямоугольников
double leftRectangles(double a, double b, int n) {
    double h = (b - a) / n, sum = 0;
    for (int i = 0; i < n; ++i)
        sum += f(a + i * h);
    return h * sum;
}

// Метод правых прямоугольников
double rightRectangles(double a, double b, int n) {
    double h = (b - a) / n, sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += f(a + i * h);
    return h * sum;
}

// Метод средних прямоугольников
double middleRectangles(double a, double b, int n) {
    double h = (b - a) / n, sum = 0;
    for (int i = 0; i < n; ++i)
        sum += f(a + h * (i + 0.5));
    return h * sum;
}

// Метод трапеций
double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2.0;
    for (int i = 1; i < n; ++i)
        sum += f(a + i * h);
    return h * sum;
}

// Метод Симпсона
double simpson(double a, double b, int n) {
    if (n % 2 != 0) n++; // Симпсон требует чётное n
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i += 2)
        sum += 4 * f(a + i * h);
    for (int i = 2; i < n - 1; i += 2)
        sum += 2 * f(a + i * h);
    return h * sum / 3;
}

// Абсолютная погрешность
double absoluteError(double exact, double approx) {
    return fabs(exact - approx);
}

// Универсальный запуск расчётов
void runForN(double a, double b, int n, double exact) {
    cout << "\nn = " << n << endl;
    cout << fixed << setprecision(4);

    double left = leftRectangles(a, b, n);
    cout << "Левые прямоугольники:\n  Значение: " << left
        << ", Погрешность: " << absoluteError(exact, left) << endl;

    double right = rightRectangles(a, b, n);
    cout << "Правые прямоугольники:\n  Значение: " << right
        << ", Погрешность: " << absoluteError(exact, right) << endl;

    double middle = middleRectangles(a, b, n);
    cout << "Средние прямоугольники:\n  Значение: " << middle
        << ", Погрешность: " << absoluteError(exact, middle) << endl;

    double trap = trapezoidal(a, b, n);
    cout << "Метод трапеций:\n  Значение: " << trap
        << ", Погрешность: " << absoluteError(exact, trap) << endl;

    double simp = simpson(a, b, n);
    cout << "Метод Симпсона:\n  Значение: " << simp
        << ", Погрешность: " << absoluteError(exact, simp) << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
    double a = 1.2;
    double b = 2.0;

    double exact = F(b) - F(a);

    cout << fixed << setprecision(10);
    cout << "Точное значение интеграла (по Ньютону–Лейбницу): " << exact << endl;

    runForN(a, b, 4, exact);
    runForN(a, b, 40, exact);
    runForN(a, b, 140, exact);

    return 0;
}
