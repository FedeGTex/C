#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "entregas.h"
#include "utn.h"


int main()
{
    LinkedList* listaEntregas = ll_newLinkedList();
    controller_loadFromText("data.csv",listaEntregas);
    //controller_ListEntregas(listaEntregas);
    controller_saveAsText("informe.txt",listaEntregas);
    return 0;
}

