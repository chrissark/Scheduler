#pragma once
#include <vector>
#include <map>
#include <memory>
#include "tasks.h"
#include "PeriodicTask.h"
#include "Node.h"
#include "Schedule.h"
using std::string;
using std::multimap;
using std::vector;
using std::shared_ptr;

//Планировщик
class Scheduler {
	// набор заданий
	// при добавлении заданий по умолчанию сортируется по возрастанию уровня важности
	multimap<int, shared_ptr<Task> > set;
public:
	Scheduler() { };
	void add_task(Task* t); // добавить задание в планировщик
	Schedule* make_schedule() const; // составить расписание из набора заданий
	void print_tasks() const; // печать для отладки

};
