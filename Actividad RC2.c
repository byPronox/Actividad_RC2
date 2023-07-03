#include <stdio.h>

#include <stdlib.h>

#include <time.h>

char *materias[] = {

    "Ingenieria de Software",

    "Administracion",

    "Economia",

    "Relaciones Internacionales",

    "Matematicas",

    "Contabilidad",

    "Ingenieria Industrial"};

void CAMI(int Datos[][2][7], FILE *archivoResultados)
{

    int Ami = 0; // Año de máximo ingreso

    int Mi = 0; // Número máximo de ingreso

    for (int a = 0; a < 5; a++)
    {

        int ti = 0; // Total de ingresos se inicializa en 0

        for (int s = 0; s < 2; s++)
        {

            for (int c = 0; c < 7; c++)
            {

                ti += Datos[a][s][c];
            }
        }

        if (ti > Mi)
        {

            Mi = ti;

            Ami = 2023 - 5 + a;
        }
    }

    fprintf(archivoResultados, "El año con la mayor cantidad de alumnos ingresaron a la universidad fue: %d\n", Ami);
}

void mostrarMenu()
{

    printf("Menu:\n");

    printf("1. Calcular el año con la mayor cantidad de alumnos ingresados a la universidad.\n");

    printf("2. Calcular la carrera que recibió la mayor cantidad de alumnos en el último año.\n");

    printf("3. Calcular el año en que la carrera de Ingeniería de Software recibió la mayor cantidad de alumnos.\n");

    printf("4. Salir.\n");
}

int main()
{
    srand(time(NULL));

    int Datos[5][2][7];

    int a, s, c;

    for (a = 0; a < 5; a++)
    {

        for (s = 0; s < 2; s++)
        {

            for (c = 0; c < 7; c++)
            {

                Datos[a][s][c] = rand() % 201;
            }
        }
    }

    FILE *archivoDatos;

    archivoDatos = fopen("datos.txt", "w");

    if (archivoDatos == NULL)
    {

        printf("No se pudo abrir el archivo datos.txt.\n");

        return 1;
    }

    for (a = 0; a < 5; a++)
    {

        fprintf(archivoDatos, "Año %d:\n", 2023 - 5 + a);

        for (s = 0; s < 2; s++)
        {

            fprintf(archivoDatos, "Semestre %d:\n", s + 1);

            for (c = 0; c < 7; c++)
            {

                fprintf(archivoDatos, "Carrera %d - %s: %d alumnos\n", c + 1, materias[c], Datos[a][s][c]);
            }
        }
    }

    fclose(archivoDatos);

    int opcion;

    int salir = 0;

    FILE *archivoResultados;

    archivoResultados = fopen("resultados.txt", "w");

    if (archivoResultados == NULL)
    {

        printf("No se pudo abrir el archivo resultados.txt.\n");

        return 1;
    }

    while (!salir)
    {

        mostrarMenu();

        printf("Ingrese su opcion: ");

        scanf("%d", &opcion);

        switch (opcion)
        {

        case 1:

            CAMI(Datos, archivoResultados);

            break;

        case 2:

            CCMI(Datos, archivoResultados);

            break;

        case 3:

            CAMIS(Datos, archivoResultados);

            break;

        case 4:

            salir = 1;

            break;

        default:

            printf("Opcion no valida. Por favor, ingrese una opcion valida.\n");
        }

        printf("\n");
    }

    fclose(archivoResultados);

    printf("Los resultados se han guardado en el archivo resultados.txt.\n");

    return 0;
}
