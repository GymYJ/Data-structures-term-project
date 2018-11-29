#include "Application.h"


// 프로그램 드라이버
void Application::Run()
{
	while (1)
	{
		int num; // 커맨드넘버
		string input; // 잘못된 입력을 방지하기 위한 스트링 변수
		cout << "┌────────────────────────────────────────┐" << endl;
		cout << "│         1. 관리자 모드                 │" << endl;
		cout << "│         2. 유저 모드                   │" << endl;
		cout << "│         0. 종료                        │" << endl;
		cout << "└────────────────────────────────────────┘" << endl << "-> ";
		cin >> input;

		try
		{
			num = stoi(input); // 숫자 이외의 값이 들어가면 오류
			if (num <= -1 || num >= 3)
			{
				throw invalid_argument("숫자 범위 오류");
			}
		}
		catch (invalid_argument)
		{
			cout << "잘못된 명령어 입니다." << endl;
			system("pause");
			cout << endl;
			system("CLS");
			continue;
		}

		switch (num)
		{
		case 1:	// 관리자 모드로 이동
			system("CLS");
			MasterMode();
			break;
		case 2:	// 유저 모드로 이동
			system("CLS");
			UserMode();
			break;
		case 0:
			cout << "프로그램을 종료합니다." << endl;
			//exit(100);
			return;
		default:
			break;
		}
	}
}

// 마스터계정 모드
void Application::MasterMode()
{
	while (1)
	{
		int num; // 커맨드넘버
		string input; // 잘못된 입력을 방지하기 위한 스트링 변수
		cout << "┌────────────────────────────────────────┐" << endl;
		cout << "│         1. 음악 추가                   │" << endl;
		cout << "│         2. 음악 삭제                   │" << endl;
		cout << "│         3. 음악 갱신                   │" << endl;
		cout << "│         4. 모든 음악 정보 출력         │" << endl;
		cout << "│         5. 파일 로드                   │" << endl;
		cout << "│         6. 파일 저장                   │" << endl;
		cout << "│         0. 이전 메뉴로                 │" << endl;
		cout << "└────────────────────────────────────────┘" << endl << "-> ";
		cin >> input;

		try
		{
			num = stoi(input); // 숫자 이외의 값이 들어가면 오류
			if (num <= -1 || num >= 7)
			{
				throw invalid_argument("숫자 범위 오류");
			}
		}
		catch (invalid_argument)
		{
			cout << "잘못된 명령어 입니다." << endl;
			system("pause");
			cout << endl;
			system("CLS");
			continue;
		}

		switch (num)
		{
		case 1:	// 음악 추가 – 정렬
			AddMusic();
			system("pause");
			cout << endl;
			system("CLS");
			break;
		case 2:	// 리스트에서 음악 삭제
			DeleteMusic();
			system("pause");
			cout << endl;
			system("CLS");
			break;
		case 3:	// 리스트에 있는 음악 갱신 – 딜리트하고 애드
			ReplaceMusic();
			system("pause");
			cout << endl;
			system("CLS");
			break;
		case 4:	// 모든 음악 정보 출력
			DisplayAllMusic();
			system("pause");
			cout << endl;
			system("CLS");
			break;
		case 5:	// 파일 로드
			ReadDataFromFile();
			system("pause");
			cout << endl;
			system("CLS");
			break;
		case 6:	// 파일 저장
			WriteDataToFile();
			system("pause");
			cout << endl;
			system("CLS");
			break;
		case 0:	// 이전 메뉴로
			system("CLS");
			return;
		default:
			break;
		}
	}
}

