#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>

void play_audio(char *path) {
    PlaySoundA(path, NULL, SND_FILENAME | SND_ASYNC);
}