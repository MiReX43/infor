#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Функция для вычисления exp(-x) с заданной точностью
double taylor(double x, double eps, int& terms) {
    double sum = 1.0; // Первое слагаемое ряда (n=0)
    double term = 1.0; // Первое слагаемое (x^0 / 0!)
    terms = 1; // Считаем первое слагаемое

    int k = 1;
    while (fabs(term) > eps) {
        term *= -x / k; // Следующее слагаемое ряда
        sum += term;
        k++;
        terms++;
    }

    return sum;
}

double cube_root(double a, double eps) {
    double x_n = a / 3.0; // Начальное приближение
    double x_next;
    int iteration = 0;

    do {
        x_next = (2.0 / 3.0) * (x_n + (a / (2.0 * x_n * x_n))); // Формула
        iteration++;

        // Проверяем условие выхода
        if (fabs(x_next - x_n) < eps) break;

        x_n = x_next;
    } while (iteration < 1000); // Ограничение итераций

    cout << "Найденное значение: " << x_next << " за " << iteration << " итераций." << endl;
    return x_next;
}


// Функция для проверки первого предела
void check1Limit(double epsilon) {
    double x = 1.0;
    double result;
    int n = 0;

    while (true) {
        result = sin(x) / x;
        n++;
        if (fabs(result - 1) < epsilon) {
            break;
        }
        x /= 2; // Уменьшаем x в два раза
    }

    cout << "Для первого предела результат приближается к 1 при n = " << n
        << " и x = " << x << ", значение: " << result << endl;
}

// Функция для проверки второго предела
void check2Limit(double epsilon) {
    double e = exp(1); // Теоретическое значение e
    double result;
    int n = 1;

    while (true) {
        result = pow(1 + 1.0 / n, n);
        if (fabs(result - e) < epsilon) {
            break;
        }
        n++;
    }

    cout << "Для второго предела результат приближается к e при n = " << n
        << ", значение: " << result << endl;
}

int main() {
    setlocale(LC_ALL, "RUS");

    //Ex5

    double epsil;

    cout << "Введите погрешность эпсилон: ";
    cin >> epsil;

    // Проверка первого предела
    check1Limit(epsil);

    // Проверка второго предела
    check2Limit(epsil);

    return 0;

    //Ex4

    int num;
    cout << "Введите натуральное число n: ";
    cin >> num;

    // Инициализация значений для a_1 и b_1
    double a_prev = 1, b_prev = 1;
    double sum = a_prev * b_prev; // Начальная сумма для a_1 * b_1

    for (int k = 2; k <= num; ++k) {
        // Вычисляем a_k и b_k по формулам
        double a_k = 0.5 * (sqrt(b_prev) + 0.5 * a_prev);
        double b_k = 2 * a_prev * a_prev + b_prev;

        // Добавляем a_k * b_k к общей сумме
        sum += a_k * b_k;

        // Обновляем a_prev и b_prev для следующей итерации
        a_prev = a_k;
        b_prev = b_k;
    }

    // Выводим итоговую сумму
    cout << "Сумма: " << sum << endl;

    return 0;

    //Ex3

    int n;
    cout << "Введите натуральное число n: ";
    cin >> n;

    // Инициализация переменной для хранения минимального значения
    double min_value = INFINITY;

    for (int k = 1; k <= n; ++k) {
        // Вычисление значение выражения
        double value = pow(k, 3) * sin(n + static_cast<double>(k) / n);

        // Обновляем минимальное значение, если текущее меньше
        if (value < min_value) {
            min_value = value;
        }
    }

    // Выводим наименьшее значение
    cout << "Наименьшее значение выражения: " << min_value << endl;

    //Ex2
    
    double a, eps;

    // Ввод значений
    cout << "Введите число a: ";
    cin >> a;
    cout << "Введите точность eps: ";
    cin >> eps;

    // Вычисление и вывод результата
    double result = cube_root(a, eps);
    cout << "Проверка: cbrt(a) = " << cbrt(a) << endl;
  
    //Ex1

    double xn, xk, dx;

    // Ввод параметров диапазона
    cout << "Введите начальное значение x (xn): ";
    cin >> xn;
    cout << "Введите конечное значение x (xk): ";
    cin >> xk;
    cout << "Введите шаг dx: ";
    cin >> dx;

    // Установленные точности
    const double eps1 = 0.1;
    const double eps2 = 0.000001;

    // Вывод заголовка таблицы
    cout << setw(10) << "x"
        << setw(15) << "exp(-x)"
        << setw(10) << "eps1"
        << setw(15) << "f1(x)"
        << setw(10) << "terms1"
        << setw(10) << "eps2"
        << setw(15) << "f2(x)"
        << setw(10) << "terms2"
        << "\n";

    cout << string(100, '-') << "\n";


    cout << fixed << setprecision(6);
    // Цикл по значениям x
    for (double x = xn; x <= xk; x += dx) {
        int terms1 = 0, terms2 = 0;
        double exact_value = exp(-x);
        double f1 = taylor(x, eps1, terms1);
        double f2 = taylor(x, eps2, terms2);

        // Вывод строки таблицы
        cout << setw(10) << x
            << setw(15) << exact_value
            << setw(10) << eps1
            << setw(15) << f1
            << setw(10) << terms1
            << setw(10) << eps2
            << setw(15) << f2
            << setw(10) << terms2
            << "\n";
    }

    return 0;
}