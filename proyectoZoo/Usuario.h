#pragma once

#include <vcclr.h>

namespace proyectoZoo {

	using namespace System;
	using namespace System::Collections::Generic;

	public ref class Usuario
	{
	public:
		String^ Nombre;
		String^ Cedula;
		String^ Correo;
		String^ Edad;
		String^ UsuarioName;
		String^ Clave;
		String^ Cargo;

		Usuario() {}
		Usuario(String^ nombre, String^ cedula, String^ correo, String^ edad, String^ usuario, String^ clave, String^ cargo)
		{
			Nombre = nombre;
			Cedula = cedula;
			Correo = correo;
			Edad = edad;
			UsuarioName = usuario;
			Clave = clave;
			Cargo = cargo;
		}

		// 
		static List<Usuario^>^ GetAllUsers();

		// validar credenciales
		static Usuario^ ValidateCredentials(String^ username, String^ password);
	};

}

