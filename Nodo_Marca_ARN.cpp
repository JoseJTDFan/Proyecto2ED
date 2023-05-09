#include "Nodo_Marca_ARN.h"

string to_Stiringeo(int pNumero)
{
	ostringstream buff;
	buff << pNumero;
	return buff.str();
}

void rotSimpleDer_Gr (puntero_Marca & nodo, puntero_Marca & n1)
{
    if (nodo->getHIzq() != NULL && nodo->getHIzq()->getRojo()) {
    	nodo->getHIzq()->setRojo (false);
    	n1->setRojo (false);
    	nodo->setRojo (true);
    	return;
	} else {
		if (n1->getHIzq() != NULL) n1->getHIzq()->setPadre (nodo);
        
		nodo->setHDer(n1->getHIzq());
	    n1->setHIzq (nodo);
	    
	    n1->setPadre (nodo->getPadre());
	    nodo->setPadre (n1);
	    
	    n1->setRojo (false);
	    nodo->setRojo (true);
        nodo = n1;
    }
}

void rotSimpleIzq_Gr (puntero_Marca & nodo, puntero_Marca & n1)
{
	if (nodo->getHDer() != NULL && nodo->getHDer()->getRojo()) {
    	nodo->getHDer()->setRojo (false);
    	n1->setRojo (false);
    	nodo->setRojo (true);
    	return;
    } else {
    	if (n1->getHDer() != NULL) n1->getHDer()->setPadre (nodo);
    	
	    nodo->setHIzq (n1->getHDer());
        n1->setHDer (nodo);
        
        n1->setPadre (nodo->getPadre());
	    nodo->setPadre (n1);

        n1->setRojo (false);
	    nodo->setRojo (true);
        nodo = n1;
    }
}

void rotDobleDer_Gr (puntero_Marca & nodo, puntero_Marca & n1)
{
    if (nodo->getHIzq() != NULL && nodo->getHIzq()->getRojo()) {
    	nodo->getHIzq()->setRojo (false);
    	n1->setRojo (false);
    	nodo->setRojo (true);
    	return;
    } else {
	    puntero_Marca n2;
        n2 = n1->getHIzq();
    
	    if (n2->getHIzq() != NULL) n2->getHIzq()->setPadre(nodo);
        
	    nodo->setHDer (n2->getHIzq());
	    n2->setHIzq (nodo);
    
        if (n2->getHDer() != NULL) n2->getHDer()->setPadre(n1);

	    n1->setHIzq (n2->getHDer());
        n2->setHDer (n1);
    
        n2->setPadre (nodo->getPadre());
        n2->getHDer()->setPadre (n2);
        n2->getHIzq()->setPadre (n2);

        n2->setRojo (false);
	    nodo->setRojo (true);
        nodo = n2;
    }
}

void rotDobleIzq_Gr (puntero_Marca & nodo, puntero_Marca & n1)
{	
	if (nodo->getHDer() != NULL && nodo->getHDer()->getRojo()) {
    	nodo->getHDer()->setRojo (false);
    	n1->setRojo (false);
    	nodo->setRojo (true);
    	return;
    } else {
		puntero_Marca n2;
    	n2 = n1->getHDer();
    
    	if (n2->getHDer() != NULL) n2->getHDer()->setPadre(nodo);
    
    	nodo->setHIzq(n2->getHDer());
    	n2->setHDer(nodo);
    
    	if (n2->getHIzq() != NULL) n2->getHIzq()->setPadre(n1);
    
    	n1->setHDer (n2->getHIzq());
    	n2->setHIzq (n1);
    
    	n2->setPadre (nodo->getPadre());
    	n2->getHDer()->setPadre (n2);
    	n2->getHIzq()->setPadre (n2);

    	n2->setRojo (false);
		nodo->setRojo (true);
		nodo = n2;
    }
}

Nodo_Marca::Nodo_Marca()
{
	this->rojo = true;
	this->codMarca = 0; 
	this->cantGondola = 0; 
	this->precio = 0;
	this->nombre="";
	this->padre = NULL;
	this->hDer = NULL;
	this->hIzq = NULL;
}

Nodo_Marca::Nodo_Marca (int codMarca, int cantGondola, int precio, string nombre) 
{
	
	this->rojo = true;
	this->codMarca = codMarca;
	this->cantGondola = cantGondola;
	this->precio = precio;
	this->nombre=nombre;
	this->padre = NULL;
	this->hDer = NULL;
	this->hIzq = NULL;
}

