#include<iostream>
#include<set>

using namespace std;

class Subscriber {
    public:
        virtual void notify(string message) = 0;
        virtual ~Subscriber() {}
};

class AndroidSubscriber : public Subscriber {
    private:
        string name;
    public:
        AndroidSubscriber(string name) {
            this->name = name;
        }
        void notify(string message) {
            cout << "Notified " << name << " as " << message << endl;
        }
};

class IPhoneSubscriber : public Subscriber {
    private:
        string name;
    public:
        IPhoneSubscriber(string name) {
            this->name = name;
        }
        void notify(string message) {
            cout << "Notified " << name << " as " << message << endl;
        }
};

class HotStarChannel {
    private:
        set<Subscriber*> subscriberSet;
    public:
        void addSubscriber(Subscriber* subscriber) {
            subscriberSet.insert(subscriber);
        }
        void removeSubscriber(Subscriber* subscriber) {
            subscriberSet.erase(subscriber);
        }
        void notifySubscriber(string message) {
            for(auto it: subscriberSet) {
                it->notify(message);
            }
        }
};

int main() {
    Subscriber* s1 = new AndroidSubscriber("Lav");
    Subscriber* s2 = new AndroidSubscriber("Kush");
    Subscriber* s3 = new IPhoneSubscriber("Supriya");
    Subscriber* s4 = new IPhoneSubscriber("Test");
    HotStarChannel* hotStarChannel = new HotStarChannel();
    hotStarChannel->addSubscriber(s1);
    hotStarChannel->addSubscriber(s2);
    hotStarChannel->addSubscriber(s3);
    hotStarChannel->addSubscriber(s4);
    hotStarChannel->notifySubscriber("Bahubali is Live");
    hotStarChannel->removeSubscriber(s4);
    hotStarChannel->notifySubscriber("KGF is Live");
    delete hotStarChannel;
    return 0;
}