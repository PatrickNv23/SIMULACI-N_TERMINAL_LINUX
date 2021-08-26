#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>
char ruta[100];
//char carpeta[20];
//struct dirent *ep;
void comandoMkdir();
void comandoRmdir();
int comandoGrep();
int comandoHead();
int comandoCat();
int comandoCp();
int comandoTail();
int comandoFind();
int comandoLocate();
int comandoLs();
int comandoDiff();
int comandoPwd();
int comandoJobs();
int comandoPs();
int comandoDu();
int comandoSort();
int comandoRm();
int comandoNeofetch();
int comandoUname();
int comandoTouch();
void comandoLess();

int main(int argc,char*argv[]){
    int i;
    char comandoMain[20];
    //system('cls');
    do
    {
        i=0;
        getcwd(ruta,100);
        printf("RUta actual: %s\n", &ruta);
        printf("Ingrese un comando\n");
        scanf("%s", &comandoMain);
        if(strcmp(comandoMain, "exit") == 0){
            i = -1;
        }else {
            if(strcmp(comandoMain,"mkdir") == 0){i = 1;}
            if(strcmp(comandoMain,"rmdir") == 0){i = 2;}
            if(strcmp(comandoMain,"grep") == 0){i = 3;}
            if(strcmp(comandoMain,"head") == 0){i = 4;}
            if(strcmp(comandoMain,"cat") == 0){i = 5;}
            if(strcmp(comandoMain,"cp") == 0){i = 6;}
            if(strcmp(comandoMain,"tail") == 0){i = 7;}
            if(strcmp(comandoMain,"find") == 0){i = 8;}
            if(strcmp(comandoMain,"locate") == 0){i = 9;}
            if(strcmp(comandoMain,"ls") == 0){i = 10;}
            if(strcmp(comandoMain,"diff") == 0){i = 11;}
            if(strcmp(comandoMain,"pwd") == 0){i = 12;}
            if(strcmp(comandoMain,"jobs") == 0){i = 13;}
            if(strcmp(comandoMain,"ps") == 0){i = 14;}
            if(strcmp(comandoMain,"du") == 0){i = 15;}
            if(strcmp(comandoMain,"sort") == 0){i = 16;}
            if(strcmp(comandoMain,"rm") == 0){i = 17;}
            if(strcmp(comandoMain,"neofetch") == 0){i = 18;}
            if(strcmp(comandoMain,"uname") == 0){i = 19;}
            if(strcmp(comandoMain,"touch") == 0){i = 20;}
            switch (i){
                case 1: printf("Ejecutando mkdir\n");comandoMkdir();break;
                case 2:printf("Ejecutando rmdir\n");comandoRmdir();break;
                case 3:printf("Ejecutando grep\n");comandoGrep();break;
                case 4:printf("Ejecutando head\n");comandoHead();break;
                case 5:printf("Ejecutando cat\n");comandoCat();break;
                case 6:printf("Ejecutando cp\n");comandoCp();break;
                case 7:printf("Ejecutando tail\n");comandoTail();break;
                case 8:printf("Ejecutando find\n");comandoFind();break;
                case 9:printf("Ejecutando locate\n");comandoLocate();break;
                case 10:printf("Ejecutando ls\n");comandoLs();break;
                case 11:printf("Ejecutando diff\n");comandoDiff();break;
                case 12:printf("Ejecutando pwd\n");comandoPwd();break;
                case 13:printf("Ejecutando Jobs\n");comandoJobs();break;
                case 14:printf("Ejecutando Ps\n");comandoPs();break;
                case 15:printf("Ejecutando Du\n");comandoDu();break;
                case 16:printf("Ejecutando sort\n");comandoSort();break;
                case 17:printf("Ejecutando Rm\n");comandoRm();break;
                case 18:printf("Ejecutando Neofetch\n");comandoNeofetch();break;
                case 19:printf("Ejecutando uname\n");comandoUname();break;
                case 20:printf("Ejecutando touch\n");comandoTouch();break;
                default:printf("No se encontro el comando\n");break;
            }
        }
    } while (i!=-1);
    printf("TERMINAL FINALIZADO\n");
    //comandoLocate();
    //comandoCat();
    return 0;
}

