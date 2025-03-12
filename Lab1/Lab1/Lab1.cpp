#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

int zero(double num) {
    stringstream ss;
    ss << fixed << setprecision(15) << num;
    string buf = ss.str();

    size_t pointPos = buf.find('.');
    if (pointPos == string::npos) {
        return 0;
    }

    int count = 0;
    for (size_t i = pointPos + 1; i < buf.length() && buf[i] == '0'; ++i) {
        count++;
    }
    return count;
}

double roundToPrecision(double num, int n) {
    double factor = pow(10.0, n);
    return std::round(num * factor) / factor;
}

int main() {

    setlocale(LC_ALL, "RUS");

    //Ex1(�)

    // �������� ������
    double num;
    double delta;

    cout << "������� �����: ";
    cin >> num;
    cout << "������� ����������� (%): ";
    cin >> delta;

    // ���������� ����� �� ������ ��������
    double rounded_num = roundToPrecision(num, zero(delta / 100));

    // ������ ���������� �����������
    double res = num - rounded_num;

    // ����� ����������
    cout << "����������� �����: " << rounded_num << endl;
    cout << "���������� �����������: " << res << endl;

    return 0;


    //Ex1(a)
    double a, b, c;
    double exact1, exact2, approx1, approx2;

    // ���� �������� �������������
    cout << "������� a/b: ";
    cin >> a >> b;
    exact1 = a / b;
    cout << "������� ����������� �������� ��� a/b: ";
    cin >> approx1;
    cout << "������� c ��� sqrt(c): ";
    cin >> c;
    exact2 = sqrt(c);
    cout << "������� ����������� �������� ��� sqrt(c): ";
    cin >> approx2;

    // ���������� ���������� � ������������� ������������
    double abs_error1 = fabs(exact1 - approx1);
    double abs_error2 = fabs(exact2 - approx2);
    double rel_error1 = (abs_error1 / exact1) * 100;
    double rel_error2 = (abs_error2 / exact2) * 100;

    // ����� �������� � ������
    cout << fixed << setprecision(10);
    cout << "\n������ ��������:\n";
    cout << "��������� 1 = " << exact1 << "\n";
    cout << "��������� 2 = " << exact2 << "\n";

    cout << "���������� �����������:\n";
    cout << abs_error1 << "\n";
    cout << abs_error2 << "\n";

    cout << "������������� ����������� (%):\n";
    cout << rel_error1 << " %\n";
    cout << rel_error2 << " %\n";

    // ����������� ����� ������� ���������
    if (rel_error1 < rel_error2) {
        cout << "��������� 1 ����� ������.\n";
    }
    else {
        cout << "��������� 2 ����� ������.\n";
    }



    //Ex(�)

    double number;
    cout << "������� ������������ �����: ";
    cin >> number;

    // ���������� ���������� �����������
    double absoluteError = pow(10, floor(log10(number) - 2)) / 2;

    // ���������� ������������� �����������
    double relativeError = (absoluteError / number) * 100;

    // ����� �����������
    cout << "������������ �����: " << number << endl;
    cout << "���������� ���������� �����������: " << absoluteError << endl;
    cout << "���������� ������������� �����������: " << setprecision(3) << relativeError << "%" << endl;

    return 0;

}
