#include <iostream>
#include <windows.h>

int main() {
    // Replace "COM1" with the appropriate name of your serial port (e.g., "COM2")
    const char* portName = "COM1";
    HANDLE hSerial = CreateFileA(portName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if (hSerial == INVALID_HANDLE_VALUE) {
        std::cerr << "Error opening serial port " << portName << std::endl;
        return 1;
    }

    DCB dcbSerialParams = { 0 };
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

    if (!GetCommState(hSerial, &dcbSerialParams)) {
        std::cerr << "Error getting serial port state" << std::endl;
        CloseHandle(hSerial);
        return 1;
    }

    dcbSerialParams.BaudRate = CBR_9600;  // Set the baud rate (e.g., 9600)
    dcbSerialParams.ByteSize = 8;         // 8 data bits
    dcbSerialParams.StopBits = ONESTOPBIT;// 1 stop bit
    dcbSerialParams.Parity = NOPARITY;    // No parity

    if (!SetCommState(hSerial, &dcbSerialParams)) {
        std::cerr << "Error setting serial port state" << std::endl;
        CloseHandle(hSerial);
        return 1;
    }

    COMMTIMEOUTS timeouts = { 0 };
    timeouts.ReadIntervalTimeout = 50;          // Max time between receiving characters (in milliseconds)
    timeouts.ReadTotalTimeoutConstant = 50;     // Max time to read (in milliseconds)
    timeouts.ReadTotalTimeoutMultiplier = 10;   // Time per byte to read (in milliseconds)

    if (!SetCommTimeouts(hSerial, &timeouts)) {
        std::cerr << "Error setting timeouts" << std::endl;
        CloseHandle(hSerial);
        return 1;
    }

    // Sample: Send "Hello" to the serial port
    const char* message = "Hello";
    DWORD bytesWritten;
    if (!WriteFile(hSerial, message, strlen(message), &bytesWritten, NULL)) {
        std::cerr << "Error writing to serial port" << std::endl;
        CloseHandle(hSerial);
        return 1;
    }

    // Sample: Read from the serial port
    const int bufferSize = 256;
    char buffer[bufferSize];
    DWORD bytesRead;
    if (!ReadFile(hSerial, buffer, bufferSize - 1, &bytesRead, NULL)) {
        std::cerr << "Error reading from serial port" << std::endl;
        CloseHandle(hSerial);
        return 1;
    }

    buffer[bytesRead] = '\0';
    std::cout << "Received: " << buffer << std::endl;

    CloseHandle(hSerial);
    return 0;
}

