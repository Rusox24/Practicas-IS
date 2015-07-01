#include<stdio.h>

#include<conio.h>

#include<iostream>

#define bool int

#define true 1

#define false 0

using namespace std;
 

 

FILE *archivo, *temporal;

 

void AGREGAR_PERSONA()

{

	int dni, registro;

	char apellido[20], nombre[20], telefono[15], resp;

	bool no_encontrado;

	do{

		if((archivo = fopen("datos.ag","r")) == NULL)

		{

			cout<<"\n No se Encuentra el Archivo!";

			cout<<"\n\n Pulse una tecla para continuar...";

			getch();

		}else{

			//clrscr();

			no_encontrado = true;

			cout<<"\n Introduzca el dni: "; cin>> registro;

			while ((!feof(archivo)) && (no_encontrado))

			{

				fscanf(archivo,"%d %s %s %s", &dni, &apellido, &nombre, &telefono);

				if(registro == dni)

				{

					no_encontrado = false;

				}

			}

			fclose(archivo);

			if(no_encontrado)

			{

				archivo = fopen("datos.ag","a");

				dni = registro;

				cout<<" Introduzca el Apellido: "; cin>> apellido;

				cout<<" Introduzca el Nombre: "; cin>> nombre;

				cout<<" Introduzca el Telefono: "; cin>> telefono;

				fprintf(archivo,"%d %s %s %s\n", dni, apellido, nombre, telefono);

			}else{

				cout<<"\n El paciente ya existe en la agenda";

			}

			cout<<"\n\n Desea registrar otro paciente? S/N: "; resp = getch();

			fclose(archivo);

		}

	}while((resp == 's') || (resp == 'S'));

} //Fin del procedimiento AGREGAR_PERSONA

 

void CONSULTAR_REGISTRO()

{

	int registro, dni; // Se declaran enteros porque si se dejan como string luego no se puede hacer la comparacion normal sino por comparacion de cadenas.

	char apellido[20], nombre[20], telefono[15], resp;

	bool no_encontrado;

	do{

		if((archivo = fopen("datos.ag","r")) == NULL)

		{

			cout<<"\n No se Encuentra el Archivo!";

			cout<<"\n\n Pulse una tecla para continuar...";

			getch();

		}else{

			//clrscr();

			no_encontrado = true;

			cout<<"\n Introduzca la dni a Consultar: "; cin>>registro;

			while((!feof(archivo)) && (no_encontrado))

			{

				fscanf(archivo,"%d %s %s %s", &dni, &apellido, &nombre, &telefono);

				if(registro == dni)

				{

					no_encontrado = false;

				}

			}

			if(no_encontrado)

			{

				cout<<"\n No existe ningun paciente con el DNI indicado\n\n";

			}else{

				cout<<"\n Paciente encontrado \n\n";

				cout<<" dni:   " <<dni <<"\n";

				cout<<" Apellido: " <<apellido <<"\n";

				cout<<" Nombre:   " <<nombre <<"\n";

				cout<<" Telefono: " <<telefono <<"\n\n";

			}

			cout<<" Desea realizar otra consulta? S/N: "; resp = getch();

			fclose(archivo);

		}

	}while((resp == 's') || (resp == 'S'));

} //Fin del procedimiento CONSULTAR_REGISTRO

 

void ELIMINAR_PERSONA()

