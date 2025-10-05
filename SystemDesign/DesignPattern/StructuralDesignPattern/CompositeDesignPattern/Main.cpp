#include<iostream>

using namespace std;

class FileSystemNode {
    protected:
        string name;
    public:
        virtual void printFileSystemNode(int indent = 0) = 0;
};

class File : public FileSystemNode {
    public:
        File(string name) {
            FileSystemNode::name = name;
        }
        void printFileSystemNode(int indent = 0) {
            cout << string(indent, ' ') << name << endl;
        }
};

class Folder : public FileSystemNode {
    private:
        vector<FileSystemNode*> fileSystemNodeList;
    public:
        Folder(string name) {
            FileSystemNode::name = name;
        }
        void printFileSystemNode(int indent = 0) {
            cout << string(indent, ' ') << name << endl;
            for(auto it: fileSystemNodeList) {
                it->printFileSystemNode(indent+2);
            }
        }
        void addFileSystemNode(FileSystemNode* fileSystemNode) {
            fileSystemNodeList.push_back(fileSystemNode);
        }
};

int main() {
    Folder* root = new Folder("ROOT");
    Folder* systemDesign = new Folder("System Design");
    Folder* dsaSheet = new Folder("DSA sheet");

    File* striver = new File("Striver");
    File* loveBabbar = new File("Love Babbar");
    File* hld = new File("HLD");
    File* lld = new File("LLD");
    
    root->addFileSystemNode(systemDesign);
    root->addFileSystemNode(dsaSheet);
    systemDesign->addFileSystemNode(hld);
    systemDesign->addFileSystemNode(lld);
    dsaSheet->addFileSystemNode(striver);
    dsaSheet->addFileSystemNode(loveBabbar);
    root->printFileSystemNode();
    
    delete lld;
    delete hld;
    delete loveBabbar;
    delete striver;
    delete dsaSheet;
    delete systemDesign;
    delete root;

    return 0;
}