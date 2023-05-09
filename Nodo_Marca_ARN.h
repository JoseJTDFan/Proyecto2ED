#pragma once
#include <iostream>
#include "Arboles_Inventario.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string> 
#include <sstream>

using namespace std;

class Nodo_Marca { //ARN
	private:
		bool rojo;
		int codMarca, cantGondola, precio;
		string nombre;
		Nodo_Marca* padre;
		Nodo_Marca* hDer;
		Nodo_Marca* hIzq;
	public:
		Nodo_Marca ();
		Nodo_Marca (int codMarca, int cantGondola, int precio, string nombre);
		void insertMarca (Nodo_Marca* &nodo, bool  Hh, int codMarca, int cantGondola, int precio, string nombre);
		Nodo_Marca * buscarMarca (int codMarca);
		void mostrarMarca();
		bool verificarMarca(bool i, int codMarca);
		
		void setRojo (bool rojo);
		void setPrecio (int pPrecio);
		void setNombre (string pNombre);
		void setPadre (Nodo_Marca * padre);
		void setHDer (Nodo_Marca * hijoDer);
		void setHIzq (Nodo_Marca * hijoIzq);
		//void setPrecio(int precio);
		void setCantGondola(int cantidad);
		void setCodigo(int pCodigo);
		
		bool getRojo ();
		int getCodMarca ();
		int getCantGondola();
		int getPrecio();
		string getNombre();
		Nodo_Marca * getPadre ();
		Nodo_Marca * getHDer ();
		Nodo_Marca * getHIzq ();
		
		string inOrden_Marca ();
		string imrpimir_Arbol ();
		
		void revisar_Gondola (Arbol_Inventario & pArbol, int & pCodPasillo, int & pCodProducto);
		
		
};

typedef Nodo_Marca * puntero_Marca;

void rotSimpleDer_Gr (puntero_Marca & nodo, puntero_Marca & n1);
void rotSimpleIzq_Gr (puntero_Marca & nodo, puntero_Marca & n1);
void rotDobleDer_Gr (puntero_Marca & nodo, puntero_Marca & n1);
void rotDobleIzq_Gr (puntero_Marca & nodo, puntero_Marca & n1);
string to_Stiringeo(int pNumero);


void equilibrar_Uno_RN(puntero_Marca& pNodo, bool& pHh, int& pCodMarca);
void equilibrar_Dos_RN(puntero_Marca& pNodo, bool& pHh, int& pCodMarca);
void borrar_RN(puntero_Marca& pProducto_Sustituto, puntero_Marca& pNodo, bool& pHh);
void borrar_Marca_RN(puntero_Marca& pNodo, bool& pHh, int& pCodMarca);
