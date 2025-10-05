#include<iostream>

using namespace std;

class FileProcessor {
    protected:
        void openFile() {
            cout << "Opening file..." << endl;
        }
        virtual void readFile() = 0;
        virtual void processFile() = 0;
        void closeFile() {
            cout << "Closing file..." << endl;
        }
    public:
        void process() {
            openFile();
            readFile();
            processFile();
            closeFile();
        }
};

class JSONFileProcessor : public FileProcessor {
    public:
        void readFile() {
            cout << "Reading JSON File..." << endl;
        }
        void processFile() {
            cout << "Processing JSON file..." << endl;
        }
};

class CSVFileProcessor : public FileProcessor {
    public:
        void readFile() {
            cout << "Reading CSV File..." << endl;
        }
        void processFile() {
            cout << "Processing CSV file..." << endl;
        }
};

int main() {
    FileProcessor* jsonFileProcessor = new JSONFileProcessor();
    FileProcessor* csvFileProcessor = new CSVFileProcessor();
    cout << "------------------------------" << endl;
    cout << "Processing JSON file" << endl;
    cout << "------------------------------" << endl;
    jsonFileProcessor->process();
    cout << "------------------------------" << endl;
    cout << "------------------------------" << endl;
    cout << "Processing CSV file" << endl;
    cout << "------------------------------" << endl;
    csvFileProcessor->process();
    return 0;
}