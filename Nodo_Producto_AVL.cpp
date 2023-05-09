#include "Nodo_Producto_AVL.h"


void rotSimpleDer_Cur (puntero_Producto &nodo, puntero_Producto &n1)
{
    nodo->setHDer(n1->getHIzq());
	n1->setHIzq(nodo);
	
    if(n1->getFB() == 1) {
        nodo->setFB(0); n1->setFB(0);
    } else {
        nodo->setFB(1); n1->setFB(-1);
    } nodo = n1;
}

void rotSimpleIzq_Cur (puntero_Producto &nodo, puntero_Producto &n1)
{
	nodo->setHIzq(n1->getHDer());
    n1->setHDer(nodo);

    if(n1->getFB()==-1) {
        nodo->setFB(0); n1->setFB(0);
    } else {
        nodo->setFB(-1); n1->setFB(-1);
    } nodo = n1;
}

void rotDobleDer_Cur (puntero_Producto &nodo, puntero_Producto &n1)
{    
	puntero_Producto n2;
    n2 = n1->getHIzq ();
    nodo->setHDer (n2->getHIzq ());
    n2->setHIzq (nodo);
    n1->setHIzq (n2->getHDer ());
    n2->setHDer (n1);

    if(n2->getFB() == 1) {nodo->setFB(-1);}	
	else {nodo->setFB(0);}
    if(n2->getFB() == -1) {n1->setFB(1);}
	else {n1->setFB(0);}
	
    n2->setFB(0); nodo = n2;
}

void rotDobleIzq_Cur (puntero_Producto &nodo, puntero_Producto &n1)
{    
	puntero_Producto n2;
    n2 = n1->getHDer();
    nodo->setHIzq (n2->getHDer ());
    n2->setHDer (nodo);
    n1->setHDer (n2->getHIzq ());
    n2->setHIzq (n1);

    if(n2->getFB() == 1) {n1->setFB(-1);} 
	else {n1->setFB(0);}
    if(n2->getFB() == -1) {nodo->setFB(1);}
	else {nodo->setFB(0);}
    
	n2->setFB(0); nodo = n2;
}

Nodo_Producto::Nodo_Producto() 
{
	this->FB = 0;
	//this->codPasillo = 0; 
	this->codProducto = 0; 
	this->nombre = "";
	this->hDer = NULL; 
	this->hIzq = NULL;
	this->dirMarcas = NULL;
}

Nodo_Producto::Nodo_Producto (int codProducto, string nombre) 
{
	this->FB = 0;
	//this->codPasillo = codPasillo; 
	this->codProducto = codProducto; 
	this->nombre = nombre;
	this->hDer = NULL; 
	this->hIzq = NULL;
	this->dirMarcas = NULL;
}

void Nodo_Producto::insertProducto (Nodo_Producto * &nodo, bool & Hh, int &codProducto, string &nombre)
{
	puntero_Producto n1, inputAux;
	if (nodo == NULL) 
		{
		nodo = new Nodo_Producto (codProducto,nombre);
		Hh = true; 
		return;
		}
	
	if (nodo->getCodProducto() < codProducto) {
		inputAux = nodo->getHDer (); 
		nodo->insertProducto (inputAux, Hh, codProducto, nombre); 
		nodo->setHDer (inputAux);
        if (Hh) {
            switch (nodo->getFB()) {
            	case -1:
            		nodo->setFB (0); Hh = false;
            		break;
            	case 0:
            		nodo->setFB (1); 
					break;
            	case 1:
					n1 = nodo->getHDer();
            		if(n1->getFB() == 1) {
            			inputAux = nodo; rotSimpleDer_Cur (inputAux, n1); nodo = inputAux;
                    } else { 
						inputAux = nodo; rotDobleDer_Cur (inputAux, n1); nodo = inputAux;
                    } Hh = false; break;
			}
		}
    } 
	else {
    	inputAux = nodo->getHIzq (); nodo->insertProducto (inputAux, Hh, codProducto, nombre); 
		nodo->setHIzq (inputAux);
        if(Hh) {
            switch (nodo->getFB ()) {
                case 1:
				    nodo->setFB (0); Hh = false;
                    break;
                case 0:
				    nodo->setFB (-1);
                    break;
                case -1:         
					n1 = nodo->getHIzq();
                    if(n1->getFB() == -1) {
						inputAux = nodo; rotSimpleIzq_Cur (inputAux, n1); nodo = inputAux;
                    } else {
						inputAux = nodo; rotDobleIzq_Cur (inputAux, n1); nodo = inputAux;
                    } Hh = false; break;
            }
        }
	}
}

