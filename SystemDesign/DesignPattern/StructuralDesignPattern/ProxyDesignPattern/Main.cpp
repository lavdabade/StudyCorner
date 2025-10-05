#include<iostream>

using namespace std;

class Image {
    private:
        string name;
    public:
        Image(string name) {
            this->name = name;
        }
        void loadImageFromDisk() {
            cout << "Loading Image " << name << " from Disk " << endl;
        }

};

class ProxyImage {
    private:
        Image* image;
        bool authorised;
        void checkIsRequestAuthorised() {
            authorised = true;
        }
    public:
        ProxyImage() {
            image = NULL;
        }
        void loadImageFromDisk(string name) {
            checkIsRequestAuthorised();
            if(!authorised) {
                cout << "Unauthorised access..." << endl;
                return;
            }
            if(!image) image = new Image(name);
            image->loadImageFromDisk();
        }
        ~ProxyImage() {
            delete image;
        }
};

int main() {
    ProxyImage* proxyImage = new ProxyImage();
    proxyImage->loadImageFromDisk("Lav.jpeg");
    delete proxyImage;
    return 0;
}