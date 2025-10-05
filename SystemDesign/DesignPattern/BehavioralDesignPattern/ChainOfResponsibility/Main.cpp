#include<iostream>

using namespace std;

enum LogLevel {
    INFO,
    WARN,
    FATAL
};

class Logger {
    protected:
        Logger* nextLoggerHop;

    public:
        void setNextLoggerHop(Logger* nextLoggerHop) {
            this->nextLoggerHop = nextLoggerHop;
        }

        virtual void log(LogLevel logLevel, string message) = 0;
};

class InfoLogger : public Logger {
    public:
        void log(LogLevel logLevel, string message) {
            if(logLevel == INFO) {
                cout << "INFO: " << message << endl;
            }
            else {
                nextLoggerHop->log(logLevel, message);
            }
        }
};

class WarnLogger : public Logger {
    public:
        void log(LogLevel logLevel, string message) {
            if(logLevel == WARN) {
                cout << "WARN: " << message << endl;
            }
            else {
                nextLoggerHop->log(logLevel, message);
            }
        }
};

class FatalLogger : public Logger {
    public:
        void log(LogLevel logLevel, string message) {
            if(logLevel == FATAL) {
                cout << "FATAL: " << message << endl;
            }
        }
};

int main() {
    InfoLogger* infoLogger = new InfoLogger();
    WarnLogger* warnLogger = new WarnLogger();
    FatalLogger* fatalLogger = new FatalLogger();

    infoLogger->setNextLoggerHop(warnLogger);
    warnLogger->setNextLoggerHop(fatalLogger);

    infoLogger->log(INFO, "with info enum");
    infoLogger->log(WARN, "with warn enum");
    infoLogger->log(FATAL, "with fatal enum");

    delete infoLogger;
    delete warnLogger;
    delete fatalLogger;

    return 0;
}