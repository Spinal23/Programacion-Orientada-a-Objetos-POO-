#include <iostream>
#include <string>
using namespace std;

class vehiculo {
public:
    string marca;
    string modelo;
    int ano;
    double preciobase;
    double taxes;

    vehiculo(string m, string mod, int a, double pb, double t)
        : marca(m), modelo(mod), ano(a), preciobase(pb), taxes(t) {}

    virtual double calcularprecio() {
        return preciobase + (preciobase * taxes);
    }
};

class carro : public vehiculo {
public:
    int numerodepuertas;

    carro(string m, string mod, int a, double pb, double t, int np)
        : vehiculo(m, mod, a, pb, t), numerodepuertas(np) {}

    double calcularprecio() override {
        return preciobase + (preciobase * taxes);
    }
};

class moto : public vehiculo {
public:
    int cilindraje;

    moto(string m, string mod, int a, double pb, double t, int c)
        : vehiculo(m, mod, a, pb, t), cilindraje(c) {}

    double calcularprecio() override {
        return preciobase + (preciobase * taxes);
    }
};

int main() {
    carro miauto("Nissan", "Sentra", 2020, 200000, 0.15, 4);
    moto mimoto("Yamaha", "FZ", 2021, 80000, 0.10, 150);

    cout << "El precio del auto es: " << miauto.calcularprecio() << endl;
    cout << "El precio de la moto es: " << mimoto.calcularprecio() << endl;
    return 0;
}
