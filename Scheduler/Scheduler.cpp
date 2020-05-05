#include "Scheduler.h"
#include "tasks.h"
#include "PeriodicTask.h"
#include "Schedule.h"
#include <map>
#include <vector>
#include <algorithm>
using std::multimap;
using std::vector;

void Scheduler::add_task(Task* t)
{
	set.insert(std::make_pair(t->get_importance(), shared_ptr<Task>(t)));
}

void Scheduler::print_tasks() const
{
	for (auto itr = set.rbegin(); itr != set.rend(); ++itr)
	{
		itr->second->print();
	}
}

//составить план (жадный алгоритм)
Schedule* Scheduler::make_schedule() const
{
	int N = set.size();
	vector<int> d;
	vector<int> exec_time; // для хранения времен планируемых выполнений
	//multimap<int, Task*> test;
	d.resize(N);
	int k = 0;
	int d_max = 0;
	// обходим набор заданий в обратном порядке (по убыванию важности для корректной работы жадного алгоритма)
	// формируем массив сроков выполнения и ищем в нем максимальный элемент
	for (auto it = set.rbegin(); it != set.rend(); ++it, ++k)
	{
		d[k] = it->second->get_deadline();
		if (d_max < d[k])
			d_max = d[k];
    }
	exec_time.resize(d_max);
	for (int i = 0; i < N; i++)
	{
		k = d[i];
		while (k >= 1 && exec_time[k-1])
			k--;
		if (k == 0)
			continue;
		exec_time[k-1] = i + 1;
    }
	/*
	for (int i = 0; i < d_max; i++)
		printf("%i ",exec_time[i]);
	printf("\n");*/
	Schedule* S = new Schedule();
	k = 1;
	for (auto it = set.rbegin(); it != set.rend(); ++it, k++)
		for (int i = 0; i < d_max; i++)
		{
			if (exec_time[i] == k)
			{
				S->add_node((it->second).get(), i);
			}
				//test.insert(std::make_pair(i, it->second));
		}
	/*for (auto it = test.begin(); it != test.end(); ++it)
	{
		printf("Execution time: %i \n", it->first);
		it->second->print();
	}*/
	return S;
}



