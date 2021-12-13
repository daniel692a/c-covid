#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_menu();
void show_suggestion();
void write_suggestion();
void test_covid();
void help();
void show_suggestion1();

void help()
{
    /*
    * Funcion help():
    * Esta funcion se encarga de mostrar una pequeña ayuda al usuario
    */
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
    /*
    * Funcion show_suggestion():
    * Esta funcion se encarga de mostrar recomendaciones para el tratamiento de COIVD 19
    */
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
        printf("\n\t\t\tRECOMENDACIONES:\n\n");
        while ((content = fgetc(fp)) != EOF)
        {
            printf("%c", content);
        }
    }
    fclose(fp);
}

void show_suggestion1()
{
    /*
    * Funcion show_suggestion1():
    * Esta funcion se encarga de mostrar medidas de prevencion para evitar el contagio de covid19.
    */
	FILE *fp;
	char content;
	fp = fopen("suggestion1.txt", "r");
	if (fp == NULL)
	{
		printf ("Error opening file!\n");
		exit(1);
	}
	else
	{
		printf("\t\t\t\tMEDIAS DE PREVENCION: \n\n");
		while ((content = fgetc(fp)) != EOF)
		{
			printf("%c", content);
		}
	}
	fclose(fp);
}

void write_suggestion()
{
    /*
    * Funcion write_suggestion():
    * Esta funcion se encarga de escribir sugerencias de recomendaciones dentro
    * de el archivo sugerencias.txt
    */
	FILE *fp;
    char suggestion[100];
    fp = fopen("sugerencias.txt", "a");
    if (fp == NULL)
    {
        printf("No se pudo abrir el archivo");
        exit(0);
    }
    while (fgets(suggestion, 100, fp) != NULL)
    {
        printf("%s", suggestion);
    }
    fclose(fp);
}

void test_covid()
{
    /*
    * Funcion test_covid():
    * Esta funcion se encarga de realizar un test de covid en una persona.
    * Si el test resulta positivo, se le mostrara recomendaciones.
    * Si el test resulta negativo, se le mostrara una lista de medias de prevencion.
    */
    int in_Q2, in_Q3, in_Q4, in_Q5, in_Q6, in_Q7, in_Q8, in_Q9, in_Q10, in_Q11, in_Q12, in_Q13;
    printf("\n\tSI HA PRESENTADO ALGUNO DE LOS SIGUIENTES SINTOMAS ESCRIBA EL NUMERO SEGUN SEA EL CASO:\n\n");
    printf("\t\t\t\t\t\tSi=1 y No=0 \n\n");
    printf("\t1.- Fiebre mayor a 38 grados Celsius: ");
    scanf("%d", &in_Q2);
    printf("\t2.- Tos: ");
    scanf("%d", &in_Q3);
    printf("\t3.- Dificultad para respirar (sentir que le falta aire): ");
    scanf("%d", &in_Q4);
    printf("\t4.- Fatiga: ");
    scanf("%d", &in_Q5);
    printf("\t5.- Dolores musculares y corporales: ");
    scanf("%d", &in_Q6);
    printf("\t6.- Dolor de cabeza: ");
    scanf("%d", &in_Q7);
    printf("\t7.- Perdida reciente del olfato o el gusto: ");
    scanf("%d", &in_Q8);
    printf("\t8.- Congestion nasal o moqueo: ");
    scanf("%d", &in_Q9);
    printf("\t9.- Nauseas o vomito: ");
    scanf("%d", &in_Q10);
    printf("\t10.- Diarrea: ");
    scanf("%d", &in_Q11);
    printf("\t11.- Viaje o estancia a paises con transmision local: ");
    scanf("%d", &in_Q12);
    printf("\t12.- Has tenido contacto con un caso sospechoso o confirmado de COVID-19 en los 14 dias previos: ");
    scanf("%d", &in_Q13);
    int sum = in_Q2 + in_Q3 + in_Q4 + in_Q5 + in_Q6 + in_Q7 + in_Q8 + in_Q9 + in_Q10 + in_Q11 + in_Q12 + in_Q13;
    if(sum>=7){
        printf("\n\n\n\tDEBERA REALIZARCE UNA PRUEBA (PCR O ANTIGENOS) PARA DETERMINAR SI ES PORTADOR DEL VIRUS SARS-COV2\n\n");
        show_suggestion();
    } else {
        printf("\n\n\n\tNO NECESITA ATENCION MEDICA. AQUI TIENE UNA GUIA DE MEDIDAS PARA PREVENIR EL CONTAGIO DEL VIRUS SARS-COV2\n\n");
        show_suggestion1();
    }
}

void show_menu()
{
    /*
    * Funcion show_menu():
    * Esta funcion se encarga de mostrar el menu de opciones para que el usuario elija una opcion.
    */
    int answer;
    printf("\n\tSELECCIONE UNA OPCION:\n\n\t1.Test: Sintomas de COVID-19\n\t2.Ver Medidas de Prevencion y Recomendaciones\n\t3.Escribir alguna Medida Preventiva y/o Recomendacion\n\t4.Ayuda\n\t5.Salir\n\n\t");
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
        printf("ESPEREMOS QUE TE HAYA SIDO UTIL LA INFORMACION PROPORCIONADA. SALUDOS\n");
        exit(0);
        break;
    default:
        printf("\nOpcion no valida\n");
        break;
    }
}

void requirements()
{
    /*
    * Funcion requirements():
    * Esta funcion se encarga de recopilar los datos de la persona
    * para poder iniciar el test de COVID-19.
    */
    struct personal_data person;
    printf("\n\n\t\tBIENVENID@\n\n");
    printf("\tIngrese su nombre: ");
    scanf("%s", person.name);
    printf("\tIngrese su sexo: ");
    scanf("%s", person.sex);
    printf("\tIngrese su colonia: ");
    scanf("%s", person.colonia);
    printf("\tIngrese su municipio: ");
    scanf("%s", person.municipio);
    printf("\tIngrese su edad: ");
    scanf("%d", &person.age);
    printf("\tIngrese un numero de celular: ");
    scanf("%d", &person.phone_number);
    show_menu();
}

int main(int argc, char **argv)
{
    requirements();
    return 0;
}