void Nodo_Marca::insertMarca (Nodo_Marca* &nodo, bool  Hh, int codMarca, int cantGondola, int precio, string nombre)
{
	puntero_Marca n1, inputAux;

    if(nodo == NULL) {
		nodo = new Nodo_Marca (codMarca, cantGondola, precio, nombre); 
		Hh = true; 
		return;
	}
    if(nodo->getCodMarca() < codMarca){
    	inputAux = nodo->getHDer(); 
		insertMarca (inputAux, Hh, codMarca, cantGondola, precio, nombre);
        
        if (nodo == inputAux->getHIzq() || nodo == inputAux->getHDer() || nodo == inputAux) {
			nodo = inputAux;
			}
		else {
			inputAux->setPadre (nodo); 
			nodo->setHDer (inputAux);
			}
		
		if (Hh) {
			if (nodo->getRojo() && nodo->getHDer()->getRojo()) {
            	if (nodo->getPadre() != NULL) {
            		n1 = nodo;
					if (nodo->getPadre()->getCodMarca() < codMarca) {
						inputAux = nodo->getPadre(); 
						rotSimpleDer_Gr (inputAux, n1); 
						nodo = inputAux;
					} else {
						inputAux = nodo->getPadre(); 
						rotDobleIzq_Gr (inputAux, n1); 
						nodo = inputAux;
					}
				}
			}
        }
    } else {
    	inputAux = nodo->getHIzq(); 
		insertMarca (inputAux, Hh, codMarca, cantGondola, precio, nombre);
            
        if (nodo == inputAux->getHIzq() || nodo == inputAux->getHDer() || nodo == inputAux) {
			nodo = inputAux;
			}
		else {
			inputAux->setPadre (nodo); 
			nodo->setHIzq (inputAux);
		}
        
		if(Hh==true) {
			if (nodo->getRojo() && nodo->getHIzq()->getRojo()) {
            	if (nodo->getPadre() != NULL){
            		n1 = nodo;
					if (nodo->getPadre()->getCodMarca() >= codMarca) {
						inputAux = nodo->getPadre(); 
						rotSimpleIzq_Gr (inputAux, n1); 
						nodo = inputAux;
					} else {
						inputAux = nodo->getPadre(); 
						rotDobleDer_Gr (inputAux, n1); 
						nodo = inputAux;
					}
				}
			}
        }
    }
}

Nodo_Marca * Nodo_Marca::buscarMarca (int codMarca) 
{
	if (this->codMarca == codMarca) {
		return this;
	}
	if (this->codMarca < codMarca) {
		if (this->getHDer () == NULL)
			return NULL;
		else
			return this->getHDer ()->buscarMarca (codMarca);
	} else {
		if (this->getHIzq () == NULL)
			return NULL;
		else 
			return this->getHIzq ()->buscarMarca (codMarca);
	}	
}

void Nodo_Marca::mostrarMarca ()
{
	if(this==NULL){
        return;
	}else{
		if(this->hIzq!=NULL)
        	this->hIzq->mostrarMarca();
        cout<<this->codMarca<<" <> ";
        if (this->hDer)
			this->hDer->mostrarMarca();
    }
}

bool Nodo_Marca::verificarMarca (bool i, int codMarca) 
{
	if(this==NULL){
        return i;
    }else{
		if (this->getCodMarca()==codMarca){
			return i=true;
		}
		else{
			if(this->hIzq!=NULL)
				i=this->hIzq->verificarMarca(i,codMarca);
			if(this->hDer!=NULL)
				i=this->hDer->verificarMarca(i,codMarca);	
		} 
    }
}


void equilibrar_Uno_RN(puntero_Marca& pNodo, bool& pHh, int& pCodMarca)
{
	puntero_Marca producto_NUno = NULL;
	puntero_Marca producto_Aux = NULL;
	producto_Aux = pNodo->getHDer();

	if (pNodo == producto_Aux->getHIzq() || pNodo == producto_Aux->getHDer() || pNodo == producto_Aux) {
		pNodo = producto_Aux;
	}
	else {
		producto_Aux->setPadre(pNodo);
		pNodo->setHDer(producto_Aux);
	}
	if (pHh) {
		if (pNodo->getRojo() && pNodo->getHDer()->getRojo()) {
			if (pNodo->getPadre() != NULL) {
				producto_NUno = pNodo;
				pHh = false;
				if (pNodo->getPadre()->getCodMarca() < pCodMarca) {
					//pHh = false;
					producto_Aux = pNodo->getPadre();
					rotSimpleDer_Gr(producto_Aux, producto_NUno);
					pNodo = producto_Aux;
				}
				else {
					//pHh = false;
					producto_Aux = pNodo->getPadre();
					rotDobleIzq_Gr(producto_Aux, producto_NUno);
					pNodo = producto_Aux;
				}
			}
		}
	}
}

