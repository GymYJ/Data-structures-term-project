#include "Application.h"


// 프로그램 드라이버
void Application::Run()
{
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:	// 음악 추가 – 정렬
			AddMusic();
			break;
		case 2:	// 리스트에서 음악 삭제
			DeleteMusic();
			break;
		case 3:	// 리스트에 있는 음악 갱신 – 딜리트하고 애드
			ReplaceMusic();
			break;
		case 4:	// 리스트에 있는 음악 검색
				// 단, 검색어가 곡명에 포함된다면 출력한다
				// 	ex) 검색어 : ‘사랑’ / 출력 : 가난한사랑,천년의사랑,..
			SearchByName(); // find()함수
			break;
		case 5:	// 리스트에 있는 가수 검색
				// 단, 검색어가 가수명에 포함된다면 출력한다
			SearchByArtist();
			break;
		case 6:	// 리스트에 있는 앨범 검색
				// 단, 검색어가 앨범명에 포함된다면 출력한다
			SearchByAlbum();
			break;
		case 7:	// 리스트에 있는 장르 검색
				// 단, 검색어가 장르명에 포함된다면 출력한다
			SearchByGenre();
			break;
		case 8:	// 리스트에 있는 모든 음악정보 출력
			DisplayAllMusic();
			break;
		case 9:	// 장르별로 음악 출력
			ReadDataFromFile();
			break;
		case 10:	// 곡명과 장르가 일치하는 음악을 찾아서 화면에 출력
			WriteDataToFile();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;


		}
	}
}


// 명령어를 스크린에 보여주고 키보드로 입력받음
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add Music" << endl;
	cout << "\t   2 : Delete Music" << endl;
	cout << "\t   3 : Replace Music" << endl;
	cout << "\t   4 : Search by name" << endl;
	cout << "\t   5 : Search by artist" << endl;
	cout << "\t   6 : Search by album" << endl;
	cout << "\t   7 : Search by genre" << endl;
	cout << "\t   8 : Display all music" << endl;
	cout << "\t   9 : Read data from file" << endl;
	cout << "\t   10 : Write data from file" << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// 리스트에 새로운 Music 추가
int Application::AddMusic()
{
	MusicType music;
	SimpleMusicType simplemusic;
	GenreType genre;
	ArtistType artist;
	AlbumType album;

	cout << "추가할 곡의 정보를 입력해 주세요." << endl;
	music.SetRecordFromKB();
	simplemusic.SetRecord(music.GetSong(), music.GetSinger());
	genre.SetGenre(music.GetGenre());
	artist.SetRecord(music.GetSinger());
	album.SetRecord(music.GetSinger(), music.GetAlbum());

	bool Found;
	m_List.RetrieveItem(music, Found);
	if (Found == true)
	{
		cout << "같은 음악이 존재합니다." << endl;
		return 0;
	}

	// MusicList에 추가
	m_List.Add(music);

	// GenreList에 추가
	m_GenreList.Add(genre);

	bool FoundFromGenre;
	m_GenreList.RetrieveItem(genre, FoundFromGenre);
	genre.Add(simplemusic);
	m_GenreList.ReplaceItem(genre);

	// ArtistList에 추가
	m_ArtistList.Add(artist);

	bool FoundFromArtist;
	m_ArtistList.RetrieveItem(artist, FoundFromArtist);
	artist.Add(simplemusic);
	m_ArtistList.ReplaceItem(artist);

	// AlbumList에 추가
	m_AlbumList.Add(album);

	bool FoundFromAlbum;
	m_AlbumList.RetrieveItem(album, FoundFromAlbum);
	album.Add(simplemusic);
	m_AlbumList.ReplaceItem(album);

	// 현재 list 출력
	DisplayAllMusic();

	return 1;
}

// 리스트에서 Music 하나 삭제
int Application::DeleteMusic()
{
	MusicType music;
	SimpleMusicType simplemusic;
	GenreType genre;
	ArtistType artist;
	AlbumType album;

	cout << "삭제할 곡의 곡명과 가수를 입력해주세요." << endl;
	music.SetSongFromKB();
	music.SetSingerFromKB();

	bool Found;
	m_List.RetrieveItem(music, Found);
	if (Found == false)
	{
		cout << "일치하는 음악이 없습니다." << endl;
		return 0;
	}
	simplemusic.SetRecord(music.GetSong(), music.GetSinger());
	genre.SetGenre(music.GetGenre());
	artist.SetRecord(music.GetSinger());
	album.SetRecord(music.GetSinger(), music.GetAlbum());

	// MusicList에서 삭제
	m_List.DeleteItem(music);

	// GenreList에서 삭제
	bool FoundFromGenre;
	m_GenreList.RetrieveItem(genre, FoundFromGenre);
	genre.Delete(simplemusic);
	m_GenreList.ReplaceItem(genre);

	// ArtistList에 삭제
	bool FoundFromArtist;
	m_ArtistList.RetrieveItem(artist, FoundFromArtist);
	artist.Delete(simplemusic);
	m_ArtistList.ReplaceItem(artist);

	// AlbumList에 삭제
	bool FoundFromAlbum;
	m_AlbumList.RetrieveItem(album, FoundFromAlbum);
	album.Delete(simplemusic);
	m_AlbumList.ReplaceItem(album);

	DisplayAllMusic();
	return 0;
}

