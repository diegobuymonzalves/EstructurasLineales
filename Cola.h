#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include "Lista.h"

template<typename TIPOCOLA>
class Cola: private Lista<TIPOCOLA> {
public:
   void enqueue(const TIPOCOLA &datos) {
      Lista<TIPOCOLA>::insertarAlFinal(datos);
   }

   bool dequeue(TIPOCOLA &datos) {
      return Lista<TIPOCOLA>::eliminarDelFrente(datos);
   }

   bool estaListaVacia() const {
      return Lista<TIPOCOLA>::estaVacia();
   }

   void imprimirCola() const {
      Lista<TIPOCOLA>::imprimir();
   }
};

#endif // COLA_H_INCLUDED
