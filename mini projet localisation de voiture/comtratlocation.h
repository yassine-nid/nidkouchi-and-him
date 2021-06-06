#ifndef COMTRATLOCATION_H_INCLUDED
#define COMTRATLOCATION_H_INCLUDED
#endif // COMTRATLOCATION_H_INCLUDED
typedef struct Date{
    int jour;
    int mois;
    int annee;
}date;
typedef struct contratLocation
{
    float numContrat;
    int idVoiture;
    int idClient;
    date debut;
    date fin;
    int cout;
} contrat;
int verifierC(int idc){
    client c;
    FILE *f;
    int cv=0;
    f=fopen("client.txt","r");
    while(fread(&c,sizeof(client),1,f)!=0){
        if(c.idClient==idc){
            printf("bonjour monsieur %s\n",c.prenom);
            cv=1;
        }
    }
    if (cv==0){
        printf("le client n'exist pas pour ajouter un client aller au menu client\n");
        fclose(f);
        return 0;
    }
    fclose(f);
    return 1;
}
int verifierV(int idv){
    voiture v;
    FILE *f;
    int vv=0,enl=1;
    f=fopen("voiture.txt","rw");
    while(fread(&v,sizeof(voiture),1,f)!=0){
        if(v.idVoiture==idv){
            vv=1;
            if (!strcmp(v.EnLocation,"oui")){enl=0;
            }
        }
    }
    if (vv==0){
        printf("la voiture n'exist pas  pour ajouter une voiture aller au menu voiture\n");
        fclose(f);
        return 0;
    }
    else if(enl==0){
        printf("la voiture n'est pas disponible\n");
        fclose(f);
        return 0;
    }
    fclose(f);
    return 1;
}
contrat CrContrat(int idc,int idv){
    contrat c;
    printf("enter le num de contrat: ");
    scanf("%f",&c.numContrat);
    c.idClient=idc;
    c.idVoiture=idv;
    printf("enter la date de debut de contrat:\n");
    printf("j: ");
    scanf("%d",&c.debut.jour);
    printf("m: ");
    scanf("%d",&c.debut.mois);
    printf("a: ");
    scanf("%d",&c.debut.annee);
    printf("enter la date de la fin de contrat:\n");
    printf("j: ");
    scanf("%d",&c.fin.jour);
    printf("m: ");
    scanf("%d",&c.fin.mois);
    printf("a: ");
    scanf("%d",&c.fin.annee);
    printf("enter le cout; ");
    scanf("%d",&c.cout);
    return c;
}
void LouerVoiture(){
    voiture v;
    contrat cn;
    char vsup[]="Voiture.txt";
    FILE *f,*f1;
    int ts;
    int tv,tc,idc,idv;
    printf("enter votre id: ");
    scanf("%d",&idc);
    tc=verifierC(idc);
    printf("enter la voiture id: ");
    scanf("%d",&idv);
    tv=verifierV(idv);
    if(tc==0||tv==0)exit(0);
    f=fopen("Voiture.txt","r");
    rewind(f);
    f1=fopen("tmp.txt","a+");
    while(fread(&v,sizeof(voiture),1,f)!=0){
        if (v.idVoiture!=idv){
            fwrite(&v,sizeof(voiture),1,f1);
        }
        else {
            v.EnLocation[0]='o';
            v.EnLocation[1]='u';
            v.EnLocation[2]='i';
            }
            fwrite(&v,sizeof(voiture),1,f1);
    }
    fclose(f1);
    fclose(f);
    ts=remove(vsup);
    if (ts!=0){
        printf("error de sup\n");
    }
    rename("tmp.txt","Voiture.txt");
    cn=CrContrat(idc,idv);
    f=fopen("contrat.txt","a+");
    fwrite(&cn,sizeof(contrat),1,f);
    fclose(f);
}
void AfficheContrat(){
    FILE *f;
    contrat c;
    f=fopen("contrat.txt","r");
    fseek(f,0,SEEK_SET);
    printf("la list de contrat:");
    while(fread(&c,sizeof(contrat),1,f)!=0){
        printf("num contrat: %f\n",c.numContrat);
        printf("id client: %d\n",c.idClient);
        printf("id voiture: %d\n",c.idVoiture);
        printf("date de debut: %d/%d/%d\n",c.debut.jour,c.debut.mois,c.debut.annee);
        printf("date de fin: %d/%d/%d\n",c.fin.jour,c.fin.mois,c.fin.annee);
        printf("le cout est: %d\n",c.cout);
    }
    fclose(f);
}
void VisualiserContrat(){
    FILE *f;
    float nc;
    contrat c;
    printf("enter le num de contrat: ");
    scanf("%f",&nc);
    f=fopen("contrat.txt","r");
    fseek(f,0,SEEK_SET);
    printf("la list de contrat:");
    while(fread(&c,sizeof(contrat),1,f)!=0){
        if (nc==c.numContrat){
        printf("num contrat: %f\n",c.numContrat);
        printf("id client: %d\n",c.idClient);
        printf("id voiture: %d\n",c.idVoiture);
        printf("date de debut: %d/%d/%d\n",c.debut.jour,c.debut.mois,c.debut.annee);
        printf("date de fin: %d/%d/%d\n",c.fin.jour,c.fin.mois,c.fin.annee);
        printf("le cout est: %d\n",c.cout);
    }}
    fclose(f);
}
void RetournerVoiture(){
    contrat c;
    voiture v;
    FILE *f,*f1;
    int idv,ts;
    float nc;
    printf("enter le num de contrat: ");
    scanf("%f",&nc);
    f=fopen("contrat.txt","r");
    fseek(f,0,SEEK_SET);
    printf("la list de contrat:");
    while(fread(&c,sizeof(contrat),1,f)!=0){
        if (nc==c.numContrat){
            idv=c.idVoiture;
    }}
    fclose(f);
    //la supressiont de contrat
    f=fopen("contrat.txt","r");
    rewind(f);
    f1=fopen("tmp.txt","a+");
    while(fread(&c,sizeof(contrat),1,f)!=0){
        if (nc!=c.numContrat){
            fwrite(&c,sizeof(contrat),1,f1);
        }
    }
    fclose(f1);
    fclose(f);
    ts=remove("contrat.txt");
    if (ts!=0){
        printf("error de sup\n");
    }
    rename("tmp.txt","contrat.txt");
    //changer la valeur de enlocation
    f=fopen("Voiture.txt","r");
    rewind(f);
    f1=fopen("tmp.txt","a+");
    while(fread(&v,sizeof(voiture),1,f)!=0){
        if (v.idVoiture!=idv){
            fwrite(&v,sizeof(voiture),1,f1);
        }
        else {
            v.EnLocation[0]='n';
            v.EnLocation[1]='o';
            v.EnLocation[2]='n';
            }
            fwrite(&v,sizeof(voiture),1,f1);
    }
    fclose(f1);
    fclose(f);
    ts=remove("Voiture.txt");
    if (ts!=0){
        printf("error de sup\n");
    }
    rename("tmp.txt","Voiture.txt");
}
void SupContrat(){
    contrat c;
    char asup[]="contrat.txt";
    FILE *f,*f1;
    int ts;
    float nc;
    printf("enter le num du contrat a suprimer: \n");
    scanf("%f",&nc);
    f=fopen("contrat.txt","r");
    rewind(f);
    f1=fopen("tmp.txt","a+");
    while(fread(&c,sizeof(contrat),1,f)!=0){
        if (nc!=c.numContrat){
            fwrite(&c,sizeof(contrat),1,f1);
        }
    }
    fclose(f1);
    fclose(f);
    ts=remove(asup);
    if (ts!=0){
        printf("error de sup\n");
    }
    rename("tmp.txt","contrat.txt");

}
