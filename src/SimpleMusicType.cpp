#include "SimpleMusicType.h"


// �⺻������, ���ȣ�� -1, ����� ���� ������ �ʱ�ȭ
SimpleMusicType::SimpleMusicType()
{
	song = "";
	singer = "";
}


SimpleMusicType::~SimpleMusicType()
{
}

void operator<<(ostream& out, SimpleMusicType& simplemusic)
{
	out << "\tSong   : " << simplemusic.song << endl;
	out << "\tSinger : " << simplemusic.singer << endl;
}