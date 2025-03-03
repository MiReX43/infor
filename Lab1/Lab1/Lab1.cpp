#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

    setlocale(LC_ALL,"RUS");


    //Ex(в)

        double number;
        cout << "Введите приближенное число: ";
        cin >> number;

        // Предельная абсолютная погрешность
        double absoluteError = pow(10, floor(log10(number) - 2)) / 2;

        // Предельная относительная погрешность
        double relativeError = (absoluteError / number) * 100;

        // Вывод результатов
        cout << "Приближенное число: " << number << endl;
        cout << "Предельная абсолютная погрешность: " << absoluteError << endl;
        cout << "Предельная относительная погрешность: " << setprecision(3) << relativeError << "%" << endl;

        return 0;


    //Ex1(б)

        // Исходные данные
        double num;
        double delta_percent;

        cout << "Введите число: ";
        cin >> num;
        cout << "Введите относительную погрешность (%): ";
        cin >> delta_percent;
    

        // Расчет погрешности
        double delta = (delta_percent / 100) * num;

        // Округление числа до нужной точности (три знака после запятой)
        double rounded_number = round(num * 1000) / 1000;

        // Вывод результата
        cout << fixed << setprecision(4);
        cout << "Исходное число: " << num << endl;
        cout << "Погрешность: " << delta << endl;
        cout << "Округленное число: " << fixed << setprecision(3) << rounded_number << endl;
        cout << "Абсолютная погрешность: " << delta << endl;


    //Ex1(a)
    double a, b, c;
    double exact1, exact2, approx1, approx2;

    // Ввод значений пользователем
    cout << "Введите a/b: ";
    cin >> a >> b;
    exact1 = a / b;
    cout << "Введите округленное значение для a/b: ";
    cin >> approx1;
    cout << "Введите c для sqrt(c): ";
    cin >> c;
    exact2 = sqrt(c);
    cout << "Введите округленное значение для sqrt(c): ";
    cin >> approx2;

    // Вычисление абсолютных и относительных погрешностей
    double abs_error1 = fabs(exact1 - approx1);
    double abs_error2 = fabs(exact2 - approx2);
    double rel_error1 = (abs_error1 / exact1) * 100;
    double rel_error2 = (abs_error2 / exact2) * 100;

    // Вывод значений и ошибок
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

    
    

    

}