void comandoMkdir(){

    printf("1.Crear carpeta\n");
    int opcion;
    scanf("%i",&opcion);
    if( opcion == 1){
        printf("Ingrese el nombre de la carpeta\n");
        char carpeta[30];
        scanf("%s",&carpeta);
        int status = mkdir(carpeta,0777); 
        if (status == 0)
        {
            printf("Carpeta creada correctamente\n");  
        } else {
            printf("No se creo la carpeta\n");
            comandoMkdir();
        }
 }
}


void comandoRmdir(){
    printf("Seleccione la carpeta que desea borrar\n");
    char borrado[30];
    scanf("%s",&borrado);
    int delete = rmdir(borrado);
    if (delete == 0)
        {
            printf("Carpeta borrada correctamente\n");  
        } else {
            printf("No se pudo borrar la carpeta\n");
            comandoRmdir();
        }

}

int comandoGrep(){ // -v -c
    int pid = fork();
    if(pid == -1){
        return 1;
    }
    if(pid == 0) { // proceso hijo
        char comando[50];
        char modo[50];
        char entrada[50];
        char archivo[50];
        scanf("%s %s %s %s", &comando, &modo, &entrada, &archivo);
        FILE *busqueda = fopen(archivo,"r");
        if(busqueda == NULL){
            printf("No se encontro el archivo\n");
        }
        else{
            if(modo == "null"){
                execlp("/bin/grep","grep",entrada,archivo,NULL);
            }else{
            execlp("/bin/grep","grep",modo, entrada,archivo,NULL);
            }
                  
        }
    }else{ // proceso padre
            wait(NULL);
            printf("Grep finalizado\n"); 
    }
    return 1;

}


int comandoHead(){ // tiene opcion 1 sin cantidad, 2 con cantidad
    int pid = fork();
    if(pid == -1){
        return 1;
    }
    if(pid == 0) { // proceso hijo
    char comando[50];
    char cantidad[50];
    char archivo[50];
    int opcion;
    scanf("%i",&opcion);
    if(opcion == 1){
            scanf("%s %s", &comando, &archivo);
            FILE *busqueda = fopen(archivo,"r");
            if(busqueda == NULL){
                printf("No se encontro el archivo\n");
            }else{
                 execlp("/bin/head","head", archivo, NULL);        
            }
            
    }else if(opcion == 2){
            scanf("%s %s %s", &comando, &cantidad, &archivo);
            FILE *busqueda = fopen(archivo,"r");
    
            if(busqueda == NULL){
                printf("No se encontro el archivo\n");
            }else{
                execlp("/bin/head","head", cantidad, archivo, NULL); 
            }
            
        }
    }else{
        wait(NULL);
        printf("Head finalizado\n");
    }
    //printf("Ingrese el nombre del archivo\n");
    //char archivo[50];
    //scanf("%s",&archivo);
    return 1;
}

int comandoCat(){ // -n
    int pid = fork();
    if(pid == -1){
        return 1;
    }
    if(pid == 0){
        char comando[50];
        char modo[20];
        char nombre[30];
        scanf("%s %s %s", &comando, &modo, &nombre);
        FILE *busquedacontenido = fopen(nombre,"r");
        if(busquedacontenido == NULL){
            printf("No se encontro el archivo\n");
        }
        else{
            execlp("/bin/cat","cat",modo, nombre,NULL);    
        }
    }else{
        wait(NULL);
        printf("Cat finalizado\n");
    }
    return 1;
}

int comandoCp(){ // cp -r(recursion) Pruebacp Pruebacp2
    int pid = fork();
    if(pid == -1){
        return 1;
    }
    if(pid == 0){
    char comando[50];
    char modo[20];
    char nombre[30];
    char destino[30];
    scanf("%s %s %s %s", &comando, &modo, &nombre, &destino);
    FILE *busquedacp = fopen(nombre,"r");
    if(busquedacp == NULL){
        printf("No se encontro el archivo\n");
    }
    else{
        if(strcmp(modo,"") == 0){
            execlp("/bin/cp","cp",nombre,destino,NULL);
        }else{
            execlp("/bin/cp","cp",modo, nombre,destino,NULL);
        }    
    }
    }else{
        wait(NULL);
        printf("Cp finalizado\n");
    }
    return 1;
}