Nodo_Producto * Nodo_Producto::buscarProducto (int &codProducto)
{
	if (this->codProducto == codProducto) 
		return this;
	
	if (this->codProducto < codProducto) {
		if (this->getHDer () == NULL) 
			return NULL;
		else 
			return this->getHDer ()->buscarProducto (codProducto);
	} else {
		if (this->getHIzq () == NULL) return NULL;
		else return this->getHIzq ()->buscarProducto (codProducto);
	}
}



void equilibrar_Uno_Vent(Nodo_Producto*& pNodo, bool& pHh)
{
	Nodo_Producto* producto_NUno;
	Nodo_Producto* producto_Aux;
	switch (pNodo->getFB()) {
	case -1:
		pNodo->setFB(0); //pNodo->FB = 0;
		break;
	case 0:
		pNodo->setFB(1); //pNodo->FB = 1;
		pHh = false;
		break;
	case 1:
		producto_NUno = pNodo->getHDer();
		if (producto_NUno->getFB() >= 0) {
			if (producto_NUno->getFB() == 0)
				pHh = false;
			producto_Aux = pNodo; rotSimpleDer_Cur(producto_Aux, producto_NUno); pNodo = producto_Aux;
			//RotacionSimpleDerecha(n, n1);
		}
		else {
			producto_Aux = pNodo; rotDobleDer_Cur(producto_Aux, producto_NUno); pNodo = producto_Aux;
			//RotacionDobleDerecha(n, n1);
		}
	}
}

void equilibrar_Dos_Vent(Nodo_Producto*& pNodo, bool& pHh)
{
	Nodo_Producto* producto_NUno;
	Nodo_Producto* producto_Aux;
	switch (pNodo->getFB()) {
	case 1:
		pNodo->setFB(0);//n->FB = 0;
		break;
	case 0:
		pNodo->setFB(-1);//n->FB = -1; //1;
		pHh = false;
		break;
	case -1:
		producto_NUno = pNodo->getHIzq();
		if (producto_NUno->getFB() <= 0) {
			if (producto_NUno->getFB() == 0)
				pHh = false;
			producto_Aux = pNodo; rotSimpleIzq_Cur(producto_Aux, producto_NUno); pNodo = producto_Aux;
			//RotacionSimpleIzquierda(n, n1);
		}
		else {
			producto_Aux = pNodo; rotDobleIzq_Cur(producto_Aux, producto_NUno); pNodo = producto_Aux;
			//RotacionDobleIzquierda(n, n1);
		}
	}
}

void borrar_Vent(Nodo_Producto*& pProducto_Sustituto, Nodo_Producto*& pNodo, bool& pHh)
{
	Nodo_Producto* producto_Aux = NULL;
	Nodo_Producto* sustituto_Temp = NULL;

	if (pNodo->getHDer() != NULL) {
		producto_Aux = pNodo->getHDer();
		sustituto_Temp = pNodo->getHDer();

		borrar_Vent(sustituto_Temp, producto_Aux, pHh);

		pProducto_Sustituto = sustituto_Temp;
		pNodo->setHDer(producto_Aux);  //Borrar(D->Hder, Hh);
		if (pHh) {
			if (pNodo->getHDer() == sustituto_Temp)
				pNodo->setHDer(pNodo->getHDer()->getHIzq());
			producto_Aux = pNodo; equilibrar_Dos_Vent(producto_Aux, pHh); pNodo = producto_Aux; //Equilibrar2(D, Hh); 
		}
		else { //Copia y asigna nuevo q

		}
	}
	else
		pHh = true;
}

