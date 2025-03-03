#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

    setlocale(LC_ALL,"RUS");


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


    //Ex1(�)

        // �������� ������
        double num;
        double delta_percent;

        cout << "������� �����: ";
        cin >> num;
        cout << "������� ������������� ����������� (%): ";
        cin >> delta_percent;
    

        // ������ �����������
        double delta = (delta_percent / 100) * num;

        // ���������� ����� �� ������ �������� (��� ����� ����� �������)
        double rounded_number = round(num * 1000) / 1000;

        // ����� ����������
        cout << fixed << setprecision(4);
        cout << "�������� �����: " << num << endl;
        cout << "�����������: " << delta << endl;
        cout << "����������� �����: " << fixed << setprecision(3) << rounded_number << endl;
        cout << "���������� �����������: " << delta << endl;


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

    
    

    

}
