using namespace std;
#include <iostream>
#include <fstream> //guardar fichero
#include<stdlib.h>

int main()
{
    int cod,opcion,Bcod,glg,tol,xld;
    char nombre[10],apellido[10], puest[15];
    ofstream Guardar;
    ifstream Leer;
    fstream Temp; //referencia aun archivo temporal
    Guardar.open("dat.txt",ios::app);
    while(true)
    {
        cout<<"//////////////////"<<endl;
        cout<<"1 GUARDAR EMPLEADO"<<endl;
        cout<<"2 LEER EMPLEADOS"<<endl;
        cout<<"3 BUSCAR EMPLEADO"<<endl;
        cout<<"4 MODIFICAR DATO"<<endl;
        cout<<"5 ELIMINAR EMPLEADO"<<endl;
        cout<<"6 SALIR"<<endl;
        cout<<"//////////////////"<<endl;
        cout<<endl;
        cout<<"Elija una opcion:"<<endl;
        cin>>opcion;

        switch(opcion)
        {
            case 1:
                {
                    system("cls");
                    cout<<"Ingrese Nombre: ";
                    cin>>nombre;
                    cout<<"Ingrese Apellido: ";
                    cin>>apellido;
                    cout<<"Ingrese El sueldo base + bonificacion: ";
                    cin>>glg;
                    cout<<"Ingrese puesto : ";
                    cin>>puest;
                    cout<<"Ingrese su codigo: ";
                    cin>>cod;
                    Guardar<<nombre<<" "<<apellido<<" "<<glg<<" "<<puest<<" "<<cod<<endl;
                    break;
                }
            case 2:
                {
                    system("cls");  
                    Leer.open("dat.txt");
                    Leer>>nombre>>apellido>>glg>>puest;
                    while(!Leer.eof())
                    {
                        Leer>>cod;
                        cout<<"----------------------------"<<endl;
                        cout<<"Nombre:    "<<nombre<<endl;
                        cout<<"Apellido:  "<<apellido<<endl;
                        cout<<"Sueldo:      "<<glg<<" Q"<<endl;
                        cout<<"Puesto:  "<<puest<<endl;
                        cout<<"Codigo:    "<<cod<<endl;
                        cout<<"----------------------------"<<endl;
                        cout<<endl;
                        Leer>>nombre>>apellido>>glg>>puest;
                    }
                    Leer.close();
                    break;
                }
            case 3:
                {
                    system("cls");  
                    Leer.open("dat.txt");
                    Leer>>nombre>>apellido>>glg>>puest;
                    bool encontrado=false;
                    cout<<"Ingrese su codigo para buscar:"<<endl;
                    cin>>Bcod;
                    while(!Leer.eof())
                    {
                        Leer>>cod;
                        if(cod==Bcod)
                        {
                            encontrado=true;
                              cout<<"----------------------------"<<endl;
                        cout<<"Nombre:    "<<nombre<<endl;
                        cout<<"Apellido:  "<<apellido<<endl;
                        cout<<"Sueldo:      "<<glg<<" Q"<<endl;
                        cout<<"Puesto:  "<<puest<<endl;
                        cout<<"Codigo:    "<<cod<<endl;
                        cout<<"----------------------------"<<endl;
                            cout<<endl;
                        }
                        Leer>>nombre>>apellido>>glg>>puest;
                    }
                    if(encontrado==false)
                    {
                        cout<<"Codigo no encontrad"<<endl;
                    }
                    Leer.close();
                    break;
                }

            case 4:
                {
                    system("cls");  
                    Leer.open("dat.txt");//abre fichero original
                    Temp.open("Temp.txt");//abrimos el temporal tambn
                    Leer>>nombre>>apellido>>glg>>puest;
                    bool encontrado=false;
                    cout<<"Ingrese codigo a modificar"<<endl;
                    cin>>Bcod;
                    while(!Leer.eof())
                    {
                        Leer>>cod;
                        if(cod==Bcod)
                        {
                            encontrado=true;
                            cout<<"----------------------------"<<endl;
                        cout<<"Nombre:    "<<nombre<<endl;
                        cout<<"Apellido:  "<<apellido<<endl;
                        cout<<"Sueldo base:      "<<glg<<" Q"<<endl;
                        cout<<"Puesto:  "<<puest<<endl;
                        cout<<"Codigo:    "<<cod<<endl;
                        cout<<"----------------------------"<<endl;
                            cout<<endl;
                            cout<<"Ingrese su nuevo sueldo a modificar: "<<endl;
                            cin>>xld;
                            cout<<"Ingrese su nuevo puesto: "<<endl;
                            cin>>tol;
                            Temp<<nombre<<" "<<apellido<<" "<<xld<<" "<<tol<<" "<<cod<<endl;
                            cout<<endl;
                            cout<<"Modificado :)"<<endl;
                        }
                        else
                        {
                            Temp<<nombre<<" "<<apellido<<" "<<glg<<" "<<puest<<" "<<cod<<endl;
                        }
                        Leer>>nombre>>apellido>>glg>>puest;
                    }
                    if(encontrado==false)
                    {
                        cout<<"Codigo no encontrada"<<endl;
                    }
                    Leer.close();
                    Temp.close();
                    remove("dat.txt");
                    rename("Temp.txt","Fichero.txt");
                    break;
                }

            case 5:
                {
                    system("cls");
                    Leer.open("dat.txt");
                    Temp.open("Temp.txt");
                    Leer>>nombre>>apellido>>glg>>puest;
                    bool encontrado=false;
                    cout<<"Ingrese clave a eliminar"<<endl;
                    cin>>Bcod;
                    while(!Leer.eof())
                    {
                        Leer>>cod;
                        if(cod==Bcod)
                        {
                            encontrado=true;
                             cout<<"----------------------------"<<endl;
                        cout<<"Nombre:    "<<nombre<<endl;
                        cout<<"Apellido:  "<<apellido<<endl;
                        cout<<"Sueldo :      "<<glg<<" Q"<<endl;
                        cout<<"Puesto:  "<<puest<<endl;
                        cout<<"Codigo:    "<<cod<<endl;
                        cout<<"----------------------------"<<endl;
                            cout<<endl;
                            cout<<"Eliminado"<<endl;
                        }
                        else
                        {
                            Temp<<nombre<<" "<<apellido<<" "<<glg<<" "<<puest<<" "<<cod<<endl;
                        }
                        Leer>>nombre>>apellido>>glg>>puest;
                    }
                    if(encontrado==false)
                    {
                        cout<<"Codigo no encontrada"<<endl;
                    }
                    Leer.close();
                    Temp.close();
                    remove("dat.txt");
                    rename("Temp.txt","dat.txt");

                    break;
                }

            case 6:
                {
                    system("cls");

                    break;
                }   
        }   
    }
    return 0;
}
