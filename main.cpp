#include <iostream>
#include <string>
#include <exception>

#include "Lista.h"
#include "Pila.h"
#include "Cola.h"

void instruccionesLista();
void instruccionesPila();
void instruccionesCola();
template <typename T>
int probarLista(Lista<T> &objetoLista);
template <typename T>
int probarPila(Pila<T> &objetoPila);
template <typename T>
int probarCola(Cola<T> &objetoCola);

int main() {
   Lista<int> listaEnteros;
   Pila<int> pilaEnteros;
   Cola<int> colaEnteros;

   std::string dataIn;
   int tipoEstructura = 0;

    while(tipoEstructura == 0) {
        std::cout << "Estructuras lineales (Pilas, Colas y Listas). Elige una opcion:\n"
                  << "  lista -> ir a la estructura Lista\n"
                  << "  pila  -> ir a la estructura Pila\n"
                  << "  cola  -> ir a la estructura Cola\n"
                  << "  fin   -> finalizar programa\n"
                  << "estructura> ";

        std::cin >> dataIn;
        if(dataIn == "lista")
            tipoEstructura = 1;
        else if(dataIn == "pila")
            tipoEstructura = 2;
        else if(dataIn == "cola")
            tipoEstructura = 3;
        else if(dataIn == "fin")
            return 0;
        else
            std::cout << "opcion incorrecta." << std::endl;
    }

   while(tipoEstructura != 0) {
        switch(tipoEstructura) {
            case 1:
                tipoEstructura = probarLista(listaEnteros);
                break;
            case 2:
                tipoEstructura = probarPila(pilaEnteros);
                break;
            case 3:
                tipoEstructura = probarCola(colaEnteros);
                break;
        }
   }
   return 0;
}

template<typename T>
int probarLista(Lista<T> &objetoLista) {
   instruccionesLista();

   int opcion;
   std::string dataIn;
   T valor;

   while(true) {
      std::cout << "lista> ";
      std::cin >> dataIn;
      if(dataIn == "pila")
        return 2;
      else if(dataIn == "cola")
        return 3;
      else if(dataIn == "fin")
        return 0;
      try {
          opcion = std::stoi(dataIn);
      } catch(std::invalid_argument &exp) {
          std::cout << "opcion incorrecta" << std::endl;
          continue;
      }

      switch (opcion) {
         case 1: // inserta al principio
            std::cout << "numero entero> ";
            std::cin >> valor;
            objetoLista.insertarAlFrente(valor);
            objetoLista.imprimir();
            break;
         case 2: // inserta al final
            std::cout << "numero entero> ";
            std::cin >> valor;
            objetoLista.insertarAlFinal(valor);
            objetoLista.imprimir();
            break;
         case 3: // elimina del principio
            if (objetoLista.eliminarDelFrente(valor))
               std::cout << valor << " se elimino de la lista\n";
            objetoLista.imprimir();
            break;
         case 4: // elimina del final
            if (objetoLista.eliminarDelFinal(valor))
               std::cout << valor << " se elimino de la lista\n";
            objetoLista.imprimir();
            break;
         default:
            std::cout << "opcion incorrecta" << std::endl;
      }
   }
   return 0;
}

template<typename T>
int probarPila(Pila<T> &objetoPila) {
   instruccionesPila();

   int opcion;
   std::string dataIn;
   T valor;

   while(true) {
      std::cout << "pila> ";
      std::cin >> dataIn;
      if(dataIn == "lista")
        return 1;
      else if(dataIn == "cola")
        return 3;
      else if(dataIn == "fin")
        return 0;
      try {
          opcion = std::stoi(dataIn);
      } catch(std::invalid_argument &exp) {
          std::cout << "opcion incorrecta" << std::endl;
          continue;
      }

      switch (opcion) {
         case 1:
            std::cout << "numero entero> ";
            std::cin >> valor;
            objetoPila.push(valor);
            objetoPila.imprimirPila();
            break;
         case 2:
            if (objetoPila.pop(valor))
               std::cout << valor << " se saco de la pila\n";
            objetoPila.imprimirPila();
            break;
        default:
            std::cout << "opcion incorrecta" << std::endl;
      }
   }
   return 0;
}

template<typename T>
int probarCola(Cola<T> &objetoCola) {
   instruccionesCola();

   int opcion;
   std::string dataIn;
   T valor;

   while(true) {
        std::cout << "cola> ";
        std::cin >> dataIn;
        if(dataIn == "lista")
            return 1;
        else if(dataIn == "pila")
            return 2;
        else if(dataIn == "fin")
            return 0;

      try {
          opcion = std::stoi(dataIn);
      } catch(std::invalid_argument &exp) {
          std::cout << "opcion incorrecta" << std::endl;
          continue;
      }

      switch (opcion) {
         case 1:
            std::cout << "numero entero> ";
            std::cin >> valor;
            objetoCola.enqueue(valor);
            objetoCola.imprimirCola();
            break;
         case 2: // elimina del principio
            if (objetoCola.dequeue(valor))
               std::cout << valor << " se elimino de la cola\n";
            objetoCola.imprimirCola();
            break;
        default:
            std::cout << "opcion incorrecta" << std::endl;
      }
   }
   return 0;
}

void instruccionesLista() {
   std::cout << "Estructura de dato lineal Lista.\nElige una opcion:\n"
   << "  1    -> insertar al principio\n"
   << "  2    -> insertar al final\n"
   << "  3    -> eliminar del principio\n"
   << "  4    -> eliminar del final\n"
   << "  fin  -> finalizar programa\n"
   << "  pila -> ir a la estructura Pila\n"
   << "  cola -> ir a la estructura Cola" << std::endl;
}
void instruccionesPila() {
    std::cout << "Estructura de dato lineal Pila.\nElige una opcion:\n"
    << "  1     -> agregar\n"
    << "  2     -> sacar\n"
    << "  fin   -> finalizar programa\n"
    << "  lista -> ir a la estructura Lista\n"
    << "  cola  -> ir a la estructura Cola"<< std::endl;
}
void instruccionesCola() {
    std::cout << "Estructura de dato lineal Cola.\nElige una opcion:\n"
    << "  1     -> enqueue\n"
    << "  2     -> dequeue\n"
    << "  fin   -> finalizar programa\n"
    << "  pila  -> ir a la estructura Pila\n"
    << "  lista -> ir a la estructura Lista"<< std::endl;
}
