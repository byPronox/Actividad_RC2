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




void CAMI (int Datos[][2][7], FILE *archivoResultados) {

  int Ami = 0; // Año de máximo ingreso

  int Mi = 0;  // Número máximo de ingreso




  for (int a = 0; a < 5; a++) {

    int ti = 0; // Total de ingresos se inicializa en 0




    for (int s = 0; s < 2; s++) {

      for (int c = 0; c < 7; c++) {

        ti += Datos[a][s][c];

      }

    }




    if (ti > Mi) {

      Mi = ti;

      Ami = 2023 - 5 + a;

    }

  }




  fprintf(archivoResultados, "El año con la mayor cantidad de alumnos ingresaron a la universidad fue: %d\n", Ami);

}




void CCMI(int Datos[][2][7], FILE *archivoResultados) {

  int Mis = 0; // El mayor número de ingresos registrado

  int cma = 0; // La carrera a la que entraron la mayor cantidad de alumnos




  for (int c = 0; c < 7; c++) {

    int tdi = Datos[4][1][c]; // Total de ingresos en el último año (5 - 1 = 4 y 2 - 1 = 1)




    if (tdi > Mis) {

      Mis = tdi;

      cma = c;

    }

  }




  fprintf(archivoResultados, "La carrera que recibió la mayor cantidad de alumnos inscritos este último año fue la de %s\n", materias[cma]);

}




void CAMIS(int Datos[][2][7], FILE *archivoResultados) {

  int Is = 0; // Ingeniería de Software

  int Im = 0; // Ingresos mayores

  int Am = 0; // Años con mayor cantidad de alumnos que ingresaron




  for (int a = 0; a < 5; a++) {

    int idl = Datos[a][1][Is]; // Ingresos de la carrera




    if (idl > Im) {

      Im = idl;

      Am = 2023 - 5 + a;

    }

  }




  fprintf(archivoResultados, "La carrera de Ingeniería de Software recibió la mayor cantidad de alumnos en el año: %d\n", Am);

}




void mostrarMenu() {

  printf("Menu:\n");

  printf("1. Calcular el año con la mayor cantidad de alumnos ingresados a la universidad.\n");

  printf("2. Calcular la carrera que recibió la mayor cantidad de alumnos en el último año.\n");

  printf("3. Calcular el año en que la carrera de Ingeniería de Software recibió la mayor cantidad de alumnos.\n");

  printf("4. Salir.\n");

}




int main() {

  srand(time(NULL));




  // Se genera una matriz de datos usando el número de años (5), el número de semestres (2) y el número de carreras que son (7)

  int Datos[5][2][7];

  int a, s, c; // a = años, s = semestre, c = carreras




  for (a = 0; a < 5; a++) {

    for (s = 0; s < 2; s++) {

      for (c = 0; c < 7; c++) {

        Datos[a][s][c] = rand() % 201; // Generar los datos aleatoriamente entre 0 y 200

      }

    }

  }




  FILE *archivoDatos;

  archivoDatos = fopen("datos.txt", "w");

  if (archivoDatos == NULL) {

    printf("No se pudo abrir el archivo datos.txt.\n");

    return 1;

  }




  // Escribir los datos en el archivo datos.txt

  for (a = 0; a < 5; a++) {

    fprintf(archivoDatos, "Año %d:\n", 2023 - 5 + a);

    for (s = 0; s < 2; s++) {

      fprintf(archivoDatos, "Semestre %d:\n", s + 1);

      for (c = 0; c < 7; c++) {

        fprintf(archivoDatos, "Carrera %d - %s: %d alumnos\n", c + 1, materias[c], Datos[a][s][c]);

      }

    }

  }




  fclose(archivoDatos);




  int opcion;

  int salir = 0;




  FILE *archivoResultados;

  archivoResultados = fopen("resultados.txt", "w");

  if (archivoResultados == NULL) {

    printf("No se pudo abrir el archivo resultados.txt.\n");

    return 1;

  }




  while (!salir) {

    mostrarMenu();

    printf("Ingrese su opcion: ");

    scanf("%d", &opcion);




    switch (opcion) {

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
