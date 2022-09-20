#pragma once /* ������ �� �������� ����������� ������������� ����� */

using namespace std;
// ��������� ������ (��������� ��� ������)
class Tabulator
{
public:
    Tabulator(float, float, int); // ����������� ������ Tabulator
    ~Tabulator() {};               //����������

    bool set_interval_of_tabulation(float, float); // ��������� ��������� �������������
    void get_interval_of_tabulation();             // ��������� ��������� �������������

    bool set_number_of_tabulation(int); // ��������� ���-�� ����� �������������
    void get_number_of_tabulation();    // ��������� ���-�� ����� �������������

    void tabulate_the_function(); //������������� ������� � ����������� �����������
    bool linearly_interpolate_and_compare(float); // �������� ���������������� � ����������� �� ��������� �������� �������

private:
    float interval_of_tabulation_a; // ������ ��������� �������������
    float interval_of_tabulation_b; // ����� ��������� �������������
    float number_of_tabulation_n;   // ���-�� ����� �������������
};
//� h ����� ��������� ����� ������ ������� ����� ���� �����. � ��������� ��������� ����� �������� ����� ���� ��� � ������. 