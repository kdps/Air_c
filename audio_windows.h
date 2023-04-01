#ifndef _AUDIO_WINDOWS_H_
#define _AUDIO_WINDOWS_H_

#pragma comment(lib,"winmm.lib")

typedef unsigned long  DWORD;

extern void play_audio(char *path);

extern int play_midi(char *path);

#endif