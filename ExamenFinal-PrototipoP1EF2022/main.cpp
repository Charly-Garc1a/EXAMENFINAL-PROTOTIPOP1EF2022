/*
SEGUNDO PARCIAL - SERIE 3
CHARLY ALEXANDER GARCIA GOMEZ
9959-19-5853
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h> // getch
#include <vector>

/*Librerias para la Fecha y La Hora*/
#include <iomanip>
#include <ctime>

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <cstdlib>
#include <windows.h>

#define ENTER 13
#define BACKSPACE 8
#define INTENTOS 3
typedef struct {
   int  cuenta;
   char nomalum[40];
   char gmail[40];
   int primpar;
   int segpar;
   int estatus;
   int direccion;
   int nit;
}


Alumno;
void  MenuPrincipal(void);
void  SubMenu(void);
void  Crear(void);
void  Imprimir(void);
void  Anexar (void);
void  Modificar(void);
void  Borrar(void);

void  Catalogos(void);
void  Procesos(void);
void  MenuInformes(void);



void MenuEquipo(void);
void MenuPais(void);
void MenuPuesto(void);
void MenuJugador(void);

void CrearEquipo(void);
void AnexarEquipo(void);
void ImprimirEquipo(void);

void CrearPais(void);
void AnexarPais(void);
void ImprimirPais(void);

void CrearPuesto(void);
void AnexarPuesto(void);
void ImprimirPuesto(void);

void CrearJugador(void);
void AnexarJugador(void);
void ImprimirJugador(void);

int op,cent;
#include <iostream>
#include <fstream>

using namespace std;

