#pragma once

namespace proyectoZoo {

    using namespace System;
    using namespace System::Collections::Generic;

    public ref class Ingreso
    {
    public:
        String^ Description;
        double Value;

        Ingreso(String^ desc, double val)
        {
            Description = desc;
            Value = val;
        }
    };

    public ref class Ingresos
    {
    public:
        static List<Ingreso^>^ GetAll();
    };

}

