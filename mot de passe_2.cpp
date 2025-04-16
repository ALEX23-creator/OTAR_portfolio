#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void menu(){
	
	printf("\n\n\n\t\t\t*_*_*_*_*_*_*_*_*_1-Nouveau mot de passe_*_*_*_*_*_*_*_*_*_*");
	printf("\n\n\t\t\t*_*_*_*_*_*_*_*_*_*_2-Changer de mot de passe_*_*_*_*_*_*_*_*_*_*");
	printf("\n\n\t\t\t*_*_*_*_*_*_*_*_*_*_3-Supprimer mot de passe_*_*_*_*_*_*_*_*_*_*");
	printf("\n\n\t\t\t*_*_*_*_*_*_*_*_*_*_4-Modfication du fichier_*_*_*_*_*_*_*_*_*_*");
	printf("\n\n\t\t\t*_*_*_*_*_*_*_*_*_*_5-Afficher les informations du fichier_*_*_*_*_*_*_*_*_*_*");
}

void nouveau(){
	char passwd[16];
	char conf[16];
	int verif,i=0,j=0;
	FILE * New;
	FILE * erreur;
	FILE * liste;
	p_etape:
	printf("\n\n\n\t\t\t*_*_*_*_*_*_*_*_*_*_1-Nouveau mot de passe_*_*_*_*_*_*_*_*_*_*\n\n\n");
	printf("\t\t\t Entrez le nouveau mot de passe:		");
	scanf("%s",passwd);
	printf("\n\n");
	system("cls");
	printf("\n\n\n\t\t\t*_*_*_*_*_*_*_*_*_*_1-Nouveau mot de passe_*_*_*_*_*_*_*_*_*_*\n\n\n");
	d_etape:
	printf("\n\n\n\t\t\t Confirmez le mot de passe:		");
	scanf("%s",conf);
	i++;
	j++;
	verif=strcmp(passwd,conf);
	if(verif==0){
		New=fopen("passwd.txt","w");
		fprintf(New,"%s	:	Nouveau mot de passe \n\n\nConfirmation effectee en %d fois\n\n",conf,i);
		printf("\n\n\n\t\t\t Mot de passe configure avec succes.......\n\n\n");
		fclose(New);
		liste=fopen("Passwords_list.txt","a");
		fprintf(liste,"Nouveau mot de passe:	%s\nConfirmation du mot de passe:	%s\n\n\n",passwd,conf);
		fclose(liste);
	}else{
		if(j==3){
			j=0;
			printf("\n\n\t\t\t 3tentatives erronées reesayez!!!");
			printf("\n\n\n\t\t\tAppuyez sur 'entrer' pour continuer....");
			getchar();
			getchar();
			system("cls");
			goto p_etape;	
		}else{
			printf("\n\n\t\t\tTentatives erronees reesayez!!!");
			printf("\n\n\n\t\t\tAppuyez sur 'entrer' pour continuer....");
			getchar();
			getchar();
			erreur=fopen("erreur.txt","a");
			fprintf(erreur,"erreur de saisie %d :	%s\n\n",i,conf);
			fclose(erreur);
			system("cls");
			goto d_etape;
		}
	}
}
//void nouveau() conmplete

void changer(){
	char p_pswd[16],n_pswd[16],pswd[16];
	int verif,comp,i=0,j=0;
	FILE * reset;
	FILE * New;
	FILE * erreur;
	FILE * liste;
	reset=fopen("change.txt","a");
	New=fopen("passwd.txt","r");
	p_etape:
	printf("\n\n\t\t\t*_*_*_*_*_*_*_*_*_*_2-Changer de mot de passe_*_*_*_*_*_*_*_*_*_*");
	printf("\n\n\n\t\t\tEntrez votre Ancien mot de passe:		");
	scanf("%s",p_pswd);
	fscanf(New,"%s",n_pswd);
	comp=strcmp(p_pswd,n_pswd);
	if(comp==0){
		d_etape:
		system("cls");
		printf("\n\n\t\t\tEntrez votre nouveau mot de passe:		");
		scanf("%s",n_pswd);
		t_etape:
		printf("\n\n\t\t\tConfirmez votre nouveau mot de passe:		");
		scanf("%s",pswd);
		i++;
		j++;
		verif=strcmp(pswd,n_pswd);
		if(verif==0){
			liste=fopen("Passwords_list.txt","a");
			fprintf(liste,"\n\n\t\tChangement de mot de passe:	%s\n\nConfirmation de changement:	%s\n\n",n_pswd,pswd);
			fscanf(New,"%s",p_pswd);
			fclose(New);
			New=fopen("passwd.txt","w");
			fprintf(New,"%s	:	Nouveau mot de passe \n\n\nConfirmation effectee en %d fois\n\n",pswd,i);
			fprintf(reset,"Mot de passe précédent:	%s\n\nChangement de mot de passe:	%s\n\n",p_pswd,n_pswd);
			system("cls");
			fclose(New);
			fclose(reset);
			printf("\n\n\t\t\tMot de passe modifie avec succes......");
		}else{
			if(j==3){
				j=0;
				system("cls");
				printf("\n\n\t\t\t3 tentatives erronées reesayez!!!");
				printf("\n\n\n\t\t\tAppuyez sur 'entrer' pour continuer....");
				getchar();
				getchar();
				goto d_etape;
			}else{
				printf("\n\n\t\t\tVerification failed.....Retry\n\n");
				printf("\n\n\n\t\t\tAppuyez sur 'entrer' pour continuer....");
				getchar();
				getchar();
				system("cls");
				goto t_etape;
			}	
		}
	}else{
			printf("\n\n\t\t\tVerification failed.....Retry\n\n");
			printf("\n\n\n\t\t\tAppuyez sur 'entrer' pour continuer....");
			getchar();
			getchar();
			system("cls");
			goto p_etape;
	}
}	
	
int main(){
	int choix;
	printf("\n\n\n\t\t\tBonjour,bienvenue......\n\n");
	printf("\n\n\n\t\t\tAppuyez sur 'entrer' pour continuer....");
	getchar();
	system("cls");
	r:
	menu();
	printf("\n\n\n\t\t\toption:		");
	scanf("%d",&choix);
	switch(choix){
		case 1:{
			system("cls");
			nouveau();
			goto r;
			break;
		}
		case 2:{
			changer();
			goto r;
			break;
		}
		case 3:{
			system("cls");
			printf("\n\n\n\t\t\t*_*_*_*_*_*_*_*_*_*_3-_*_*_*_*_*_*_*_*_*_*");
			goto r;
			break;
		}
	}
}