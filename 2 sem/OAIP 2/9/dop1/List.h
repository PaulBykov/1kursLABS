#pragma once
#define NULL 0

#include "fstream"

__declspec(selectany) char smr[7] = "delete";
__declspec(selectany) void* smert = smr;

struct Element                   // ������� ������ 
{
	Element* Prev;                // ��������� �� ���������� ������� 
	Element* Next;                // ��������� �� ��������� ������� 
	void* Data;                  //  ������  
	Element(Element* prev, void* data, Element* next)
	{
		Prev = prev;
		Data = data;
		Next = next;
	}
	Element* GetNext()            // �������� ���������
	{
		return Next;
	};
	Element* GetPrev()            // �������� ����������  
	{
		return Prev;
	};
};
//-----------------------------------------------------------
struct Object                     // ���� ���������� ������� 
{
	Element* Head;                 // ��������� �� ������ ������
	Object()
	{
		Head = NULL;
	};
	Element* GetFirst()            // �������� ������ ������� ������
	{
		return Head;
	};
	Element* GetLast();            // �������� ��������� ������� ������
	Element* Search(void* data);   // �����  ������ ������� �� ������ 
	bool Insert(void* data);       // �������� ������� � ������
	bool InsertEnd(void* data);    // �������� � ����� 
	bool Delete(Element* e);       // ������� �� ������ �������� 
	bool Delete(void* data);       // ������� ������ �� ������
	int CountList(Element** Head);
	void DeleteList(Element** phead, Element* plast, int k);		    // �������� ������ 
	void PrintList(void(*f)(void*));
	void PrintList(void(*f)(void*), Element*);
	bool DeleteDouble();
};
Object Create();
