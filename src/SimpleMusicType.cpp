#include "SimpleMusicType.h"


// �⺻������, ���ȣ�� -1, ����� ���� ������ �ʱ�ȭ
SimpleMusicType::SimpleMusicType()
{
	song = "";
	singer = "";
	numberofplay = 0;
}


SimpleMusicType::~SimpleMusicType()
{
}

void operator<<(ostream& out, SimpleMusicType& simplemusic)
{
	out << "\t���   : " << simplemusic.song << endl;
	out << "\t������ : " << simplemusic.singer << endl;
}