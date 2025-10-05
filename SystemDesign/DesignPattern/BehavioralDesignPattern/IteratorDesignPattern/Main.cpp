#include<iostream>

using namespace std;

class MusicPlayer {
    private:
        vector<pair<string, bool>> songsList;
    public:
        vector<pair<string, bool>> getSongsList() {
            return songsList;
        }
        void addSong(string songName, bool isFav = false) {
            songsList.push_back({songName, isFav});
        }
};

class Iterator {
    public:
        virtual bool hasNext() = 0;
        virtual void next() = 0;
};

class SimpleIterator : public Iterator{
    private:
        MusicPlayer* musicPlayer;
        int idx;
    public:
        SimpleIterator(MusicPlayer* musicPlayer) {
            idx=0;
            this->musicPlayer = musicPlayer;
        } 
        bool hasNext() {
            return musicPlayer->getSongsList().size() > idx;
        }
        void next() {
            cout << musicPlayer->getSongsList()[idx].first << endl;
            idx++;
        }
};

class ReverseIterator : public Iterator{
    private:
        MusicPlayer* musicPlayer;
        int idx;
    public:
        ReverseIterator(MusicPlayer* musicPlayer) {
            idx=musicPlayer->getSongsList().size()-1;
            this->musicPlayer = musicPlayer;
        } 
        bool hasNext() {
            return idx>=0;
        }
        void next() {
            cout << musicPlayer->getSongsList()[idx].first << endl;
            idx--;
        }
};

class FavoriteIterator : public Iterator{
    private:
        MusicPlayer* musicPlayer;
        int idx;
    public:
        FavoriteIterator(MusicPlayer* musicPlayer) {
            idx=0;
            this->musicPlayer = musicPlayer;
        } 
        bool hasNext() {
            int tempIdx = idx;
            while(tempIdx < musicPlayer->getSongsList().size()) {
                if(musicPlayer->getSongsList()[tempIdx].second) {
                    return true;
                }
                tempIdx++;
            }
            return false;
        }
        void next() {
            while(idx < musicPlayer->getSongsList().size()) {
                if(musicPlayer->getSongsList()[idx].second) {
                    break;
                }
                idx++;
            }
            if(idx < musicPlayer->getSongsList().size()) {
                cout << musicPlayer->getSongsList()[idx].first << endl;
                idx++;
            }
        }
};

int main() {
    MusicPlayer* musicPlayer = new MusicPlayer();
    musicPlayer->addSong("A");
    musicPlayer->addSong("B", true);
    musicPlayer->addSong("c");
    musicPlayer->addSong("D", true);
    musicPlayer->addSong("E");
    musicPlayer->addSong("F");
    musicPlayer->addSong("G");
    musicPlayer->addSong("H", true);
    cout << "---------------------------------------" << endl;
    cout << "Simple Iterator" << endl;
    cout << "---------------------------------------" << endl;
    Iterator* simpleIterator = new SimpleIterator(musicPlayer);
    while(simpleIterator->hasNext()) {
        simpleIterator->next();
    }
    cout << "---------------------------------------" << endl;
    cout << "Reverse Iterator" << endl;
    cout << "---------------------------------------" << endl;
    Iterator* reverseIterator = new ReverseIterator(musicPlayer);
    while(reverseIterator->hasNext()) {
        reverseIterator->next();
    }
    cout << "---------------------------------------" << endl;
    cout << "Favorite Iterator" << endl;
    cout << "---------------------------------------" << endl;
    Iterator* favoriteIterator = new FavoriteIterator(musicPlayer);
    while(favoriteIterator->hasNext()) {
        favoriteIterator->next();
    }
    return 0;
}