#include <iostream>
#include <string>
#include <iomanip>
#include "List.h"
using namespace std;

void ClearList(ListTRAIN*& list)
{
	if (list->head) {
		while (list->size > 0) //���� ����������� ������ �� ������ �������
		{
			TRAIN* temp = list->head;
			if (list->head->next) {
				temp = list->head->next;
			}
			delete list->head; //����������� ������ �� ��������� ��������
			list->head = temp; //����� ������ ������ �� ����� ���������� ��������
			list->size--; //���� ������� ����������. ������������ ����� ���������
		}
	}
	list->head = NULL;
}
void AddList(ListTRAIN*& list, TRAIN*& yacheeka)
{
	if (yacheeka != NULL) {
		TRAIN* newelem = yacheeka; //��������� ������ ��� ������ �������� ������
		if (!list) {
			list = new ListTRAIN;
			list->head = newelem;
			list->end = newelem;
			list->head->next = NULL;
			list->size = 1; //��� ������ ���������� �������� ����������� �����	��������� � ������
			return;
		}
		TRAIN* temp = list->head; //��������� ������ ��� ������ �������� ������
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = newelem;
		list->end = newelem;
		list->end->next = NULL;
		list->size++; //��� ������ ���������� �������� ����������� ����� ���������	� ������
	}
}
void numbering(ListTRAIN*& list) {
	TRAIN* tmp = list->head; //��������� �� ������
	int i = 1;
	while (tmp) //���� �� �������� ������� ������� �� ����� ������
	{
		tmp->num = i;
		i++;
		tmp = tmp->next; //���������, ��� ����� ��������� �������
	}
}
void Show(ListTRAIN* list)
{
	if (list->size < 1) {
		std::cout << "������ ����" << std::endl;
		return;
	}
	numbering(list);
	TRAIN* tempHead = list->head; //��������� �� ������
	while (tempHead) //���� �� �������� ������� ������� �� ����� ������
	{
		std::cout << tempHead->num<<" "<<tempHead->destination << " " << tempHead->number << " " <<//std::setw(15) <<
			tempHead->time << std::endl;
		tempHead = tempHead->next; //���������, ��� ����� ��������� �������
	}
	std::cout << "\n";
}
void Delete(ListTRAIN*& list, int num) {
	if (num > list->size || num < 1 || list->size <= 0) {
		std::cout << "������(������ ��� ���)" << std::endl;
		return;
	}
	int q = 0;
	TRAIN* tmp = list->head;
	while (q < num - 1)
	{
		tmp = tmp->next; //���������, ��� ����� ��������� �������
		q++;
	}
	std::cout << "������ " << tmp->destination << " \n"; //������� ��������� ������� ������ �� �����
	tmp->next = tmp->next->next;
	list->size--;
	cout << "�������" << endl;
}
void Delete(ListTRAIN*& list, TRAIN* yacheeka) {
	if (yacheeka != NULL) {
		TRAIN* tmp = list->head;
		if (yacheeka == list->head) {
			list->head = list->head->next;
			list->size--;
			return;
		}
		while (tmp->next != yacheeka)
		{
			tmp = tmp->next; //���������, ��� ����� ��������� �������
		}
		tmp->next = tmp->next->next;
		list->size--;
		cout << "�������" << endl;
	}
}
TRAIN* SbN(ListTRAIN*& list, std::string number) {
	TRAIN* tmp = list->head; //��������� �� ������
	while (tmp) //���� �� �������� ������� ������� �� ����� ������
	{
		if (tmp->number == number) {
			return tmp;
		}
		tmp = tmp->next; //���������, ��� ����� ��������� �������
	}
	std::cout << " �� ������� " << std::endl;
	return NULL;
}
TRAIN* SbD(ListTRAIN*& list, std::string destination) {
	TRAIN* tmp = list->head; //��������� �� ������
	while (tmp) //���� �� �������� ������� ������� �� ����� ������
	{
		if (tmp->destination == destination) {
			return tmp;
		}
		tmp = tmp->next; //���������, ��� ����� ��������� �������
	}
	std::cout << " �� ������� " << std::endl;
	return NULL;
}
TRAIN* SbT(ListTRAIN*& list, std::string time)
{
	TRAIN* tmp = list->head; //��������� �� ������
	while (tmp) //���� �� �������� ������� ������� �� ����� ������
	{
		if (tmp->time == time) {
			return tmp;
		}
		tmp = tmp->next; //���������, ��� ����� ��������� �������
	}
	std::cout << " �� ������� " << std::endl;
	return NULL;
}
void Search_by_ALL(ListTRAIN*& list, string number) {
	TRAIN* tmp = list->head; //��������� �� ������
	while (tmp) //���� �� �������� ������� ������� �� ����� ������
	{
		if (tmp->number == number) {
			std::cout << std::setw(25) << tmp->destination << std::setw(15) << tmp->number<<setw(25) <<tmp->time << std::endl;
		}
		tmp = tmp->next; //���������, ��� ����� ��������� �������
	}
}