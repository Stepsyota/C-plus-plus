#pragma once

#include <iostream>

using namespace std;

//1. ������
//� ������������ (������)
//� ������� (����� ���� ��� �����, ��� � ������ �� ������)
//� ���� ������������� (�������� ��� � ��� ������������� ����)
// 
//2. �������� ������
//� ������������ (������)
//� ��������������� ��������� (�������� ��� � ��� ������������� ����)
// 
//3. �������
//� ��� ���������� (������)
//� ����� (������)
//� ����� �������� (���)
// 
//4. ���������
//� ��� ���������� (������)
//� ����� (������)
//� ����� �������� (���)
// 
//5. ����������
//� ��� ���������� (������)
//� ����� �������� (���)


class Coins
{
protected:
	char* designation;
private:
	double denomination;
	unsigned int start_of_use;
	unsigned int end_of_use;
};

class Edged_Weapon : public Coins
{
private:
	unsigned int start_dating;
	unsigned int end_dating;
};

class Photos
{
protected:
	char* what_is_pictured;
	unsigned int creation_time;
};

class Paintings : public Photos
{
protected:
	char* author;
};

class Statuettes : public Paintings
{

};