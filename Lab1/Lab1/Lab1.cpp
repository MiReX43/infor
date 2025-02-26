#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double round(double value, double relative_error) {
    int significant_digits = ceil(-log10(relative_error / 100.0)); 
    return round(value * pow(10, significant_digits)) / pow(10, significant_digits);
}

int main() {

    setlocale(LC_ALL,"RUS");
    //Ex(в)

    double number;
    cout << "Введите приближенное число: ";
    cin >> number;

    // Предельная абсолютная погрешность
    double absoluteError = pow(10, floor(log10(number) - 1)) / 2;

    // Предельная относительная погрешность
    double relativeError = absoluteError / number;

    // Вывод результатов
    cout << "Приближенное число: " << number << endl;
    cout << "Предельная абсолютная погрешность: " << absoluteError << endl;
    cout << "Предельная относительная погрешность: " << relativeError << endl;

    return 0;

    //Ex1(б)

    double value, reletive_error;

    //Ввод данных
    cout << "Введите число: ";
    cin >> value;
    cout << "Введите относительную погрешность (%) : ";
    cin >> reletive_error;

    //Округление числа
    double rounded_value = round(value, reletive_error);

    //Вычисление абсолютной погрешности
    double absolute_error = abs(value - rounded_value);

    //Вывод результатов
    cout << fixed << setprecision(6);
    cout << "Округленное число: " << rounded_value << endl;
    cout << "Абсолютная погрешность: " << absolute_error << endl;


    //Ex1(a)
    double exact1, exact2, approx1, approx2;

    // Ввод данных
    cout << "Введите точное значение первого выражения: ";
    cin >> exact1;
    cout << "Введите округленное значение первого выражения: ";
    cin >> approx1;
    cout << "Введите точное значение второго выражения: ";
    cin >> exact2;
    cout << "Введите округленное значение второго выражения: ";
    cin >> approx2;

    // Вычисление погрешностей
    double abs_error1 = exact1 - approx1;
    double abs_error2 = exact2 - approx2;
    double rel_error1 = (abs_error1 / exact1) * 100;
    double rel_error2 = (abs_error2 / exact2) * 100;

    // Вывод результатов
    cout << fixed << setprecision(10);
    cout << "\nТочные значения:\n";
    cout << "Выражение 1 = " << exact1 << "\n";
    cout << "Выражение 2 = " << exact2 << "\n";

    cout << "Абсолютные погрешности:\n";
    cout << abs_error1 << "\n";
    cout << abs_error2 << "\n";

    cout << "Относительные погрешности (%):\n";
    cout << rel_error1 << " %\n";
    cout << rel_error2 << " %\n";

    // Определение более точного выражения
    if (rel_error1 < rel_error2) {
        cout << "Выражение 1 более точное.\n";
    }
    else {
        cout << "Выражение 2 более точное.\n";
    }

    return 0;
}
