#include <iostream>
#include <windows.h>

using namespace std;

bool copyFile(const char* sourceFilePath, const char* destinationFilePath, int bufferSize, bool overwrite) {
    HANDLE sourceFile = CreateFileA(
        sourceFilePath,
        GENERIC_READ,
        0,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (sourceFile == INVALID_HANDLE_VALUE) {
        cout << "Failed to open source file." << endl;
        return false;
    }

    DWORD creationDisposition = overwrite ? CREATE_ALWAYS : CREATE_NEW;

    HANDLE destinationFile = CreateFileA(
        destinationFilePath,
        GENERIC_WRITE,
        0,
        NULL,
        creationDisposition,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (destinationFile == INVALID_HANDLE_VALUE) {
        cout << "Failed to create destination file." << endl;
        CloseHandle(sourceFile);
        return false;
    }

    DWORD bufferSizeBytes = bufferSize * 1024;
    char* buffer = new char[bufferSizeBytes];
    DWORD bytesRead = 0;
    DWORD bytesWritten = 0;

    while (ReadFile(sourceFile, buffer, bufferSizeBytes, &bytesRead, NULL) && bytesRead > 0) {
        WriteFile(destinationFile, buffer, bytesRead, &bytesWritten, NULL);

        if (bytesRead != bytesWritten) {
            cout << "Failed to write to destination file." << endl;
            CloseHandle(sourceFile);
            CloseHandle(destinationFile);
            delete[] buffer;
            return false;
        }
    }

    CloseHandle(sourceFile);
    CloseHandle(destinationFile);
    delete[] buffer;

    cout << "File copied successfully." << endl;

    return true;
}

int main(int argc, const char* argv[]) {
    if (argc != 5) {
        cout << "Syntax Error!" << endl;
        cout << "<program> <From> <To> <buffer_size_in_kb> <overwrite: YES/NO>" << endl;
        return 0;
    }

    const char* sourceFilePath = argv[1];
    const char* destinationFilePath = argv[2];
    int bufferSize = atoi(argv[3]);
    bool overwrite = (strcmp(argv[4], "YES") == 0);

    bool result = copyFile(sourceFilePath, destinationFilePath, bufferSize, overwrite);

    if (!result) {
        cout << "Failed to copy file." << endl;
    }

    return 0;
}
