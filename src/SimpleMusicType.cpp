#include "SimpleMusicType.h"


// 기본생성자, 곡번호는 -1, 곡명은 없는 것으로 초기화
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