// 유저계정 모드
void Application::UserMode()
{
	while (1)
	{
		int num; // 커맨드넘버
		string input; // 잘못된 입력을 방지하기 위한 스트링 변수
		cout << "┌────────────────────────────────────────┐" << endl;
		cout << "│     1. 재생 목록 출력                  │" << endl;
		cout << "│     2. 재생 목록에서 음악 삭제         │" << endl;
		cout << "│     3. 곡명으로 음악 검색              │" << endl;
		cout << "│     4. 가수명으로 음악 검색            │" << endl;
		cout << "│     5. 앨범명으로 음악 검색            │" << endl;
		cout << "│     6. 장르로 음악 검색                │" << endl;
		cout << "│     7. 가장 많이 재생한 30곡 목록 출력 │" << endl;
		cout << "│     0. 이전 메뉴로                     │" << endl;
		cout << "└────────────────────────────────────────┘" << endl << "-> ";
		cin >> input;

		try
		{
			num = stoi(input); // 숫자 이외의 값이 들어가면 오류
			if (num <= -1 || num >= 8)
			{
				throw invalid_argument("숫자 범위 오류");
			}
		}
		catch (invalid_argument)
		{
			cout << "잘못된 명령어 입니다." << endl;
			system("pause");
			cout << endl;
			system("CLS");
			continue;
		}

		switch (num)
		{
		case 1:	// 재생 목록 출력
			DisplayPlayList();
			system("pause");
			cout << endl;
			system("CLS");
			break;
		case 2:	// 재생 목록에서 음악 삭제
			deleteMusicFromPlayList();
			system("pause");
			cout << endl;
			system("CLS");
			break;
		case 3:	// 곡명으로 리스트에 있는 음악 검색
			SearchByName();
			system("pause");
			cout << endl;
			system("CLS");
			break;
		case 4:	// 가수명으로 리스트에 있는 음악 검색
			SearchByArtist();
			system("pause");
			cout << endl;
			system("CLS");
			break;
		case 5:	// 앨범명으로 리스트에 있는 음악 검색
			SearchByAlbum();
			system("pause");
			cout << endl;
			system("CLS");
			break;
		case 6:	// 장르로 리스트에 있는 음악 검색
			SearchByGenre();
			system("pause");
			cout << endl;
			system("CLS");
			break;
		case 7:	// 가장 많이 재생한 곡 출력
			DisplayMostPlayList();
			system("pause");
			cout << endl;
			system("CLS");
			break;
		case 0:	// 이전 메뉴로
			system("CLS");
			return;
		default:
			break;
		}
	}
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
	bool Found;
	m_SongList.RetrieveItem(music, Found);
	if (Found == true)
	{
		cout << "같은 음악이 존재합니다." << endl;
		return 0;
	}

	string filename;
	filename = dir + music.GetSong() + ".wav";
	char* file;
	file = (char*)filename.c_str();
	file[filename.size()] = '\0';

	_finddata_t find;
	long handle;
	handle = _findfirst(file, &find);
	if (handle == -1)
	{
		cout << "폴더에 파일이 없습니다." << endl;
		return 0;
	}

	simplemusic.SetRecord(music.GetSong(), music.GetSinger());
	genre.SetGenre(music.GetGenre());
	artist.SetRecord(music.GetSinger());
	album.SetRecord(music.GetSinger(), music.GetAlbum());


	// MusicList에 추가
	m_SongList.Add(music);

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

	cout << "추가되었습니다." << endl;

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

	cout << "삭제할 곡의 곡명을 입력해주세요." << endl;
	music.SetSongFromKB();

	bool Found;
	m_SongList.RetrieveItem(music, Found);
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
	m_SongList.DeleteItem(music);

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

	cout << "삭제되었습니다." << endl;

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
		cout << "갱신할 곡의 곡명을 입력해주세요." << endl;
		music.SetSongFromKB();

		bool Found;
		m_SongList.RetrieveItem(music, Found);
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
		m_SongList.DeleteItem(music);

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
		bool Found;
		m_SongList.RetrieveItem(music, Found);
		if (Found == true)
		{
			cout << "같은 음악이 존재합니다." << endl;
			cout << "갱신 중인 곡이 삭제됩니다." << endl;
			return 0;
		}

		string filename;
		filename = dir + music.GetSong() + ".wav";
		char* file;
		file = (char*)filename.c_str();
		file[filename.size()] = '\0';

		_finddata_t find;
		long handle;
		handle = _findfirst(file, &find);
		if (handle == -1)
		{
			cout << "폴더에 파일이 없습니다." << endl;
			cout << "갱신 중인 곡이 삭제됩니다." << endl;
			return 0;
		}
		
		simplemusic.SetRecord(music.GetSong(), music.GetSinger());
		genre.SetGenre(music.GetGenre());
		artist.SetRecord(music.GetSinger());
		album.SetRecord(music.GetSinger(), music.GetAlbum());

		// MusicList에 추가
		m_SongList.Add(music);

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

	cout << "갱신되었습니다." << endl;

	DisplayAllMusic();
	return 0;
}


