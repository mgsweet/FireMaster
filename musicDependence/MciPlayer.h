#ifndef _MCI_PLAYER_WIN32_H_
#define _MCI_PLAYER_WIN32_H_

#include "platform/CCStdC.h"
#include <mmsystem.h>
#include <string>
using namespace std;


namespace CocosDenshion {

class MciPlayer
{
public:
    MciPlayer();
    ~MciPlayer();

    void Close();

    /**
    @brief Open audio file
    @param pFileName The file name which includes the file path.
    @param uId  The audio ID
    */
    void Open(const char* pFileName, UINT uId);

    /**
    @brief Play audio file
    @param nTimes The repeat times, its default value is 1 which means only play once
    */
    void Play(UINT uTimes = 1);

    /**
    @brief Pause play
    */
    void Pause();

    /**
    @brief Resume play
    */
    void Resume();

    /**
    @brief Stop play
    */
    void Stop();

    /**
    @brief Replay
    */
    void Rewind();

    /**
    @brief Is Playing
    */
    bool IsPlaying();

    /**
    @brief  Get playing sound's ID
    @return Sound's ID
    */
    UINT GetSoundID();

	//@volume value ranges from 0 .. 1000
	void Volume(UINT volume);

	//@return value ranges from 0 .. 1000
	UINT MciPlayer::Volume() const;

private:
    friend LRESULT WINAPI _SoundPlayProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

    void _SendGenericCommand(int nCommand, DWORD_PTR param1 = 0, DWORD_PTR parma2 = 0);

    HWND        _wnd;
    MCIDEVICEID _dev;
    UINT        _soundID;
    UINT        _times;
    bool        _playing;
    std::string strExt;
};

} // end of namespace CocosDenshion

#endif
