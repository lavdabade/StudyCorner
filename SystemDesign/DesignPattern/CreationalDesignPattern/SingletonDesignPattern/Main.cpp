#include<iostream>
#include<thread>
#include<mutex> 

using namespace std;

class Logger {
    private:
        Logger() {
            cout << "Creating logger instance" << endl;
        }
        
    public:
        static Logger* logger;
        static mutex mtx;

        static Logger* getLoggerInstance() {
            if(logger == NULL) {
                mtx.lock();
                    if(logger == NULL) {
                        logger = new Logger();
                    }
                mtx.unlock();
            }
            return logger;
        }
};

Logger* Logger::logger = NULL;
mutex Logger::mtx;

void log01() {
    Logger* l1 = Logger::getLoggerInstance();
}

void log02() {
    Logger* l2 = Logger::getLoggerInstance();
}

int main() {
    thread t1(log01);
    thread t2(log02);
    t1.join();
    t2.join();
    return 0;
}


////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


// #include<iostream>
// #include<thread>
// #include<mutex> 

// using namespace std;

// class Logger {
//     private:
//         Logger() {
//             cout << "Creating logger instance" << endl;
//         }
        
//     public:
//         static Logger* logger;
//         static mutex mtx;

//         static Logger* getLoggerInstance() {
//             mtx.lock();
//                 if(logger == NULL) {
//                     logger = new Logger();
//                 }
//             mtx.unlock();
//             return logger;
//         }
// };

// Logger* Logger::logger = NULL;
// mutex Logger::mtx;

// void log01() {
//     Logger* l1 = Logger::getLoggerInstance();
// }

// void log02() {
//     Logger* l2 = Logger::getLoggerInstance();
// }

// int main() {
//     thread t1(log01);
//     thread t2(log02);
//     t1.join();
//     t2.join();
//     return 0;
// }



////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


// #include<iostream>
// #include <thread>

// using namespace std;

// class Logger {
//     private:
//         Logger() {
//             cout << "Creating logger instance" << endl;
//         }
        
//     public:
//         static Logger* logger;

//         static Logger* getLoggerInstance() {
//             if(logger == NULL) {
//                 logger = new Logger();
//             }
//             return logger;
//         }
// };

// Logger* Logger::logger = NULL;

// void log01() {
//     Logger* l1 = Logger::getLoggerInstance();
// }

// void log02() {
//     Logger* l2 = Logger::getLoggerInstance();
// }

// int main() {
//     thread t1(log01);
//     thread t2(log02);
//     t1.join();
//     t2.join();
//     return 0;
// }

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

// #include<iostream>

// using namespace std;

// class Logger {
//     private:
//         Logger() {
//             cout << "Creating logger instance" << endl;
//         }
        
//     public:
//         static Logger* logger;

//         static Logger* getLoggerInstance() {
//             if(logger == NULL) {
//                 logger = new Logger();
//             }
//             return logger;
//         }
// };

// Logger* Logger::logger = NULL;

// int main() {
//     Logger* l1 = Logger::getLoggerInstance();
//     Logger* l2 = Logger::getLoggerInstance();
//     return 0;
// }