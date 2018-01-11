#include "stdafx.h"
#include "Wrapper.h"
#include "fmod_errors.h"

void ErrorCheck(const FMOD_RESULT &result)
{
	std::cout << "";
	if ((result != FMOD_OK) && (result != FMOD_ERR_INVALID_HANDLE) && (result != FMOD_ERR_CHANNEL_STOLEN))
	{
		std::cout << "FMOD error!("<< result<<") "<< FMOD_ErrorString(result) << std::endl;
		exit(EXIT_FAILURE);
	}
}

void Wrapper::Init()
{
	m_result = FMOD::System_Create(&m_system);
	ErrorCheck(m_result);
	m_result = m_system->getVersion(&m_version);
	ErrorCheck(m_result);
	if (m_version < FMOD_VERSION)
	{
		std::cout << "FMOD lib version " <<m_version<<" doesn't match header version "<<FMOD_VERSION<< std::endl;
	}
	m_result = m_system->init(32, FMOD_INIT_NORMAL, m_extraDriverData);
	ErrorCheck(m_result);
}

void Wrapper::Load(const char *path,bool stream)
{
	if (stream)
	{
		m_result = m_system->createSound(path, FMOD_CREATESTREAM, 0, &m_sound);
		ErrorCheck(m_result);
	}
	else
	{
		m_result = m_system->createSound(path, FMOD_DEFAULT, 0, &m_sound);
		ErrorCheck(m_result);
	}
	m_result = m_system->playSound(m_sound, 0, false, &m_channel);
	ErrorCheck(m_result);
}

void Wrapper::Play()
{
	if (m_firstTime)
	{
		m_result = m_channel->setPaused(false);
		ErrorCheck(m_result);
		m_firstTime = false;
	}
	else
	{
		m_result = m_channel->setPaused(false);
		ErrorCheck(m_result);
	}
}

void Wrapper::Pause()
{
	m_result = m_channel->setPaused(true);
	ErrorCheck(m_result);
}

void Wrapper::Stop()
{
	m_firstTime = true;
	m_result= m_channel->stop();
	ErrorCheck(m_result);
}

void Wrapper::LoopSound()
{
	m_result = m_sound->setMode(FMOD_LOOP_NORMAL);
	ErrorCheck(m_result);
}

void Wrapper::OneShootSound()
{
	m_result = m_sound->setMode(FMOD_LOOP_OFF);
	ErrorCheck(m_result);
}

void Wrapper::Pan(float pan)
{
	if (pan<-1.0f || pan>1.0f)
	{
		pan = pan / abs(pan);
	}
	m_result = m_channel->setPan(pan);
	ErrorCheck(m_result);
}

void Wrapper::Volume(float volume)
{
	m_result = m_channel->setVolume(volume);
	ErrorCheck(m_result);
}
