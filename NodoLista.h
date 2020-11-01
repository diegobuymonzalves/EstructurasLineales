#ifndef NODOLISTA_H_INCLUDED
#define NODOLISTA_H_INCLUDED

template<typename TIPONODO> class Lista;

template<typename TIPONODO>
class NodoLista
{
   friend class Lista<TIPONODO>;

public:
   explicit NodoLista(const TIPONODO &info)
   : datos(info), siguientePtr(nullptr) {
       //vacio
   }
   TIPONODO obtenerDatos() const {return this->datos;}

private:
   TIPONODO datos;
   NodoLista<TIPONODO> *siguientePtr;
};

#endif
