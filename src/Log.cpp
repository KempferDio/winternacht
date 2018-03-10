#include <Log.h>

using namespace Core;
using namespace std::chrono;

void Log::makeNote(const std::string &msg) {
    std::ostringstream stm;
    milliseconds ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    auto diff = duration_cast<milliseconds>(ms - startTime);
    float msgTime = diff.count();

    stm << msgTime << " :: " << msg << "\n";

    recordIntoLogFile(stm.str());
}

void Log::makeNote(const std::string &msg, const std::string &module) {
    std::ostringstream stm;
    milliseconds ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    auto diff = duration_cast<milliseconds>(ms - startTime);
    float msgTime = diff.count();

    stm << msgTime << " :: " << msg << " :: " << module << "\n";

    recordIntoLogFile(stm.str());
}

void Log::recordIntoLogFile(std::string fullMsg) {
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