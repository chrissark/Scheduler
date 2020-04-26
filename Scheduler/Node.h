#pragma once
#include <string>
#include "tasks.h"
#include "PeriodicTask.h"
using std::string;

// ���� ��������� ������
class Node {
	friend class Schedule;
	Task* task;
	int time; // ����������� ����� ����������
	Node* left, * right;
	bool right_is_thread; // ������� ��������� ��� ��������� ��������
public:
	Node(Task* task, int time)
	{
		this->task = task;
		this->time = time;
		this->left = this->right = nullptr;
		right_is_thread = false;
	}
	void print_node() const
	{
		task->print();
		printf("Execution time: %i\n", time);
		if (this->right_is_thread)
			printf("Right is thread\n");

	}
};