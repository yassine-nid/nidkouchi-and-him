#ifndef VOITURE_H_INCLUDED
#define VOITURE_H_INCLUDED
#endif // VOITURE_H_INCLUDED
typedef struct Voiture
{
    int idVoiture;
    char marque[15];
    char nomVoiture[15];
    char couleur[7];
    int nbplaces;
    int prixJour;
    char EnLocation[4];
}voiture;
voiture Crvoiture(){
    voiture v;
    printf("enter la marque de voiture: ");
    scanf("%s",v.marque);
    printf("enter le nom de voiture: ");
    scanf("%s",v.nomVoiture);
    printf("enter le id: ");
    scanf("%d",&v.idVoiture);
    printf("enter la couleur: ");
    scanf("%s",v.couleur);
    printf("enter le nombre de place: ");
    scanf("%d",&v.nbplaces);
    printf("enter le prix de jour: ");
    scanf("%d",&v.prixJour);
    printf("entrer est ce que la voiture en location ou non ");
    scanf("%s",v.EnLocation);
    return v;
}
void AjouterVoiture(){
    voiture v;
    v=Crvoiture();
    FILE *file=NULL;
    file=fopen("Voiture.txt","a");
    fwrite(&v,sizeof(voiture),1,file);
    fclose(file);
 }
void AfficheVoiture(){
    FILE *f;
    voiture v;
    f=fopen("Voiture.txt","r");
    fseek(f,0,SEEK_SET);
    while(fread(&v,sizeof(voiture),1,f)!=0){
        printf("%s %s %s %s %d %d %d\n",v.marque,v.nomVoiture,v.couleur,v.EnLocation,v.idVoiture,v.nbplaces,v.prixJour);
    }
    fclose(f);
}
 void SupprimerVoiture() {
  voiture v;
  FILE *f;
  FILE *tmp;
  int ts,id;
  char vsup[]="Voiture.txt";
  printf("enter le id du voiture a supprimer ");
    scanf("%d",&id);
  f=fopen("Voiture.txt","r");
  rewind(f);
  if (f==NULL)
    printf("erreur. \n");
  else
  {   tmp=fopen("Voituretmp.txt","w");
   if (tmp==NULL)
     printf("erreur \n");
     else {
 while(fread(&v,sizeof(voiture),1,f)!=0){
    if(v.idVoiture!=id)
       fwrite(&v,sizeof(voiture),1,tmp);
 }
    fclose(f);
    fclose(tmp);
    ts=remove(vsup);
    if (ts!=0){
        printf("error de sup\n");}
    rename("Voituretmp.txt","Voiture.txt");
    } }}
 void modVoiture(){
    voiture v;
    char vsup[]="Voiture.txt";
    FILE *f,*f1;
    int ts,m,id;
    printf("enter le id du voiture a modifier: \n");
    scanf("%d",&id);
    f=fopen("Voiture.txt","r");
    rewind(f);
    f1=fopen("tmp.txt","a+");
    while(fread(&v,sizeof(voiture),1,f)!=0){
        if (v.idVoiture==id){
            fwrite(&v,sizeof(voiture),1,f1);
        }
        else {
            printf("selectioner l'element a modifier:\n1->la marque\n2->le nom\n3->le id\n4->la couleur\n5->le nombre de place->6\nle prix de jout\n7-->est la voiture est en location");
            scanf("%d",&m);
            switch(m){
                case 1: printf("enter la marque de voiture: ");scanf("%s",v.marque);break;
                case 2: printf("enter le nom de voiture: ");scanf("%s",v.nomVoiture);break;
                case 3: printf("enter le id: ");scanf("%d",&v.idVoiture);break;
                case 4: printf("enter la couleur: ");scanf("%s",v.couleur);break;
                case 5: printf("enter le nombre de place: ");scanf("%d",&v.nbplaces);break;
                case 6: printf("enter le prix de jour: ");scanf("%d",&v.prixJour);break;
                case 7: printf("entrer est ce que la voiture en location ou non ");scanf("%s",v.EnLocation);break;

                fwrite(&v,sizeof(voiture),1,f1);
            }
            fwrite(&v,sizeof(voiture),1,f1);
        }
    }
    fclose(f1);
    fclose(f);
    ts=remove(vsup);
    if (ts!=0){
        printf("error de sup\n");
    }
    rename("tmp.txt","Voiture.txt");
}
