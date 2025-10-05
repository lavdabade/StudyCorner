#include<iostream>

using namespace std;

class ExternalDevice {
    public:
        virtual void connectExternalDevice() = 0;
        virtual ~ExternalDevice() {};
};

class PenDrive : public ExternalDevice {
    public:
        void connectExternalDevice() {
            cout << "Connecting PenDrive to loptop" << endl;
        }
};

class FloppyDisk {
    public:
        void readData() {
            cout << "Reading data from Floppy Disk" << endl;
        }
};

class FloppyDiskAdapter : public ExternalDevice {
    private:
        FloppyDisk* floppyDisk;
    public:
        FloppyDiskAdapter(FloppyDisk* floppyDisk) {
            this->floppyDisk = floppyDisk;
        }
        void connectExternalDevice() {
            floppyDisk->readData();
        }
};

int main() {
    ExternalDevice* penDrive = new PenDrive();
    penDrive->connectExternalDevice();
    FloppyDisk* floppyDisk = new FloppyDisk();
    FloppyDiskAdapter* floppyDiskAdapter = new FloppyDiskAdapter(floppyDisk);
    floppyDiskAdapter->connectExternalDevice();
    return 0;
}