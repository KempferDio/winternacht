#ifndef LOG_H
#define LOG_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <chrono>
#define LOG_FILE_NAME "log.txt"
#define MS_IN_SEC 1000
#define DEFAULT_COLOR "\033[0m"
#define BLUE_COLOR "\033[0;34m"
#define CYAN_COLOR "\033[0;96m"
#define YELLOW_COLOR "\033[0;33m"
#define RED_COLOR "\033[0;31m"
using namespace std::chrono;

namespace Core {
    class Log {
    public:
        static bool isLogFileWasCreated;
        static std::chrono::milliseconds startTime;


        template<typename T, typename... Args>
        static void LogInfo(T first, Args... args) {
            std::string msg = MakeMsg(BLUE_COLOR, "INFO", first).str();
            std::cout << msg;
            WriteIntoLogFile(msg);
            callCounter++;
            LogInfo(args ...);
        }

        template<typename T, typename... Args>
        static void LogDebug(T first, Args... args) {
            std::string msg = MakeMsg(CYAN_COLOR, "DEBUG", first).str();
            std::cout << msg;
            WriteIntoLogFile(msg);
            callCounter++;
            LogDebug(args ...);
        }

        template<typename T, typename... Args>
        static void LogWarning(T first, Args... args) {
            std::string msg = MakeMsg(YELLOW_COLOR, "WARNING", first).str();
            std::cout << msg;
            WriteIntoLogFile(msg);
            callCounter++;
            LogWarning(args ...);
        }

        template<typename T, typename... Args>
        static void LogError(T first, Args... args) {
            std::string msg = MakeMsg(RED_COLOR, "ERROR", first).str();
            std::cout << msg;
            WriteIntoLogFile(msg);
            callCounter++;
            LogError(args ...);
        }

        static void LogInfo() {
            breakRecoursion();
        }

        static void LogWarning() {
            breakRecoursion();
        }

        static void LogDebug() {
            breakRecoursion();
        }

        static void LogError() {
            breakRecoursion();
        }
        
    private:
        static void WriteIntoLogFile(std::string fullMsg) {
            std::ofstream logFile;
            if(!isLogFileWasCreated) {
                logFile.open(LOG_FILE_NAME, std::ios::trunc);
                isLogFileWasCreated = true;
            }
            else {
                logFile.open(LOG_FILE_NAME, std::fstream::app);
            }

            logFile << fullMsg;

            logFile.close();
        }

        static float GetCurrentTimeFromStart() {
            milliseconds ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
            auto diff = duration_cast<milliseconds>(ms - startTime);
            float msgTime = diff.count();
            return msgTime / MS_IN_SEC;
        }
        static int callCounter;

        static void breakRecoursion() {
            callCounter = 0;
            std::cout << "\n";
            WriteIntoLogFile("\n");
        }
        template <typename T>
        static std::ostringstream MakeMsg(std::string color, std::string msgType, T first) {
            std::ostringstream stm;
            if(callCounter == 0) {
                stm << GetCurrentTimeFromStart() << " [" << color << " " << msgType << DEFAULT_COLOR << " ] ";
            }
            stm << first << " :: ";

            return stm;
        }
    };

}

#endif