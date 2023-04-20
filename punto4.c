#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

char * TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} typedef Producto;

struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”
} typedef Cliente;

int calcularCostoProducto(Cliente *Cli);

int main(){
    int cantClien, aux;
    Cliente *buff; //variable auxiliar
    Cliente *clientes;
    do
    {
        printf("\n Ingresar cantidad de clientes: ");
        scanf("%i", &cantClien);
    } while (cantClien > 5);
    clientes = malloc(cantClien * sizeof(Cliente));

    buff = malloc(cantClien *sizeof(Cliente));
    for (int i = 0; i < cantClien; i++)
    {
        printf("\n Ingresar nombre de cliente %i: ", i+1);
        scanf("%s", &buff->NombreCliente);

        clientes->NombreCliente = malloc((strlen(buff->NombreCliente)+1) * sizeof(char));
        strcpy(clientes->NombreCliente, buff->NombreCliente);

        puts(clientes->NombreCliente);
    }
    
/*    clientes = malloc(cantClien * sizeof(Cliente));

    srand(time(NULL));
    for (int i = 0; i < cantClien; i++)
    {
        clientes->ClienteID = i+1;
        printf("\n Ingresar nombre del cliente: ");
        gets(clientes->NombreCliente);
        clientes->CantidadProductosAPedir = rand()%5 + 1;
        aux = clientes->CantidadProductosAPedir;
        
        costos = malloc(aux*sizeof(int));

        clientes->Productos = malloc(aux * sizeof(Producto));
        for (int i = 0; i < aux; i++)
        {
            clientes->Productos->ProductoID = i+1;
            clientes->Productos->Cantidad = rand()%10 +1;

            clientes->Productos->TipoProducto = rand()%4;
            
            clientes->Productos->PrecioUnitario = rand()%100 + 10;
            
            costos[i] = calcularCostoProducto(&clientes->Productos);
        }
        
    }
    mostrar(clientes, costos);
*/    
    return 0;
}

int calcularCostoProducto(Cliente *Cli){
    int costo;
    costo = Cli->CantidadProductosAPedir * Cli->Productos->PrecioUnitario;
    return costo;
}