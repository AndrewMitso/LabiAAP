#include <iostream>
#include <string>

using namespace std;

class Automobile {
protected:
    string model;
    int maxSpeed;

public:
    Automobile(const string& _model, int _maxSpeed) : model(_model), maxSpeed(_maxSpeed) {}

    virtual void printParameters() {
        cout << "Model: " << model << endl;
        cout << "Max Speed: " << maxSpeed << " km/h" << endl;
    }
};

class Truck : public Automobile {
private:
    double loadCapacity;

public:
    Truck(const string& _model, int _maxSpeed, double _loadCapacity)
        : Automobile(_model, _maxSpeed), loadCapacity(_loadCapacity) {}

    void printParameters() override {
        Automobile::printParameters();
        cout << "Load Capacity: " << loadCapacity << " tons" << endl;
    }
};

int main() {
    Automobile car("Sedan", 180);
    Truck truck("Ford F-150", 160, 2.5);

    Automobile* vehicle1 = &car;
    Automobile* vehicle2 = &truck;

    vehicle1->printParameters();
    cout << "------------------------" << endl;
    vehicle2->printParameters();

    return 0;
}
