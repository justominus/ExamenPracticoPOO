#include "Animal.h"

namespace proyectoZoo {

    List<Animal^>^ AnimalsData::GetAll()
    {
        List<Animal^>^ list = gcnew List<Animal^>();
        list->Add(gcnew Animal("Leo", "A001", "León", "M", "5"));
        list->Add(gcnew Animal("Maya", "A002", "Elefante", "F", "8"));
        return list;
    }

}
