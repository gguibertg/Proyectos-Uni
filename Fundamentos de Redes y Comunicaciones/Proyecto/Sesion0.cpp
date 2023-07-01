//============================================================================
// ----------- PRACTICAS DE FUNDAMENTOS DE REDES DE COMUNICACIONES -----------
// ---------------------------- CURSO 2020/21 --------------------------------
// ----------------------------- SESION4 ---------------------------------
//============================================================================

/*
 * Sesion0.cpp
 *
 * Autor: Gabriel Fernando Guiberteau Garcia
 * Grupo 8 --> Jueves 08:30 - 10:00 h
 * 
 */

#include "interfaz.h"
#include "maestra.h"
#include "esclava.h"

using namespace std;

int main(){

 pcap_if_t *avail_ifaces = NULL;
 char *nombreInterfaz = NULL;
 interface_t iface;
 unsigned char tipo[2];
 int puerto, modo;
 unsigned char MAC_Aux[6];
 
 printf("\n----------------------------\n");
 printf("------ ENTREGA 4 - FRC ------\n");
 printf("----------------------------\n");
 printf("\n");
    
 avail_ifaces = GetAvailAdapters(); 

 listarInterfaces(avail_ifaces);

 seleccionarInterfaz(avail_ifaces, nombreInterfaz);  

 imprimirMACInterface(&iface, nombreInterfaz);

 elegirGrupo(tipo);

 avail_ifaces = nullptr;
 nombreInterfaz = nullptr;

 puerto = OpenAdapter(&iface); //Abrimos el puerto

 if(puerto == 0){

     modo = elegirModo();

     if(modo == 1){

         descubrirEsclava(&iface, tipo);

         bucleEsperaMaestra(&iface, tipo, MAC_Aux);

         imprimirMAC(MAC_Aux);

         seleccionOpcionesMaestra(&iface, MAC_Aux, tipo);

     }  

     if(modo == 2){
    
         bucleEsperaEsclava(&iface, tipo, MAC_Aux);

         contestarMaestra(&iface, tipo, MAC_Aux);

         imprimirMAC(MAC_Aux);

         seleccionOpcionesEsclava(&iface, MAC_Aux, tipo);

     }
     
     CloseAdapter(&iface); // Cerramos el puerto
     
     return 0;

 }else{

     cout << "Error al abrir el puerto" << endl;
     return 1;

 }

}
