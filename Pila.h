#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include "Lista.h"

template<typename TIPOPILA>
class Pila : private Lista<TIPOPILA> {
public:
   void push(const TIPOPILA &datos) {
      Lista<TIPOPILA>::insertarAlFrente(datos);
   }

   bool pop(TIPOPILA &datos) {
      return Lista<TIPOPILA>::eliminarDelFrente(datos);
   }

   bool estaPilaVacia() const {
      return Lista<TIPOPILA>::estaVacia();
   }

   void imprimirPila() const {
      Lista<TIPOPILA>::imprimir();
   }
};

#endif
