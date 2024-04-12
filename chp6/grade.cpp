//grade.cpp
#include "grade.h"
#include "median.h"
#include "Student_info.h"
#include <list>
#include <vector>
#include <stdexcept>

// �߰����� ����, �⸻���� ����, ���� ���� ��������
// �л��� ���� ������ ����
double grade(double mt, double ft, double hw) {
	return 0.2 * mt + 0.4 * ft + 0.4 * hw;
}

// �л��� ���� ���θ� �����ϴ� ���� �Լ�
bool fgrade(const Student_info& s) {
    return grade(s) < 60;
}

//�߰����� ����, �⸻���� ����, ���� ������ ���ͷ�
// �л��� ���� ������ ����
// �� �Լ��� �μ��� �������� �ʰ� median �Լ��� �ش� �۾��� ����

double grade(double mt, double ft, vector<double> hw) {
	if (hw.size() == 0)
		throw domain_error("No homework!");

	return grade(mt, ft, median(hw));
}

double grade(const Student_info s)
{
    return grade(s.midterm, s.final, s.homework);
}

// �� ��° ����:
// �ε��� ��� �ݺ��ڸ� ��������� ������
// ���� ���ϰ� �����
list<Student_info> extract_fails(list<Student_info>& students) {
    list<Student_info> fail;
    list<Student_info>::iterator iter = students.begin();

    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter); // ������ = �ݺ����� ��
            iter = students.erase(iter); // �ݺ����� �޸� ��ġ ����
        }
        else {
            ++iter;
        }
    }

    return fail;
}