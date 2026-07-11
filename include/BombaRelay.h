#ifndef BOMBARELAY_H
#define BOMBARELAY_H

class BombaRelay {
private:
    int pin;
    bool encendida;

public:
    BombaRelay(int p);
    void encender();
    void apagar();
    bool estaActiva() const;
};
#endif