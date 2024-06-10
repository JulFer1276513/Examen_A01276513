#include <iostream>
using namespace std;



class Posicion {
private:
    int posX;
    int posY;


public:
    Posicion() {}

    Posicion(int x, int y) {
        if (x > 1280) {
            posX = 0;
        } else {
            posX = x;
          ]
          
        if (x < 0) {
            posX = 0;
        } else {
            posX = x;
            ]
          
        if (y < 0) {
            posY = 0;
        } else {
            posY = y;
        }
          
        if (y > 720) {
            posY = 0;
        } else {
            posY = y;
        }
    }

      

    int getPosX() const { return posX; }
    int getPosY() const { return posY; }

    void setPosX(int x) {
        if (x < 0) {
            posX = 0;
        } else {
            posX = x;
        }
        if (x > 1280) {
            posX = 0;
        } else {
            posX = x;
        }
    }
      

    void setPosY(int y) {
        if (y < 0) {
            posY = 0;
        } else {
            posY = y;
        }
        if (y > 720) {
            posY = 0;
        } else {
            posY = y;
        }
    }
      

    void imprime() const {
        cout << "La Posicion tiene coordenadas: (" << posX << ", " << posY << ")" << endl;
    }
      

    int igual(const Posicion& otra) const {
      if (posX == otra.posX && posY == otra.posY) {
            return 1;
        } else {
            return 0;
        }
    }
};




class Personaje {
private:
    string nombre;
    Posicion pos;


public:
    Personaje() : nombre(""), pos() {}
    Personaje(const string& nombre, const Posicion& pos) : nombre(nombre), pos(pos) {
    }


    string getNombre() const { return nombre; }
    Posicion getPosicion() const { return pos; }


    void setNombre(const string& NombreActual) { nombre = NombreActual; }
    void setPosicion(const Posicion& PosActual) { pos = PosActual; }


    void imprime() const {
        cout << "El Nombre Actualizado del personaje es: " << nombre << endl;
        pos.imprime();
    }


    void avanzaHorz(int Movimiento) {
        int PosActualenX = pos.getPosX() + Movimiento;
        pos.setPosX(PosActualenX);
    }
};




//void llenaArreglo(TipoDato arr[], int num){
void llenaArreglo(Personaje arr[], int NUM) {
    for (int i = 0; i < NUM; ++i) {
        string nombre;
        int x, y;
        cout << "Ingrese el nombre del personaje " << i + 1 << ": ";
        cin >> nombre;
        cout << "Ingrese la posicion en X del " << i + 1 << " personaje: ";
        cin >> x;
        cout << "Ingrese la posicion en Y del " << i + 1 << " personaje: ";
        cin >> y;
        arr[i] = Personaje(nombre, Posicion(x, y));
    }
}



//void imprime/Llena(TipoDato arr[], int 
void imprimeArreglo(const Personaje arr[], int NUM) {
    for (int i = 0; i < NUM; ++i) {
        cout << "Personaje " << i + 1 << ":" << std::endl;
        arr[i].imprime();
    }
}



int main() {
    const int NUM = 3; 
    Personaje arreglo[NUM]; 
  

    llenaArreglo(arreglo, NUM);

    
    cout << "Datos de los Personajes:" << endl;
    imprimeArreglo(arreglo, NUM);

  
    arreglo[0].avanzaHorz(15);
    cout << "Después de avanzar, la Posicion Actual del Personaje es:" << endl;
    arreglo[0].imprime();


  
    if (arreglo[0].getPosicion().igual(arreglo[NUM - 1].getPosicion())) {
        cout << "El primer y el último Personaje se encuentran en la misma posición." << endl;
    } else {
        cout << "El primer y último Personaje no se encuentran en la misma posición." << endl;
    }

    return 0;
}