void Application::playMusic(int inNumber)
{
	string song;
	int number = inNumber;
	song = dir + m_PlayList[number].GetSong() + ".wav";
	char* directory;
	directory = (char*)song.c_str();
	directory[song.size()] = '\0';

	int key;
	while (true)
	{
		system("CLS");
		PlaySound(directory, NULL, SND_ASYNC);
	
		// 가장 많이 재생한 곡 리스트 갱신
		m_PlayList[number].AddNumberOfPlay();
		if (m_MostPlayListLength == 0)	// 리스트에 곡이 없을 때
		{
			m_MostPlayList[0] = m_PlayList[number];
			m_MostPlayListLength++;
		}
		else if (m_MostPlayListLength == 1)	// 리스트에 음악이 1개 있을 때
		{
			if (m_MostPlayList[0] == m_PlayList[number])
			{
				m_MostPlayList[0] = m_PlayList[number];
			}
			else if (m_MostPlayList[0].GetNumberOfPlay() < m_PlayList[number].GetNumberOfPlay())
			{
				m_MostPlayList[1] = m_MostPlayList[0];
				m_MostPlayList[0] = m_PlayList[number];
				m_MostPlayListLength++;
			}
			else
			{
				m_MostPlayList[1] = m_PlayList[number];
				m_MostPlayListLength++;
			}
		}
		else	// 음악이 2개이상 있을 때
		{
			// 중복된 곡이 있으면 삭제 후 추가
			for (int i = 0; i < m_MostPlayListLength; i++)
			{
				if (m_MostPlayList[i] == m_PlayList[number])
				{
					// 리스트 마지막 원소 일 때
					if (i == m_MostPlayListLength - 1)
					{
						m_MostPlayListLength--;
						break;
					}
					// 리스트 중간에 있을 때
					else
					{
						for (int j = i; j < m_MostPlayListLength - 1; j++)
						{
							m_MostPlayList[j] = m_MostPlayList[j + 1];
						}
						m_MostPlayListLength--;
						break;
					}
				}
			}
			// 추가
			if (m_MostPlayListLength == 1)	// 리스트에 음악이 1개 있을 때
			{
				if (m_MostPlayList[0].GetNumberOfPlay() < m_PlayList[number].GetNumberOfPlay())
				{
					m_MostPlayList[1] = m_MostPlayList[0];
					m_MostPlayList[0] = m_PlayList[number];
					m_MostPlayListLength++;
				}
				else
				{
					m_MostPlayList[1] = m_PlayList[number];
					m_MostPlayListLength++;
				}
			}
			else // 리스트에 음악이 2개이상 있을 때
			{
				for (int i = 0; i < m_MostPlayListLength; i++)
				{
					// 추가하는 곡이 리스트의 곡보다 재생횟수가 많을 때
					if (m_MostPlayList[i].GetNumberOfPlay() < m_PlayList[number].GetNumberOfPlay())
					{
						if (m_MostPlayListLength == 30)
						{
							for (int j = m_MostPlayListLength - 1; j > i; j--)
							{
								m_MostPlayList[j] = m_MostPlayList[j - 1];
							}
							m_MostPlayList[i] = m_PlayList[number];
							break;
						}
						else
						{
							for (int j = m_MostPlayListLength; j > i; j--)
							{
								m_MostPlayList[j] = m_MostPlayList[j - 1];
							}
							m_MostPlayList[i] = m_PlayList[number];
							m_MostPlayListLength++;
							break;
						}
					}
					// 리스트의 어떤 곡보다 적을 때
					if (i == m_MostPlayListLength - 1 && m_MostPlayListLength != 30)
					{
						m_MostPlayList[m_MostPlayListLength] = m_PlayList[number];
						m_MostPlayListLength++;
						break;
					}
				}
			}
		}

		while (true)
		{
			cout << "──────────────────────────────────────────" << endl;
			cout << "                재생목록" << endl;
			// list의 모든 데이터를 화면에 출력
			for (int i = 0; i < m_PlayListLength; i++)
			{
				cout << "──────────────────────────────────────────" << endl;
				cout << "No. " << (i + 1) << endl;
				m_PlayList[i].DisplayRecordOnScreen();
			}
			cout << "──────────────────────────────────────────" << endl;
			cout << "\t현재 재생 곡 : " << m_PlayList[number].GetSong() << endl;
			cout << "\t이전 곡 재생 : ←" << endl;
			cout << "\t다음 곡 재생 : →" << endl;
			cout << "\t재생 중지    : Space Bar" << endl;

			key = _getch();
			if (key == 224)
			{
				key = _getch();
				switch (key)
				{
				case 75:	// ←키 눌렀을 때
					if (number == 0)	// 첫곡 일 때 마지막 곡으로
					{
						number = m_PlayListLength - 1;
						song = dir + m_PlayList[number].GetSong() + ".wav";
						directory = (char*)song.c_str();
						directory[song.size()] = '\0';
					}
					else	// 첫곡이 아닐 때
					{
						number = number - 1;
						song = dir + m_PlayList[number].GetSong() + ".wav";
						directory = (char*)song.c_str();
						directory[song.size()] = '\0';
					}
					break;
				case 77:	// →키 눌렀을 때
					if (number == (m_PlayListLength - 1))	// 마지막곡 일 때 첫곡으로
					{
						number = 0;
						song = dir + m_PlayList[number].GetSong() + ".wav";
						directory = (char*)song.c_str();
						directory[song.size()] = '\0';
					}
					else	// 마지막곡이 아닐 때
					{
						number = number + 1;
						song = dir + m_PlayList[number].GetSong() + ".wav";
						directory = (char*)song.c_str();
						directory[song.size()] = '\0';
					}
					break;
				default:
					break;
				}
				if (key == 75 || key == 77)
					break;
				else
					system("CLS");
			}
			else if (key == 32)
			{
				PlaySound(NULL, 0, 0);
				cout << "재생이 중지되었습니다." << endl;
				return;
			}
			else
			{
				system("CLS");
			}
		}
	}
	return;
}

