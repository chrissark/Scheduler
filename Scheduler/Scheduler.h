#pragma once
#include <vector>
#include <map>
#include "tasks.h"
#include "PeriodicTask.h"
#include "Node.h"
#include "Schedule.h"
using std::string;
using std::multimap;
using std::vector;

//�����������
class Scheduler {
	// ����� �������
	// ��� ���������� ������� �� ��������� ����������� �� ����������� ������ ��������
	multimap<int, Task*> set;
public:
	Scheduler() { };
	void add_task(Task* t); // �������� ������� � �����������
	Schedule make_schedule() const; // ��������� ���������� �� ������ �������
	void print_tasks() const; // ������ ��� �������

};
