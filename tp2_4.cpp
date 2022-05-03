#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 5

typedef struct compu
{
    int velocidad; //entre 1 y 3ghz
    int anio; //entre 2000 y 2017
    int cantidad; //entre 1 y 4
    char *tipo_cpu; //valores del arrglo 'tipos'
}pc;

char tipos [6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

void cargarDatos(struct compu *Pdatos);
void mostrarDatos(struct compu *Pdatos);
void masVieja(struct compu *Pdatos);
void mayorVelocidad(struct compu *Pdatos);


int main()
{
    srand((int) time (NULL));

    struct compu pc[MAX];
    cargarDatos(pc);
    mostrarDatos(pc);
    masVieja(pc);
    mayorVelocidad(pc);

   
    for(int i=0;i<MAX;i++)
    {
        free(pc[i].tipo_cpu);  //libero memoria
    }
}

void mayorVelocidad(struct compu *Pdatos)
{
    int max=0, aux=0;
    for(int i=0;i<MAX;i++){
        if((Pdatos->velocidad)>max){
            max=Pdatos->velocidad;
            aux=i;
        }
        Pdatos++;
    }
    Pdatos-=MAX;
    Pdatos+=aux;
    printf("\n\tCaracteristicas PC mas rapida: ");
    printf("\nA%co: %i", 164, Pdatos->anio);
    printf("\nProcesador: %s, Velocidad: %iGhz, Cantidad de Nucleos: %i", Pdatos->tipo_cpu, Pdatos->velocidad, Pdatos->cantidad);
}

void masVieja(struct compu *Pdatos)
{
    int min=2023, aux=0;
    for(int i=0; i<MAX; i++){
        if((Pdatos->anio)<min){
            min=Pdatos->anio;
            aux=i;
        }
        Pdatos++;
    }
    Pdatos-=MAX;
    Pdatos+=aux;
    printf("\n\tCaracteristicas PC mas vieja: ");
    printf("\nAnio: %i", Pdatos->anio);
    printf("\nProcesador: %s, Velocidad: %iGhz, Cantidad de Nucleos: %i", Pdatos->tipo_cpu, Pdatos->velocidad, Pdatos->cantidad);
}

void mostrarDatos(struct compu *Pdatos)
{
    for(int i=0; i<MAX; i++)
    {
        printf("\n\tCaracteristicas PC %i: ", i+1);
        printf("\nAnio: %i", Pdatos->anio);
        printf("\nProcesador: %s, Velocidad: %iGhz, Cantidad de Nucleos: %i",Pdatos->tipo_cpu, Pdatos->velocidad, Pdatos->cantidad);
        Pdatos++;
    }
}



void cargarDatos(struct compu *Pdatos)
{
    char tipos [6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    int num;
    for(int i=0; i<=MAX; i++)
    {
        Pdatos -> tipo_cpu = (char *)malloc(10);
        printf("\n\tCarga PC %i\n", i+1);
        printf("\nIndique la velocidad del procesador entre 1 y 3Ghz: \n");
        do{
            scanf("%i", &(Pdatos -> velocidad));
            fflush(stdin);
            if(Pdatos -> velocidad<1 || Pdatos-> velocidad>3)
            {
                printf("\nIngrese una velocidad valida!\n");
            }
        }while (Pdatos -> velocidad<1 || Pdatos -> velocidad>3);
        printf("\nIndique el anio entre 2015 y 2022: \n");
        do
        {
            scanf("%i", &(Pdatos -> anio));
            fflush(stdin);
            if(Pdatos -> anio<2015 || Pdatos -> anio>2022)
            {
                printf("\nIngrese un Anio valido!\n");
            }   
        }while(Pdatos -> anio<2015 || Pdatos -> anio>2022);
        printf("\nIndique la cantidad de nucleos del procesador entre 1 y 8: \n");
        do
        {
            scanf("%i", &(Pdatos -> cantidad));
            fflush(stdin);
            if(Pdatos -> cantidad<1 || Pdatos -> cantidad>8)
            {
                printf("\nIngrese una cantidad valida!\n");
            }
        }while(Pdatos -> cantidad<1 || Pdatos-> cantidad>8);
        printf("\nIndique el tipo de procesador: \n\t1=Intel \n\t2=AMD \n\t3=Celeron \n\t4=Athlon \n\t5=Core \n\t6=Pentium\n");
        do
        {
            scanf("%i", &num);
            fflush(stdin);
            if(num<1 || num>6)
            {
                printf("\nIngrese un tipo valido!\n");
            }
        }while(num<1 || num>6);
        
        switch(num)
        {
            case 1:
                strcpy(Pdatos->tipo_cpu,tipos[0]);
                break;
            case 2:
                strcpy(Pdatos->tipo_cpu,tipos[1]);
                break;
            case 3:
                strcpy(Pdatos->tipo_cpu,tipos[2]);
                break;
            case 4:
                strcpy(Pdatos->tipo_cpu,tipos[3]);
                break;
            case 5:
                strcpy(Pdatos->tipo_cpu,tipos[4]);
                break;
            case 6:
                strcpy(Pdatos->tipo_cpu,tipos[5]);
                break;     
            /*default:
            Pdatos->tipo_cpu="Error";
            printf("Error!");
            break;*/
        }
        Pdatos++;           
        
            
    }
    
}