// 리스트에서 Music 하나 갱신
int Application::ReplaceMusic()
{
	MusicType music;
	SimpleMusicType simplemusic;
	GenreType genre;
	ArtistType artist;
	AlbumType album;

	// 노래삭제
	{
		cout << "갱신할 곡의 곡명과 가수를 입력해주세요." << endl;
		music.SetSongFromKB();
		music.SetSingerFromKB();

		bool Found;
		m_List.RetrieveItem(music, Found);
		if (Found == false)
		{
			cout << "일치하는 음악이 없습니다." << endl;
			return 0;
		}
		simplemusic.SetRecord(music.GetSong(), music.GetSinger());
		genre.SetGenre(music.GetGenre());
		artist.SetRecord(music.GetSinger());
		album.SetRecord(music.GetSinger(), music.GetAlbum());

		// MusicList에서 삭제
		m_List.DeleteItem(music);

		// GenreList에서 삭제
		bool FoundFromGenre;
		m_GenreList.RetrieveItem(genre, FoundFromGenre);
		genre.Delete(simplemusic);
		m_GenreList.ReplaceItem(genre);

		// ArtistList에 삭제
		bool FoundFromArtist;
		m_ArtistList.RetrieveItem(artist, FoundFromArtist);
		artist.Delete(simplemusic);
		m_ArtistList.ReplaceItem(artist);

		// AlbumList에 삭제
		bool FoundFromAlbum;
		m_AlbumList.RetrieveItem(album, FoundFromAlbum);
		album.Delete(simplemusic);
		m_AlbumList.ReplaceItem(album);
	}

	// 노래 추가
	{
		cout << "갱신할 곡의 정보를 입력해 주세요." << endl;
		music.SetRecordFromKB();
		simplemusic.SetRecord(music.GetSong(), music.GetSinger());
		genre.SetGenre(music.GetGenre());
		artist.SetRecord(music.GetSinger());
		album.SetRecord(music.GetSinger(), music.GetAlbum());

		bool Found;
		m_List.RetrieveItem(music, Found);
		if (Found == true)
		{
			cout << "같은 음악이 존재합니다." << endl;
			return 0;
		}

		// MusicList에 추가
		m_List.Add(music);

		// GenreList에 추가
		m_GenreList.Add(genre);

		bool FoundFromGenre;
		m_GenreList.RetrieveItem(genre, FoundFromGenre);
		genre.Add(simplemusic);
		m_GenreList.ReplaceItem(genre);

		// ArtistList에 추가
		m_ArtistList.Add(artist);

		bool FoundFromArtist;
		m_ArtistList.RetrieveItem(artist, FoundFromArtist);
		artist.Add(simplemusic);
		m_ArtistList.ReplaceItem(artist);

		// AlbumList에 추가
		m_AlbumList.Add(album);

		bool FoundFromAlbum;
		m_AlbumList.RetrieveItem(album, FoundFromAlbum);
		album.Add(simplemusic);
		m_AlbumList.ReplaceItem(album);
	}

	DisplayAllMusic();
	return 0;
}

// 리스트에서 제목이 일치하는 Music 모두 출력
int Application::SearchByName()
{
	string song;
	cout << "찾을 곡의 곡명을 입력하세요" << endl << "\tSong   : ";
	cin >> song;
	cout << "------------------------------------------" << endl;

	m_List.RetrieveByString(song);
	return 1;
}

//  리스트에서 가수명이 일치하는 Music 모두 출력
int Application::SearchByArtist()
{
	ArtistType artist;
	string data;
	cout << "찾을 곡의 가수명을 입력하세요" << endl << "\tSinger   : ";
	cin >> data;
	artist.SetArtistName(data);

	bool FoundFromArtist;
	m_ArtistList.RetrieveItem(artist, FoundFromArtist);
	cout << "------------------------------------------" << endl;
	artist.DisplaySongListOnScreen();

	return 1;
}

