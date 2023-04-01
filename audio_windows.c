#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>

void play_audio(char *path) {
    PlaySoundA(path, NULL, SND_FILENAME | SND_ASYNC);
}

int play_midi(char *path) {
    wchar_t* midiPath = (wchar_t *)path;

    UINT wDeviceId;
    DWORD dwReturn;
    DWORD dwLength;
    MCI_OPEN_PARMS mciOpenParms;
    MCI_PLAY_PARMS mciPlayParms;
    MCI_STATUS_PARMS mciStatusParms;
    MCI_SEQ_SET_PARMS mciSeqSetParms;

    mciOpenParms.lpstrDeviceType = "sequencer";
    mciOpenParms.lpstrElementName = path;
    if (dwReturn = mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&mciOpenParms))
    {
        return dwReturn;
    }

    wDeviceId = mciOpenParms.wDeviceID;

    mciStatusParms.dwItem = MCI_SEQ_STATUS_PORT;
    if (dwReturn = mciSendCommand(wDeviceId, MCI_STATUS, MCI_STATUS_ITEM, (DWORD)(LPVOID)&mciStatusParms))
    {
        mciSendCommand(wDeviceId, MCI_CLOSE, 0, 0);
        return dwReturn;
    }

    mciStatusParms.dwItem = MCI_STATUS_LENGTH;
    if (dwReturn = mciSendCommand(wDeviceId, MCI_STATUS, MCI_STATUS_ITEM | MCI_WAIT, (DWORD)(LPVOID)&mciStatusParms))
    {
        mciSendCommand(wDeviceId, MCI_CLOSE, 0, 0);
        return dwReturn;
    }

    dwLength = mciStatusParms.dwReturn;

    mciSendCommand(wDeviceId, MCI_PLAY, 0, 0);

    mciStatusParms.dwItem = MCI_STATUS_POSITION;
    while (1)
    {
        if (dwReturn = mciSendCommand(wDeviceId, MCI_STATUS, MCI_STATUS_ITEM | MCI_WAIT, (DWORD)(LPVOID)&mciStatusParms))
        {
            break;
        }

        if (dwLength == mciStatusParms.dwReturn)
        {
            break;
        }
    }

    mciSendCommand(wDeviceId, MCI_CLOSE, 0, 0);
}