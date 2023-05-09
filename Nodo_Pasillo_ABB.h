#pragma once
#include <iostream>
#include "Nodo_Producto_AVL.h"

using namespace std;

class Nodo_Pasillo { //ABB
	
	private:
		int codPasillo; 
		string nombre;
		Nodo_Pasillo * hDer;
		Nodo_Pasillo * hIzq;
		puntero_Producto dirProductos;
	public:
		Nodo_Pasillo ();
		Nodo_Pasillo (int &codPasillo, string &nombre);
		void insert (int &codPasillo, string &nombre);
		Nodo_Pasillo * buscarPasillo (int &codPasillo);

		void borrar(int& pCodPasillo, Nodo_Pasillo*& pPasillo, Nodo_Pasillo*& pPasilloAux);

		void setHDer (Nodo_Pasillo * hijoDer);
		void setHIzq (Nodo_Pasillo * hijoIzq);
		void setDirProductos (puntero_Producto dirProductos);
		
		Nodo_Pasillo * getHDer ();
		Nodo_Pasillo * getHIzq ();
		puntero_Producto getProductos ();
		
		string inOrden_Pasillos ();
		string imrpimir_Arbol ();
		
		void revisar_Gondola (Arbol_Inventario & pArbol);
		
		
	friend class Nodo_Producto;

};
typedef Nodo_Pasillo * puntero_Pasillo;