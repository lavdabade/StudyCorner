#include<iostream>

using namespace std;

class TV {
    public:
        void turnOn() {
            cout << "Turning On TV" << endl;
        }
        void playMovie(string movieName) {
            cout << "playing movie " << movieName << endl;
        }
        void turnOff() {
            cout << "Turning Off TV" << endl;
        }
};

class Speaker {
    public:
        void turnOn() {
            cout << "Turning On Speaker" << endl;
        }
        void setVolume(int volume) {
            cout << "Setting volume to " << volume << endl;
        }
        void turnOff() {
            cout << "Turning Off Speaker" << endl;
        }
};

class PlayMovieFacade {
    private:
        TV* tv;
        Speaker* speaker;
    public:
        PlayMovieFacade(TV* tv, Speaker* speaker) {
            this->tv = tv;
            this->speaker = speaker;
        }
        void playMovie() {
            tv->turnOn();
            speaker->turnOn();
            speaker->setVolume(80);
            tv->playMovie("YJHD");
        }
        void stopMovie() {
            speaker->turnOff();
            tv->turnOff();
        }
};

int main() {
    TV* tv = new TV();
    Speaker* speaker = new Speaker();
    PlayMovieFacade* playMoviefacade = new PlayMovieFacade(tv, speaker);
    
    playMoviefacade->playMovie();
    playMoviefacade->stopMovie();
    
    delete playMoviefacade;
    delete speaker;
    delete tv;
    return 0;
}