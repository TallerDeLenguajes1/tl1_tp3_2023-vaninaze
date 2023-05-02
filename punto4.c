#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

struct Producto
{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} typedef Producto;

struct Cliente
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos;         // El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”
} typedef Cliente;

float calcularCostoProducto(Producto prod);
void mostrarCliente(Cliente clien, float total);
int main()
{
    int cantClien, aux;
    float costo, total = 0;
    Cliente *buff; // variable auxiliar
    Cliente *punt_clientes;

    srand(time(NULL));
    do
    {
        printf("\n Ingresar cantidad de clientes: ");
        scanf("%i", &cantClien);
    } while (cantClien > 5);

    punt_clientes = malloc(cantClien * sizeof(Cliente));

    buff = (Cliente *)malloc(sizeof(Cliente));
    buff->NombreCliente = malloc(20 * sizeof(char));

    for (int i = 0; i < cantClien; i++)
    {
        printf("\n ----------Carga de cliente: %i --------", i + 1);
        punt_clientes[i].ClienteID = i + 1;
        printf("\n Ingresar nombre del cliente: ");
        fflush(stdin);
        gets(buff->NombreCliente);

        punt_clientes[i].NombreCliente = malloc((strlen(buff->NombreCliente) + 1) * sizeof(char));
        strcpy(punt_clientes[i].NombreCliente, buff->NombreCliente);

        punt_clientes[i].CantidadProductosAPedir = rand() % 5 + 1;
        aux = punt_clientes[i].CantidadProductosAPedir; // cant de prod a pedir
        punt_clientes[i].Productos = malloc(aux * sizeof(Producto));

        // carga de productos
        printf("\n ---Se cargan %i productos---", aux);
        for (int j = 0; j < aux; j++)
        {
            printf("\n --Producto: %i a cargar--", j + 1);
            punt_clientes[i].Productos[j].ProductoID = j + 1;
            printf("\n Ingresar cantidad del producto: ");
            scanf("%i", &punt_clientes[i].Productos[j].Cantidad);

            buff->Productos = malloc(sizeof(Producto));
            buff->Productos->TipoProducto = malloc(sizeof(char) * 20);

            buff->Productos->TipoProducto = TiposProductos[(rand() % 5)];
            // puts(buff->Productos->TipoProducto);

            punt_clientes[i].Productos[j].TipoProducto = malloc((strlen(buff->Productos->TipoProducto) + 1) * sizeof(char));

            strcpy(punt_clientes[i].Productos[j].TipoProducto, buff->Productos->TipoProducto);
            puts(punt_clientes[i].Productos[j].TipoProducto);

            punt_clientes[i].Productos[j].PrecioUnitario = rand() % 91 + 10;

            costo = calcularCostoProducto(punt_clientes[i].Productos[i]);
            printf("\n Costo: %.2f", costo);
        }
        total = total + costo;
        mostrarCliente(punt_clientes[i], total);
    }
    free(buff);
    free(punt_clientes);
    return 0;
}

float calcularCostoProducto(Producto prod)
{
    float costo;
    costo = prod.PrecioUnitario * prod.Cantidad;
    return costo;
}
void mostrarCliente(Cliente clien, float total)
{
    printf("\n ——- CLIENTE ID: %i ———", clien.ClienteID);
    printf("\n Nombre del cliente: %s", clien.NombreCliente);
    printf("\n Cant de productos a pedir: %i", clien.CantidadProductosAPedir);
    for (int i = 0; i < clien.CantidadProductosAPedir; i++)
    {
        printf("\n —PRODUCTO ID: %i—", clien.Productos[i].ProductoID);
        printf("\n Cantidad: %i", clien.Productos[i].Cantidad);
        printf("\n Tipo de producto: %s", clien.Productos[i].TipoProducto);
        printf("\n Precio unitario: %.2f", clien.Productos[i].PrecioUnitario);
    }
    printf("\n Total: %.2f", total);
}
