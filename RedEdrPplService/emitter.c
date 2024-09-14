#include <stdio.h>
#include <Windows.h>

#include "../Shared/common.h"

HANDLE hPipe = NULL;


BOOL ConnectEmitterPipe() {
    log_message(L"Emitter: Connect pipe %s to RedEdr", DLL_PIPE_NAME);
    hPipe = CreateFile(DLL_PIPE_NAME, GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
    if (hPipe == INVALID_HANDLE_VALUE) {
        log_message(L"Emitter: Error connecting to pipe %s error %ld", 
            DLL_PIPE_NAME, GetLastError());
        return FALSE;
    }
    return TRUE;
}


void SendEmitterPipe(wchar_t* buffer) {
    DWORD pipeBytesWritten = 0;
    DWORD res = 0;
    if (hPipe == NULL) {
        log_message(L"Emitter: Error when sending as pipe is closed");
        return;
    }
    DWORD len = (DWORD)(wcslen(buffer) * 2) + 2; // +2 -> include two trailing 0 bytes
    res = WriteFile(hPipe, buffer, len, &pipeBytesWritten, NULL);
    if (res == FALSE) {
        log_message(L"Emitter: Error when sending to pipe");
    }
}


void DisconnectEmitterPipe() {
    log_message(L"Emitter: Disconnect pipe %s to RedEdr", DLL_PIPE_NAME);
    CloseHandle(hPipe);
    hPipe = NULL;
}