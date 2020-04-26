#include <cstdio>
#include "tasks.h"

bool Task::extend_deadline(int dt) // продление срока исполнения
{
	if (dt > 0)
	{
		deadline += dt;
		return true;
	}
	else return false;

}

bool Task::change_level(int lvl) //изменение уровня важности задания
{
	if (lvl > 0)
	{
		importance = lvl;
		return true;
	}
	else
		return false;
}

void Task::print() const //печать информации о задании
{
    printf("%s \n %s \n deadline - %ds, importance level - %d \n", id.c_str(), text.c_str(), deadline, importance);
}

int Task::get_deadline() const
{
	return deadline;
}

int Task::get_importance() const 
{
	return importance;
}



