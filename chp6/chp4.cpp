// chp4ex0.cpp
// �߰����, �⸻���, �׸��� ���� ���� ��� �ް�
// ������ ��� ��� ������ ����ϱ�.
#include <algorithm>
#include <ios>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using std::cin;        using std::setprecision; // �Ǽ� ���� ���� ����
using std::cout; using std::string;
using std::endl; using std::streamsize;
using std::sort; using std::vector;
using std::domain_error; using std::istream;

// �߰����� ����, �⸻���� ����, ���� ���� ��������
// �л��� ���� ������ ����
double grade(double mt, double ft, double hw) {
    return 0.2 * mt + 0.4 * ft + 0.4 * hw;
}

// vector<double>�� �߾Ӱ��� ����.
// �Լ��� ȣ���ϸ� �μ��� ������ ���͸� ��°�� ����
double median(vector<double> vec) {
    // ���� ������ �Է� ������ Ȯ��
    typedef vector<double>::size_type vec_sz;
    vec_sz size = vec.size();
    if (size == 0) {
        throw domain_error("Median of empty vector");
    }

    // ������ ����
    sort(vec.begin(), vec.end());

    // ���� ������ �߾Ӱ��� ����
    vec_sz mid = size / 2;
    return size % 2 == 0
        ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

// �߰����� ����, �⸻���� ����, ���� ������ ���ͷ�
// �л��� ���� ������ ����.
// �� �Լ��� �μ��� �����ϱ� �ʰ� median �Լ��� �ش� �۾��� ����.
double grade(double mt, double ft, const vector<double>& hw) {
    if (hw.size() == 0)
        throw domain_error("No homework!");

    return grade(mt, ft, median(hw));
}

// �Է� ��Ʈ������ ���� ������ �о vector<double>�� ����.
istream& read_hw(istream& in, vector<double>& hw) {
    if (in) {
        // ���� ������ ����
        hw.clear();

        // �Է��� ���� ����
        double x; // cin���� ����ϱ� 

        // �Һ���: ���ݱ��� count�� ������ �Է¹޾�����
        // �Է¹��� ������ ���� sum
        while (in >> x) {
            hw.push_back(x);
        }

        // ���� �л��� ���� �Է� �۾��� ����� ��Ʈ���� ����
        in.clear();

        return in;
    }
}

int main() {
    // �л��� �̸��� ���� �Է¹ޱ�
    cout << "Your name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    // �߰����� �⸻��� ������ ���� �Է¹ޱ�
    cout << "Midterm & Final scores: ";
    double midterm, final; // double = �ּ� 10�ڸ�����, ���� 15�ڸ�����
    cin >> midterm >> final;

    // ���� ������ ����
    cout << "Enter all homework grades "
        "followed by EOF: "; // End-Of-File

    vector<double> homework;

    // ���� ������ ����
    read_hw(cin, homework);

    // ���� ������ ����� ����
    try {
        double final_grade = grade(midterm, final, homework);
        // ����� ���
        streamsize prec = cout.precision(); // ���� cout precision
        cout << "Final grade: " << setprecision(3)
            << final_grade << setprecision(prec) << endl;
    }
    catch (domain_error) {
        cout << endl << "No grades entered. Try again." << endl;
        return 1;
    }

    return 0;
} // main ��
