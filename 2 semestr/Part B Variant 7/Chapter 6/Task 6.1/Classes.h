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

class Instance
{
protected:
	char* name;
	int year_start;
	int year_end;
};

class ArtObject
{
protected:
	char* what_is_puctured;
	int year_of_creation;
};

class Coins : public Instance
{
	double value;
};

class Edged_Weapon : public Instance
{
};

class Photos : public ArtObject
{
};

class Paintings : public ArtObject
{
	char* author;
};

class Statuettes : public ArtObject
{
	char* author;
};