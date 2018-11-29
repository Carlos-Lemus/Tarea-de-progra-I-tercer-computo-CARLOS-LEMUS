//Hecho por Carlos Alfonso Lemus Rodezno LR18001

//Programa que reaaliza la serie de numeros fiboanacci y taylor y los muestra

#include <iostream> //Libreria estandar nos permite usar sus funciones
#include <fstream> //libreria que permite la manipulacion de archivos txt
#include <windows.h> //libreria nos permite usar sus funciones

using namespace std; //espacion de nombre usar std nos permite abrebiar el codigo

void menu(); //declaracion de funcion que contiene el menu
void fibonacci(); //declaracion de funcion que ingresara la seire de fibonacci
void taylor(); //declaracion de funcion que ingresara la serie de taylor
void resulfibonacci(); //declaracion de funcion que mostrara la serie de fibonacci
void resultaylor(); //declaracion de funcion que mostrara la serie de taylor
void clear(); //Funcion que permite limpiar la pantalla
void cargar(); //Declaracion //funcion que permite dar un tiempo de carga
void errordato(); //Declaracion funcion que evita que se ingrese datos incorrectos

int main()
{
    
    menu(); //se dirigira a la funion menu
    
    system("pause");
    return 0;
}

void menu() // funcion que contiene el menu
{   //declaracion de variables
    int opcion;
    
    //ciclo que evita la entrada de datos erroneos
    do{
        clear(); //funcion que limpia la pantalla de la consola del texto que se encuentre en ella
        
        system("color 4E"); //añade color al fondo y letra de la consola
        
        cout << "-------------------" << endl;
        cout << "*                 *" << endl;  
        cout << "*       MENU      *" << endl;
        cout << "*                 *" << endl;
        cout << "-------------------" << endl;
        
        cout << "\nOpciones" << endl;
        cout << "1.Serie de numeros de fibonacci" << endl;
        cout << "2.Serie de numeros de taylor" << endl;
        cout << "3.Resultados series de numero de fibonacci" << endl;
        cout << "4.Resultado series de numero de taylor" << endl;
        cout << "5.Salir" << endl;
        
        cout << "\nElija una opcion: ";
        cin >> opcion;
        errordato(); //Funcion que se utiliza para evitar errores de datos
        
    } while(opcion < 1 || opcion > 5);
    
    switch(opcion) //sentencia para eleijir una opcion
    {
        case 1:
            fibonacci();
            break;
        case 2:
            taylor();
            break;
        case 3:
            cout << '\a'; //produce un sonido
            resulfibonacci();
            break;
        case 4:
            cout << '\a'; //produce un sonido
            resultaylor();
            break;
        case 5:
            clear(); //funcion que limpia la pantalla de la consola del texto que se encuentre en ella
            cout << "Gracias por usar el programa\n" << endl;
            break;            
    
    }
}

void fibonacci() //funcion que ingresara la seire de fibonacci
{
    ofstream archivo("fibonacci.txt"); //se crea un archivo txt
    //Delacaracion de variables
    int series;
    int x = 0;
    int y = 1;
    int z = 0;
    
   do {
        clear(); //funcion que limpia la pantalla de la consola del texto que se encuentre en ella
         
        cout << "\nSerie de Numeros Fibonacci" << endl;
        cout << "==========================" << endl;
        
        cout << "\nIngrese el numero de series de fibonacci: ";
        cin >> series;
        errordato(); //Funcion que se utiliza para evitar errores de datos
    } while(series < 1);
    
    archivo << "\nResultado de fibonaccir\n";
    archivo << "***********************\n\n";
    archivo << "Numero de la opcion elejida: 1" << endl;
    archivo << "Nombre de la serie: fibonacci" << endl;
    archivo << "Numero de series ingresado: " << series << endl; 
    
    archivo << "Resultado: 1, ";
    cout << "1, ";
    
    for(int i = 1; i <= series; i++)
    {
        //se intercambian el valor de las variables para generar la serie fibonacci
        x = y;
        y = z;
        z = x + y;
        
        //se imprime el el resutao de cada iteracione en el archivo txt
        archivo << z << ", ";
        cout << z << ", ";
             
    }
    
    archivo << "\n\n";
    cout << "\n\n";
    
    archivo.close(); //se cierra eñ archivo txt
    system("pause");
    menu();
}

