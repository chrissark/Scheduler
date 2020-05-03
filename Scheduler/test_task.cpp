#include <cassert>
#include <vector>
#include "tasks.h"
#include "PeriodicTask.h"
#include "Schedule.h"
#include "Scheduler.h"


#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


using namespace std;


void test_task()
{
	Task t("job1", "Run prog1.exe", 2, 1);
	Task m = Task("job2", "Run prog2.exe", 2, 30);
	PeriodicTask d("job3", "Disc defragmentation", 3, 1, 2);
	assert(t.change_level(35) == true); // изменили уровень важности 
	int tmp = t.get_importance();
	assert(tmp == 35);
	assert(t.change_level(-100) == false); // изменили с ошибкой
	tmp = t.get_importance();
	assert(tmp == 35);
	assert(m.extend_deadline(40) == true); // продлили крайний срок выполнения
	tmp = m.get_deadline();
	assert(tmp == 42);
	assert(m.extend_deadline(-5) == false); // продлили с ошибкой
	tmp = m.get_deadline();
	assert(tmp == 42);
	assert(d.get_deadline() == 3);
	d.skip_task(); // пропуск периодического задания
	assert(d.get_deadline() == 5);

}

void test_scheduler()
{
	Scheduler S = Scheduler();
	S.add_task(new Task("job1", "Run prog1.exe", 1, 2));
	S.add_task(new Task("job2", "Run prog2.exe", 2, 1));
	S.add_task(new PeriodicTask("job3", "prog3", 11, 1, 2));
	S.add_task(new PeriodicTask("job5", "prog5", 2, 1, 5));
	S.add_task(new Task("job6", "prog6", 6, 6));
	Schedule* Plan = S.make_schedule();
	Plan->print_Schedule();
	Plan->execute_task();
	Plan->execute_task();
	Plan->execute_task();
	Plan->execute_task();
	Plan->execute_task();
	Plan->execute_task();
	Plan->execute_task();
	Plan->print_Schedule();
	delete Plan;
}

int main()
{
	//test_task();
	test_scheduler();
	_CrtDumpMemoryLeaks();
	return 0;
}