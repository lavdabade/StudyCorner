#include<iostream>

using namespace std;

class SignalContext;

class State {
    public:
        virtual void getState() = 0;
        virtual void setNextState(SignalContext* signalContext) = 0;
        virtual ~State() {}
};

class RedSignal : public State {
    public: 
        void getState() {
            cout << "Current state is red" << endl;
        }
        void setNextState(SignalContext* signalContext);
};

class YellowSignal : public State {
    public: 
        void getState() {
            cout << "Current state is yellow" << endl;
        }
        void setNextState(SignalContext* signalContext);
};

class GreenSignal : public State {
    public: 
        void getState() {
            cout << "Current state is green" << endl;
        }
        void setNextState(SignalContext* signalContext);
};


class SignalContext {
    private:
        State* state;
    
    public:
        SignalContext() {
            state = new RedSignal();
        }
        void setSignalState(State* state) {
            this->state = state;
        }
        void setNextState() {
            state->setNextState(this);
        }
        void getCurrentState() {
            state->getState();
        }
};

void GreenSignal::setNextState(SignalContext* signalContext) {
    signalContext->setSignalState(new YellowSignal());
}
void RedSignal::setNextState(SignalContext* signalContext) {
    signalContext->setSignalState(new GreenSignal());
}
void YellowSignal::setNextState(SignalContext* signalContext) {
    signalContext->setSignalState(new RedSignal());
}

int main() {
    SignalContext* signalContext = new SignalContext();
    signalContext->getCurrentState();
    signalContext->setNextState();
    signalContext->getCurrentState();
    signalContext->setNextState();
    signalContext->getCurrentState();
    signalContext->setNextState();
    signalContext->getCurrentState();
    signalContext->setNextState();
    signalContext->getCurrentState();
    signalContext->setNextState();
    delete signalContext;
    return 0;
}