void taylor() //funcion que ingresara la serie de taylor
{
    ofstream archivo("taylor.txt"); //se crea un archivo txt
    
    //declaracion de variables
    int i;
    int j;
    int n;
    double x;
    double dividiendo;
    double divisor;
    double signo;
    double seno = 0;
    //ciclo para evitar el ingreso de datos erroneos
    do {
        
        clear(); //funcion que limpia la pantalla de la consola del texto que se encuentre en ella
    
        cout << "\nSerie de Numeros de Taylor" << endl;
        cout << "==========================" << endl;
        
        cout << "\nIngrese el numero de la serie de taylor: ";
        cin >> n;
        
        cout << "\nIngrese el valor de x: ";
        cin >> x;
    
    } while (cin.fail());
    
    
    cout << "\n\n";
    //ciclo para calcular el valor de seno
    for(i = 0; i <= n; i++) {
        
        dividiendo = 1;
        for(j = 0; j < 2*i+1; j++) {
        
            dividiendo *= x;
        
        }
        
        divisor = 1;
        for(j = 1; j <= 2*i+1; j++) {
        
            divisor *= j;
        
        }
        
        if(i%2==0) {
            signo = -1;
        }
        else {
            signo = 1;
        }
        
        seno = seno + (dividiendo / divisor) * signo;
        
    }
    //se imprime en el archivo txt los datos
    archivo << "\nResultado de la Taylor\n";
    archivo << "***********************\n\n";
    archivo << "Numero de la opcion elejida: 2" << endl;
    archivo << "Nombre de la serie: Taylor" << endl;
    archivo << "Numero de serie ingresado de taylor: " << n << endl; 
    archivo << "Valor de x ingresado: " << n << endl; 
    archivo << "El rsultado de la serie de taylor es de: " << seno << "\n\n"; 
    
    cout << "El resultado de la serie de taylor es de: " << seno << "\n\n";
    
    archivo.close(); //se cierra el archivo txt creado
    system("pause");
    menu();
}

void resulfibonacci() //funcion que mostrara la serie de fibonacci
{
    clear(); //funcion que limpia la pantalla de la consola del texto que se encuentre en ella
    
    /*ifstream es un tipo especializado en tipo caracteres que permite la lectura al fichero
	por eso definimos nuestra fichero como de tipo ifstream*/
	ifstream archivo;
	
	//Abrimos el archivo con la funcion open y especificamos con ios::in que leermos los datos del fichero
	archivo.open("fibonacci.txt", ios::in);
	//ciclo en caso de que ocurra un error
	if(archivo.fail()){
        
        cout << "Se produjo un error, ingrese a la opcion 1 primero\n\n";
        system("pause"); 
        menu();
         
    }
	//declaracion de variable
	string texto;
	//ciclo para imprimer la informacion del archivo txt
    while(!archivo.eof()){
    
        getline(archivo, texto);
        cout << texto << endl;
    
    }
	
	//finalmente se cierra el fichero con la funcion close()
	archivo.close();
  
    system("pause");
    menu();
}

void resultaylor() //funcion que mostrara la serie de taylor
{
    clear(); //funcion que limpia la pantalla de la consola del texto que se encuentre en ella
    
    /*ifstream es un tipo especializado en tipo caracteres que permite la lectura al fichero
	por eso definimos nuestra fichero como de tipo ifstream*/
	ifstream archivo2;
	
	//Abrimos el archivo con la funcion open y especificamos con ios::in que leermos los datos del fichero
	archivo2.open("taylor.txt", ios::in);
	//ciclo en caso de que ocurra un error
	if(archivo2.fail()){
        
        cout << "Se produjo un error, ingrese a la opcion 2 primero\n\n";
        system("pause"); 
        menu();
    }
	//declaracion de variable
	string texto2;
	//ciclo para imprimer la informacion del archivo txt
    while(!archivo2.eof()){
    
        getline(archivo2, texto2);
        cout << texto2 << endl;
    
    }
	
	//finalmente se cierra el fichero con la funcion close()
	archivo2.close();
  
    system("pause");
    menu();
}

void clear() //Funcion que permite limpiar la pantalla
{
	//funcion system("cls") que limpia la pantalla de los textos que esta contiene
	system("cls");
}

void errordato() //funcion que evita que se ingrese datos incorrectos
{
		//Ciclo while paraevitar datos incorrectos
		while(cin.fail()){
		
		//Limpia el buffer de los datos ingresados
		cin.clear();
		
		//Ignora los primeros 1000 caracteres o en este caso los numeros
		cin.ignore(1000,'\n');
		
		}
}
