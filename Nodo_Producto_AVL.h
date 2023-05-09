#pragma once
#include <iostream>
#include "Nodo_Marca_ARN.h"

using namespace std;

class Nodo_Producto { //AVL

	private:
		
		int FB;
		int codProducto;
		string nombre;
		Nodo_Producto * hDer;
		Nodo_Producto * hIzq;
		puntero_Marca dirMarcas;
		
	public:
		
		Nodo_Producto ();
		Nodo_Producto (int codProducto, string nombre);
		void insertProducto (Nodo_Producto * &nodo, bool & Hh, int &codProducto, string &nombre);
		Nodo_Producto * buscarProducto (int &codProducto);
		string toString ();
		
		void setFB(int FB);
		void setnombre (string nombre);
		void setHDer (Nodo_Producto * hijoDer);
		void setHIzq (Nodo_Producto * hijoIzq);
		void setMarcas (puntero_Marca pMarcas);
		void setCodigo(int pCodigo);
		
		string inOrden_Producto();
		string imrpimir_Arbol ();
		
		
		void revisar_Gondola (Arbol_Inventario & pArbol, int & pCodPasillo);
		
		int getFB();
		int getCodProducto ();
		string getNombre ();
		Nodo_Producto * getHDer ();
		Nodo_Producto * getHIzq ();
		puntero_Marca getMarcas ();
};

typedef Nodo_Producto * puntero_Producto;

void rotSimpleDer_Cur (puntero_Producto &nodo, puntero_Producto &n1);
void rotSimpleIzq_Cur (puntero_Producto &nodo, puntero_Producto &n1);
void rotDobleDer_Cur (puntero_Producto &nodo, puntero_Producto &n1);
void rotDobleIzq_Cur (puntero_Producto &nodo, puntero_Producto &n1);

void equilibrar_Uno_Vent(Nodo_Producto*& pNodo, bool& pHh);
void equilibrar_Dos_Vent(Nodo_Producto*& pNodo, bool& pHh);
void borrar_Vent(Nodo_Producto*& pProducto_Sustituto, Nodo_Producto*& pNodo, bool& pHh);
void borrar_Producto_Vent(Nodo_Producto*& pNodo, bool& pHh, int& pCodProducto);