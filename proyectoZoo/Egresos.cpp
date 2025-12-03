#include "Egresos.h"

namespace proyectoZoo {

    List<Egreso^>^ Egresos::GetAll()
    {
        List<Egreso^>^ list = gcnew List<Egreso^>();
        list->Add(gcnew Egreso("Compra alimentos", 80.0));
        list->Add(gcnew Egreso("Mantenimiento", 40.0));
        return list;
    }

}
