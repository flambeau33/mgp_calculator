/*
MGP CALCULATOR
AUTEUR:FLAMBEAU
DESCRIPTION: CALCULES LA MGP EN FONCTION DES NOTES ET DES CREDITS ENTRÉES */


#include<stdio.h>
#include<string.h>

typedef struct{
    char nom[11];
    float note;
    float mgp;
    int credit;
    char grade[3];
}UE;

int main(){

    int n;
    printf("combien d'UE?: ");
    scanf("%d",&n);
    UE tableau_UE[n];
    float S=0.0;
    int total_credit=0;
    
    for(int i=0;i<n;i++){
        printf("\nEntrez le nom de l'UE %d (10 caracteres max sans espaces) : ",i+1);
        scanf("%9s",tableau_UE[i].nom);

        printf("Entrez le nombre de credits ");
        scanf("%d",&tableau_UE[i].credit);
        total_credit+=tableau_UE[i].credit;

        printf("Entrez la note obtenue /100 ");
        scanf("%f",&tableau_UE[i].note);
        
        if(tableau_UE[i].note<35){
            tableau_UE[i].mgp=0;
            strcpy(tableau_UE[i].grade,"F");
        }else if(tableau_UE[i].note>=35 && tableau_UE[i].note<40){
            tableau_UE[i].mgp=1;
            strcpy(tableau_UE[i].grade,"D");
        }else if(tableau_UE[i].note>=40 && tableau_UE[i].note<45){
            tableau_UE[i].mgp=1.3;
            strcpy(tableau_UE[i].grade,"D+");
        }else if(tableau_UE[i].note>=45 && tableau_UE[i].note<50){
            tableau_UE[i].mgp=1.7;
            strcpy(tableau_UE[i].grade,"C-");
        }else if(tableau_UE[i].note>=50 && tableau_UE[i].note<55){
            tableau_UE[i].mgp=2;
            strcpy(tableau_UE[i].grade,"C");
        }else if(tableau_UE[i].note>=55 && tableau_UE[i].note<60){
            tableau_UE[i].mgp=2.3;
            strcpy(tableau_UE[i].grade,"C+");
        }else if(tableau_UE[i].note>=60 && tableau_UE[i].note<65){
            tableau_UE[i].mgp=2.7;
            strcpy(tableau_UE[i].grade,"B-");
        }else if(tableau_UE[i].note>=65 && tableau_UE[i].note<70){
            tableau_UE[i].mgp=3;
            strcpy(tableau_UE[i].grade,"B");
        }else if(tableau_UE[i].note>=70 && tableau_UE[i].note<75){
            tableau_UE[i].mgp=3.3;
            strcpy(tableau_UE[i].grade,"B+");
        }else if(tableau_UE[i].note>=75 && tableau_UE[i].note<80){
            tableau_UE[i].mgp=3.7;
            strcpy(tableau_UE[i].grade,"A-");
        }else{
            tableau_UE[i].mgp=4;
           strcpy(tableau_UE[i].grade,"A");
        }
        S+=tableau_UE[i].mgp*tableau_UE[i].credit;
    }

    for(int i=0;i<n;i++){
        printf("Nom:%s --- Note:%.2f/100 --- Credit:%d --- Mgp:%.1f --- %s\n",tableau_UE[i].nom,tableau_UE[i].note,tableau_UE[i].credit,tableau_UE[i].mgp,tableau_UE[i].grade);
    }
    printf("\n\n================================================\n");
    printf("Votre MGP est:  %.2f/4 (%.2f/20)\n\n",S/total_credit,(S/total_credit)*5);
}