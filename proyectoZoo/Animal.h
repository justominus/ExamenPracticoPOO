#pragma once

namespace proyectoZoo {

    using namespace System;
    using namespace System::Collections::Generic;

    public ref class Animal
    {
    public:
        String^ Nombre;
        String^ Identificacion;
        String^ Especie;
        String^ Sexo;
        String^ Edad;

        Animal(String^ nombre, String^ id, String^ especie, String^ sexo, String^ edad)
        {
            Nombre = nombre;
            Identificacion = id;
            Especie = especie;
            Sexo = sexo;
            Edad = edad;
        }
    };

    public ref class AnimalsData
    {
    public:
        static List<Animal^>^ GetAll();
    };

}

