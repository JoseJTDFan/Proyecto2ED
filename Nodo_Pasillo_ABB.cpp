#include "Nodo_Pasillo_ABB.h"


Nodo_Pasillo::Nodo_Pasillo() {
		codPasillo = 0; 
		nombre = "";
		hDer = NULL; 
		hIzq = NULL;
		dirProductos = NULL;
	}

Nodo_Pasillo::Nodo_Pasillo(int &codPasillo, string &nombre) {
		this->codPasillo = codPasillo; 
		this->nombre = nombre;
		hDer = NULL; 
		hIzq = NULL;
		dirProductos = NULL;
	}

void Nodo_Pasillo::insert (int &codPasillo, string &nombre)
{
	if (this->codPasillo >= codPasillo) {
        if (this->getHIzq () == NULL) {this->setHIzq (new Nodo_Pasillo (codPasillo, nombre));} 
		else {this->getHIzq ()->insert (codPasillo, nombre);}
    } else {
        if (this->getHDer () == NULL) {this->setHDer (new Nodo_Pasillo (codPasillo, nombre));} 
		else {this->getHDer ()->insert (codPasillo, nombre);}
    }
}

Nodo_Pasillo * Nodo_Pasillo::buscarPasillo (int &codPasillo)
{
	if (this->codPasillo == codPasillo) return this;
	
	if (this->codPasillo < codPasillo) {
		if (this->getHDer () == NULL) 
			return NULL;
		else 
			return this->getHDer ()->buscarPasillo (codPasillo);
	} else {
		if (this->getHIzq () == NULL) 
			return NULL;
		else 
			return this->getHIzq ()->buscarPasillo (codPasillo);
	}
}

void Nodo_Pasillo::borrar(int& pCodPasillo, Nodo_Pasillo*& pPasillo, Nodo_Pasillo*& pPasilloAux) //(int &pCodPasillo, Nodo_Pasillo_Inventario* &pPasillo, Nodo_Pasillo_Inventario* &pPasilloAux)
{
	puntero_Pasillo pasillo_Aux;
	if (pPasillo->codPasillo == pCodPasillo) {

		if (pPasillo->hDer == NULL && pPasillo->hIzq == NULL) {
			pasillo_Aux = pPasillo;
			pPasillo = NULL;
			pPasilloAux = NULL;
			delete pasillo_Aux;
			return;
		}
		if (pPasillo->hDer == NULL) {
			pasillo_Aux = pPasillo;
			pPasilloAux = pPasillo->hIzq;
			delete pasillo_Aux;
			return;
		}
		if (pPasillo->hIzq == NULL || pPasillo->hDer->hIzq == NULL) {
			pasillo_Aux = pPasillo;
			pPasilloAux = pPasillo->hDer;
			pPasilloAux->hIzq = pPasillo->hIzq;
			delete pasillo_Aux;
			return;
		}

		puntero_Pasillo pasillo_Sustituto = pPasillo->hDer;
		while (pasillo_Sustituto->hIzq != NULL)
			pasillo_Sustituto = pasillo_Sustituto->hIzq;

		pPasillo->codPasillo = pasillo_Sustituto->codPasillo;
		pPasillo->nombre = pasillo_Sustituto->nombre;

		pasillo_Aux = pPasilloAux;
		this->borrar(codPasillo, pPasillo->hDer, pasillo_Aux);
		pPasillo->hDer = pasillo_Aux;
		pPasilloAux = pPasillo;

	}
	if (pPasillo->codPasillo < pCodPasillo) {
		if (pPasillo->hDer != NULL)
		{
			pasillo_Aux = pPasilloAux;
			this->borrar(pCodPasillo, pPasillo->hDer, pasillo_Aux);
			pPasillo->hDer = pasillo_Aux;
			pPasilloAux = pPasillo;
		}
		else {
			pPasilloAux = pPasillo;
		}
	}
	else {
		if (pPasillo->hIzq != NULL)
		{
			pasillo_Aux = pPasilloAux;
			this->borrar(pCodPasillo, pPasillo->hIzq, pasillo_Aux);
			pPasillo->hIzq = pasillo_Aux;
			pPasilloAux = pPasillo;
		}
		else {
			pPasilloAux = pPasillo;
		}
	}
}


string Nodo_Pasillo::inOrden_Pasillos()
{
	string reporte = "";
	if (this->getHIzq() != NULL)
		reporte += this->getHIzq()->inOrden_Pasillos();
	reporte += "\n\tCodigo: "+to_Stiringeo(this->codPasillo)+" - Nombre: "+this->nombre;
	if (this->getHDer()!= NULL)
		reporte += this->getHDer()->inOrden_Pasillos();
	return reporte;
}

string Nodo_Pasillo::imrpimir_Arbol()
{
	string reporte = "";
	if (this->getHIzq() != NULL)
		reporte += this->getHIzq()->imrpimir_Arbol();

	reporte += "\n\n\t--------\n\tPasillo:  ";
	reporte += "Codigo: "+to_Stigear(this->codPasillo) +" - Nombre: "+this->nombre;
	reporte += "\n\t--------";
	if (this->dirProductos != NULL)
		reporte += this->dirProductos->imrpimir_Arbol();
	
	if (this->getHDer()!= NULL)
		reporte += this->getHDer()->imrpimir_Arbol();
	return reporte;
}

void Nodo_Pasillo::revisar_Gondola (Arbol_Inventario & pArbol)
{
	if (this->getHIzq() != NULL)
		this->getHIzq()->revisar_Gondola (pArbol);
		
	if (this->dirProductos != NULL)
		this->dirProductos->revisar_Gondola (pArbol, this->codPasillo);
	
	if (this->getHDer()!= NULL)
		this->getHDer()->revisar_Gondola (pArbol);
}

void Nodo_Pasillo::setHDer (Nodo_Pasillo * hijoDer) {this->hDer = hijoDer;}
void Nodo_Pasillo::setHIzq (Nodo_Pasillo * hijoIzq) {this->hIzq = hijoIzq;}
void Nodo_Pasillo::setDirProductos (puntero_Producto dirProductos) {this->dirProductos = dirProductos;}

Nodo_Pasillo * Nodo_Pasillo::getHDer () {return this->hDer;}
Nodo_Pasillo * Nodo_Pasillo::getHIzq () {return this->hIzq;}
puntero_Producto Nodo_Pasillo::getProductos() {
	return this->dirProductos;
}
