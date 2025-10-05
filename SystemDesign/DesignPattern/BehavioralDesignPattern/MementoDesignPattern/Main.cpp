#include<iostream>

using namespace std;

class Editor {
    private:
        string name;
    public:
        void setName(string name) {
            this->name = name;
        }
        string getName() {
            return name;
        }
};

class EditorMemento {
    private:
        string name;
    public:
        EditorMemento() {}
        EditorMemento(Editor* editor) {
            this->name = editor->getName();
        }
        string getName() {
            return name;
        }
};

class CareTaker {
    private:
        stack<EditorMemento*> st;
    public:
        void save(Editor* editor) {
            st.push(new EditorMemento(editor));
        }
        void undo(Editor* editor) {
            EditorMemento* top = st.top();
            editor->setName(top->getName());
            st.pop();
            delete top;
        }
};

int main() {
    Editor* editor = new Editor();
    CareTaker* careTaker = new CareTaker();

    editor->setName("Lav");
    cout << "Setted name as " << editor->getName() << endl;
    
    careTaker->save(editor);
    cout << "Saved name as " << editor->getName() << endl;
    
    editor->setName("LavDabade");
    cout << "Setted name as " << editor->getName() << endl;

    editor->setName("Lav Dabade");
    cout << "Setted name as " << editor->getName() << endl;

    careTaker->save(editor);
    cout << "Saved name as " << editor->getName() << endl;

    careTaker->undo(editor);
    cout << "Performed undo operation : current name is " << editor->getName() << endl;

    careTaker->undo(editor);
    cout << "Performed undo operation : current name is " << editor->getName() << endl;
    
    delete careTaker;
    delete editor;
    
    return 0;
}