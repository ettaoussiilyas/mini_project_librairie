#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int choix ;
char authors[100][100];
char titles[100][100];
float prix [100];
int qantity[100];
int nombre_book = -1;




void menu(){

    printf("\n#################################################\n");
    printf("##### Merci de Saisir le Nombre de Operation ####\n");
    printf("#################################################\n");
    printf("##### Pour Ajouter un Livre Sairer 1 ############\n");//done
    printf("##### Pour Afficher Tout Les Livres Saiser 2 ####\n");//done
    printf("##### Pour Mettre a Jour Qantity d'un Livre 3 ###\n");//done
    printf("##### Pour Supprimer un Livre Sairer 4 ##########\n");//done
    printf("##### Pour Afficher Le Nombre des Livres 5 ######\n");//done
    printf("##### Pour Rechercher  les Livre Saisire 6 ######\n");//done
    printf("##### Pour Quiter Le Pregramme 7 ################\n");//done
    printf("#################################################\n");
    printf("\nMerci de Saisir Votre Choix d'Operation : ");
    scanf("%d",&choix);
}
void ajouter(){

    if(nombre_book>=100){
        printf("\nLe Stock est Pleine ne peux pas jouter un Livre .\n");

    }else{
        nombre_book++;
        printf("\nMerci de saisir les informations du livre numero %d : \n",nombre_book+1);
        printf("\nAuteur : ");
        //scanf("%s",authors[nombre_book]);
        fgets(authors[nombre_book],50,stdin);
        fgets(authors[nombre_book],50,stdin);
        printf("\nTitre : ");
        //scanf("%s",titles[nombre_book]);
        fgets(titles[nombre_book],50,stdin);
        printf("\nPrix : ");
        scanf("%f",&prix[nombre_book]);
        printf("\nQuantite : ");
        scanf("%d",&qantity[nombre_book]);
    }
}

void afficher_nombre_book(){
    if(nombre_book!=0){
        int quantity_total = 0; 
        for(int i=0;i<=nombre_book;i++){

            quantity_total += qantity[i];

        }
        printf("quantity total estimated: %d\n",quantity_total);
    }else{
        printf("\nLe Stock est Vide aucun livre n'est stocke.\n");
    }
}

void afficher(){
    
    if(nombre_book<0){
        printf("\nLe Stock est Vide aucun livre n'est stocke.\n");
    }else{
        printf("Les Livre on Stock est :\n");
        for(int i=0; i<=nombre_book; i++){
            printf("\nLivre numero %d ...\n",i+1);
            printf("Auteur : %s\n",authors[i]);
            printf("Titre : %s\n",titles[i]);
            printf("Prix : %.2f\n",prix[i]);
            printf("Quantite : %d\n",qantity[i]);

        }
        
    }
}


void mettreAjour(){
    if(nombre_book<0){
        printf("\nLe Stock est Vide aucun livre n'est stocke.\n");
    }else{
        
        char recherche_book[50];
        int noveauQantity=0;
        int trouve=0;
        printf("\nMerci de saisir le titre du livre que vous recherchez pour Modifier : ");
        fgets(recherche_book,50,stdin);
        fgets(recherche_book,50,stdin);

        for(int i=0 ; i<=nombre_book ;i++){

            if(strcmp(titles[i],recherche_book)==0){

                printf("\nMerci de Saisir la noveau quantiy :");
                scanf("%d",&noveauQantity);
                qantity[i] = noveauQantity;
                trouve=1;
                break;
            }

        }
        if(trouve==0){
                printf("\nAucun livre avec Ce Titre.\n");
        }else{
                printf("\nMerci.\n");
        }
    }
}

void supprimer(){
    if(nombre_book==0){
        printf("\nLe Stock est Vide aucun livre n'est stocke.\n");
    }else{
        int supp =0;
        char supp_book[50];
        printf("\nMerci de Saisir le Titre de Livre Pour Supprimer : \n");
        fgets(supp_book,50,stdin);
        fgets(supp_book,50,stdin);
        
        for(int i=0; i<=nombre_book; i++){
            
            if(strcmp(titles[i],supp_book)==0){
                for(int j=i; j<nombre_book; j++){
                    strcpy(authors[j],authors[j+1]);
                    strcpy(titles[j],titles[j+1]);
                    prix[j] = prix[j+1];
                    qantity[j] = qantity[j+1];
                }
                nombre_book--;
                supp =1;
                printf("Bien Supprimer.Merci");
                break;
            }
        }
        if(supp==0){
            printf("\nAucun livre avec ce Titre.\n");
        }
    }
}


void rechercher(){
    if(nombre_book<0){
        printf("\nLe Stock est Vide aucun livre n'est stocke.\n");
    }else{
        
        char recherche_book[50];
        int trouve=0;
        printf("\nMerci de saisir le titre du livre que vous recherchez : ");
        fgets(recherche_book,50,stdin);
        fgets(recherche_book,50,stdin);

        for(int i=0 ; i<=nombre_book ;i++){

            if(strcmp(titles[i],recherche_book)==0){

                printf("Auteur : %s\n",authors[i]);
                printf("Titre : %s\n",titles[i]);
                printf("Prix : %.2f\n",prix[i]);
                printf("Quantite : %d\n",qantity[i]);
            }

        }
        if(trouve==0){
                printf("\nAucun livre avec Ce Titre.\n");
        }else{
                printf("\nMerci.\n");
        }
    }
}


int main(){
    
    do{
        menu();
        switch(choix){
            case 1:
                ajouter();
                break;
            case 2:
                afficher();
                break;
            case 3:
                mettreAjour();
                break;
            case 4:
                supprimer();
                break;
            case 5:
                afficher_nombre_book();
                break;
            case 6:
                rechercher();
                break;
            case 7:
                printf("\nMerci d'avoir utiliser notre application.\n");
                break;
            
            default:
                printf("\nMerci d'avoir saiser le choix d'opperation correctement (1-7).\n");
                break;
        }

    }while(choix != 7);


    return 0;
}