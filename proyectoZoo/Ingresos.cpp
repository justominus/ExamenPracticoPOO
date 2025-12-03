#include "Ingresos.h"

namespace proyectoZoo {

    List<Ingreso^>^ Ingresos::GetAll()
    {
        List<Ingreso^>^ list = gcnew List<Ingreso^>();
        list->Add(gcnew Ingreso("Venta boletos", 150.0));
        list->Add(gcnew Ingreso("Donación", 50.0));
        return list;
    }

}
