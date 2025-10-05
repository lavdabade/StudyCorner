#include<iostream>

using namespace std;

class Mediator;

class User {
    private:
        string name;
        Mediator* mediator;
    public:
        User(string name, Mediator* mediator) {
            this->name = name;
            this->mediator = mediator;
        }
        string getName() {
            return name;
        }
        void sendMessage(string message);
        void receiveMessage(User* user, string message) {
            cout << name << " received message \"" << message << "\" from user " << user->getName() << endl;
        }
};

class Mediator {
    private:
        vector<User*> userList;
    public:
        void addUser(User* user) {
            userList.push_back(user);
        }
        void sendMessage(User* user, string message) {
            for(auto* it: userList) {
                if(it != user) {
                    it->receiveMessage(user, message);
                }
            }
        }
};

void User::sendMessage(string message) {
    cout << name << " sends message \"" << message << "\"" << endl;
    mediator->sendMessage(this, message);
}

int main() {
    Mediator* mediator = new Mediator();
    User* u1 = new User("Lav", mediator);
    User* u2 = new User("Kush", mediator);
    User* u3 = new User("Supriya", mediator);
    User* u4 = new User("Test", mediator);
    mediator->addUser(u1);
    mediator->addUser(u2);
    mediator->addUser(u3);
    mediator->addUser(u4);
    u1->sendMessage("Hello");
    u2->sendMessage("Hey");
    u3->sendMessage("hi");

    delete u1;
    delete u2;
    delete u3;
    delete u4;
    delete mediator;
    return 0;
}