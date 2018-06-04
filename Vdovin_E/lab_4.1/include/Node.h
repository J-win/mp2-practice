#pragma once

#include <iostream>
#include <string>
using namespace std;

template <class valtype>
class node
{
public:
	valtype data; //������
	node<valtype> *next; //��������� �� ����. �������
	node() { next = NULL; } //����������� �� ���������
	~node() {} //����������
	node(const valtype &d); //����������� �� ������
	node(const node<valtype> &nod); //����������� �����������
	node(const valtype &d, const node<valtype> *n); //����������� �� ������ � ��������� ����. ��������
	const node<valtype>& operator=(const node<valtype> &nod); //�������� ������������
	bool operator==(const node<valtype> &n) const; //�������� ��������� �����
	bool operator!=(const node<valtype> &n) const; //�������� ��������� �� �����
};

template<class valtype>
inline node<valtype>::node(const node<valtype>& nod)
{
	data = nod.data;
	next = nod.next;
}

template<class valtype>
inline node<valtype>::node(const valtype & d)
{
	data = d;
	next = NULL;
}

template<class valtype>
inline node<valtype>::node(const valtype & d, const node<valtype> * n)
{
	data = d;
	next = n;
}

template<class valtype>
inline const node<valtype>& node<valtype>::operator=(const node<valtype>& nod)
{
	data = nod.data;
	next = nod.next;
	return *this;
}

template<class valtype>
inline bool node<valtype>::operator==(const node<valtype>& n) const
{
	return (data == n.data);
}

template<class valtype>
inline bool node<valtype>::operator!=(const node<valtype>& n) const
{
	return !(*this == n);
}
