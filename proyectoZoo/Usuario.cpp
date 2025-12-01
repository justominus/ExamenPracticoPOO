#include "Usuario.h"
#include <vcclr.h>

using namespace proyectoZoo;
using namespace System;
using namespace System::Collections::Generic;

List<Usuario^>^ Usuario::GetAllUsers()
{
	static bool initialized = false;
	static gcroot<List<Usuario^>^> allUsers;
	if (!initialized) {
		allUsers = gcnew List<Usuario^>();
		allUsers->Add(gcnew Usuario(L"Alex Dubert", L"12345678", L"alex@gmail.com", L"23", L"alex", L"1234", L"Administrador"));
		allUsers->Add(gcnew Usuario(L"Maria Lopez", L"87654321", L"maria@gmail.com", L"28", L"marial", L"abcd", L"Dueño"));
		allUsers->Add(gcnew Usuario(L"Carlos Ruiz", L"11223344", L"carlos@gmail.com", L"45", L"carlosr", L"pass", L"Dueño"));
		allUsers->Add(gcnew Usuario(L"Pedro Perez", L"22334455", L"pedro@example.com", L"30", L"pedro", L"1111", L"Cajero"));
		initialized = true;
	}
	return allUsers;
}

Usuario^ Usuario::ValidateCredentials(String^ username, String^ password)
{
	if (username == nullptr || password == nullptr) return nullptr;
	for each (Usuario^ u in GetAllUsers()) {
		if (u->UsuarioName->Equals(username, StringComparison::InvariantCultureIgnoreCase) && u->Clave == password) {
			return u;
		}
	}
	return nullptr;
}