//LOGIN//
int main(){




vector<string> usuarios;
    vector<string> claves;

    // Se añaden usuarios al vector
    usuarios.push_back("Charly");

    // Se añaden claves al vector
    claves.push_back("123");


    string usuario, password;

    int contador = 0;
    bool ingresa = false;

    do
    {

        system("cls");
        printf("\n--------------------CHARLY ALEXANDER GARCIA GOMEZ--------------------------\n");
        auto t = std::time(nullptr);
        auto tm = *std::localtime(&t);
        std::cout << std::put_time(&tm, "\n\t\t\t\t%d-%m-%Y %H-%M-%S\n") << std::endl;
        printf("\n---------------------------------------------------------------------------\n");
        printf("\n");
        Sleep(300);
        cout << "\t\t\t\tLOGIN DE USUARIO" << endl;
        cout << "\t\t\t\t----------------" << endl;
        cout << "\n\t\t\tUsuario: ";
        Sleep(200);
        getline(cin, usuario);

        char caracter;

        cout << "\t\t\tPassword: ";
        caracter = getch();

        password = "";

        while (caracter != ENTER)
        {

            if (caracter != BACKSPACE)
            {
                password.push_back(caracter);
                cout << "*";
            }
            else
            {
                if (password.length() > 0)
                {
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }

            caracter = getch();
        }

        for (int i = 0; i < usuarios.size(); i++)
        {
            if (usuarios[i] == usuario && claves[i] == password)
            {
                ingresa = true;
                break;
            }
        }

        if (!ingresa)
        {
            cout << "\n\n\t\t\tEl usuario y/o password son incorrectos" << endl;
            cin.get();
            contador++;
        }

    } while (ingresa == false && contador < INTENTOS);

    if (ingresa == false)
    {
        cout << "\n\tUsted no pudo ingresar al sistema. ADIOS" << endl;
    }
    else
    {
        system("cls");
        cout << "\n\n\t\t\t\t\t----------\2--------------" << endl;
        MenuPrincipal();

    }

    cin.get();

    return 0;

}

//MENU PRINCIPAL//
void MenuPrincipal(void){
      while(cent<=6){
            printf("\n---------------------------------------------------------------------------\n");
            printf("\t\t\t\tCHARLY GARCIA 9959-19-5853\n");
            printf("\t\t\t\tBIENVENDIO AL MENU PRINCIPAL DEL SISTEMA POLIDEPORTIVO\n");
            printf("\n\t\t\t\t1.- Catalogos\n");
            printf("\n\t\t\t\t2.- Procesos\n");
            printf("\n\t\t\t\t3.- Informes\n");
            printf("\n\t\t\t\t4.- Salir del menu\n");
            printf("\n\n\t\t\t\tOpcion: ");
            scanf("%d",&op);

            switch(op){
               case 1:
                  Catalogos();
               break;
               case 2:
                  Procesos();
               break;
               case 3:
                  MenuInformes();
               break;
               case 4:
                  cent=7;
               break;
               default:
                  system("cls");
                  printf("\n!!!Error, opcion inexistente!!!");
                  printf("\n Introduce una opcion valida");
                  getch();
               break;
            }
        system("cls");
        }
        getch();

}

//MENU DE CATALOGO//
void Catalogos(void){
    system("cls");
     cent=7;
      while(cent<=7){
            printf("Bienvenido al menu de CATALOGO");
            printf("\n\n1.- Crear archivo y crear un nuevo Entrenador");
            printf("\n\n2.- Visualizar la lista existente de Entrenadores");
            printf("\n\n3.- Añadir nuevo entrenador al archivo existente");
            printf("\n\n4.- Modificar el registro de un vendedor");
            printf("\n\n5.- Borrar el registro de Vendedor");
            printf("\n\n6.- Salir al Menu Principal");
            printf("\n\nOpcion: ");
            scanf("%d",&op);

            switch(op){
               case 1:
                  Crear();
               break;
               case 2:
                  Imprimir();
               break;
               case 3:
                  Anexar();
               break;
               case 4:
                  Modificar();
               break;
               case 5:
                  Borrar();
               break;
               case 6:
                  MenuPrincipal();
               break;
               default:
                  printf("\n!!!Error, opcion inexistente!!!");
                  printf("\n Introduce una opcion valida");
                  getch();
               break;
            }
        system("cls");
        }
        getch();
}

//FUNCION PARA CREAR EL ARCHIVO//
void Crear(void){
   FILE *fp;
   Alumno alm;
   // Creacion del archivo y guardar datos
   if(!(fp=fopen("entrenadores.dat","wb")))
   	printf("\n Error de apuertura del registro");
   else{
      fflush(stdin);
      system("cls");
      printf("\tELIGIO LA OPCION 1: CREAR ARCHIVO y AÑADIR UN ENTRENADOR");
      printf("\n\nIntroduce el Nombre del Entrenador: ");
      gets(alm.nomalum);
      printf("\nIntroduce el Codigo: ");
      scanf("%d",&alm.cuenta);
      printf("\nIntroduce la Fecha de Nacimiento: ");
      scanf("%d",&alm.direccion);
      printf("\nIntroduce el ID de USUARIO:  ");
      scanf("%d",&alm.segpar);
      printf("\nIntroduce la Foto del Entrenador:");
      scanf("%d",&alm.estatus);
      fwrite(&alm, sizeof(alm), 1, fp);
      printf("\n!!!REGISTRO REALIZADO CON EXITO!!!");
      printf("\nPresiona cualquier tecla para regresar al menu principal...");
      getch();
      fclose(fp);
      Catalogos();
   }
}

//FUNCION PARA IMPRIMIR EL REGISTRO DE VENDEDORES//
void Imprimir(void){
   FILE *fp;
   Alumno  alm;
   int n;
   if(!(fp=fopen("entrenadores.dat","rb")))
   	printf("Error de apuertura del registro");
   else{
      system("cls");
      printf("\tELIGIO LA OPCION 2:IMPRIMIR REGISTRO DE ENTRENADORES\n");
      printf("\n\n\t\t R E G I S T R O  D E V E N D E D O R E S \n");
      printf("\n---------------------------------------------------------------------------\n");
      printf("NOMBRE \tCODIGO \t FECHA-NAC \t ID USUARIO \t FOTO DEL DT");
      printf("\n-------------------------------------------------------------------------\n\n");
      while ((n=fread(&alm, sizeof(alm),1, fp))!=0){
         printf("%s \t\t",alm.nomalum);
         printf("%d \t\t",alm.cuenta);
         printf("%d \t",alm.direccion);
         printf("%d \t",alm.segpar);
         printf("%d \t\n",alm.estatus);
      }
      printf("\n-------------------------------------------------------------------------\n\n");
      printf("\nPresiona una tecla para continuar...");
      getch();
      fclose(fp);
   }
}

//FUNCION PARA ANEXAR DATOS AL REGISTRO DE EMPLEADO//
void Anexar(void){
   FILE *fp;
   Alumno	alm;

   system("cls");
   printf("\tELIGIO LA OPCION 3: ANEXAR ENTRENADORES AL ARCHIVO");
   printf("\n\n!!Se anexaran nuevos entrenadores al registro de entrenadores.dat!!\n");
   if(!(fp=fopen("entrenadores.dat","ab")))
   	printf("\n Error de apuertura del registro");
   else{
      fflush(stdin);
      printf("\n\nIntroduce el nombre del Entrenador: ");
      gets(alm.nomalum);
      fflush(stdin);
      printf("\nIntroduce el Codigo: ");
      scanf("%d",&alm.cuenta);
      printf("\nIntroduce la Fecha Nacimiento:  ");
      scanf("%d",&alm.direccion);
      printf("\nIntroduce el ID Usuario:  ");
      scanf("%d",&alm.segpar);
      printf("\nIntroduce la Foto del entrenador:  ");
      scanf("%d",&alm.estatus);
      fwrite(&alm, sizeof(alm), 1, fp);
      printf("\n!!!ANEXO REALIZADO CON EXITO!!!");
      printf("\nPresiona una tecla para continuar...");
      getch();
      fclose(fp);
   }
}

//FUNCION PARA MODIFICAR UN REGISTRO CON BUSQUEDA
void Modificar(void){
   FILE *fp;
   Alumno alm;
   int n,c,opc;

   if(!(fp=fopen("entrenadores.dat","r+b")))
   	printf("\n Error de apuertura del registro");
   else{
      system("cls");
      printf("\tELIGIO LA OPCION 4: MODIFICAR EL REGISTRO DE ENTRENADORES");
      printf("\n\nIntroduzca el Codigo de Entrenador: ");
      scanf("%d",&alm.cuenta);
      c=alm.cuenta;
      while ((n=fread(&alm, sizeof(alm), 1, fp))!=0 && alm.cuenta!=c);
      if (alm.cuenta!=c)
         printf("No existe el Codigo: %d ",c);
      else{
         system("cls");
         printf("\n!!Se encontro el Entrenador!!");
         printf("\n¿Que desea cambiar?, Seleccione una opcion");
         printf("\n\n1.-Nombre");
         printf("\n\n2.-Codigo");
         printf("\n\n3.-Fecha Nacimiento");
         printf("\n\n4.-ID Usuario");
         printf("\n\n6.-FOTO");
         printf("\n\nIntroduzca opicion: ");
         scanf("%d",&opc);
         switch(opc){
                     case 1:
                        fflush(stdin);
                        printf("\nIntroduzca el nuevo nombre: ");
                        gets(alm.nomalum);
                     break;
                     case 2:
                        printf("\nIntroduza el nuevo Codigo: ");
                        scanf("%d",&alm.cuenta);
                     break;
                     case 3:
                        printf("\nIntroduzca la nueva Fecha de Nacimiento: ");
                        scanf("%d",&alm.direccion);
                     break;
                     case 4:
                        printf("\nIntroduzca el numero de ID Usuario:  ");
                        scanf("%d",&alm.segpar);
                     break;
                     case 5:
                        printf("\nIntroduzca el numero de Foto:  ");
                        scanf("%d",&alm.estatus);
                     break;
                     default:
                        printf("\Error, opcion inexistente");
                     break;
         }
         printf("\nGrabando registro\n");
         fseek(fp,-sizeof(alm),SEEK_CUR);
         fwrite(&alm, sizeof(alm), 1, fp);
         printf("\nRegistro grabado con exito");
         printf("\nPresiona una tecla para continuar...");
         getch();
      }
      fclose(fp);
   }
}

//FUNCION PARA BORRAR REGISTROS DE  EMPLEADOS//
void Borrar(void){
   FILE *fp,*fd;
   Alumno alm;
   int n,c,encontrado=0;
 system("cls");
   printf("\tELIGIO LA OPCION 5: BORRAR EL REGISTRO DE UN ENTRENADOR");
   printf("\n\nIngrese el Codigo del Entrenador que desea Eliminar: ");
   scanf("%d",&alm.cuenta);
   c=alm.cuenta;
   if(!(fp=fopen("entrenadores.dat","rb")))
   	printf("\n Error de apuertura del registro");
   else{
      if(!(fd=fopen("auxregis.txt","wb")))
         printf("\n Error,imposible borrar registro, el archivo no existe");
      else{
         while ((n=fread(&alm, sizeof(alm), 1, fp))!=0){
            if(alm.cuenta!=c)
              fwrite(&alm, sizeof(alm), 1, fd);
            else
              encontrado=1;
         }
         fclose(fd);
      }
      fclose(fp);
      if(encontrado){
         system("del registro.dat");
         system("ren auxregis.txt registro.dat");
         printf("\n!!!Registro borrado satisfactoriamente!!!\n");
         printf("\n\nPresiona una tecla para continuar");
         getch();
      }
      else{
         system("del auxregis.txt");
         printf("\n!!!No se entontro ningun alumno con ese numero de cuenta!!!");
         printf("\n\nPresiona una tecla para continuar");
         getch();
      }
   }
}

void Procesos(void){
system("cls");
     cent=7;
      while(cent<=7){
            printf("Bienvenido al menu de PROCESOS");
            printf("\n\n1.- EQUIPO");
            printf("\n\n2.- PAIS");
            printf("\n\n3.- PUESTO");
            printf("\n\n4.- TIPO DE JUGADOR");
            printf("\n\n6.- Salir al Menu Principal");
            printf("\n\nOpcion: ");
            scanf("%d",&op);

            switch(op){
               case 1:
                  MenuEquipo();
               break;
               case 2:
                  MenuPais();
               break;
               case 3:
                  MenuPuesto();
               break;
               case 4:
                  MenuJugador();
               break;
               case 5:
                  system("cls");
                  MenuPrincipal();
               break;
               default:
                  printf("\n!!!Error, opcion inexistente!!!");
                  printf("\n Introduce una opcion valida");
                  getch();
               break;
            }
        system("cls");
        }
        getch();
}

void MenuEquipo(void){
system("cls");
     cent=7;
      while(cent<=7){
            printf("Bienvenido al menu de EQUIPO");
            printf("\n\n1.- Crear Archivo de EQUIPO");
            printf("\n\n2.- Anexar Equipos Nuevos al Archivo");
            printf("\n\n3.- Salir al Menu Principal");
            printf("\n\nOpcion: ");
            scanf("%d",&op);

            switch(op){
               case 1:
                  CrearEquipo();
               break;
               case 2:
                  AnexarEquipo();
               break;
               case 3:
                  MenuPrincipal();
               break;
               default:
                  printf("\n!!!Error, opcion inexistente!!!");
                  printf("\n Introduce una opcion valida");
                  getch();
               break;
            }
        system("cls");
        }
        getch();
}

void CrearEquipo(void){
FILE *fp;
   Alumno alm;
   // Creacion del archivo y guardar datos
   if(!(fp=fopen("equipos.dat","wb")))
   	printf("\n Error de apuertura del registro");
   else{
      fflush(stdin);
      system("cls");
      printf("\tELIGIO LA OPCION 1: CREAR ARCHIVO y AÑADIR UN EQUIPO");
      printf("\n\nIntroduce el Nombre del Equipo: ");
      gets(alm.nomalum);
      printf("\nIntroduce el Codigo del Equipo: ");
      scanf("%d",&alm.cuenta);
      printf("\nIntroduce el ID del entrenador: ");
      scanf("%d",&alm.direccion);
      fwrite(&alm, sizeof(alm), 1, fp);
      printf("\n!!!REGISTRO REALIZADO CON EXITO!!!");
      printf("\nPresiona cualquier tecla para regresar al menu principal...");
      getch();
      fclose(fp);
      MenuPrincipal();
   }
}

void AnexarEquipo(void){
FILE *fp;
   Alumno	alm;

   system("cls");
   printf("\tELIGIO LA OPCION 3: ANEXAR EQUIPOS AL ARCHIVO");
   printf("\n\n!!Se anexaran nuevos EMPLEADOS al registro de clientes.dat!!\n");
   if(!(fp=fopen("equipos.dat","ab")))
   	printf("\n Error de apuertura del registro");
   else{
      fflush(stdin);
      printf("\n\nIntroduce el nombre del cliente: ");
      gets(alm.nomalum);
      fflush(stdin);
      printf("\nIntroduce el Codigo: ");
      scanf("%d",&alm.cuenta);
      printf("\nIntroduce el ID del Entrenador:  ");
      scanf("%d",&alm.direccion);
      fwrite(&alm, sizeof(alm), 1, fp);
      printf("\n!!!ANEXO REALIZADO CON EXITO!!!");
      printf("\nPresiona una tecla para continuar...");
      getch();
      fclose(fp);
   }
}

void ImprimirEquipo(void){
     FILE *fp;
   Alumno  alm;
   int n;
   if(!(fp=fopen("equipos.dat","rb")))
   	printf("Error de apuertura del registro");
   else{
      system("cls");
      printf("\tELIGIO LA OPCION 2:IMPRIMIR REGISTRO EQUIPOS\n");
      printf("\n\n\t\t R E G I S T R O  D E   E Q U I P O S \n");
      printf("\n---------------------------------------------------------------------------\n");
      printf("EQUIPO \t\tCODIGO \t ID ENTRENADOR \t");
      printf("\n-------------------------------------------------------------------------\n\n");
      while ((n=fread(&alm, sizeof(alm),1, fp))!=0){
         printf("%s \t\t",alm.nomalum);
         printf("%d \t\t",alm.cuenta);
         printf("%d \t",alm.direccion);
      }
      printf("\n-------------------------------------------------------------------------\n\n");
      printf("\nPresiona una tecla para continuar...");
      getch();
      fclose(fp);
   }
}

void MenuPais(void){
system("cls");
     cent=7;
      while(cent<=7){
            printf("Bienvenido al menu de PAIS");
            printf("\n\n1.- Crear Archivo de Pais");
            printf("\n\n2.- Anexar Paises Nuevos al Archivo");
            printf("\n\nOpcion: ");
            scanf("%d",&op);

            switch(op){
               case 1:
                  CrearPais();
               break;
               case 2:
                  AnexarPais();
               break;
               default:
                  printf("\nPresiona una tecla para continuar...");
                  getch();
                  MenuPrincipal();
               break;
            }
        system("cls");
        }
        getch();
}

void CrearPais(void){
FILE *fp;
   Alumno alm;
   // Creacion del archivo y guardar datos
   if(!(fp=fopen("paises.dat","wb")))
   	printf("\n Error de apuertura del registro");
   else{
      fflush(stdin);
      system("cls");
      printf("\tELIGIO LA OPCION 1: CREAR ARCHIVO y AÑADIR UN PRODUCTO");
      printf("\n\nIntroduce el Nombre del Pais: ");
      gets(alm.nomalum);
      printf("\nIntroduce el ID del Pais: ");
      scanf("%d",&alm.cuenta);
      fwrite(&alm, sizeof(alm), 1, fp);
      printf("\n!!!REGISTRO REALIZADO CON EXITO!!!");
      printf("\nPresiona cualquier tecla para regresar al menu principal...");
      getch();
      fclose(fp);
      MenuPrincipal();
   }
}

void AnexarPais(void){
FILE *fp;
   Alumno	alm;

   system("cls");
   printf("\tELIGIO LA OPCION 3: ANEXAR PAIS AL ARCHIVO");
   printf("\n\n!!Se anexaran nuevos PAIS al registro de paises.dat!!\n");
   if(!(fp=fopen("paises.dat","ab")))
   	printf("\n Error de apuertura del registro");
   else{
      fflush(stdin);
      printf("\n\nIntroduce el nombre del Pais: ");
      gets(alm.nomalum);
      fflush(stdin);
      printf("\nIntroduce el Codigo del Pais: ");
      scanf("%d",&alm.cuenta);
      printf("\nIntroduce el ID del Entrenador:  ");
      scanf("%d",&alm.direccion);
      fwrite(&alm, sizeof(alm), 1, fp);
      printf("\n!!!ANEXO REALIZADO CON EXITO!!!");
      printf("\nPresiona una tecla para continuar...");
      getch();
      fclose(fp);
   }
}

void ImprimirPais(void){
FILE *fp;
   Alumno  alm;
   int n;
   if(!(fp=fopen("paises.dat","rb")))
   	printf("Error de apuertura del registro");
   else{
      system("cls");
      printf("\tELIGIO LA OPCION 2:IMPRIMIR REGISTRO DE PAISES\n");
      printf("\n\n\t\t R E G I S T R O  D E  P A I S E S \n");
      printf("\n---------------------------------------------------------------------------\n");
      printf("PAIS \tCODIGO \t ID ENTRENADOR \t");
      printf("\n-------------------------------------------------------------------------\n\n");
      while ((n=fread(&alm, sizeof(alm),1, fp))!=0){
         printf("%s \t\t",alm.nomalum);
         printf("%d \t\t",alm.cuenta);
         printf("%d \t",alm.direccion);
      }
      printf("\n-------------------------------------------------------------------------\n\n");
      printf("\nPresiona una tecla para continuar...");
      getch();
      fclose(fp);
   }
}

void MenuPuesto(void){
system("cls");
     cent=7;
      while(cent<=7){
            printf("Bienvenido al menu de Puesto");
            printf("\n\n1.- Crear Archivo de Puesto");
            printf("\n\n2.- Anexar Puesto Nuevos al Archivo");
            printf("\n\n6.- Salir al Menu Principal");
            printf("\n\nOpcion: ");
            scanf("%d",&op);

            switch(op){
               case 1:
                  CrearPuesto();
               break;
               case 2:
                  AnexarPuesto();
               break;
               case 3:
                  system("cls");
                  MenuPrincipal();
               break;
               default:
                  printf("\n!!!Error, opcion inexistente!!!");
                  printf("\n Introduce una opcion valida");
                  getch();
               break;
            }
        system("cls");
        }
        getch();
}

void CrearPuesto(void){
FILE *fp;
   Alumno alm;
   // Creacion del archivo y guardar datos
   if(!(fp=fopen("puestos.dat","wb")))
   	printf("\n Error de apuertura del registro");
   else{
      fflush(stdin);
      system("cls");
      printf("\tELIGIO LA OPCION 1: CREAR ARCHIVO y AÑADIR PUESTOS");
      printf("\n\nIntroduce el Nombre del puesto: ");
      gets(alm.nomalum);
      printf("\nIntroduce el Codigo del Puesto: ");
      scanf("%d",&alm.cuenta);
      printf("\nIntroduce el Salario:");
      scanf("%d",&alm.estatus);
      fwrite(&alm, sizeof(alm), 1, fp);
      printf("\n!!!REGISTRO REALIZADO CON EXITO!!!");
      printf("\nPresiona cualquier tecla para regresar al menu principal...");
      getch();
      fclose(fp);
      MenuPrincipal();
   }
}

void AnexarPuesto(void){
FILE *fp;
   Alumno	alm;

   system("cls");
   printf("\tELIGIO LA OPCION 3: ANEXAR PUESTOS AL ARCHIVO");
   printf("\n\n!!Se anexaran nuevos PUESTOS al registro de puestos.dat!!\n");
   if(!(fp=fopen("puestos.dat","ab")))
   	printf("\n Error de apuertura del registro");
   else{
      fflush(stdin);
      printf("\n\nIntroduce el nombre del Puesto: ");
      gets(alm.nomalum);
      fflush(stdin);
      printf("\nIntroduce el Codigo del Puesto: ");
      scanf("%d",&alm.cuenta);
      printf("\nIntroduce el Salario:  ");
      scanf("%d",&alm.estatus);
      fwrite(&alm, sizeof(alm), 1, fp);
      printf("\n!!!ANEXO REALIZADO CON EXITO!!!");
      printf("\nPresiona una tecla para continuar...");
      getch();
      fclose(fp);
   }
}

void ImprimirPuesto(void){
FILE *fp;
   Alumno  alm;
   int n;
   if(!(fp=fopen("puestos.dat","rb")))
   	printf("Error de apuertura del registro");
   else{
      system("cls");
      printf("\tELIGIO LA OPCION 2:IMPRIMIR REGISTRO DE PUESTOS\n");
      printf("\n\n\t\t R E G I S T R O  D E  P U E S T O S  \n");
      printf("\n---------------------------------------------------------------------------\n");
      printf("PUESTO \tCODIGO \t SALARIO");
      printf("\n-------------------------------------------------------------------------\n\n");
      while ((n=fread(&alm, sizeof(alm),1, fp))!=0){
         printf("%s \t\t",alm.nomalum);
         printf("%d \t\t",alm.cuenta);
         printf("%d \t\n",alm.estatus);
      }
      printf("\n-------------------------------------------------------------------------\n\n");
      printf("\nPresiona una tecla para continuar...");
      getch();
      fclose(fp);
   }
}

void MenuJugador(void){
system("cls");
     cent=7;
      while(cent<=7){
            printf("Bienvenido al menu de JUGADOR");
            printf("\n\n1.- Crear Archivo de JUGADOR");
            printf("\n\n2.- Anexar JUGADOR Nuevos al Archivo");
            printf("\n\n6.- Salir al Menu Principal");
            printf("\n\nOpcion: ");
            scanf("%d",&op);

            switch(op){
               case 1:
                  CrearJugador();
               break;
               case 2:
                  AnexarJugador();
               break;
               case 3:
                  system("cls");
                  MenuPrincipal();
               break;
               default:
                  printf("\n!!!Error, opcion inexistente!!!");
                  printf("\n Introduce una opcion valida");
                  getch();
               break;
            }
        system("cls");
        }
        getch();
}

void CrearJugador(void){
FILE *fp;
   Alumno alm;
   // Creacion del archivo y guardar datos
   if(!(fp=fopen("jugadores.dat","wb")))
   	printf("\n Error de apuertura del registro");
   else{
      fflush(stdin);
      system("cls");
      printf("\tELIGIO LA OPCION 1: CREAR ARCHIVO y AÑADIR JUGADORES");
      printf("\n\nIntroduce el Nombre del Jugador: ");
      gets(alm.nomalum);
      printf("\nIntroduce el Codigo del Jugador: ");
      scanf("%d",&alm.cuenta);
      printf("\nIntroduce el Numero de Posicion (1)Po (2)De (3)Me (4)Dt:");
      scanf("%d",&alm.estatus);
      fwrite(&alm, sizeof(alm), 1, fp);
      printf("\n!!!REGISTRO REALIZADO CON EXITO!!!");
      printf("\nPresiona cualquier tecla para regresar al menu principal...");
      getch();
      fclose(fp);
      MenuPrincipal();
   }
}

void AnexarJugador(void){
    FILE *fp;
   Alumno	alm;

   system("cls");
   printf("\tELIGIO LA OPCION 3: ANEXAR JUGADORES AL ARCHIVO");
   printf("\n\n!!Se anexaran nuevas LINEAS al registro de jugadores.dat!!\n");
   if(!(fp=fopen("jugadores.dat","ab")))
   	printf("\n Error de apuertura del registro");
   else{
      fflush(stdin);
      printf("\n\nIntroduce el nombre del Jugador: ");
      gets(alm.nomalum);
      fflush(stdin);
      printf("\nIntroduce el Codigo del Jugador: ");
      scanf("%d",&alm.cuenta);
      printf("\nIntroduce el Numero de Posicion (1)Po (2)De (3)Me (4)Dt:  ");
      scanf("%d",&alm.estatus);
      fwrite(&alm, sizeof(alm), 1, fp);
      printf("\n!!!ANEXO REALIZADO CON EXITO!!!");
      printf("\nPresiona una tecla para continuar...");
      getch();
      fclose(fp);
   }
}

void ImprimirJugador(void){
FILE *fp;
   Alumno  alm;
   int n;
   if(!(fp=fopen("jugadores.dat","rb")))
   	printf("Error de apuertura del registro");
   else{
      system("cls");
      printf("\tELIGIO LA OPCION 2:IMPRIMIR REGISTRO DE JUGADORES\n");
      printf("\n\n\t\t R E G I S T R O  D E  J U G A D O R E S \n");
      printf("\n---------------------------------------------------------------------------\n");
      printf("JUGADORES \tCODIGO \tPOSICION");
      printf("\n-------------------------------------------------------------------------\n\n");
      while ((n=fread(&alm, sizeof(alm),1, fp))!=0){
         printf("%s \t\t",alm.nomalum);
         printf("%d \t\t",alm.cuenta);
         printf("%d \t\n",alm.estatus);
      }
      printf("\n-------------------------------------------------------------------------\n\n");
      printf("\nPresiona una tecla para continuar...");
      void MenuInformes(void);
      getch();
      fclose(fp);
   }
}

void MenuInformes(void){
system("cls");
     cent=7;
      while(cent<=7){
            printf("Bienvenido al menu de PROCESOS");
            printf("\n\n1.- IMPRIMIR ENTRENADORES");
            printf("\n\n2.- IMPRIMIR EQUIPO");
            printf("\n\n3.- IMPRIMIR PAISES");
            printf("\n\n4.- IMPRIMIR PUESTOS");
            printf("\n\n5.- IMPRIMIR JUGADORES");
            printf("\n\nOpcion: ");
            scanf("%d",&op);

            switch(op){
               case 1:
                  Imprimir();
               break;
               case 2:
                  ImprimirEquipo();
               break;
               case 3:
                  ImprimirPais();
               break;
               case 4:
                  ImprimirPuesto();
               break;
               case 5:
                  ImprimirJugador();
               break;
               default:
                  printf("\nPresiona una tecla para continuar...");
                  getch();
                  MenuPrincipal();
               break;
            }
        system("cls");
        }
        getch();
}