void borrar_Producto_Vent(Nodo_Producto*& pNodo, bool& pHh, int& pCodProducto)
{
	Nodo_Producto* producto_Q = NULL;
	Nodo_Producto* producto_Aux = NULL;
	if (pNodo != NULL) {
		if (pCodProducto < pNodo->getCodProducto()) {
			producto_Aux = pNodo->getHIzq(); borrar_Producto_Vent(producto_Aux, pHh, pCodProducto); pNodo->setHIzq(producto_Aux);
			//BorrarBalanceado (pNodo->getHIzq(), pHh, pCodProducto);
			if (pHh)
			{
				producto_Aux = pNodo; equilibrar_Uno_Vent(producto_Aux, pHh); pNodo = producto_Aux;
				//Equilibrar1(raiz, Hh);
				return;
			}
		}
		else {
			if (pCodProducto > pNodo->getCodProducto()) {
				producto_Aux = pNodo->getHDer(); borrar_Producto_Vent(producto_Aux, pHh, pCodProducto); pNodo->setHDer(producto_Aux);
				//BorrarBalanceado(raiz->Hder, Hh, x);
				if (pHh)
				{
					producto_Aux = pNodo; equilibrar_Dos_Vent(producto_Aux, pHh); pNodo = producto_Aux;
					//Equilibrar2(raiz, Hh);
					return;
				}
			}
			else {
				producto_Q = pNodo;
			}
		}
		if (pCodProducto != pNodo->getCodProducto())
			return;
		if (producto_Q->getHDer() == NULL) {
			pNodo = producto_Q->getHIzq();
			pHh = true;
		}
		else {
			if (producto_Q->getHIzq() == NULL) {
				pNodo = producto_Q->getHDer();
				pHh = true;
			}
			else {

				Nodo_Producto* producto_Sustituto = pNodo->getHIzq();
				producto_Aux = pNodo->getHIzq();

				borrar_Vent(producto_Sustituto, producto_Aux, pHh);

				pNodo->setHIzq(producto_Aux);
				pNodo->setCodigo(producto_Sustituto->getCodProducto());
				pNodo->setnombre(producto_Sustituto->getNombre());

				if (producto_Sustituto == pNodo->getHIzq()) {
					pNodo->setHIzq(NULL);
					pHh = true;
				}
				producto_Q = producto_Sustituto;
			}
			if (pHh)
			{
				producto_Aux = pNodo; equilibrar_Uno_Vent(producto_Aux, pHh); pNodo = producto_Aux;
				//Equilibrar1(raiz, Hh);
			}
		}
	}
	if (producto_Q != NULL) {
		delete producto_Q;
	}
}



string Nodo_Producto::inOrden_Producto()
{
	string reporte = "";
	if (this->getHIzq() != NULL)
		reporte += this->getHIzq()->inOrden_Producto();
	reporte += "\n\tCodigo: "+to_Stiringeo(this->codProducto)+" - Nombre: "+this->nombre;
	if (this->getHDer()!= NULL)
		reporte += this->getHDer()->inOrden_Producto();
	return reporte;
}

string Nodo_Producto::imrpimir_Arbol()
{	
	string reporte = "";
	if (this->getHIzq() != NULL)
		reporte += this->getHIzq()->imrpimir_Arbol();
	reporte += "\n\n\t\t---------\n\t\tProducto\n";
	reporte += "\n\t\tCodigo: "+to_Stigear(this->codProducto) + " - Nombre: "+this->nombre;
	if (this->dirMarcas != NULL)
		reporte += this->dirMarcas->imrpimir_Arbol();
	
	if (this->getHDer()!= NULL)
		reporte += this->getHDer()->imrpimir_Arbol();
	return reporte;
}

void Nodo_Producto::revisar_Gondola (Arbol_Inventario & pArbol, int & pCodPasillo)
{
	if (this->getHIzq() != NULL)
		this->getHIzq()->revisar_Gondola (pArbol, pCodPasillo); 
	
	if (this->dirMarcas != NULL)
		this->dirMarcas->revisar_Gondola (pArbol, pCodPasillo, this->codProducto);
	
	if (this->getHDer()!= NULL)
		this->getHDer()->revisar_Gondola (pArbol, pCodPasillo);
}


void Nodo_Producto::setMarcas (puntero_Marca pMarcas) {this->dirMarcas = pMarcas;}
void Nodo_Producto::setFB (int FB) {this->FB = FB;}
void Nodo_Producto::setnombre (string nombre) {this->nombre = nombre;}
void Nodo_Producto::setHDer (Nodo_Producto * hijoDer) {this->hDer = hijoDer;}
void Nodo_Producto::setHIzq (Nodo_Producto * hijoIzq) {this->hIzq = hijoIzq;}
void Nodo_Producto::setCodigo(int pCodigo) { this->codProducto = pCodigo; }
	
int Nodo_Producto::getFB(){return this->FB;}
int Nodo_Producto::getCodProducto () {return this->codProducto;}
string Nodo_Producto::getNombre () {return this->nombre;}
	
Nodo_Producto * Nodo_Producto::getHDer () {return this->hDer;}
Nodo_Producto * Nodo_Producto::getHIzq () {return this->hIzq;}
puntero_Marca Nodo_Producto::getMarcas() {return this->dirMarcas;}