int Application::AddMusicToPlayList(string inSong)
{
	MusicType music;
	SimpleMusicType simplemusic;
	music.SetSong(inSong);

	bool found;
	m_SongList.RetrieveItem(music, found);
	simplemusic.SetRecord(music.GetSong(), music.GetSinger());
	
	// 재생목록 다 차있으면 추가불가
	if (m_PlayListLength == 30)
	{
		cout << "재생목록이 다 차있습니다." << endl;
		return 0;
	}

	// 재생목록 제일 앞에 추가
	for (int i = m_PlayListLength; i > 0; i--)
	{
		m_PlayList[i] = m_PlayList[i - 1];
	}
	m_PlayList[0] = simplemusic;
	m_PlayListLength++;
	
	cout << "재생목록에 추가되었습니다." << endl;

	return 1;
}

int Application::deleteMusicFromPlayList()
{
	if (m_PlayListLength == 0)
	{
		cout << "재생목록이 비어있습니다." << endl;
		return 0;
	}

	cout << "──────────────────────────────────────────" << endl;
	cout << "                재생목록" << endl;
	// list의 모든 데이터를 화면에 출력
	for (int i = 0; i < m_PlayListLength; i++)
	{
		cout << "──────────────────────────────────────────" << endl;
		cout << "No. " << (i + 1) << endl;
		m_PlayList[i].DisplayRecordOnScreen();
	}
	cout << "──────────────────────" << endl;

	int num; // 커맨드넘버
	string input; // 잘못된 입력을 방지하기 위한 스트링 변수
	cout << "삭제할 곡의 번호를 선택해주세요." << endl;
	cout << "Number : ";
	cin >> input;

	try
	{
		num = stoi(input); // 숫자 이외의 값이 들어가면 오류
		if (num <= 0 || num > m_PlayListLength)
		{
			throw invalid_argument("숫자 범위 오류");
		}
	}
	catch (invalid_argument)
	{
		cout << "잘못된 명령어 입니다." << endl;
		return 0;
	}

	SimpleMusicType simplemusic;
	simplemusic.SetSong(m_PlayList[num - 1].GetSong());
	simplemusic.SetSinger(m_PlayList[num - 1].GetSinger());

	int number = GetSeqNumOfPlayList(simplemusic);
	
	// 재생목록에서 삭제
	for (int i = number; i < m_PlayListLength - 1; i++)
	{
		m_PlayList[i] = m_PlayList[i + 1];
	}
	cout << "삭제되었습니다" << endl;
	m_PlayListLength--;
	return 1;

	return 1;
}

int Application::GetSeqNumOfPlayList(SimpleMusicType inData)
{
	for (int i = 0; i < m_PlayListLength; i++)
	{
		// 일치하는 곡을 찾으면 해당곡의 순서 리턴
		if (m_PlayList[i] == inData)
		{
			return i;
		}
	}
	return -1;
}

