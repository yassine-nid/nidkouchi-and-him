#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED
#endif // CLIENT_H_INCLUDED
typedef struct Client
{
    int idClient;
    char nom[20];
    char prenom[20];
    int cin;
    char adresse[15];
    int telephone;
}client;
client crClient(){
    client c;
    printf("enter le nom de client: ");
    scanf("%s",c.nom);
    printf("enter le prenom: ");
    scanf("%s",c.prenom);
    printf("enter le id: ");
    scanf("%d",&c.idClient);
    printf("enter le cin: ");
    scanf("%d",&c.cin);
    printf("enter l'adresse: ");
    scanf("%s",c.adresse);
    printf("enter le num telephon: ");
    scanf("%d",&c.telephone);
    return c;
}
void AjouterClient(){
    client c;
    c=crClient();
    FILE *file=NULL;
    file=fopen("client.txt","a+");
    fwrite(&c,sizeof(client),1,file);
    fclose(file);
 }
void AfficheClient(){
    FILE *f;
    client c;
    f=fopen("client.txt","r");
    fseek(f,0,SEEK_SET);
    while(fread(&c,sizeof(client),1,f)!=0){
        printf("%s %s %d\n",c.nom,c.prenom,c.idClient);
    }
    fclose(f);
}
void SupClient(){
    client c;
    char nom[20],asup[]="client.txt";
    FILE *f,*f1;
    int ts;
    printf("enter le nom du client a suprimer: \n");
    scanf("%s",nom);
    f=fopen("client.txt","r");
    rewind(f);
    f1=fopen("tmp.txt","a+");
    while(fread(&c,sizeof(client),1,f)!=0){
        if (strcmp(c.nom,nom)){
            fwrite(&c,sizeof(client),1,f1);
        }
    }
    fclose(f1);
    fclose(f);
    ts=remove(asup);
    if (ts!=0){
        printf("error de sup\n");
    }
    rename("tmp.txt","client.txt");

}
void modClient(){
    client c;
    char nom[20],asup[]="client.txt";
    FILE *f,*f1;
    int ts,m;
    printf("enter le nom du client a modifier: \n");
    scanf("%s",nom);
    f=fopen("client.txt","r");
    rewind(f);
    f1=fopen("tmp.txt","a+");
    while(fread(&c,sizeof(client),1,f)!=0){
        if (strcmp(c.nom,nom)){
            fwrite(&c,sizeof(client),1,f1);
        }
        else {
            printf("selectioner l'element a modifier:\n1->le nom\n2->le prenom\n3->le id\n4->le cin\n5->l'adresse->6le num telephon\n");
            scanf("%d",&m);
            switch(m){
                case 1: printf("enter le nom de client: ");scanf("%s",c.nom);break;
                case 2: printf("enter le prenom: ");scanf("%s",c.prenom);break;
                case 3: printf("enter le id: ");scanf("%d",&c.idClient);break;
                case 4: printf("enter le cin: ");scanf("%d",&c.cin);break;
                case 5: printf("enter l'adresse: ");scanf("%s",c.adresse);break;
                case 6: printf("enter le num telephon: ");scanf("%d",&c.telephone);break;
                fwrite(&c,sizeof(client),1,f1);
            }
            fwrite(&c,sizeof(client),1,f1);
        }
    }
    fclose(f1);
    fclose(f);
    ts=remove(asup);
    if (ts!=0){
        printf("error de sup\n");
    }
    rename("tmp.txt","client.txt");
}
