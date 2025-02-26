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
    //Ex(�)

    double number;
    cout << "������� ������������ �����: ";
    cin >> number;

    // ���������� ���������� �����������
    double absoluteError = pow(10, floor(log10(number) - 1)) / 2;

    // ���������� ������������� �����������
    double relativeError = absoluteError / number;

    // ����� �����������
    cout << "������������ �����: " << number << endl;
    cout << "���������� ���������� �����������: " << absoluteError << endl;
    cout << "���������� ������������� �����������: " << relativeError << endl;

    return 0;

    //Ex1(�)

    double value, reletive_error;

    //���� ������
    cout << "������� �����: ";
    cin >> value;
    cout << "������� ������������� ����������� (%) : ";
    cin >> reletive_error;

    //���������� �����
    double rounded_value = round(value, reletive_error);

    //���������� ���������� �����������
    double absolute_error = abs(value - rounded_value);

    //����� �����������
    cout << fixed << setprecision(6);
    cout << "����������� �����: " << rounded_value << endl;
    cout << "���������� �����������: " << absolute_error << endl;


    //Ex1(a)
    double exact1, exact2, approx1, approx2;

    // ���� ������
    cout << "������� ������ �������� ������� ���������: ";
    cin >> exact1;
    cout << "������� ����������� �������� ������� ���������: ";
    cin >> approx1;
    cout << "������� ������ �������� ������� ���������: ";
    cin >> exact2;
    cout << "������� ����������� �������� ������� ���������: ";
    cin >> approx2;

    // ���������� ������������
    double abs_error1 = exact1 - approx1;
    double abs_error2 = exact2 - approx2;
    double rel_error1 = (abs_error1 / exact1) * 100;
    double rel_error2 = (abs_error2 / exact2) * 100;

    // ����� �����������
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

    return 0;
}
