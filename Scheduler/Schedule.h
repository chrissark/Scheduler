#pragma once
#include <string>
#include "tasks.h"
#include "PeriodicTask.h"
#include "Node.h"
using std::string;
// План (бинарное дерево, прошитое по возрастанию ключа)
class Schedule {
public:
	Node* root;
	Schedule():
		root(nullptr) { };
	void add_node(Task *t, int time);
	void show(Node* p) const; // вывести план
	void execute_task(); //выполнить задание 

};



