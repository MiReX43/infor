#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// ������� f(x)
double f(double x) {
    if (x == 0.0) return INFINITY; // ������ �� ������� �� ����
    return atan(x) - 1.0 / (3 * pow(x, 3));
}

// ����������� ������� f(x)
double df(double x) {
    if (x == 0.0) return INFINITY;
    return 1.0 / (1 + x * x) + 1.0 / pow(x, 4);
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

// ����� ����
void chords(double a, double b, double eps, double& x, double& fx, int& iterations) {
    double f1 = f(a), f2 = f(b);
    iterations = 1;
    double z, h;

    cout << "\n  �������� ������ ���� [" << a << "; " << b << "]" << endl;
    cout << "  --------------------------------------------------------------------" << endl;
    cout << "  �  |       x       |       z       |       f(x)     |        h   " << endl;
    cout << "  --------------------------------------------------------------------" << endl;

    if (f1 * f2 >= 0) {
        cout << "�� ���� ��������� ��� ����� (��� ����� �����)." << endl;
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

// ����� ������� (����� �����������)
void newtonMethod(double a, double b, double eps, double& x, double& fx, int& iterations) {
    iterations = 1;
    x = (a + b) / 2.0; // ��������� �����������

    cout << "\n  �������� ������ ������� (�����������) [" << a << "; " << b << "]" << endl;
    cout << "  --------------------------------------------------------------------" << endl;
    cout << "  �  |       x      |      f(x)     |      f'(x)     |    delta x" << endl;
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

// ����� ���������� � �������
void findRoots(double a, double b, double step, double eps, int method) {
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

            if (method == 1)
                dichotomy(x1, x2, eps, x, fx, iterations);
            else if (method == 2)
                chords(x1, x2, eps, x, fx, iterations);
            else if (method == 3)
                newtonMethod(x1, x2, eps, x, fx, iterations);



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
    int choice;

    cout << "������� ���������: arctg(x) - 1 / (3x^3) = 0" << endl;
    cout << "������� ��������� �������� ��������� (a): ";
    cin >> a;
    cout << "������� �������� �������� ��������� (b): ";
    cin >> b;
    cout << "������� ��� ��� ������ �������� ������: ";
    cin >> step;
    cout << "������� �������� (eps): ";
    cin >> eps;

    while (1) {
        cout << "\n========== ������� ���� ==========\n";
        cout << "\n�������� ����� ������� ���������� �������������� ���������\n";
        cout << "1. ����� ������� ������� ������� (���������)\n";
        cout << "2. ����� ����\n";
        cout << "3. ����� ����������� (����� �������)\n";
        cout << "4. ����� ���������������� ����������� (����� ������� ��������)\n";
        cout << "5. ����� Ce�����\n";
        cout << "6. ��������������� ����� ���� � �����������\n";
        cout << "7. ����� �� ��������� \n";
        cout << "\n==================================\n";
        cout << "�������� ��������: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\n����� ������� ������� ������� (���������)\n";

            findRoots(a, b, step, eps, choice);
            break;

        case 2:
            cout << "\n����� ����\n";
            findRoots(a, b, step, eps, choice);
            break;
        case 3:
            cout << "\n����� ����������� (����� �������)\n";
            findRoots(a, b, step, eps, choice);
            break;
        case 4:
            cout << "\n����� ���������������� ����������� (����� ������� ��������)\n";
            break;
        case 5:
            cout << "����� �������";
            break;
        case 6:
            cout << "��������������� ����� ���� � �����������";
            break;
        case 7:
            cout << "����� �� ���������. �� ��������!\n";
            return 0;

        default:
            cout << "������: �������� �����! ���������� �����.\n";

        }

    }

    return 0;
}
