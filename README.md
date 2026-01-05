# 🧵 libft_malloc — Custom Memory Allocator

Una implementación completa de `malloc`, `free` y `realloc` utilizando `mmap`, diseñada para comportarse como el *allocator* de libc, pero escrita desde cero.

Este proyecto forma parte del currículo de 42 y tiene como objetivo comprender cómo funciona realmente la gestión dinámica de memoria en sistemas UNIX.

---

## 📚 Características principales

- Implementación propia de:
  - `malloc(size_t size)`
  - `free(void *ptr)`
  - `realloc(void *ptr, size_t size)`
- Gestión de memoria mediante **zonas**:
  - **TINY**: asignaciones pequeñas
  - **SMALL**: asignaciones medianas
  - **LARGE**: asignaciones grandes (mapeadas individualmente)
- Minimización de llamadas a `mmap` y `munmap`
- Alineación correcta de memoria
- Visualización del estado del heap con:
  - `show_alloc_mem()`
- Sin uso de `malloc` interno (self-hosted allocator)
- Compatible con macOS y Linux

---

## 🧩 Arquitectura del proyecto

El allocator se basa en tres conceptos:

### 🔸 Zonas

Cada zona agrupa múltiples bloques del mismo tipo (TINY o SMALL).  
Las zonas se reservan con `mmap` y su tamaño es múltiplo de `getpagesize()`.

### 🔸 Bloques

Cada asignación se representa mediante un bloque con metadatos:

- tamaño
- estado (libre/ocupado)
- puntero al siguiente bloque

### 🔸 Asignaciones LARGE

Las asignaciones grandes se gestionan con `mmap` individual, fuera de las zonas.

---

## 📦 Estructura del repositorio

```code
├── include/
│   └── malloc.h
├── src/
│   ├── malloc.c
│   ├── free.c
│   ├── realloc.c
│   ├── zones.c
│   ├── blocks.c
│   ├── show_alloc_mem.c
│   └── utils.c
├── libft/
├── Makefile
└── README.md
```

---

## ⚙️ Compilación

El proyecto genera una librería dinámica con el nombre:

```code
libft_malloc_$HOSTTYPE.so
```

El Makefile crea además un enlace simbólico:

```code
libft_malloc.so -> libft_malloc_$HOSTTYPE.so
```

Comandos disponibles

```bash
make            # Compila libft y el allocator
make clean      # Elimina objetos
make fclean     # Elimina objetos y librerías
make re         # Recompila todo
```

## 🧪 Uso

Para utilizar tu malloc personalizado:

```bash
export DYLD_INSERT_LIBRARIES=./libft_malloc.so      # macOS
export LD_PRELOAD=./libft_malloc.so                 # Linux
```

Ejecuta cualquier programa y usará tu allocator.

## 🔍 Visualización del heap

Llama a:

```bash
show_alloc_mem();
```

Salida esperada:

```code
TINY : 0xA0000
0xA0020 - 0xA004A : 42 bytes
0xA006A - 0xA00BE : 84 bytes

SMALL : 0xAD000
0xAD020 - 0xADEAD : 3725 bytes

LARGE : 0xB0000
0xB0020 - 0xBBEEF : 48847 bytes

Total : 52698 bytes
```

## ⭐ Bonus implementados

- Thread-safety mediante pthread_mutex_t
- show_alloc_mem_ex() con:
  - volcado hexadecimal
  - historial de asignaciones
- Defragmentación de bloques libres
- Variables de entorno para depuración