{

	int registro, dni;

	char resp, apellido[20], nombre[20], telefono[15], eliminar;

	bool no_encontrado;

	do{

		if ((archivo = fopen("datos.ag","r")) == NULL)

		{

			cout<<"\n No se encuentra el archivo";

			cout<<"\n\n Pulse una tecla para continuar...";

			getch();

		}else{

			//clrscr();

			no_encontrado = true;

			cout<<"\n Introduzca el DNI del paciente: "; cin>>registro;

			while((!feof(archivo)) && (no_encontrado))

			{

				fscanf(archivo,"%d %s %s %s", &dni, &apellido, &nombre, &telefono);

				if(registro == dni)

				{

					no_encontrado = false;

				}

			}

			if(no_encontrado)

			{

				cout<<"\n No existe ningun registro con el DNI indicado \n\n";

			}else{

				cout<<"\n Registro encontrado\n\n";

				cout<<" DNI:   " <<dni <<"\n";

				cout<<" Apellido: " <<apellido <<"\n";

				cout<<" Nombre:   " <<nombre <<"\n";

				cout<<" Telefono: " <<telefono <<"\n\n";

				fclose(archivo);

				cout<<" Desea eliminar este paciente? S/N: "; eliminar = getch();

			}

			if ((eliminar == 's') || (eliminar == 'S'))

			{

				if((archivo = fopen("datos.ag","r")) == NULL)

				{

					cout<<"\n No se encuentra el archivo";

					cout<<"\n\n Pulse una tecla para continuar...";

					getch();

				}else{

					temporal = fopen("temporal.ang","w");

					while(!feof(archivo))

					{

						fscanf(archivo,"%d %s %s %s\n", &dni, &apellido, &nombre, &telefono);

						if (registro != dni)

						{

							fprintf(temporal,"%d %s %s %s\n", dni, apellido, nombre, telefono);

						}

					}

					fclose(temporal);

					fclose(archivo);

					if((temporal = fopen("temporal.ang","r")) == NULL)

					{

						cout<<"\n ERROR: No se encuentra el archivo";

						cout<<"\n\n Pulse una tecla para continuar...";

						getch();

					}else{

						archivo = fopen("datos.ag","w");

						while(!feof(temporal))

						{

							fscanf(temporal,"%d %s %s %s\n", &dni, &apellido, &nombre, &telefono);

							fprintf(archivo,"%d %s %s %s\n", dni, apellido, nombre, telefono);

						}

						fclose(temporal);

						fclose(archivo);

						cout<<"\n\n Se ha eliminado el registro";

						//Vaciamos el Archivo temporal

						temporal = fopen("temporal.ang","w");

						fclose(temporal);

					}

				}

			}

			cout<<"\n\n ¿Desea eliminar otro registro? S/N: "; resp = getch();

		}

	}while((resp == 's') || (resp == 'S'));

} //Fin del procedimiento ELIMINAR_REGISTRO

 

void VACIAR_AGENDA()

{

	char resp;

	cout<<"\n\n Se procedera al borrado total de la agenda, ¿Esta seguro? S/N: "; cin>> resp;

	if ((resp == 's') || (resp == 'S'))

	{

		if((archivo = fopen("datos.ag","w")) == NULL)

		{

			cout<<"\n No se encuentra el archivo";

			cout<<"\n\n Pulse una tecla para continuar...";

			getch();

		}else{

			fclose(archivo);

			cout<<"\n Datos de agenda eliminados";

			cout<<"\n\n Pulse una tecla para continuar...";

			getch();

		}

	}

} //Fin del procedimiento VACIAR_AGENDA

 

void DESPLEGAR_AGENDA()

{

	char dni[8], apellido[20], nombre[20], telefono[15];

	if((archivo = fopen("datos.ag","r")) == NULL)

	{

		cout<<"\n No se encuentra el archivo";

		cout<<"\n\n Pulse una tecla para continuar...";

		getch();

	}else{

		//clrscr();
		cout<<"\n";
		
		cout<<"  DNI        APELLIDO        NOMBRE        TELEFONO\n\n";

		while(!feof(archivo))

		{

			fscanf(archivo,"%s %s %s %s\n", &dni, &apellido, &nombre, &telefono);

			cout<<" "<<dni<<"     "<<apellido<<"         "<<nombre<<"          "<<telefono<<"\n";

		}

		fclose(archivo);

		cout<<"\n\n Pulse una tecla para continuar...";

		getch();

	}

} //Fin del procedimiento DESPLEGAR_AGENDA


void MENU()

{

	cout<<"\n  AGENDA ELECTRONICA \n";

	cout<<" 1- Agregar un paciente \n";

	cout<<" 2- Buscar un paciente \n";

	cout<<" 3- Listar todos los pacientes \n";

	cout<<" 4- Eliminar un paciente \n";

	cout<<" 5- Vaciar la Agenda \n\n";

	cout<<" S- Salir.\n";

} // Fin del procedimiento MENU

 

int main ()

{

	char op;

	bool salir = false;

	do{

		//clrscr();

		if ((archivo = fopen("datos.ag","r")) == NULL)

		{

			archivo = fopen("datos.ag","w");

			fclose(archivo);

			cout<<"\n\n Archivo creado con exito\n\n";

			MENU();

			cout<<"\n Seleccione una opcion: "; op = getch();

		}else{

			MENU();

			cout<<"\n Seleccione una opcion: "; op = getch();

		}

		switch (op)

		{

			case '1':

				AGREGAR_PERSONA();

				break;

			case '2':

				CONSULTAR_REGISTRO();

				break;

			case '3':

				DESPLEGAR_AGENDA();

				break;

			case '4':

				ELIMINAR_PERSONA();

				break;

			case '5':

				VACIAR_AGENDA();

				break;

			case 's': case 'S':

				salir = true;

				break;

		}

	}while(salir == false);

} // Fin del main (void)
