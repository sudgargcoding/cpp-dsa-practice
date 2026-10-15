#include <iostream>
#include <stdexcept>

using namespace std;

class Elevator {
public:
    enum class State {
        IDLE,
        MOVING_UP,
        MOVING_DOWN,
        DOOR_OPEN
    };

private:
    State state;
    int currentFloor;

public:
    Elevator() : state(State::IDLE), currentFloor(0) {}

    void moveTo(int targetFloor) {
        if (state == State::DOOR_OPEN)
            throw runtime_error("Cannot move with door open.");

        if (targetFloor == currentFloor) {
            cout << "Already on floor " << currentFloor << endl;
            return;
        }

        if (targetFloor > currentFloor) {
            state = State::MOVING_UP;
        } else {
            state = State::MOVING_DOWN;
        }

        cout << "Moving from "
             << currentFloor
             << " to "
             << targetFloor
             << endl;

        currentFloor = targetFloor;

        arrive();
    }

    void openDoor() {
       transitionTo(State::DOOR_OPEN);
    }

    void closeDoor() {
        transitionTo(State::IDLE);
    }

    void arrive() {
        transitionTo(State::IDLE);
    }
};

void transitionTo(State next) {
    switch (state) {
        case State::IDLE:
            if (next != State::MOVING_UP &&
                next != State::MOVING_DOWN &&
                next != State::DOOR_OPEN)
                throw runtime_error("Invalid transition");
            break;

        case State::MOVING_UP:
        case State::MOVING_DOWN:
            if (next != State::IDLE)
                throw runtime_error("Must arrive before changing state");
            break;

        case State::DOOR_OPEN:
            if (next != State::IDLE)
                throw runtime_error("Close door first");
            break;
    }

    state = next;
}

int main() {

    Elevator e;

    e.moveTo(5);

    e.openDoor();

    e.closeDoor();

    e.moveTo(2);

    e.openDoor();
}