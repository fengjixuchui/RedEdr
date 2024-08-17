#pragma once

#ifndef COMMON_H
#define COMMON_H

#define PIPE_BUFFER_SIZE 4096 // Default
#define DATA_BUFFER_SIZE 4096


#define IOCTL_MY_IOCTL_CODE CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_BUFFERED, FILE_ANY_ACCESS)
typedef struct _MY_DRIVER_DATA {
    WCHAR filename[256];
    int flag;
} MY_DRIVER_DATA, * PMY_DRIVER_DATA;



#define DRIVER_KERNEL_PIPE_NAME L"\\??\\pipe\\RedEdrKrnCom"
#define KERNEL_PIPE_NAME L"\\\\.\\pipe\\RedEdrKrnCom"
#define DLL_PIPE_NAME L"\\\\.\\pipe\\RedEdrDllCom"


#endif