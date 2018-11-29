#include "SimpleMusicType.h"


// 기본생성자, 곡번호는 -1, 곡명은 없는 것으로 초기화
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
	out << "\t곡명   : " << simplemusic.song << endl;
	out << "\t가수명 : " << simplemusic.singer << endl;
}