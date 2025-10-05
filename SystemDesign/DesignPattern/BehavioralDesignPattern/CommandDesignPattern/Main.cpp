#include<iostream>

using namespace std;

class ACRemote {
    public:
        void turnOn() {
            cout << "Turning on AC" << endl;
        }
        void turnOff() {
            cout << "Turning off AC" << endl;
        }
        void setTemperature(int temperature) {
            cout << "Setting temperature to " << temperature << endl;
        }
};

class TVRemote {
    public:
        void turnOn() {
            cout << "Tunrnig on TV" << endl;
        }
        void turnOff() {
            cout << "Turning off TV" << endl;
        }
        void setChannel(int channelNo) {
            cout << "Setting channel no " << channelNo << endl;
        }
};

class Command {
    public:
        virtual void execute() = 0;
};

class ACCommand : public Command {
    private:
        ACRemote* acRemote;
    public:
        ACCommand(ACRemote* acRemote) {
            this->acRemote = acRemote;
        }
        void execute() {
            acRemote->turnOn();
            acRemote->setTemperature(20);
            acRemote->turnOff();
        }
};

class TVCommand : public Command {
    private:
        TVRemote* tvRemote;
    public:
        TVCommand(TVRemote* tvRemote) {
            this->tvRemote = tvRemote;
        }
        void execute() {
            tvRemote->turnOn();
            tvRemote->setChannel(10);
            tvRemote->turnOff();
        }
};

class CombinedCommand : public Command {
    private:
        TVRemote* tvRemote;
        ACRemote* acRemote;
    public:
        CombinedCommand(TVRemote* tvRemote, ACRemote* acRemote) {
            this->tvRemote = tvRemote;
            this->acRemote = acRemote;
        }
        void execute() {
            acRemote->turnOn();
            tvRemote->turnOn();
            acRemote->setTemperature(18);
            tvRemote->setChannel(10);
            acRemote->turnOff();
            tvRemote->turnOff();
        }
};

class RemoteControl {
    private:
        Command* command;
    public:
        void setCommand(Command* command) {
            this->command = command;
        }
        void buttonPressed() {
            command->execute();
        }
};

int main() {
    RemoteControl* remoteControl = new RemoteControl();
    ACRemote* acRemote = new ACRemote();
    TVRemote* tvRemote = new TVRemote();
    ACCommand* acCommand = new ACCommand(acRemote);
    TVCommand* tvCommand = new TVCommand(tvRemote);
    CombinedCommand* combinedCommand = new CombinedCommand(tvRemote, acRemote);
    cout << "----------------------------------------" << endl;
    cout << "AC Command" << endl;
    cout << "----------------------------------------" << endl;
    remoteControl->setCommand(acCommand);
    remoteControl->buttonPressed();
    cout << "----------------------------------------" << endl;
    cout << "TV Command" << endl;
    cout << "----------------------------------------" << endl;
    remoteControl->setCommand(tvCommand);
    remoteControl->buttonPressed();
    cout << "----------------------------------------" << endl;
    cout << "Combined Command" << endl;
    cout << "----------------------------------------" << endl;
    remoteControl->setCommand(combinedCommand);
    remoteControl->buttonPressed();
    delete combinedCommand;
    delete tvCommand;
    delete acCommand;
    delete tvRemote;
    delete acRemote;
    delete remoteControl;
    return 0;
}