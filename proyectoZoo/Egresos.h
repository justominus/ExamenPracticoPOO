#pragma once

namespace proyectoZoo {

    using namespace System;
    using namespace System::Collections::Generic;

    public ref class Egreso
    {
    public:
        String^ Description;
        double Value;

        Egreso(String^ desc, double val)
        {
            Description = desc;
            Value = val;
        }
    };

    public ref class Egresos
    {
    public:
        static List<Egreso^>^ GetAll();
    };

}

