#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <iostream>
#include "NodoLista.h"

template<typename TIPONODO>
class Lista
{
public:
   Lista()
   : primeroPtr(nullptr), ultimoPtr(nullptr) {
       //vacio
   }
    ~Lista() {
        if (!estaVacia()) {
            NodoLista<TIPONODO> *actualPtr = primeroPtr;
            NodoLista<TIPONODO> *tempPtr = nullptr;

            while (actualPtr != nullptr){
                tempPtr = actualPtr;
                actualPtr = actualPtr->siguientePtr;
                delete tempPtr;
            }
        }
    }
   void insertarAlFrente(const TIPONODO &);
   void insertarAlFinal(const TIPONODO &);
   bool eliminarDelFrente(TIPONODO &);
   bool eliminarDelFinal(TIPONODO &);
   bool estaVacia() const;
   void imprimir() const;
private:
   NodoLista<TIPONODO> *primeroPtr;
   NodoLista<TIPONODO> *ultimoPtr;
   NodoLista<TIPONODO> *obtenerNuevoNodo(const TIPONODO &);
};

template<typename TIPONODO>
void Lista<TIPONODO>::insertarAlFrente(const TIPONODO &valor) {
   NodoLista<TIPONODO> *nuevoPtr = obtenerNuevoNodo(valor);

   if (estaVacia())
      primeroPtr = ultimoPtr = nuevoPtr;
   else {
      nuevoPtr->siguientePtr = primeroPtr;
      primeroPtr = nuevoPtr;
   }
}

template<typename TIPONODO>
void Lista<TIPONODO>::insertarAlFinal(const TIPONODO &valor) {
   NodoLista<TIPONODO> *nuevoPtr = obtenerNuevoNodo(valor);

   if (estaVacia())
      primeroPtr = ultimoPtr = nuevoPtr;
   else {
      ultimoPtr->siguientePtr = nuevoPtr;
      ultimoPtr = nuevoPtr;
   }
}

template<typename TIPONODO>
bool Lista<TIPONODO>::eliminarDelFrente(TIPONODO &valor) {
   if (estaVacia())
      return false;
   else {
      NodoLista<TIPONODO> *tempPtr = primeroPtr;

      if (primeroPtr == ultimoPtr)
         primeroPtr = ultimoPtr = nullptr;
      else
         primeroPtr = primeroPtr->siguientePtr;

      valor = tempPtr->datos;
      delete tempPtr;
      return true;
   }
}

template<typename TIPONODO>
bool Lista<TIPONODO>::eliminarDelFinal(TIPONODO &valor)
{
   if (estaVacia())
      return false;
   else {
      NodoLista<TIPONODO> *tempPtr = ultimoPtr;

      if (primeroPtr == ultimoPtr)
         primeroPtr = ultimoPtr = nullptr;
      else {
         NodoLista<TIPONODO> *actualPtr = primeroPtr;

         while (actualPtr->siguientePtr != ultimoPtr)
            actualPtr = actualPtr->siguientePtr;

         ultimoPtr = actualPtr;
         actualPtr->siguientePtr = nullptr;
      }

      valor = tempPtr->datos;
      delete tempPtr;
      return true;
   }
}

template<typename TIPONODO>
bool Lista<TIPONODO>::estaVacia() const {
   return primeroPtr == nullptr;
}

template<typename TIPONODO>
NodoLista<TIPONODO> *Lista<TIPONODO>::obtenerNuevoNodo(
   const TIPONODO &valor) {
   return new NodoLista<TIPONODO>(valor);
}

template<typename TIPONODO>
void Lista<TIPONODO>::imprimir() const {
   if (estaVacia()) {
      std::cout << "Estructura vacia\n\n";
      return;
   } // fin de if

   NodoLista<TIPONODO> *actualPtr = primeroPtr;

   std::cout << "Cotenido actual de la estructura:\n";

   while (actualPtr != nullptr) {
      std::cout << '[' << actualPtr->datos << "]->";
      actualPtr = actualPtr->siguientePtr;
   }

   std::cout << "nullptr\n\n";
}

#endif // LISTA_H_INCLUDED
