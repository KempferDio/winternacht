#ifndef LOG_H
#define LOG_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <chrono>
#define LOG_FILE_NAME "log.txt"
#define CLOCKS_PER_MS (CLOCKS_PER_SEC * 1000)

namespace Core {
    class Log {
    public:
        static bool isLogFileWasCreated;
        static std::chrono::milliseconds startTime;
        static void makeNote(const std::string &msg);
        static void makeNote(const std::string &msg, const std::string &module);
    private:
        static void recordIntoLogFile(std::string fullMsg);
    };
}



#endif