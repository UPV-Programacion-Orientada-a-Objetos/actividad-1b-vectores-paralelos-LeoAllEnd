#include <iostream>
#include <string>


int main() {
    //Aqui estan todos los vectores que ocupare a lo largo del programa con un indice de 100 cada uno
    //Los vectores tienen un nombre autoexplicativo para el contexto del programa
    int codigos[100];
    std::string nombres[100];
    int stock[100];
    float precios[100];
    //El minimo de 5 productos
    int totalProductos = 5;
    //Una variable para la opcion que se seleccione, relevante para el switch
    int op;
// La entrada de datos base a los arrays
    //El codigo de barras; Nombres de cada producto; La cantidad en stock; Y los precios
    codigos[0] = 101; nombres[0] = "Martillo de bola"; stock[0] = 50; precios[0] = 15.50;
    codigos[1] = 102; nombres[1] = "Destornillador"; stock[1] = 120; precios[1] = 8.75;
    codigos[2] = 103; nombres[2] = "Cinta metrica"; stock[2] = 75; precios[2] = 20.00;
    codigos[3] = 104; nombres[3] = "Llave inglesa"; stock[3] = 45; precios[3] = 25.99;
    codigos[4] = 105; nombres[4] = "Taladro alambrico"; stock[4] = 10; precios[4] = 120.00;

    //Uso do while ya que me asegura que inicie al menos una vez el menu
    do {
        //Nombre de sistema original; no afecta al programa
        //Opciones del menu, el dato recibido se guarda en op de opcion
        std::cout << "\n--- Bienvenido al sistema de inventario de Ferre Walter ---\n" << std::endl;
        std::cout << "Seleccione una opcion:" << std::endl;
        std::cout << "1. Consultar un producto" << std::endl;
        std::cout << "2. Actualizar inventario" << std::endl;
        std::cout << "3. Generar reporte completo" << std::endl;
        std::cout << "4. Encontrar el producto mas caro" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cin >> op;
        // Se le muestra al usuario la opcion que selecciono y pasa al switch
        std::cout << "\nOpcion seleccionada: "<< op;
        switch(op) {
            case 1: {
                //Variable donde se guarda el codigo del producto que se busca
                int codigoBuscar;
                //Variable booleana/bandera para determinar si el producto fue encontrado
                bool TeEncontre = false;

                std::cout << "\nIngrese el codigo del producto que desea  consultar: ";
                std::cin >> codigoBuscar;

                //Ciclo que va de 0 a el total de productos ya que son los que tienen codigo existente
                for(int i = 0; i < totalProductos; i++) {
                    //Condicion que se va actualizando junto con el ciclo conforme se busque el codigo del producto
                    if(codigos[i] == codigoBuscar) {
                        std::cout << "\nInformacion del Producto:" << std::endl;
                        std::cout << "Codigo: " << codigos[i] << std::endl;
                        std::cout << "Nombre: " << nombres[i] << std::endl;
                        std::cout << "Cantidad en stock: " << stock[i] << std::endl;
                        std::cout << "Precio unitario: $" << precios[i] << std::endl;
                        //Si se encontro el producto la bandera cambia a verdadero como forma de validacion
                        TeEncontre = true;
                        // El break es para que el sistema no tenga necesidad de leer lo demas si la condicion se cumplio
                        //Ya que significa que el producto fue encontrado
                        break;
                    }
                }
                //Si no se encuentra, una vez terminado el ciclo se evalua la bandera y se le notifica al usuario
                if(!TeEncontre) {
                    std::cout << "\nError: Producto no encontrado en el sistema" << std::endl;
                }
                //Este break si es el del switch
                break;
            }

            case 2: {
                //Parecido a buscar un producto, pero aqui se cambia la cantidad de stock de un producto con la variable cant
                int codigoBuscar, cant;
                bool TeEncontre = false;

                std::cout << "\nIngrese el codigo del producto: "<<std::endl;
                std::cin >> codigoBuscar;

                for(int i = 0; i < totalProductos; i++) {
                    if(codigos[i] == codigoBuscar) {
                        //Se imprime el nombre del producto; su cantidad en el sistema y el cambio se guarda en cant
                        std::cout << "Producto encontrado: " << nombres[i] << std::endl;
                        std::cout << "Stock actual: " << stock[i] << std::endl;
                        std::cout << "Ingrese cantidad *positiva para sumar, negativa para restar*: ";
                        std::cin >> cant;
                        //La cantidad ingresada (sea negativa o positiva) se suma al stock actual y se guarda en nuevoStock
                        int nuevoStock = stock[i] + cant;

                        //Condicional que evalua que el stock actualizado no sea negativo
                        if(nuevoStock < 0) {
                            std::cout << "Error: No se puede tener stock negativo de un productoo" << std::endl;
                        }
                        //Si no es negativo, se sobreescribe a la posicion actual del vector stock y se le notifica al usuario
                        else {
                            stock[i] = nuevoStock;
                            std::cout << "Stock actualizado :). Nuevo stock: " << stock[i] << std::endl;
                        }
                        //Misma validacion para la busqueda del producto en el ciclo
                        TeEncontre = true;
                        break;
                    }
                }

                if(!TeEncontre) {
                    std::cout << "Error: Producto no encontrado" << std::endl;
                }
                break;
            }

            case 3: {
                //Reporte del inventario con formato
                std::cout << "\n--- Reporte de inventario ---" << std::endl;
                std::cout << "Codigo\t| Nombre\t\t\t| Stock\t| Precio" << std::endl;
                std::cout << "-----------------------------------------------" << std::endl;
                //Se imprimen todos los array en orden de la informacion de los productos, por cada vuelta se actualiza el indice
                // y por ende la informacion
                for(int i = 0; i < totalProductos; i++) {
                    std::cout << codigos[i] << "\t| " << nombres[i] << "\t| " << stock[i] << "\t| $" << precios[i] << std::endl;
                }
                //Formato del final del reporte de inventario
                std::cout << "-----------------------------------------------" << std::endl;
                std::cout << "\n--- Fin del reporte ---" << std::endl;
                break;
            }

            case 4: {
                /* Esta variable es para comparar la posicion del vector precios desde el primer producto
                 * (por eso esta inicializado en 0) */
                int indiceMasCaro = 0;
                //El for compara posiciones distintas del mismo array (precios) para verficiar si el contenido es mayor
                for(int i = 1; i < totalProductos; i++) {
                    if(precios[i] > precios[indiceMasCaro]) {
                        //Si el contenido es mayor el indice iguala la posicion y sigue comparando hasta el total de productos
                        indiceMasCaro = i;
                    }
                }
                //Cuando termina el ciclo se imprime la posicion con la que se quedo el indice del producto mas caro
                std::cout << "\nEl producto mas caro es: " << nombres[indiceMasCaro] << " con un precio de $" << precios[indiceMasCaro] << std::endl;
                break;
            }

            case 5:
                //Caso de salida del sistema
                //Despedida normal
                std::cout << "\nGracias por usar mi sistema. Bye bye" << std::endl;
                break;

            default:
                //Validacion por una entrada invalida de las opciones
                std::cout << "\nOpcion invalida.Intentalo de nuevo" << std::endl;
                break;
        }
        //Si no ha elegido la opcion de salida entra al if
        if(op != 5) {
            //Para indicar que ha vuelto al menu
            std::cout << "\n--- Menu principal ---" << std::endl;
        }
        //Si elije la opcion de salida sale del ciclo y termina el programa
    } while(op != 5);

    return 0;
}