void equilibrar_Dos_RN(puntero_Marca& pNodo, bool& pHh, int& pCodMarca)
{
	puntero_Marca producto_NUno = NULL;
	puntero_Marca producto_Aux = NULL;
	producto_Aux = pNodo->getHIzq();     //inputAux = nodo->getHIzq();

	if (pNodo == producto_Aux->getHIzq() || pNodo == producto_Aux->getHDer() || pNodo == producto_Aux) {
		pNodo = producto_Aux;
	}
	else
	{
		producto_Aux->setPadre(pNodo);
		pNodo->setHIzq(producto_Aux);
	}

	if (pHh) {
		if (pNodo->getRojo() && pNodo->getHIzq()->getRojo()) {
			if (pNodo->getPadre() != NULL) {
				producto_NUno = pNodo;
				pHh = false;
				if (pNodo->getPadre()->getCodMarca() >= pCodMarca) { //pHh = false;
					producto_Aux = pNodo->getPadre();
					rotSimpleIzq_Gr(producto_Aux, producto_NUno);
					pNodo = producto_Aux;
				}
				else { //pHh = false;
					producto_Aux = pNodo->getPadre();
					rotDobleDer_Gr(producto_Aux, producto_NUno);
					pNodo = producto_Aux;
				}
			}
		}
	}
}

void borrar_RN(puntero_Marca& pProducto_Sustituto, puntero_Marca& pNodo, bool& pHh)
{
	puntero_Marca marca_Aux = NULL;
	puntero_Marca sustituto_Temp = NULL;

	if (pNodo->getHDer() != NULL) {
		marca_Aux = pNodo->getHDer();
		sustituto_Temp = pNodo->getHDer();

		borrar_RN(sustituto_Temp, marca_Aux, pHh);

		pProducto_Sustituto = sustituto_Temp;
		pNodo->setHDer(marca_Aux);  //Borrar(D->Hder, Hh);
		if (pHh) {
			int codeMarca = pProducto_Sustituto->getCodMarca();

			if (pNodo->getHDer() == sustituto_Temp) {
				pNodo->setHDer(pNodo->getHDer()->getHIzq());
			}

			if (pNodo->getHDer() != NULL) {//equilibrar_Dos_RN
				marca_Aux = pNodo; equilibrar_Uno_RN(marca_Aux, pHh, codeMarca); pNodo = marca_Aux;//equilibrar_Dos_RN (marca_Aux, pHh, codeMarca); pNodo = marca_Aux; //Equilibrar2(D, Hh); 
			}
		}
		else { //Copia y asigna nuevo q

		}
	}
	else
		pHh = true;
}

void borrar_Marca_RN(puntero_Marca& pNodo, bool& pHh, int& pCodMarca)
{
	puntero_Marca marca_Q = NULL;
	puntero_Marca marca_Aux = NULL;
	int codigoMarca = 0;

	if (pNodo != NULL) {
		if (pCodMarca < pNodo->getCodMarca()) {
			//            	cout<<"\naaaah\n\n";
			marca_Aux = pNodo->getHIzq(); borrar_Marca_RN(marca_Aux, pHh, pCodMarca); pNodo->setHIzq(marca_Aux);
			//BorrarBalanceado (pNodo->getHIzq(), pHh, pCodProducto);
			if (pHh)
			{
				codigoMarca = pCodMarca;//pNodo->getCodMarca();
				marca_Aux = pNodo; equilibrar_Uno_RN(marca_Aux, pHh, codigoMarca); pNodo = marca_Aux;
				//Equilibrar1(raiz, Hh);
				return;
			}
		}
		else {
			if (pCodMarca > pNodo->getCodMarca()) {
				//            	cout<<"\nMa bro\n\n";
				marca_Aux = pNodo->getHDer(); borrar_Marca_RN(marca_Aux, pHh, pCodMarca); pNodo->setHDer(marca_Aux);
				//	    		cout<<"\n---------------------------\n\n";
								//BorrarBalanceado(raiz->Hder, Hh, x);
				if (pHh)
				{
					codigoMarca = pCodMarca;//pNodo->getCodMarca();
					marca_Aux = pNodo; equilibrar_Dos_RN(marca_Aux, pHh, codigoMarca); pNodo = marca_Aux;
					//Equilibrar2(raiz, Hh);
					return;
				}
			}
			else {
				marca_Q = pNodo;
			}
		}

		if (pCodMarca != pNodo->getCodMarca())
			return;
		//        cout<<"Pasa";
		if (marca_Q->getHDer() == NULL) {
			//	    	cout<<"\nMy no comprender\n\n";
			//	    	cout<<"\nValor: "<< marca_Q->getCodMarca()  <<"\n\n";


			delete pNodo;
			pNodo = marca_Q->getHIzq();

			/*
			pNodo = marca_Q->getHIzq();
			pHh = true;
			*/
			//        	cout<<"\nFlagante\n\n";
			return;
		}
		else {
			if (marca_Q->getHIzq() == NULL) {
				//            	cout<<"\nay\n\n";
				pNodo = marca_Q->getHDer();
				pHh = true;
			}
			else {

				puntero_Marca marca_Sustituto = pNodo->getHIzq();
				marca_Aux = pNodo->getHIzq();

				borrar_RN(marca_Sustituto, marca_Aux, pHh);

				pNodo->setHIzq(marca_Aux);
				pNodo->setCodigo(marca_Sustituto->getCodMarca());
				pNodo->setNombre(marca_Sustituto->getNombre());

				if (marca_Sustituto == pNodo->getHIzq()) {
					pNodo->setHIzq(NULL);
					pHh = true;
				}
				marca_Q = marca_Sustituto;
			}
			if (pHh)
			{
				codigoMarca = pCodMarca;//pNodo->getCodMarca();
				marca_Aux = pNodo; equilibrar_Uno_RN(marca_Aux, pHh, codigoMarca); pNodo = marca_Aux;
				//Equilibrar1(raiz, Hh);
			}
		}
	}
	if (marca_Q != NULL) {
		//    	cout<<"\nborra q\n\n";
		delete marca_Q;
		//    	cout<<"\nborra q Finaliza\n\n";
	}
}



