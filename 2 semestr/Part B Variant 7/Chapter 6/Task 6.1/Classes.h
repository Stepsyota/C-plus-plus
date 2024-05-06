#pragma once

#include <iostream>

using namespace std;

/*
1.������
� ������������ (������)
� ����� (������)
� ����� �������� (���)
� ����� �������� (������)

� ������� (����� ���� ��� �����, ��� � ������ �� ������)
� ���� ������������� (�������� ��� � ��� ������������� ����)

� ��� ���������� (������)
� �������� (������)
� ����� (�����)

2. �������� ������
� ������������ (������)
� ����� (������)
� ����� �������� (���)
� ����� �������� (������)

� ��������������� ��������� (�������� ��� � ��� ������������� ����)

� �������� (������)
� ����� (�����)
 
3. �������
� ������������ (������)
� ����� (������)
� ����� �������� (���)
� ����� �������� (������)

� ��� ���������� (������)
� ������ (������)
 
4. ���������
� ������������ (������)
� ����� (������)
� ����� �������� (���)
� ����� �������� (������)

� �������� (������)
� ��� ���������� (������)
� ������ (������)
 
5. ����������
� ������������ (������)
� ����� (������)
� ����� �������� (���)
� ����� �������� (������)

� ��� ���������� (������)
*/


class ArtObject
{
	char* author;
	int time_of_creation;
	char* place_of_creation;
	char* designation;

	ArtObject();
};
/************************************************/
class AplliedArtObject : public ArtObject
{
	char* material;
	int number_of_copies;
	int	year_of_start_of_use;
	int year_of_end_of_use;
};

class Coin : public AplliedArtObject
{
	char* what_is_depicted;
	double value;
};

class EdgedWeapon : public AplliedArtObject
{
	char* type;
	double degree_of_sharpening;
};
/************************************************/
class VisualArtObject : public ArtObject
{
	char* genre;
	char* what_is_depicted;
};

class Painting : public VisualArtObject
{
	char* type_of_paint;
	char* dimensions;
};

class Sculpture : public VisualArtObject
{
	char* material;
	char* dimensions;
};

class Photo : public VisualArtObject
{
	char* photo_format;
	bool color_photo;
};
/************************************************/