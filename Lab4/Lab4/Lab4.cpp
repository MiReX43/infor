#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// ������� ��� ����������
double f(double x) {
    return (x - 0.5) / sqrt(x * x - 1);
}

// ������������� ��� ������� �������� (������� ����������������)
double F(double x) {
    return sqrt(x * x - 1) - 0.5 * log(x + sqrt(x * x - 1));
}

// ����� ����� ���������������
double leftRectangles(double a, double b, int n) {
    double h = (b - a) / n, sum = 0;
    for (int i = 0; i < n; ++i)
        sum += f(a + i * h);
    return h * sum;
}

// ����� ������ ���������������
double rightRectangles(double a, double b, int n) {
    double h = (b - a) / n, sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += f(a + i * h);
    return h * sum;
}

// ����� ������� ���������������
double middleRectangles(double a, double b, int n) {
    double h = (b - a) / n, sum = 0;
    for (int i = 0; i < n; ++i)
        sum += f(a + h * (i + 0.5));
    return h * sum;
}

// ����� ��������
double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2.0;
    for (int i = 1; i < n; ++i)
        sum += f(a + i * h);
    return h * sum;
}

// ����� ��������
double simpson(double a, double b, int n) {
    if (n % 2 != 0) n++; // ������� ������� ������ n
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i += 2)
        sum += 4 * f(a + i * h);
    for (int i = 2; i < n - 1; i += 2)
        sum += 2 * f(a + i * h);
    return h * sum / 3;
}

// ���������� �����������
double absoluteError(double exact, double approx) {
    return fabs(exact - approx);
}

// ������������� ������ ��������
void runForN(double a, double b, int n, double exact) {
    cout << "\nn = " << n << endl;
    cout << fixed << setprecision(4);

    double left = leftRectangles(a, b, n);
    cout << "����� ��������������:\n  ��������: " << left
        << ", �����������: " << absoluteError(exact, left) << endl;

    double right = rightRectangles(a, b, n);
    cout << "������ ��������������:\n  ��������: " << right
        << ", �����������: " << absoluteError(exact, right) << endl;

    double middle = middleRectangles(a, b, n);
    cout << "������� ��������������:\n  ��������: " << middle
        << ", �����������: " << absoluteError(exact, middle) << endl;

    double trap = trapezoidal(a, b, n);
    cout << "����� ��������:\n  ��������: " << trap
        << ", �����������: " << absoluteError(exact, trap) << endl;

    double simp = simpson(a, b, n);
    cout << "����� ��������:\n  ��������: " << simp
        << ", �����������: " << absoluteError(exact, simp) << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
    double a = 1.2;
    double b = 2.0;

    double exact = F(b) - F(a);

    cout << fixed << setprecision(10);
    cout << "������ �������� ��������� (�� ���������������): " << exact << endl;

    runForN(a, b, 4, exact);
    runForN(a, b, 40, exact);
    runForN(a, b, 140, exact);

    return 0;
}
