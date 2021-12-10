#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_menu();
void show_suggestion();
void write_suggestion();
void test_covid();
void help();

void help()
{
    printf("Para poder usar el programa, deberas escribir un numero del 1 al 5 para indicar la opcion que deseas.\n");
    show_menu();
}

struct personal_data
{
    char name[25];
    char sex[25];
    char colonia[25];
    char municipio[25];
    int age;
    int phone_number;
};

void show_suggestion()
{
    FILE *fp;
    char content;
    fp = fopen("suggestion.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    else
    {
        printf("Sugerencias:\n");
        while ((content = fgetc(fp)) != EOF)
        {
            printf("%c", content);
        }
    }
    fclose(fp);
}

void write_suggestion()
{
    FILE *fp;
    char suggestion[100];
    fp = fopen("sugerencias.txt", "r");
    if (fp == NULL)
    {
        printf("No se pudo abrir el archivo");
        exit(1);
    }
    while (fgets(suggestion, 100, fp) != NULL)
    {
        printf("%s", suggestion);
    }
    fclose(fp);
}

void test_covid()
{
    int in_Q2, in_Q3, in_Q4, in_Q5, in_Q6, in_Q7, in_Q8, in_Q9, in_Q10, in_Q11, in_Q12, in_Q13;
    printf("Si=1 y No=0\n\n");
    printf("¿Has presentado alguno de los siguientes síntomas?\n");
    printf("Fiebre mayor a 38°C\n");
    scanf("%d", &in_Q2);
    printf("Tos\n");
    scanf("%d", &in_Q3);
    printf("Dificultad para respirar (sentir que le falta aire)\n");
    scanf("%d", &in_Q4);
    printf("Fatiga\n");
    scanf("%d", &in_Q5);
    printf("Dolores musculares y corporales\n");
    scanf("%d", &in_Q6);
    printf("Dolor de cabeza\n");
    scanf("%d", &in_Q7);
    printf("Perdida reciente del olfato o el gusto\n");
    scanf("%d", &in_Q8);
    printf("Congestión nasal o moqueo\n");
    scanf("%d", &in_Q9);
    printf("Nauseas o vomito\n");
    scanf("%d", &in_Q10);
    printf("Diarrea\n");
    scanf("%d", &in_Q11);
    printf("Viaje o estancia a países con transmisión local\n");
    scanf("%d", &in_Q12);
    printf("Has tenido contacto con un caso sospechoso o confirmado de COVID-19 en los 14 días previos\n");
    scanf("%d", &in_Q13);
    int sum = in_Q2 + in_Q3 + in_Q4 + in_Q5 + in_Q6 + in_Q7 + in_Q8 + in_Q9 + in_Q10 + in_Q11 + in_Q12 + in_Q13;
    if(sum>=7){
        printf("Cuídate, aqui tienes algunas sugerencias:\n");
        show_suggestion();
    } else {
        printf("No tienes síntomas de COVID-19, no necesitas atención médica.\n");
    }
}

void show_menu()
{
    int answer;
    printf("Selecciona una opcion:\n1.Cuestinario de covid\n2.Sugerencias\n3.Escribir una cugerencia\n4.Ayuda\n5.Salir\n");
    scanf("%d", &answer);
    switch (answer)
    {
    case 1:
        test_covid();
        break;
    case 2:
        show_suggestion();
        break;
    case 3:
        write_suggestion();
        break;
    case 4:
        help();
        break;
    case 5:
        printf("Adios\n");
        exit(0);
        break;
    default:
        printf("\nOpcion no valida\n");
        break;
    }
}

void requirements()
{
    struct personal_data person;
    printf("Ingresa tu nombre: ");
    scanf("%s", person.name);
    printf("Ingresa tu sexo: ");
    scanf("%s", person.sex);
    printf("Ingresa tu colonia: ");
    scanf("%s", person.colonia);
    printf("Ingresa tu municipio: ");
    scanf("%s", person.municipio);
    printf("Ingresa tu edad: ");
    scanf("%d", &person.age);
    printf("Ingresa tu numero de telefono: ");
    scanf("%d", &person.phone_number);
    show_menu();
}

int main(int argc, char **argv)
{
    requirements();
    return 0;
}
