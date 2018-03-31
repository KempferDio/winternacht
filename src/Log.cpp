#include <Log.h>

using namespace Core;

int Log::callCounter = 0;
bool Log::isLogFileWasCreated = false;
std::chrono::milliseconds Log::startTime =
    std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
/*

template<typename T, typename... Args>
void Log::LogInfo(T first, Args... args) {
    std::string msg = MakeMsg(BLUE_COLOR, "INFO", first).str();
    std::cout << msg;
    WriteIntoLogFile(msg);
    callCounter++;
    LogInfo(first);
}

template<typename T, typename... Args>
void Log::LogDebug(T first, Args... args) {
    std::string msg = MakeMsg(CYAN_COLOR, "DEBUG", first).str();
    std::cout << msg;
    WriteIntoLogFile(msg);
    callCounter++;
    LogDebug(first);
}

template<typename T, typename... Args>
void Log::LogWarning(T first, Args... args) {
    std::string msg = MakeMsg(YELLOW_COLOR, "WARNING", first).str();
    std::cout << msg;
    WriteIntoLogFile(msg);
    callCounter++;
    LogWarning(first);
}

template<typename T, typename... Args>
void Log::LogError(T first, Args... args) {
    std::string msg = MakeMsg(RED_COLOR, "ERROR", first).str();
    std::cout << msg;
    WriteIntoLogFile(msg);
    callCounter++;
    LogError(first);
}

void Log::LogInfo() {
    breakRecursion();
}

void Log::LogDebug() {
    breakRecursion();
}

void Log::LogWarning() {
    breakRecursion();
}

void Log::LogError() {
    breakRecursion();
}


void Log::WriteIntoLogFile(std::string fullMsg) {
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

float Log::GetCurrentTimeFromStart() {
    std::chrono::milliseconds ms = duration_cast<std::chrono::milliseconds>(system_clock::now().time_since_epoch());
    auto diff = duration_cast<std::chrono::milliseconds>(ms - startTime);
    float msgTime = diff.count();
    return msgTime / MS_IN_SEC;
}

void Log::breakRecursion() {
    callCounter = 0;
    std::cout << "\n";
    WriteIntoLogFile("\n");
}

template<typename T>
std::ostringstream Log::MakeMsg(std::string color, std::string msgType, T first) {
    std::ostringstream stm;
    if(callCounter == 0) {
        stm << GetCurrentTimeFromStart() << " [" << color << " " << msgType << DEFAULT_COLOR << " ] ";
    }
    stm << first << " :: ";

    return stm;
}
*/