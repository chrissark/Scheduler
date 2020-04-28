#include <cassert>
#include <vector>
#include "tasks.h"
#include "PeriodicTask.h"
#include "Schedule.h"
#include "Scheduler.h"

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
	Task* t1 = new Task("job1", "Run prog1.exe", 5, 2);
	Task* t2 = new Task("job2", "Run prog2.exe", 1, 1);
	PeriodicTask* t3 = new PeriodicTask("job3", "prog3", 11, 1, 2);
	Task* t4 = new Task("job4", "prog4", 12, 3);
	PeriodicTask* t5 = new PeriodicTask("job5", "prog5", 2, 1, 5);
	Task* t6 = new Task("job6", "prog6", 6, 6);
	Scheduler S = Scheduler();
	S.add_task(t1);
	S.add_task(t2);
	S.add_task(t3);
	S.add_task(t4);
	S.add_task(t5);
	assert(!t6->exec());
	assert(t5->exec());
	Schedule Plan = S.make_schedule();
	Plan.print_Schedule();
	Plan.execute_task();
	Plan.execute_task();
	Plan.execute_task();
	Plan.execute_task();
	Plan.print_Schedule();
	delete t1;
	delete t2;
	delete t3;
	delete t4;
	delete t5;
	delete t6;
}


int main()
{
	test_task();
	test_scheduler();
	return 0;
}