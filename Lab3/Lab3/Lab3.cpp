#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// ������� f(x)
double f(double x) {
    if (x == 0.0) return INFINITY; // ������ �� ������� �� ����
    return atan(x) - 1.0 / pow(x, 3);
}

// ����� ��������� � ������� ���� ��������
void dichotomy(double a, double b, double eps, double& x, double& fx, int& iterations) {
    double f1 = f(a);
    iterations = 1;

    cout << "\n  �������� ��� ��������� [" << a << "; " << b << "]" << endl;
    cout << "  --------------------------------------------------------------------" << endl;
    cout << "  � |       a        |       b        |       x       |     f(x)" << endl;
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

// ����� ���������� � �������
void findRoots(double a, double b, double step, double eps) {
    cout << fixed << setprecision(10);
    double x1 = a, x2;
    bool rootFound = false;

    while (x1 < b) {
        x2 = x1 + step;

        // ��������� ������� ����� x = 0
        if (fabs(x1) < 1e-3 || fabs(x2) < 1e-3) {
            x1 = x2;
            continue;
        }

        // �������� �� ����� �����
        if (f(x1) * f(x2) < 0) {
            rootFound = true;
            double x, fx;
            int iterations;
            dichotomy(x1, x2, eps, x, fx, iterations);
            cout << "\n������ ������ �� ���������: [" << x1 << "; " << x2 << "]" << endl;
            cout << "������: x = " << x << ", f(x) = " << fx << ", ��������: " << iterations << endl << endl;
        }

        x1 = x2;
    }

    if (!rootFound) {
        cout << "����� �� ������� �� ������ ���������." << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RUS");

    double a, b, step, eps;

    cout << "������� ���������: arctg(x) - 1 / x^3 = 0" << endl;
    cout << "������� ��������� �������� ��������� (a): ";
    cin >> a;
    cout << "������� �������� �������� ��������� (b): ";
    cin >> b;
    cout << "������� ��� ��� ������ �������� ������: ";
    cin >> step;
    cout << "������� �������� (eps): ";
    cin >> eps;

    findRoots(a, b, step, eps);

    return 0;
}