// 리스트에서 제목이 일치하는 Music 모두 출력
int Application::SearchByName()
{
	MusicType music;
	bool found;
	cout << "찾을 곡의 곡명을 입력하세요" << endl;
	music.SetSongFromKB();
	cout << "──────────────────────────────────────────" << endl;

	m_SongList.RetrieveItem(music, found);
	if (found == false)
	{
		cout << "일치하는 곡이 없습니다." << endl;
		return 0;
	}
	else
	{
		music.DisplayRecordOnScreen();
		cout << "플레이리스트에 추가하시겠습니까? (Y/N)" << endl;
		string input;
		cin >> input;
		if (input == "Y")
		{
			AddMusicToPlayList(music.GetSong());
		}
	}

	return 1;
}

//  리스트에서 가수명이 일치하는 Music 모두 출력
int Application::SearchByArtist()
{
	ArtistType artist;
	string data;
	cout << "찾을 곡의 가수명을 입력하세요" << endl << "\t가수명      : ";
	cin >> data;
	artist.SetArtistName(data);

	cout << "──────────────────────────────────────────" << endl;
	bool FoundFromArtist;
	m_ArtistList.RetrieveItem(artist, FoundFromArtist);
	if (FoundFromArtist == false)
	{
		cout << "일치하는 가수가 없습니다." << endl;
		return 0;
	}
	else
	{
		artist.DisplaySongListOnScreen();
		cout << "──────────────────────────────────────────" << endl;
		MusicType music;
		bool found;
		cout << "자세히 보고 싶은 곡명을 입력하세요" << endl;
		music.SetSongFromKB();
		cout << "──────────────────────────────────────────" << endl;
		m_SongList.RetrieveItem(music, found);
		if (found == false)
		{
			cout << "일치하는 곡이 없습니다." << endl;
			return 0;
		}
		else
		{
			music.DisplayRecordOnScreen();
			cout << "플레이리스트에 추가하시겠습니까? (Y/N)" << endl;
			string input;
			cin >> input;
			if (input == "Y")
			{
				AddMusicToPlayList(music.GetSong());
			}
		}
	}
	return 1;
}

//  리스트에서 앨범이 일치하는 앨범 모두 출력
int Application::SearchByAlbum()
{
	AlbumType album;
	string data;
	cout << "찾을 곡의 앨범명을 입력하세요" << endl << "\t앨범명      : ";
	cin >> data;
	cout << "──────────────────────────────────────────" << endl;
	album.SetAlbumName(data);

	bool FoundFromAlbum;
	m_AlbumList.RetrieveItem(album, FoundFromAlbum);
	if (FoundFromAlbum == false)
	{
		cout << "일치하는 앨범이 없습니다." << endl;
		return 0;
	}
	else
	{
		album.DisplayContainMusicListOnScreen();
		cout << "──────────────────────────────────────────" << endl;
		MusicType music;
		bool found;
		cout << "자세히 보고 싶은 곡명을 입력하세요" << endl;
		music.SetSongFromKB();
		cout << "──────────────────────────────────────────" << endl;
		m_SongList.RetrieveItem(music, found);
		if (found == false)
		{
			cout << "일치하는 곡이 없습니다." << endl;
			return 0;
		}
		else
		{
			music.DisplayRecordOnScreen();
			cout << "플레이리스트에 추가하시겠습니까? (Y/N)" << endl;
			string input;
			cin >> input;
			if (input == "Y")
			{
				AddMusicToPlayList(music.GetSong());
			}
		}
	}
	return 1;
}

//  리스트에서 장르가 일치하는 Music 모두 출력
int Application::SearchByGenre()
{
	GenreType genre;
	string data;
	cout << "찾을 곡의 장르명을 입력하세요" << endl << "\t장르        : ";
	cin >> data;
	genre.SetGenre(data);
	cout << "──────────────────────────────────────────" << endl;

	bool FoundFromGenre;
	m_GenreList.RetrieveItem(genre, FoundFromGenre);
	if (FoundFromGenre == false)
	{
		cout << "일치하는 장르가 없습니다." << endl;
		return 0;
	}
	else
	{
		genre.DisplayListOnScreen();
		cout << "──────────────────────────────────────────" << endl;
		MusicType music;
		bool found;
		cout << "자세히 보고 싶은 곡명을 입력하세요" << endl;
		music.SetSongFromKB();
		cout << "──────────────────────────────────────────" << endl;
		m_SongList.RetrieveItem(music, found);
		if (found == false)
		{
			cout << "일치하는 곡이 없습니다." << endl;
			return 0;
		}
		else
		{
			music.DisplayRecordOnScreen();
			cout << "플레이리스트에 추가하시겠습니까? (Y/N)" << endl;
			string input;
			cin >> input;
			if (input == "Y")
			{
				AddMusicToPlayList(music.GetSong());
			}
		}
	}

	return 1;
}

