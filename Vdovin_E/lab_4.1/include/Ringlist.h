#pragma once

#include "Node.h"

template <class valtype>
class ringlist
{
   node<valtype> *head; //��������� �� ������ ������
   node<valtype> *tail; //��������� �� ��������� ������� ������
   node<valtype> *now; //��������� �� ������� ������� ������
public:
   ringlist(); //����������� �� ���������
   ringlist(const ringlist<valtype> &l); //����������� �����������
   ~ringlist(); //����������
   void gotohead(); //������� ������� ���������� �������
   void gotonext(); //������� ������� ���������� ���������
   bool nowhead() const; //�������� �� ����� ������
   void cleanlist(); //�������� ������
   void elemdelete(const node<valtype>* n); //�������� �������� �� ���������
   void elemdelete(const valtype &d); //�������� �������� �� ������
   void insert_to_tail(const valtype &d); //������� � �����
   void insertup(const valtype &d); //������� � ������������� ������
   bool operator==(const ringlist<valtype> &l) const; //�������� ��������� �����
   bool operator!=(const ringlist<valtype> &l) const; //�������� ��������� �� �����
   valtype& getnowdata(); //��������� ������ � ������� ��������
   node<valtype>* search(const valtype &d); //����� �������� �� ������
   const ringlist<valtype>& operator=(const ringlist<valtype> &l); //�������� ������������
   friend ostream & operator<<(ostream &out, const ringlist<valtype> &l) //�������� ������
   {
	   node<valtype>* t = l.head->next;
	   if (t == l.head)
		   out << "0";
	   while (t != l.head)
	   {
		   out << t->data << " ";
		   t = t->next;
	   }
	   return out;
   }
};

template<class valtype>
inline ringlist<valtype>::ringlist()
{
	head = new node<valtype>();
	tail = head;
	head->next = head;
}

template<class valtype>
inline ringlist<valtype>::ringlist(const ringlist<valtype>& l)
{
	head = new node<valtype>();
	node<valtype>* t = head;
	node<valtype>* tt = l.head->next;
	while (tt != l.head)
	{
		t->next = new node<valtype>(tt->data);
		tail = t->next;
		t = t->next;
		tt = tt->next;
	}
	tail->next = head;
}

template<class valtype>
inline ringlist<valtype>::~ringlist()
{
	cleanlist();
	delete head;
}

template<class valtype>
inline void ringlist<valtype>::gotohead()
{
	now = head;
}

template<class valtype>
inline void ringlist<valtype>::gotonext()
{
	now = now->next;
}

template<class valtype>
inline bool ringlist<valtype>::nowhead() const
{
	return (now == head);
}

template<class valtype>
inline void ringlist<valtype>::cleanlist()
{
	node<valtype>* t = head->next;
	while (t != head)
	{
		node<valtype>* tt = t->next;
		delete t;
		t = tt;
	}
	head->next = head;
	tail = head;
}

template<class valtype>
inline void ringlist<valtype>::elemdelete(const node<valtype>* n)
{
	node<valtype>* t = head;
	while (t->next != n)
		t = t->next;
	t->next = n->next;
	delete n;
}

template<class valtype>
inline void ringlist<valtype>::elemdelete(const valtype & d)
{
	node<valtype>* t = head;
	while (t->next->data != d)
		t = t->next;
	node<valtype>* n = t->next;
	t->next = t->next->next;
	delete n;
}

template<class valtype>
inline void ringlist<valtype>::insert_to_tail(const valtype & d)
{
	node<valtype>* t = new node<valtype>(d);
	tail->next = t;
	tail = t;
	tail->next = head;
}

template<class valtype>
inline void ringlist<valtype>::insertup(const valtype & d)
{
	node<valtype>* t = head->next;
	node<valtype>* tt = head;
	while ((t != head) && (t->data > d))
	{
		tt = t;
		t = t->next;
	}
	node<valtype>* ttt = new node<valtype>(d);
	ttt->next = t;
	tt->next = ttt;
	if (t == head)
		tail = ttt;
}

template<class valtype>
inline bool ringlist<valtype>::operator==(const ringlist<valtype>& l) const
{
	if (this != &l)
	{
		bool f = true;
		node<valtype>* t = head->next;
		node<valtype>* tt = l.head->next;
		while ((t != head) && (tt != head) && (f))
		{
			if (t->data != tt->data)
				f = false;
			t = t->next;
			tt = tt->next;
		}
		if (f)
		{
			if ((t != head) || (tt != l.head))
				f = false;
		}
		return f;
	}
	else
		return true;
}

template<class valtype>
inline bool ringlist<valtype>::operator!=(const ringlist<valtype>& l) const
{
	return !(*this == l);
}

template<class valtype>
inline valtype & ringlist<valtype>::getnowdata()
{
	return now->data;
}

template<class valtype>
inline node<valtype>* ringlist<valtype>::search(const valtype & d)
{
	node<valtype>* t = head->next;
	while ((t != head) && (t->data != d))
		t = t->next;
	if (t != head)
		return t;
	else
		return NULL;
}

template<class valtype>
inline const ringlist<valtype>& ringlist<valtype>::operator=(const ringlist<valtype>& l)
{
	cleanlist();
	head = new node<valtype>();
	node<valtype>* t = head;
	node<valtype>* tt = l.head->next;
	tail = head;
	while (tt != l.head)
	{
		t->next = new node<valtype>(tt->data);
		tail = t->next;
		t = t->next;
		tt = tt->next;
	}
	tail->next = head;
	return *this;
}