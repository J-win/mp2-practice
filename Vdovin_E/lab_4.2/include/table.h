#pragma once
#include "record.h"

class table
{
protected:
	int maxnum; //������������ ����� �������
	int num; //������� ���������� �������
	int current; //����� ������� ������

	virtual int findNumberRecord(const key &k) = 0; //����� ������ ������ � ������� �� �����
	virtual void addSize() = 0; //������������� ������, ���� ��������� 70% �������
public:
	table() { maxnum = 0; num = 0; current = 0; } //����������� �� ���������
	virtual ~table() {} //����������

	bool isFull() const { return num == maxnum; } //�������� �� �������
	bool isEmpty() const { return num == 0; } //�������� �� �������

	void reset() { current = 0; } //������� � ������ ������
	void goNext() { current++; } //������� � ��������� ������
	bool isEnded() const { return current > num; } //�������� �� ����� �������

	virtual void insRecord(const key &k, const datValue &data) = 0; //���������� ����� ������, ���� ����� ���
	virtual void delRecord(const key &k) = 0; //�������� ������, ���� ����� �������
	virtual datValue* findRecord(const key &k) = 0; //����� ������ �� �����

	virtual key getKey() = 0; //��������� ����� � ������� ������
	virtual datValue getData() = 0; //��������� ������ � ������� ������
};