string Nodo_Marca::inOrden_Marca ()
{
	string reporte = "";
	if (this->getHIzq() != NULL)
		reporte += this->getHIzq()->inOrden_Marca();
	reporte += "\n\tCodigo: "+to_Stiringeo(this->codMarca)+" - Nombre: "+this->nombre+" - Cantidad en gondola: "+ to_Stiringeo(this->cantGondola)+" - Precio: "+ to_Stiringeo(this->precio);
	if (this->getHDer()!= NULL)
		reporte += this->getHDer()->inOrden_Marca();
	return reporte;
}

string Nodo_Marca::imrpimir_Arbol()
{
	string reporte = "";
	if (this->getHIzq() != NULL)
		reporte += this->getHIzq()->imrpimir_Arbol();
		
	reporte += "\n\t\t\t------\n\t\t\tMarca";
	reporte += "\n\t\t\tCodigo: " + to_Stigear(this->codMarca) + " - Nombre: " + this->nombre;
	reporte += " - Cantidad en gondola: "+to_Stigear(this->cantGondola) +" - Precio: "+to_Stigear(this->precio);
	
	if (this->getHDer()!= NULL)
		reporte += this->getHDer()->imrpimir_Arbol();
	return reporte;
}

void Nodo_Marca::revisar_Gondola (Arbol_Inventario & pArbol, int & pCodPasillo, int & pCodProducto)
{
	if (this->getHIzq() != NULL)
		this->getHIzq()->revisar_Gondola (pArbol, pCodPasillo, pCodProducto);
	
	if (this->cantGondola <= 2) 
	{
		puntero_Inventario marca_Inventario = pArbol.buscarMarca_Inventario (pCodPasillo, pCodProducto, this->codMarca);
		if (marca_Inventario->getCantStock() > 10) {
			this->cantGondola += 10;
			marca_Inventario->setCantStock( marca_Inventario->getCantStock() - 10 );
		} else {
			this->cantGondola += marca_Inventario->getCantStock();
			marca_Inventario->setCantStock( marca_Inventario->getCantStock() - marca_Inventario->getCantStock() );
		}
	}
	
	if (this->getHDer()!= NULL)
		this->getHDer()->revisar_Gondola (pArbol, pCodPasillo, pCodProducto);
}


void Nodo_Marca::setNombre (string pNombre) {this->nombre = pNombre;}
void Nodo_Marca::setRojo (bool rojo) {this->rojo = rojo;}
void Nodo_Marca::setPrecio (int pPrecio) {this->precio = pPrecio;}
void Nodo_Marca::setPadre (Nodo_Marca * padre) {this->padre = padre;}
void Nodo_Marca::setHDer (Nodo_Marca * hijoDer) {this->hDer = hijoDer;}
void Nodo_Marca::setHIzq (Nodo_Marca * hijoIzq) {this->hIzq = hijoIzq;}
/*void Nodo_Marca::setPrecio(int precio){
	this->precio=precio;
}*/
void Nodo_Marca::setCantGondola(int cantidad) {this->cantGondola=cantidad;}
void Nodo_Marca::setCodigo(int pCodigo) { this->codMarca = pCodigo; }

bool Nodo_Marca::getRojo () {return this->rojo;}
int Nodo_Marca::getCodMarca () {return this->codMarca;}
int Nodo_Marca::getCantGondola() {return this->cantGondola;}
int Nodo_Marca::getPrecio(){return this->precio;}
string Nodo_Marca::getNombre(){return this->nombre;}

Nodo_Marca * Nodo_Marca::getPadre () {return this->padre;}
Nodo_Marca * Nodo_Marca::getHDer () {return this->hDer;}
Nodo_Marca * Nodo_Marca::getHIzq () {return this->hIzq;}

