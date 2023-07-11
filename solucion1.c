#include <stdio.h>


#define MAX_PRODUCTOS 100

struct Producto {
    char nombre[50];
    char marca[50];
    int cantidad;
    float precio;
    char proveedor[50];
    char ciudad[50];
    char pais[50];
};

struct Inventario {
    struct Producto productos[MAX_PRODUCTOS];
    int cantidadProductos;
};

void ingresarProducto(struct Inventario *inventario) {
    if (inventario->cantidadProductos < MAX_PRODUCTOS) {
        struct Producto nuevoProducto;
        printf("Ingrese el nombre del producto: ");
        scanf("%s", nuevoProducto.nombre);
        printf("Ingrese la marca del producto: ");
        scanf("%s", nuevoProducto.marca);
        printf("Ingrese la cantidad disponible: ");
        scanf("%d", &nuevoProducto.cantidad);
        printf("Ingrese el precio del producto: ");
        scanf("%f", &nuevoProducto.precio);
        printf("Ingrese el proveedor del producto: ");
        scanf("%s", nuevoProducto.proveedor);
        printf("Ingrese la ciudad de llegada del producto: ");
        scanf("%s", nuevoProducto.ciudad);
        printf("Ingrese el país de llegada del producto: ");
        scanf("%s", nuevoProducto.pais);

        inventario->productos[inventario->cantidadProductos++] = nuevoProducto;
        printf("Producto ingresado exitosamente.\n");
    } else {
        printf("El inventario está lleno. No es posible ingresar más productos.\n");
    }
}

void editarProducto(struct Inventario *inventario) {
    int indice;
    printf("Ingrese el índice del producto a editar: ");
    scanf("%d", &indice);

    if (indice >= 0 && indice < inventario->cantidadProductos) {
        struct Producto *producto = &inventario->productos[indice];
        printf("Ingrese el nuevo nombre del producto: ");
        scanf("%s", producto->nombre);
        printf("Ingrese la nueva marca del producto: ");
        scanf("%s", producto->marca);
        printf("Ingrese la nueva cantidad disponible: ");
        scanf("%d", &producto->cantidad);
        printf("Ingrese el nuevo precio del producto: ");
        scanf("%f", &producto->precio);
        printf("Ingrese el nuevo proveedor del producto: ");
        scanf("%s", producto->proveedor);
        printf("Ingrese la nueva ciudad de llegada del producto: ");
        scanf("%s", producto->ciudad);
        printf("Ingrese el nuevo país de llegada del producto: ");
        scanf("%s", producto->pais);

        printf("Producto editado exitosamente.\n");
    } else {
        printf("Índice inválido. No se encontró el producto.\n");
    }
}

void eliminarProducto(struct Inventario *inventario) {
    int indice;
    printf("Ingrese el índice del producto a eliminar: ");
    scanf("%d", &indice);

    if (indice >= 0 && indice < inventario->cantidadProductos) {
        for (int i = indice; i < inventario->cantidadProductos - 1; i++) {
            inventario->productos[i] = inventario->productos[i + 1];
        }
        inventario->cantidadProductos--;

        printf("Producto eliminado exitosamente.\n");
    } else {
        printf("Índice inválido. No se encontró el producto.\n");
    }
}

void listarProductos(struct Inventario inventario) {
    printf("Productos ingresados:\n");
    for (int i = 0; i < inventario.cantidadProductos; i++) {
        struct Producto producto = inventario.productos[i];
        printf("Índice: %d\n", i);
        printf("Nombre: %s\n", producto.nombre);
        printf("Marca: %s\n", producto.marca);
        printf("Cantidad: %d\n", producto.cantidad);
        printf("Precio: %.2f\n", producto.precio);
        printf("Proveedor: %s\n", producto.proveedor);
        printf("Ciudad de llegada: %s\n", producto.ciudad);
        printf("País de llegada: %s\n", producto.pais);
        printf("\n");
    }
}

int main() {
    struct Inventario inventario;
    inventario.cantidadProductos = 0;

    int opcion;
    do {
        printf("----- Sistema de Inventario -----\n");
        printf("1. Ingresar producto\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Listar productos\n");
        printf("5. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarProducto(&inventario);
                break;
            case 2:
                editarProducto(&inventario);
                break;
            case 3:
                eliminarProducto(&inventario);
                break;
            case 4:
                listarProductos(inventario);
                break;
            case 5:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opción inválida. Intente nuevamente.\n");
                break;
        }

        printf("\n");
    } while (opcion != 0);

    return 0;
}
