#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;

//Array de char para imprimir al final
char Verificador_final[64] = {};
int contador = 0;

void chasing(int **A[], int a, int *B[], int b, int C[], int c){
    
    int flag = 0;
    string Evaluador;
    
    string Valor1;
    string Valor2;
    
    string S_Primero;
    string S_Segundo;
    
    int Primero;
    int Segundo;
    
    //Orden es "Valor1 Primero Valor2 Segundo"
    
    while (flag == 0){
        
        //Consigo la linea
        getline(cin,Evaluador);
        
        if (Evaluador != ""){
            istringstream iss(Evaluador);
            
            //Inicialmente validos
            int valido1 = 1;
            int valido2 = 1;
            
            //Contadores de ceros (Para una excepcion)
            int contador_01 = 0;
            int contador_02 = 0;
            
            //Obtengo valores
            iss >> Valor1;
            iss >> S_Primero;
            iss >> Valor2;
            iss >> S_Segundo;
            
            //Conviero a int los valores, si no realizo lo anterior se hace un truncado.
            //En caso el valor es invalido se hace 0
            stringstream geek1(S_Primero);
            geek1 >> Primero;
            
            stringstream geek2(S_Segundo);
            geek2 >> Segundo;
            
            
            //Validación del primer numero
                //Valido que sean Numeros validos (No negativos, no decimales)
                for(int i = 0; i < S_Primero.size(); ++i) {
                    if (S_Primero[i] == '.' || S_Primero[i] == '-'){
                        valido1 = 0;
                    }
                    //Una excepcion para el 0 se tiene que hacer
                    if (S_Primero[i] == '0'){
                        contador_01++;
                    }
                }
                
                //Validacion de los 0
                if (contador_01 == S_Primero.size()){
                    Primero = 0;
                }
                //En caso no sea puros ceros, si el valor truncado es 0 ,descartalo
                else{
                    if(Primero == 0){
                        valido1 = 0;
                    }
                }
                
                
                
            //Validación del Segundo numero
                //Valido que sean Numeros validos (No negativos, no decimales)
                for(int i = 0; i < S_Segundo.size(); ++i) {
                    if (S_Segundo[i] == '.' || S_Segundo[i] == '-'){
                        valido2 = 0;
                    }
                    //Una excepcion para el 0 se tiene que hacer
                    if (S_Segundo[i] == '0'){
                        contador_02++;
                    }
                }
                
                //Validacion de los 0
                if (contador_02 == S_Segundo.size()){
                    Segundo = 0;
                }
                //En caso no sea puros ceros, si el valor truncado es 0 ,descartalo
                else{
                    if(Segundo == 0){
                        valido2 = 0;
                    }
                }
        
            
            
            //Recien ejecuto acciones si todo valido
            if (Valor1 == "A" && Valor2 == "B" && valido1 == 1 && valido2 == 1){
                if (Primero >= a || Segundo >= b){
                    Verificador_final[contador] = '0';
                }
                else{
                    A[Primero] = &B[Segundo];
                    Verificador_final[contador] = '1';
                }

            }
            else if(Valor1 == "B" && Valor2 == "C" && valido1 == 1 && valido2 == 1){
                if (Primero >= b || Segundo >= c){
                    Verificador_final[contador] = '0';
                }
                else{
                    B[Primero] = &C[Segundo];
                    Verificador_final[contador] = '1';                    
                }
            }
            else{
                Verificador_final[contador] = '0';
            }
        }
        else{
            flag = 1;
        }
    contador++;
    }
}


int main() {
        int a = 3, b = 3, c = 3;
        int **A[3] = {}, *B[3] = {}, C[3] = {2, 1, 4};
        chasing(A, a, B, b, C, c);
 
        int **ansA[3] = {} ,*ansB[3] = {};
        for (int i = 0; i < a; i++)
                ansA[i] = NULL;
        for (int i = 0; i < b; i++)
                ansB[i] = NULL;
        ansA[0] = &B[1];;
        /*Check A*/
        for (int i = 0; i < a; i++)
                if (A[i] != ansA[i] )
                        printf("A[%d] wrong answer!\n", i);
 
        /*Check B*/
        for (int i = 0; i < b; i++){
                if (B[i] != ansB[i] )
                        printf("B[%d] wrong answer!\n", i);
        }     
        for (int i = 0;i < contador;i++){
            cout << Verificador_final[i] << endl;
        }
        return 0;
}