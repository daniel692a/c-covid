#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void suggestion(){
    FILE *fp;
    char suggestion;
    fp = fopen("sugerencias.txt", "a+t");
    if (fp == NULL)
    {
        printf("No se pudo abrir el archivo");
        exit(1);
    }
    printf("\nIntroduce tu sugerencia: ");
    while ((suggestion = getchar()) != '\n')
    {
        printf("%c", fputc(suggestion, fp));
    }
    fclose(fp);
}

void write_suggestion(){
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

struct personal_data{
    char name[25];
    char sex[25];
    char colonia[25];
    char municipio[25];
    int age;
    int phone_number;
};

void test_covid(){

}

int show_menu(){
    int answer;
    switch (answer){
    case 1:
        test_covid();
        break;
    case 2:
        suggestion();
        break;
    case 3:
        write_suggestion();
        break;
    default:
        break;
    }
}

void requirements() {
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
    suggestion();
    return 0;
}