//  리스트에서 앨범이 일치하는 앨범 모두 출력
int Application::SearchByAlbum()
{
	string album;
	cout << "찾을 곡의 앨범명을 입력하세요" << endl << "\tAlbum   : ";
	cin >> album;
	cout << "------------------------------------------" << endl;

	m_AlbumList.RetrieveByString(album);

	cout << "자세히 보고 싶은 앨범의 가수명과 앨범명을 입력해주세요" << endl;
	AlbumType temp;
	string singer;
	cout << "\tArtist   : ";
	cin >> singer;
	cout << "\tAlbum   : ";
	cin >> album;
	cout << "------------------------------------------" << endl;
	temp.SetRecord(singer, album);

	bool FoundFromAlbum;
	m_AlbumList.RetrieveItem(temp, FoundFromAlbum);
	temp.DisplayContainMusicListOnScreen();

	return 1;
}

//  리스트에서 장르가 일치하는 Music 모두 출력
int Application::SearchByGenre()
{
	GenreType genre;
	string data;
	cout << "찾을 곡의 장르명을 입력하세요" << endl << "\tGenre   : ";
	cin >> data;
	genre.SetGenre(data);
	cout << "------------------------------------------" << endl;

	bool FoundFromGenre;
	m_GenreList.RetrieveItem(genre, FoundFromGenre);
	genre.DisplayListOnScreen();

	return 1;
}

// 리스트에 있는 Music 전부 삭제
int Application::MakeEmpty()
{
	m_List.MakeEmpty();
	return 0;
}

// 리스트에 있는 모든 Music 출력
void Application::DisplayAllMusic()
{
	m_List.PrintTree(cout);
}


// 파일 설명자에 의한 파일을 입력 파일로 열기
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// file open for reading.

								// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_InFile)	return 0;
	else	return 1;
}


// 파일 설명자별 파일을 출력 파일로 열기
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

								// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_OutFile)	return 0;
	else	return 1;
}


// 읽기 모드로 파일을 열고 파일의 모든 데이터를 읽은 다음 데이터별로 목록을 설정
int Application::ReadDataFromFile()
{
	MusicType music;	// 읽기용 임시 변수
	SimpleMusicType simplemusic;	// 읽기용 임시 변수
	GenreType genretype;		// 읽기용 임시 변수
	ArtistType artisttype;	// 읽기용 임시 변수
	AlbumType albumtype;	// 읽기용 임시 변수

	string song;		///< 노래제목
	string singer;		///< 가수
	string album;		///< 앨범
	string genre;		///< 장르
	string lyrics;		///< 가사

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if (!OpenInFile(filename))
	{
		cout << "읽어올 파일을 열지 못했습니다." << endl;
		return 0;
	}
	ifstream fin(filename);

	bool Found;
	bool FoundFromGenre;
	bool FoundFromArtist;
	bool FoundFromAlbum;

	// 파일의 모든 내용을 읽어 list에 추가
	while (fin >> song >> singer >> album >> genre)
	{
		getline(fin, lyrics);
		getline(fin, lyrics);

		music.SetRecord(song, singer, album, genre, lyrics);
		simplemusic.SetRecord(song, singer);
		genretype.SetGenre(genre);
		artisttype.SetRecord(singer);
		albumtype.SetRecord(singer, album);

		m_List.RetrieveItem(music, Found);
		if (Found == true)
		{
			break;
		}

		// MusicList에 추가
		m_List.Add(music);

		// GenreList에 추가
		m_GenreList.Add(genretype);

		m_GenreList.RetrieveItem(genretype, FoundFromGenre);
		genretype.Add(simplemusic);
		m_GenreList.ReplaceItem(genretype);

		// ArtistList에 추가
		m_ArtistList.Add(artisttype);

		m_ArtistList.RetrieveItem(artisttype, FoundFromArtist);
		artisttype.Add(simplemusic);
		m_ArtistList.ReplaceItem(artisttype);

		// AlbumList에 추가
		m_AlbumList.Add(albumtype);

		m_AlbumList.RetrieveItem(albumtype, FoundFromAlbum);
		albumtype.Add(simplemusic);
		m_AlbumList.ReplaceItem(albumtype);
	}

	m_InFile.close();	// 파일 닫기


	DisplayAllMusic(); // 현재 list 출력

	return 1;
}


// 파일을 쓰기 모드로 열고 모든 데이터를 파일에 기록
int Application::WriteDataToFile()
{
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if (!OpenOutFile(filename))
	{
		cout << "저장할 파일을 열지 못했습니다." << endl;
		return 0;
	}

	ofstream fout(filename);
	// list의 모든 데이터를 파일에 쓰기
	m_List.WriteTree(fout);

	m_OutFile.close();	// 파일 닫기
	cout << "저장되었습니다." << endl;
	return 1;
}

