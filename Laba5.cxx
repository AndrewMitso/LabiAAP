#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const double MATERIAL_DENSITY = 2.7; 

class Prisma_Inscribed_Rectilineal_Triangular {
private:
    double a; 
    double R; 
    double H; 

public:
    Prisma_Inscribed_Rectilineal_Triangular(double _a, double _R, double _H)
        : a(_a), R(_R), H(_H) {}

    double getBaseArea() const {
        return (a * a * sqrt(3)) / 4;
    }

    double getLateralArea() const {
        return 3 * a * H;
    }

    double getTotalArea() const {
        return 2 * getBaseArea() + getLateralArea();
    }

    double getVolume() const {
        return (sqrt(3) / 4) * a * a * H;
    }

    double getWeight() const {
        return getVolume() * MATERIAL_DENSITY;
    }

    bool operator<(const Prisma_Inscribed_Rectilineal_Triangular& other) const {
        return getWeight() < other.getWeight();
    }
};

int main() {
    const int ARRAY_SIZE = 5;
    Prisma_Inscribed_Rectilineal_Triangular prisms[ARRAY_SIZE] = {
        Prisma_Inscribed_Rectilineal_Triangular(4.0, 2.0 * sin(M_PI / 3), 10.0),
        Prisma_Inscribed_Rectilineal_Triangular(6.0, 3.0 * sin(M_PI / 3), 7.5),
        Prisma_Inscribed_Rectilineal_Triangular(3.5, 1.75 * sin(M_PI / 3), 12.0),
        Prisma_Inscribed_Rectilineal_Triangular(5.0, 2.5 * sin(M_PI / 3), 8.0),
        Prisma_Inscribed_Rectilineal_Triangular(7.0, 3.5 * sin(M_PI / 3), 9.0)
    };

    sort(prisms, prisms + ARRAY_SIZE);


    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << "Призма " << (i + 1) << ":" << endl;
        cout << "Площадь основания: " << prisms[i].getBaseArea() << endl;
        cout << "Площадь боковой поверхности: " << prisms[i].getLateralArea() << endl;
        cout << "Полная площадь: " << prisms[i].getTotalArea() << endl;
        cout << "Объем: " << prisms[i].getVolume() << endl;
        cout << "Вес: " << prisms[i].getWeight() << endl;
        cout << "------------------------" << endl;
    }

    return 0;
}

