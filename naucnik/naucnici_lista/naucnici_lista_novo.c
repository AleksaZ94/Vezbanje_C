#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define MAXR 20
#define MAXO 30
#define MAX 150

typedef struct naucnik{
    char ime[MAXR];
    char prezime[MAXR];
    unsigned int br_rad;
    char oblast[MAXO];
    struct naucnik* sledeci;
}naucnik;

struct naucnik* glava;

void unos(char*, naucnik n, int*);
void ispisi();
void zadati(char*, int);
double prosek(double*);
int poredjenje(char*, char*);

int main(int brArg, char* arg[0])
{
    naucnik n;
    char niz[MAX][MAX];
    double pr_ocena = 0;
    int x = 0; //broj naucnika koji ce se kasnije korigovati u okviru funkcije
    int zad = 0;
    int z = 0;
    glava = NULL;
    if(brArg < 4)
    {
        printf("Nedovoljan broj argumenata!");
        exit(EXIT_FAILURE);
    }
    unos(arg[1],n, &x);
    //ispisi();
    sscanf(arg[3], "%d", &zad);
    zadati(arg[2],zad);
    //ispisi();
    prosek(&pr_ocena);
    printf("Prosecna duzina prezimena je: %.2lf\n", pr_ocena);
    return 0;
}

void unos(char* input, naucnik n, int* x)
{
    FILE* f;
    f = fopen(input,"r");
    if(f == NULL)
    {
        printf("Greska prilikom otvaranja tekstualnog fajla %s", input);
        exit(EXIT_FAILURE);
    }
    while(fscanf(f, "%s %s %u %s", n.ime, n.prezime, &n.br_rad, n.oblast) != EOF)
    {
        (*x)++;
        if(glava==NULL)
        {
            naucnik* temp = (naucnik*)malloc(sizeof(naucnik));
            strcpy(temp->ime,n.ime);
            strcpy(temp->prezime,n.prezime);
            temp->br_rad = n.br_rad;
            strcpy(temp->oblast,n.oblast);
            temp->sledeci = NULL;
            glava = temp;
        }
        else
        {
            naucnik* temp2 = glava;
            while(temp2->sledeci != NULL)
            {
                temp2 = temp2->sledeci;
            }
            naucnik* temp = (naucnik*)malloc(sizeof(naucnik));
            strcpy(temp->ime,n.ime);
            strcpy(temp->prezime,n.prezime);
            temp->br_rad = n.br_rad;
            strcpy(temp->oblast,n.oblast);
            temp->sledeci = NULL;
            temp2->sledeci = temp;
        }
    }
    fclose(f);
}

void ispisi()
{
    naucnik* temp = glava;
    while(temp)
    {
        printf("%s %s %u %s \n", temp->ime, temp->prezime, temp->br_rad, temp->oblast);
        temp = temp->sledeci;
    }
}

void zadati(char* output, int zad)
{
    FILE* f;
    f = fopen(output,"w");
    if(f == NULL)
    {
        printf("Greska prilikom otvaranja fajla %s", output);
        exit(EXIT_FAILURE);
    }
    naucnik* temp = glava;
    while(temp)
    {
        if(temp->br_rad > zad)
        {
            fprintf(f,"%s %s %u %s\n", temp->ime, temp->prezime, temp->br_rad, temp->oblast);
        }
        temp = temp->sledeci;
    }
}

double prosek(double *pr_ocena)
{

}

int poredjenje(char *k , char *o)
{
    int x,y,p,i;
    p = 1;
    x = strlen(k);
    y = strlen(o);
    //printf("%s %s\n", k,o);
    if(x == y)
    {
        for(i = 0; i < x; i++)
        {
            if(k[i] != o[i])
            {
                p = 0;
                break;
            }
            else
            {
                p = 1;
            }
        }
    }
    else
    {
        p = 0;
    }
    return p;
}

