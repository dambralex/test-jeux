#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// déclarations :

int kistart (int lckM, int lckP);
int atkMons (int atkM,int defP);
int atkPers (int atkP,int defM);
void soin (int *HPP,int *HPPM);
int inv (int *t);

// utilisation :

int kistart(int lckM, int lckP)
    {
        int depart;
        if (lckP>lckM)
        {
            printf("\n \n Joueur a l'aventage \n");
            depart = 1;
        }
        else if (lckP<lckM)
        {
            printf("\n \n ***EMBUSCADE***\n Le monstre attaque en premier\n");
            depart = 0;
        }
        return (depart);
    }

int atkMons (int atkM, int defP)
    {
        int deg,lckM, lckP;
        lckM = rand()%10;
        lckP = rand()%10;
        deg =((lckM+atkM)*1.1)-((lckP+defP)*1.2);
        printf ("(( %d + %d ) *1.1)-((%d + %d ) *1.2)",lckM, atkM, lckP, defP);
        printf ("le monstre vous a inflige %d de degat\n",deg);
        return (deg);
    }

int atkPers (int atkP, int defM)
    {
        int deg,lckM, lckP;
        lckM = rand()%10;
        lckP = rand()%10;
        deg =((lckP+atkP)*1.2)-((lckM+defM)*1.1);
        printf ("Vous avez inflige %d de degat au monstre\n\n\n",deg);
        return (deg);
    }

void soin (int *HPP,int *HPPM)
    {
        printf("gain de %f HP\n",*HPP*1.2);
        *HPP = *HPP*1.2;
        if (*HPP>*HPPM)
        {
            *HPP = *HPPM;
        }

    }

int inv (int *t)
    {
        if (*t == 0)
                *t = 1;
        else if (*t == 1)
                *t = 0;
        printf ("\n***** CHANGEMENT DE TOUR *****\n");
        return 1;
    }

int main ()
    {
        int atkM, defP, lckM, lckP, atkP, defM, HPP, HPPM, HPM, HPMM, choix, tour, nbT, deg;
        srand(time(NULL));

        //début du tour
        lckM = rand()%10;
        lckP = rand()%10;
        tour = kistart(lckM,lckP);
        // temp.
        HPMM = HPM = 250;
        HPPM = HPP = 250;
        atkM = 3;
        defM = 5;
        atkP = 7;
        defP = 7;

        // fin temp.
        while (HPP>0 && HPM>0)
        {
            switch (tour)
                {
                case 0 :
                    deg=atkMons(atkM,defP);
                            if (deg>0)
                                HPP=HPP-deg;
                            else
                                printf("\n\n****MISS*****");
                break;

                case 1 :
                    system (pause);
                    system("cls");
                    printf ("Que souhaitez vous faire ?\n\n\n 1: Attaquer \n 2: Se soigner\n");
                    scanf("%d",&choix);
                    if (choix == 1)
                        {
                            deg=atkPers (atkP,defM);
                            if (deg>0)
                                HPM=HPM-deg;
                            else
                                printf("\n\n****MISS*****");
                        }
                    else if (choix == 2)
                        {
                            soin (&HPP,&HPPM);
                        }
                break;
                }
            nbT += inv (&tour);
            printf (" Perso : %d/%d \n\n Monstre %d/%d \n", HPP, HPPM, HPM, HPMM);
            printf (" atk P : %d, def P : %d, atk M : %d, def M : %d;",atkP, defP, atkM, defM);
        }
        if (HPP != 0)
            printf ("\n\n\n s'avez gagné, veinard\n");
        else
            printf ("s'pèce de nul\n");
	printf("Nombre de tours total : %d",nbT);
        return 0;
    }



