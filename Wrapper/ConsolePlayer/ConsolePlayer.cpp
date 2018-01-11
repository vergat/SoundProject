#include "stdafx.h"
#include <Wrapper.h>
#include <iostream>
#include <string>

int main()
{

	Wrapper wrapper;
	wrapper.Init();

	/********************************* Load *******************************************/
	std::cout << "Insert path and song to play (ex.C:\\..\\music.mp3)" << std::endl;
	std::string strtmp;
	bool stream = false;
	std::cin >> strtmp;
	const char* path = strtmp.c_str();
	std::cout << "Type 1 if you want stream the sound, 0 default" << std::endl;
	std::cin >> stream;
	wrapper.Load(path,stream);

	/********************************* Loop - Oneshoot **************************************/
	std::cout << "Type 0 for Loop or 1 for OneShoot" << std::endl;
	bool type=false;
	std::cin >> type;
	if (type)
	{
		wrapper.LoopSound();
	}
	else
	{
		wrapper.OneShootSound();
	}

	int action = 0;
	bool loop = true;
	while (loop)
	{
		std::cout << "Select one of these possible actions by write their number: " << std::endl;
		std::cout << "1. Play" << std::endl;
		std::cout << "2. Pause" << std::endl;
		std::cout << "4. Volume" << std::endl;
		std::cout << "5. Pan" << std::endl;
		std::cout << "6. Exit" << std::endl;
		std::cin >> action;
		switch (action)
		{
		case 1:
			wrapper.Play();
			break;
		case 2:
			wrapper.Pause();
			break;
		case 4:
		{
			float volume = 0.0f;
			std::cout << "Insert volume value" << std::endl;
			std::cin >> volume;
			wrapper.Volume(volume);
		}break;
		case 5:
		{
			float pan = 0.0f;
			std::cout << "Insert pan value" << std::endl;
			std::cin >> pan;
			wrapper.Pan(pan);
		}break;
		case 6:
			loop = false;
			break;
		default:
			std::cout << "Unknown action, repeat" << std::endl;
			break;
		}
	}
    return 0;
}

