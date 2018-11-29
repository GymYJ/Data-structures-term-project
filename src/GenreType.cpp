#include "GenreType.h"


// �⺻ ������, ũ��� 10, ���̴� 0 ���� �ʱ�ȭ
GenreType::GenreType()
{
	m_Length = 0;
}

// �Ҹ���
GenreType::~GenreType()
{
}

// ����Ʈ ���� ��������
int GenreType::GetLength()
{
	return m_Length;
}

// �帣���� SimpleMusic ���
void GenreType::DisplayListOnScreen()
{
	cout << "\t�帣      : " << genre << endl;
	cout << "������������������������������������������������������������������������������������" << endl;
	m_List.PrintTree(cout);
}

// ����Ʈ�� music �߰�
void GenreType::Add(SimpleMusicType inData)
{
	m_List.Add(inData);
	m_Length++;
}

// ����Ʈ���� music ����
void GenreType::Delete(SimpleMusicType inData)
{
	m_List.DeleteItem(inData);
	m_Length--;
}

