#pragma once
#include "fmod.hpp"
#include <iostream>

class Wrapper 
{
public:
	void Init();
	void Load(const char *path,bool stream);
	void Play();
	void Pause();
	void Stop();
	void LoopSound();
	void OneShootSound();
	void Pan(float pan);
	void Volume(float volume);
private:
	FMOD::System *m_system;
	FMOD::Sound *m_sound;
	FMOD::Channel *m_channel = 0;
	unsigned int m_version;
	FMOD_RESULT m_result;
	void *m_extraDriverData = 0;
	bool m_firstTime = true;
};