// comando mb examinar

int comandoTail(){ // con cantidad
    int pid = fork();
    if(pid == -1){
        return 1;
    }
    if(pid == 0){
    char comando[50];
    char cantidad[50];
    char archivo[50];
    scanf("%s %s %s", &comando, &cantidad, &archivo);
    //printf("Ingrese el nombre del archivo\n");
    //char archivo[50];
    //scanf("%s",&archivo);

    FILE *busquedaTail = fopen(archivo,"r");
    if(busquedaTail == NULL){
        printf("No se encontro el archivo\n");
    }
    else{
            execlp("/bin/tail","tail", cantidad, archivo,NULL);  
    }
    }else{
        wait(NULL);
        printf("tail finalizado\n");
    }
    return 1;
}


int comandoFind(){ // find Pruebacp/ -name *.txt ejemplo.*
    int pid = fork();
    if(pid == -1){
        return 1;
    }
    if(pid == 0){
    char comando[50];
    char ruta[50];
    char modo[50];
    char busqueda[50];
    scanf("%s %s %s %s", &comando, &ruta, &modo, &busqueda);
    execlp("/bin/find","find", ruta, modo, busqueda, NULL); 
    }else{
        wait(NULL);
        printf("Find finalizado\n");
    }
    return 1;
}

int comandoLocate(){ // locate *.txt      locate -c *.txt   c = cantidad de veces de una busqueda
    int pid = fork();
    if(pid == -1){
        return 1;
    }
    if(pid == 0){
    char comando[50];
    char modo[50];
    char archivo[50];
    int opcion;
    scanf("%i",&opcion);
    if(opcion == 1){
        scanf("%s %s", &comando, &archivo);
        execlp("/bin/locate","locate", archivo, NULL); 
    }else if(opcion == 2){
        scanf("%s %s %s", &comando, &modo, &archivo);
        execlp("/bin/locate","locate", modo, archivo, NULL); 
    }
    }else{
        wait(NULL);
        printf("Locate finalizado\n");
    }
    return 1;
}

int comandoLs(){// ls -al -l
    int pid = fork();
    if(pid == -1){
        return 1;
    }
    if(pid == 0) { // child process
        //char carpeta[50];
        char comando[50];
        char modo[50];
        scanf("%s %s", &comando, &modo);
        execlp("/bin/ls","ls", modo, NULL);
    }else{
        //PARENT PROCESS
        wait(NULL);
        printf("Ls finalizado\n");
    }
    return 1;    
}

/*
void comandoCD(){
    char comando[50];
    char ruta[50];
    //char carpeta[50];
    scanf("%s %s", &comando, &ruta);
    execlp("/bin/cd","cd", ruta, NULL); 
}*/

int comandoDiff(){ //diff -q -s -c ejemplo.txt ejemplo2.txt
    int pid = fork();
    if(pid == -1){
        return 1;
    }
    if(pid == 0) {
    char comando[50];
    char modo[50];
    char archivo1[50];
    char archivo2[50];
    scanf("%s %s %s %s", &comando, &modo, &archivo1, &archivo2);
    execlp("/bin/diff","diff", modo, archivo1, archivo2, NULL);
    }else{
        wait(NULL);
        printf("Diff finalizado\n");
    } 
    return 1;
}


int comandoPwd(){ // pwd -P -L
    int pid = fork();
    if(pid == -1){
        return 1;
    }
    if(pid == 0) {
    char comando[50];
    char modo[50];
    scanf("%s %s", &comando, &modo);
    execlp("/bin/pwd","pwd", modo, NULL); 
    }else{
        wait(NULL);
        printf("Pwd finalizado\n");
    }
    return 1;
}

