# Zoo Manager - Sistema de Gestión para Zoológico

Sistema de gestión integral desarrollado en C++ con Windows Forms para la administración de un zoológico. Incluye módulos multiperfil para dueño, administrador y cajero, con funcionalidades CRUD, venta de boletos y reportes automatizados.

## 📋 Características

### Sistema de Autenticación
- Login seguro con validación de credenciales
- Control de acceso basado en perfiles de usuario
- Sesiones de usuario persistentes

### Perfiles de Usuario

| Perfil | Descripción | Accesos |
|--------|-------------|---------|
| **Dueño** | Propietario del zoológico | Acceso completo a todos los módulos |
| **Administrador** | Gestión operativa | CRUD usuarios (Admin/Cajero), ventas, reportes |
| **Cajero** | Operador de ventas | Solo módulo de venta de boletos |

### Módulos del Sistema

#### 1. Módulo de Login
- Formulario de autenticación
- Validación de credenciales
- Mensajes de error descriptivos
- Usuario por defecto: `admin` / `admin123`

#### 2. Módulo CRUD de Usuarios
- Crear nuevos usuarios
- Leer/listar usuarios existentes
- Actualizar información de usuarios
- Eliminar usuarios (con confirmación)
- Asignación de perfiles y estados

#### 3. Módulo de Venta de Boletos
- Tipos de boletos disponibles:
  - Adulto: $150.00
  - Niño: $80.00
  - Adulto Mayor: $100.00
  - Estudiante: $90.00
- Selección de cantidad
- Cálculo automático de totales
- Registro de vendedor y fecha
- Historial de ventas recientes

#### 4. Módulo de Reportes
- Reporte general de ventas
- Reporte por fecha específica
- Desglose por tipo de boleto
- Totales de ventas y boletos

## 🏗️ Estructura del Proyecto

```
ExamenPracticoPOO/
├── src/
│   ├── models/
│   │   ├── Usuario.h          # Modelo de usuario
│   │   ├── Usuario.cpp
│   │   ├── Boleto.h           # Modelo de boleto
│   │   └── Boleto.cpp
│   ├── controllers/
│   │   ├── UsuarioController.h    # Controlador de usuarios
│   │   ├── UsuarioController.cpp
│   │   ├── BoletoController.h     # Controlador de boletos
│   │   └── BoletoController.cpp
│   ├── views/
│   │   ├── LoginForm.h        # Formulario de login
│   │   ├── LoginForm.cpp
│   │   ├── MainForm.h         # Formulario principal
│   │   └── MainForm.cpp
│   ├── data/                  # Directorio de datos
│   └── main.cpp               # Punto de entrada
├── ZooManager.sln             # Solución de Visual Studio
├── ZooManager.vcxproj         # Proyecto de Visual Studio
└── README.md
```

## 🛠️ Requisitos

- Visual Studio 2019 o superior
- .NET Framework
- Windows 10 o superior
- Soporte CLR habilitado

## 🚀 Compilación

1. Abrir `ZooManager.sln` en Visual Studio
2. Seleccionar configuración (Debug/Release) y plataforma (Win32/x64)
3. Compilar la solución (Ctrl+Shift+B)
4. Ejecutar el programa (F5)

## 👤 Usuario por Defecto

Al iniciar el sistema por primera vez, se crea automáticamente un usuario administrador:

- **Usuario:** admin
- **Contraseña:** admin123
- **Perfil:** Dueño (acceso completo)

## 📊 Arquitectura

El sistema sigue el patrón de arquitectura **MVC** (Modelo-Vista-Controlador):

- **Modelos**: Definen las entidades del dominio (Usuario, Boleto)
- **Vistas**: Formularios Windows Forms para la interfaz de usuario
- **Controladores**: Lógica de negocio y operaciones CRUD

## 📁 Almacenamiento de Datos

Los datos se almacenan en archivos de texto plano:
- `data/usuarios.dat`: Información de usuarios
- `data/boletos.dat`: Registro de ventas de boletos

## 📝 Licencia

Proyecto desarrollado con fines educativos para el Examen Práctico de POO.