// 재생목록 출력
void Application::DisplayPlayList()
{
	if (m_PlayListLength == 0)
	{
		cout << "재생목록이 비어있습니다." << endl;
		return;
	}
	cout << "──────────────────────────────────────────" << endl;
	cout << "                재생목록" << endl;
	// list의 모든 데이터를 화면에 출력
	for (int i = 0; i < m_PlayListLength; i++)
	{
		cout << "──────────────────────────────────────────" << endl;
		cout << "No. " << (i + 1) << endl;
		m_PlayList[i].DisplayRecordOnScreen();
	}
	cout << "──────────────────────────────────────────" << endl;

	int num; // 커맨드넘버
	string input; // 잘못된 입력을 방지하기 위한 스트링 변수
	cout << "재생할 곡의 번호를 선택해주세요." << endl;
	cout << "Number : ";
	cin >> input;

	try
	{
		num = stoi(input); // 숫자 이외의 값이 들어가면 오류
		if (num <= 0 || num > m_PlayListLength)
		{
			throw invalid_argument("숫자 범위 오류");
		}
	}
	catch (invalid_argument)
	{
		cout << "잘못된 명령어 입니다." << endl;
		return;
	}

	playMusic((num - 1));
	
	return;
}

// 리스트에 있는 Music 전부 삭제
int Application::MakeEmpty()
{
	m_SongList.MakeEmpty();
	return 0;
}

// 리스트에 있는 모든 Music 출력
void Application::DisplayAllMusic()
{
	cout << "──────────────────────────────────────────" << endl;
	cout << "전체곡 목록" << endl;
	cout << "──────────────────────────────────────────" << endl;
	m_SongList.PrintTree(cout);
}

// 가장 많이 재생한 30곡 출력
void Application::DisplayMostPlayList()
{
	if (m_MostPlayListLength == 0)
	{
		cout << "재생한 곡이 없습니다." << endl;
		return;
	}

	cout << "가장 많이 재생한 30곡" << endl;
	cout << "──────────────────────────────────────────" << endl;
	for (int i = 0; i < m_MostPlayListLength; i++)
	{
		m_MostPlayList[i].DisplayRecordOnScreen();
		m_MostPlayList[i].DisplayNumberOfPlayOnScreen();
		cout << "──────────────────────────────────────────" << endl;
	}
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
	

	string song;		///< 노래제목
	string singer;		///< 가수
	string songwriter;	///< 작곡가
	string lyricwriter;	///< 작사가
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

	string directory;
	char* file;

	// 파일의 모든 내용을 읽어 list에 추가
	while (fin >> song >> singer >> songwriter >> lyricwriter >> album >> genre)
	{
		getline(fin, lyrics);
		getline(fin, lyrics);

		MusicType music;	// 읽기용 임시 변수
		SimpleMusicType simplemusic;	// 읽기용 임시 변수
		GenreType genretype;		// 읽기용 임시 변수
		ArtistType artisttype;	// 읽기용 임시 변수
		AlbumType albumtype;	// 읽기용 임시 변수

		music.SetRecord(song, singer, songwriter, lyricwriter, album, genre, lyrics);
		m_SongList.RetrieveItem(music, Found);
		if (Found == true)	// 일치하는 곡명이 있을 때, 다음 곡 받아옴
		{
			continue;
		}

		directory = dir + music.GetSong() + ".wav";
		file = (char*)directory.c_str();
		file[directory.size()] = '\0';

		_finddata_t find;
		long handle;
		handle = _findfirst(file, &find);
		if (handle == -1)	// 폴더에 일치하는 곡이 없을 때, 다음 곡 받아옴
		{
			continue;
		}
		
		simplemusic.SetRecord(song, singer);
		genretype.SetGenre(genre);
		artisttype.SetRecord(singer);
		albumtype.SetRecord(singer, album);

		// MusicList에 추가
		m_SongList.Add(music);

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
	m_SongList.WriteTree(fout);

	m_OutFile.close();	// 파일 닫기
	cout << "저장되었습니다." << endl;
	return 1;
}

