#pragma once
#include <string>
using std::string;
// ������� � ������� ������
class Task {
	string id; // ��������� ������������� �������
	string text; // ����� �������
	int importance; // ������� ��������
	int deadline; // ������� ���� ����������

public:
	// �������� �������
	Task(const string& id, const string& text, int deadline, int importance)
	{
		this->id = id;
		this->text = text;
		this->importance = importance;
		this->deadline = deadline;
	}
	bool extend_deadline(int dt); // ��������� ����� ����������
	bool change_level(int lvl); //��������� ������ �������� �������
	virtual void print() const; // ������ ���������� � �������
	int get_deadline() const;
	int get_importance() const;
	virtual ~Task() {};
};
