#include <Log.h>

using namespace Core;
using namespace std::chrono;
int Log::callCounter = 0;

void Log::makeNote(const std::string &msg) {
    std::ostringstream stm;
    stm << GetCurrentTimeFromStart() / MS_IN_SEC << " :: " << msg << "\n";
    RecordIntoLogFile(stm.str());
}

void Log::makeNote(const std::string &msg, const std::string &module) {
    std::ostringstream stm;
    stm << GetCurrentTimeFromStart() / MS_IN_SEC << " :: " << msg << " :: " << module << "\n";
    RecordIntoLogFile(stm.str());
}

void Log::RecordIntoLogFile(std::string fullMsg) {
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
    milliseconds ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    auto diff = duration_cast<milliseconds>(ms - startTime);
    float msgTime = diff.count();
    return msgTime / MS_IN_SEC;
}
