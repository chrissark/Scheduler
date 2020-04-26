#include <cassert>
#include <vector>
#include "tasks.h"
#include "PeriodicTask.h"
#include "Schedule.h"
#include "Node.h"
#include "Scheduler.h"

using namespace std;


void test_task()
{
	Task t("job1", "Run prog1.exe", 2, 1);
	Task m = Task("job2", "Run prog2.exe", 2, 30);
	PeriodicTask d("job3", "Disc defragmentation", 3, 1, 2);
	d.skip_task();
	
	assert(t.change_level(35) == true); // изменили уровень важности 
	int tmp = t.get_importance();
	assert(tmp == 35);
	assert(t.change_level(-100) == false); // изменили с ошибкой
	tmp = t.get_importance();
	assert(tmp == 35);
	assert(m.extend_deadline(40) == true); // продлили крайний срок выполнения
	tmp = m.get_deadline();
	assert(tmp == 90);
	assert(m.extend_deadline(-5) == false); // продлили с ошибкой
	tmp = m.get_deadline();
	assert(tmp == 90);
}

void test_scheduler()
{
	Task t1("job1", "Run prog1.exe", 5, 2);
	Task t2 = Task("job2", "Run prog2.exe", 1, 1);
	//PeriodicTask t3("job3", "prog3", 11, 1, 2);
	Task t4("job4", "prog4", 8, 3);
	PeriodicTask t5("job5", "prog5", 2, 1, 5);
	Task t6("job6", "prog6", 4, 6);
	Task t7("job7", "prog7", 7, 9);
	Task t8("job8", "prog8", 6, 4);
	PeriodicTask t9("job9", "prog9", 6, 5, 3);
	Scheduler S = Scheduler();
	S.add_task(&t1);
	S.add_task(&t2);
	//S.add_task(&t3);
	S.add_task(&t4);
	S.add_task(&t5);
	S.add_task(&t6);
	S.add_task(&t7);
	S.add_task(&t8);
	S.add_task(&t9);
	//S.print_tasks();
	Schedule Plan = S.make_schedule();
	//Plan.show(Plan.root);
	Plan.execute_task();
	Plan.execute_task();
	//Plan.show(Plan.root);

}

void test_schedule()
{

}

int main()
{
	//test_task();
	test_scheduler();
	//test_schedule();
	return 0;
}