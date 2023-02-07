#pragma once
struct TRAIN
{
	int num;
	std::string destination;
	std::string number;
	std::string time;
	TRAIN* next;
};
struct ListTRAIN
{
	TRAIN* head;
	TRAIN* end;
	int size;
};
void ClearList(ListTRAIN*& list);
void AddList(ListTRAIN*& list, TRAIN*& yacheeka);
void Show(ListTRAIN* list);
void Delete(ListTRAIN*& list, int num);
void Delete(ListTRAIN*& list, TRAIN* yacheeka);
TRAIN* SbN(ListTRAIN*& list, std::string number);
TRAIN* SbD(ListTRAIN*& list, std::string destination);
TRAIN* SbT(ListTRAIN*& list, std::string time);
void Search_by_ALL(ListTRAIN*& list, std::string number);