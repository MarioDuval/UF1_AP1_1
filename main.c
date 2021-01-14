#include <stdio.h> //Per poder utilitzar caràcters
#include <string.h> //Per poder utilitzar cadenes de caràcters
#include <stdlib.h> //Per poder fer els valors aleatoris
#include <time.h> //Per poder fer els valors aleatoris
#include <ctype.h> //Per poder fer la conversió d'un caràcter a majúscules



void main(){
    char alphabet[3][10] = {
            {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', '\0'},
            {'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', '\0'},      //La matriu amb les lletres de l'abecedari
            {'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z','\0'},
    };

    printf("\t\t\t*****************************************\n");
    printf("\t\t\t*****************************************\n");
    printf("\t\t\t*****************************************\n");
    printf("\t\t\t********Bienvenid@ al AHORCADO***********\n");  //La benvinguda al joc
    printf("\t\t\t*****************************************\n");
    printf("\t\t\t*****************************************\n");
    printf("\t\t\t*****************************************\n\n");

    system("pause"); //Per pausar la neteja de pantalla
    system("cls"); //Per fer la neteja de pantalla

    int numberAttempts = 7; //Variable per controlar el número d'intents

    char *word[] = {"ORDENADOR", "MASCARILLA","DINERO", "ANIMAL", "DEPORTE", "INSTITUTO", "AVION", "ISLA"}; //array amb la selecció de paraules
    int posWord; //aletori de les paraules
    srand( (unsigned)time ( NULL ) ); //Inicia el generador de nombres pseudoaleatoris
    posWord = rand()%9; //Genera un nombre pseudoaleatori
    char *hidden = word[posWord]; //On guardem la paraula aleatoria

    char wordToComplete[strlen(hidden)]; //array en la qual s’anirà afegint les lletres de la paraula que el jugador vagi encertant.
    for (int i = 0; i < strlen(hidden); i++) {
        wordToComplete[i] = '_';         //On subsitutim la paraula per '_'
    }
    printf("\t\t\t");
    for (int i = 0; i < strlen(hidden); i++) {
        printf("%c ", wordToComplete[i]);
    }
    printf("\n\n");
    int guess = 0;
    while((numberAttempts > 0) && (guess == 0)) { //bucle que mentre es compleixi la condició les operacions s'executaran
        char selectedLetter; //Lletra introduida per teclat
        printf("\n");
        for(int i=0;i<3;i++){
            printf("\t\t\t");
            for(int j=0;j<10;j++){
                printf("%c ", alphabet[i][j]);  //Bucle per recórrer l'abecedari
            }
            printf("\n");
        }
        printf("\n");
        printf("\t\t\tNumero de intentos restantes: %d\n\n", numberAttempts); //S'ensenya els intents que li queden

        printf("\t\t\tIntroduce una letra: ");
        scanf("%c", &selectedLetter); //Escanejem la lletra introduida per teclat
        getchar(); //Retorna el caràcter llegit
        selectedLetter = toupper(selectedLetter); //Per fer la conversió de minúscula a majúscula
        printf("\n");
        int numberRightAnswer = 0; //Número de lletres que es porta encertades
        int repeat = 0; //Variable per si es repeteix la lletra introduida
        for(int i = 0; i < strlen(hidden); i++) {  //bucle per recórrer la paraula a adivinar
            if(hidden[i] == selectedLetter) {
                numberRightAnswer = 1;
                if (wordToComplete[i] == selectedLetter) //Condició de la lletra encertada
                    repeat = 1;
                    wordToComplete[i] = selectedLetter;

            }
        }


        if(repeat == 1)
            printf("Letra repetida, debes introducir una distinta\n"); //Condició on s'analitza arrel la condició anterior que la lletra no es pot repetir

        if(numberRightAnswer == 0){ //Condició de la lletra fallada
            numberAttempts--; //Es resta un a la variable dels errors que es tenen
            switch (numberAttempts) { //condició per crear el penjat a partir del número d'errrors
                case 0:
                    printf("\n\t\t\t||===== ");
                    printf("\n\t\t\t||    | ");
                    printf("\n\t\t\t||   %cO/", '\\');
                    printf("\n\t\t\t||    | ");
                    printf("\n\t\t\t||   / %c",'\\');
                    printf("\n\t\t\t||      ");
                    break;
                case 1:
                    printf("\n\t\t\t||===== ");
                    printf("\n\t\t\t||    | ");
                    printf("\n\t\t\t||   %cO/",'\\');
                    printf("\n\t\t\t||    | ");
                    printf("\n\t\t\t||     %c",'\\');
                    printf("\n\t\t\t||      ");
                    break;
                case 2:
                    printf("\n\t\t\t||===== ");
                    printf("\n\t\t\t||    | ");
                    printf("\n\t\t\t||   %cO/",'\\');
                    printf("\n\t\t\t||    | ");
                    printf("\n\t\t\t||      ");
                    printf("\n\t\t\t||      ");
                    break;
                case 3:
                    printf("\n\t\t\t||===== ");
                    printf("\n\t\t\t||    | ");
                    printf("\n\t\t\t||   %cO/",'\\');
                    printf("\n\t\t\t||      ");
                    printf("\n\t\t\t||      ");
                    printf("\n\t\t\t||      ");
                    break;
                case 4:
                    printf("\n\t\t\t||===== ");
                    printf("\n\t\t\t||    | ");
                    printf("\n\t\t\t||   %cO ",'\\');
                    printf("\n\t\t\t||      ");
                    printf("\n\t\t\t||      ");
                    printf("\n\t\t\t||      ");
                    break;
                case 5:
                    printf("\n\t\t\t||===== ");
                    printf("\n\t\t\t||    | ");
                    printf("\n\t\t\t||    O ");
                    printf("\n\t\t\t||      ");
                    printf("\n\t\t\t||      ");
                    printf("\n\t\t\t||      ");
                    break;
                case 6:
                    printf("\n\t\t\t||===== ");
                    printf("\n\t\t\t||    | ");
                    printf("\n\t\t\t||      ");
                    printf("\n\t\t\t||      ");
                    printf("\n\t\t\t||      ");
                    printf("\n\t\t\t||      ");
                    break;
            }
            printf("\n");
        }
        printf("\t\t\t");
        for (int i = 0; i<strlen(hidden); i++) {
            printf("%c ", wordToComplete[i]); //mostrem les lletres que es vagin encertan
        }

        if(strchr(wordToComplete, '_') == NULL) { //retorna null si no la conté o punter a la posició en la que es troba
            guess = 1;
            printf("\n\t\t\tFELICIDADES, HAS GANADO!!!"); //condició si les lletres formen la paraula s'ha guanyat
        }

        if (numberAttempts <=0) {
            guess = 1;
            printf("\n\n\t\t\tLASTIMA, HAS PERDIDO\n");  //condició en el cas de perdre
            printf("\t\t\tLa palabra que tenias que adivinar era: %s", hidden);
        }
    }
}








