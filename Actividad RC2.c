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

void mostrarMenu() {

  printf("Menu:\n");

  printf("1. Calcular el año con la mayor cantidad de alumnos ingresados a la universidad.\n");

  printf("2. Calcular la carrera que recibió la mayor cantidad de alumnos en el último año.\n");

  printf("3. Calcular el año en que la carrera de Ingeniería de Software recibió la mayor cantidad de alumnos.\n");

  printf("4. Salir.\n");

}




