#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// ������� ��� ���������� exp(-x) � �������� ���������
double taylor(double x, double eps, int& terms) {
    double sum = 1.0; // ������ ��������� ���� (n=0)
    double term = 1.0; // ������ ��������� (x^0 / 0!)
    terms = 1; // ������� ������ ���������

    int k = 1;
    while (fabs(term) > eps) {
        term *= -x / k; // ��������� ��������� ����
        sum += term;
        k++;
        terms++;
    }

    return sum;
}

double cube_root(double a, double eps) {
    double x_n = a / 3.0; // ��������� �����������
    double x_next;
    int iteration = 0;

    do {
        x_next = (2.0 / 3.0) * (x_n + (a / (2.0 * x_n * x_n))); // �������
        iteration++;

        // ��������� ������� ������
        if (fabs(x_next - x_n) < eps) break;

        x_n = x_next;
    } while (iteration < 1000); // ����������� ��������

    cout << "��������� ��������: " << x_next << " �� " << iteration << " ��������." << endl;
    return x_next;
}


// ������� ��� �������� ������� �������
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
        x /= 2; // ��������� x � ��� ����
    }

    cout << "��� ������� ������� ��������� ������������ � 1 ��� n = " << n
        << " � x = " << x << ", ��������: " << result << endl;
}

// ������� ��� �������� ������� �������
void check2Limit(double epsilon) {
    double e = exp(1); // ������������� �������� e
    double result;
    int n = 1;

    while (true) {
        result = pow(1 + 1.0 / n, n);
        if (fabs(result - e) < epsilon) {
            break;
        }
        n++;
    }

    cout << "��� ������� ������� ��������� ������������ � e ��� n = " << n
        << ", ��������: " << result << endl;
}

int main() {
    setlocale(LC_ALL, "RUS");

    //Ex5

    double epsil;

    cout << "������� ����������� �������: ";
    cin >> epsil;

    // �������� ������� �������
    check1Limit(epsil);

    // �������� ������� �������
    check2Limit(epsil);

    return 0;

    //Ex4

    int num;
    cout << "������� ����������� ����� n: ";
    cin >> num;

    // ������������� �������� ��� a_1 � b_1
    double a_prev = 1, b_prev = 1;
    double sum = a_prev * b_prev; // ��������� ����� ��� a_1 * b_1

    for (int k = 2; k <= num; ++k) {
        // ��������� a_k � b_k �� ��������
        double a_k = 0.5 * (sqrt(b_prev) + 0.5 * a_prev);
        double b_k = 2 * a_prev * a_prev + b_prev;

        // ��������� a_k * b_k � ����� �����
        sum += a_k * b_k;

        // ��������� a_prev � b_prev ��� ��������� ��������
        a_prev = a_k;
        b_prev = b_k;
    }

    // ������� �������� �����
    cout << "�����: " << sum << endl;

    return 0;

    //Ex3

    int n;
    cout << "������� ����������� ����� n: ";
    cin >> n;

    // ������������� ���������� ��� �������� ������������ ��������
    double min_value = INFINITY;

    for (int k = 1; k <= n; ++k) {
        // ���������� �������� ���������
        double value = pow(k, 3) * sin(n + static_cast<double>(k) / n);

        // ��������� ����������� ��������, ���� ������� ������
        if (value < min_value) {
            min_value = value;
        }
    }

    // ������� ���������� ��������
    cout << "���������� �������� ���������: " << min_value << endl;

    //Ex2
    
    double a, eps;

    // ���� ��������
    cout << "������� ����� a: ";
    cin >> a;
    cout << "������� �������� eps: ";
    cin >> eps;

    // ���������� � ����� ����������
    double result = cube_root(a, eps);
    cout << "��������: cbrt(a) = " << cbrt(a) << endl;
  
    //Ex1

    double xn, xk, dx;

    // ���� ���������� ���������
    cout << "������� ��������� �������� x (xn): ";
    cin >> xn;
    cout << "������� �������� �������� x (xk): ";
    cin >> xk;
    cout << "������� ��� dx: ";
    cin >> dx;

    // ������������� ��������
    const double eps1 = 0.1;
    const double eps2 = 0.000001;

    // ����� ��������� �������
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
    // ���� �� ��������� x
    for (double x = xn; x <= xk; x += dx) {
        int terms1 = 0, terms2 = 0;
        double exact_value = exp(-x);
        double f1 = taylor(x, eps1, terms1);
        double f2 = taylor(x, eps2, terms2);

        // ����� ������ �������
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