// si funciona pero no muestra cambios
int comandoJobs(){ // jobs -l -n -p
    int pid = fork();
    if(pid == -1){
        return 1;
    }
    if(pid == 0) {
    char comando[50];
    char modo[50];
    scanf("%s %s", &comando, &modo);
    execlp("/bin/jobs","jobs", modo, NULL); 
    }else{
        wait(NULL);
        printf("Jobs finalizado\n");
    }
    return 1;
}

int comandoPs(){ // ps -e -f
    int pid = fork();
    if(pid == -1){
        return 1;
    }
    if(pid == 0) {
    char comando[50];
    char modo[50];
    scanf("%s %s", &comando, &modo);
    execlp("/bin/ps","ps", modo, NULL); 
    }else{
        wait(NULL);
        printf("Ps finalizado\n");
    }
    return 1;
}


int comandoDu(){ // du -bsh Pruebacp/
    int pid = fork();
    if(pid == -1){
        return 1;
    }
    if(pid == 0) {
    char comando[50];
    char modo[50];
    char directorio[50];
    scanf("%s %s %s", &comando, &modo, &directorio);
    execlp("/bin/du","du", modo, directorio, NULL); 
    }else{
        wait(NULL);
        printf("Du finalizado\n");
    }
    return 1;
}

int comandoSort(){ // sort -n pruebaSORT.txt
    int pid = fork();
    if(pid == -1){
        return 1;
    }
    if(pid == 0) {
    char comando[50];
    char modo[50];
    char archivo[50];
    scanf("%s %s %s", &comando, &modo, &archivo);
    execlp("/bin/sort","sort", modo, archivo, NULL); 
    }else{
        wait(NULL);
        printf("Sort finalizado\n");
    }
    return 1;
}

int comandoRm(){ // rm -i rm.txt 
    int pid = fork();
    if(pid == -1){
        return 1;
    }
    if(pid == 0) {
    char comando[50];
    char modo[50];
    char archivo[50];
    scanf("%s %s %s", &comando, &modo, &archivo);
    execlp("/bin/rm","rm", modo, archivo, NULL); 
    }else{
        wait(NULL);
        printf("Rm finalizado\n");
    }
    return 1;
}

int comandoNeofetch(){ // neofetch
    int pid = fork();
    if(pid == -1){
        return 1;
    }
    if(pid == 0) {
    char comando[50];
    scanf("%s", &comando);
    execlp("/bin/neofetch","neofetch",NULL); 
    }else{
        wait(NULL);
        printf("Neofetch finalizado\n");
    }
    return 1;
}

int comandoUname(){ // uname -a -s -n
    int pid = fork();
    if(pid == -1){
        return 1;
    }
    if(pid == 0) {
    char comando[50];
    char modo[50];
    scanf("%s %s", &comando, &modo);
    execlp("/bin/uname","uname", modo, NULL); 
    }else{
        wait(NULL);
        printf("Uname finalizado\n");
    }
    return 1;
}

int comandoTouch(){ // touch archivo
    int pid = fork();
    if(pid == -1){
        return 1;
    }
    if(pid == 0) {
     char comando[50];
     char archivo[50];
    scanf("%s %s", &comando, &archivo);
    execlp("/bin/touch","touch", archivo, NULL); 
    }else{
        wait(NULL);
        printf("Touch finalizado\n");
    }
    return 1;
}

void comandoLess(){
    // e j para avanzar
    // y k para retroceder
    // combinarlo con numero para avanzar
    // e principio documento
    // E final del documento
    // q para salir
    char comando[50];
    char modo[50];
    char archivo[50];
    scanf("%s %s %s", &comando, &modo, &archivo);
    execlp("/bin/less","less", modo, archivo, NULL); 
}





/*
void comandoTar(){
    char comando[50];
    char modo[50];
    char comprimido[50];
    char archivo1[50];
    char archivo2[50];
    char archivo3[50];
    scanf("%s %s", &comando, &modo, &comprimido, &archivo1, &archivo2, &archivo3);
    execlp("/bin/tar","tar", modo, comprimido, archivo1, archivo2, archivo3, NULL); 
}*/


