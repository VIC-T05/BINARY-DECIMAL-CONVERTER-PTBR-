#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

main(void)
{	
	//TELA INICIALIZAÇÃO
	sleep(1);
	printf("\n\n   01110111 01100101 01101100 01100011 01101111 01101101 01100101");
	sleep(1);
	printf("\n\n   01110111 01100101|    BEM VINDO    |01101111 01101101 01100101");
	sleep(1);
	printf("\n\n   01110111 01100101 01101100 01100011 01101111 01101101 01100101\n\n");
	system("pause");
	system("cls");
	
	
	//MENU COM OPÇÕES		
	int loopingMenu = 1;	
	do{
		
		printf("\n----------------------------------------------------------------");
		printf("\n------------------ |   CONVERSOR BINARIO   | -------------------");
		printf("\n----------------------------------------------------------------");	
		printf("\n\nDIGITE O NUMERO DA OPCAO QUE DESEJA EXECUTAR:");
		printf("\n\n| 1 | CONVERTER UM NUMERO DECIMAL PARA BINARIO");
		printf("\n| 2 | CONVERTER UM NUMERO BINARIO PARA DECIMAL\n");
		
		//CONFERE SE O NUMERO DA OPÇÃO DIGITADA E VALIDO
		int opcao;
		int result = 0;
		int msg = 0;
		
		do{	  
				    
	        result = scanf("%d", &opcao);	
	  	    if(result != 1 || opcao > 2 || opcao < 1){
	        	printf("\nA OPCAO DIGITADA NAO EXITE. TENTE NOVAMENTE\n");	        	
	        	while(getchar() != '\n');		       	
	    	}			
	    }while(result != 1 || opcao > 2 || opcao < 1);
	    
	    //INICIA A PRIMEIRA OPCAO
	    if(opcao == 1){	   
		 	
	    	int loopingOpcao = 1; //inicia a variavel para controlar o looping da opcao	  
			  	
	    	do{	//Looping Primeira opcao		
		    	system("cls");
		    	printf("\n-----------------------------------------------------");
				printf("\n------------ |  DECIMAL --> BINARIO  | --------------");
				printf("\n-----------------------------------------------------");
				sleep(1);
	    	
	    																	
				//CONFERE SE O NUMERO DIGITADO É UM NUMERO INTEIRO
				
				result = 0;	//variavel para conferir se o numero inserio é valido				
				int decimal;
				int binario[8];				
				do{	
					printf("\n\n|--INSIRA UM NUMERO DECIMAL INTEIRO QUE DESEJA CONVERTER PARA BINARIO--|\n");              
			        result = scanf("%d", &decimal);
			
			  	    if(result != 1){
			        	printf("\n O NUMERO DIGITADO E INVALIDO. TENTE NOVAMENTE");
			        	sleep(1);
			        	system("cls");
			        	while(getchar() != '\n');
			    	}			
			    }while(result != 1);
			      
			    //SISTEMA DE CONVERSÃO
			     
			    int resultFinal = decimal; //variavel para guardar valor inserido
				int quociente; // variavel simples que armazena o resultado da divisão inteira  
			    int resto; // variavel simples que armazena o resto da divisão do numero insirido por 2
				      
			    for (int i = 0 ; i < 8 ; i++){
			    
			    	quociente = decimal / 2;
			   		resto = decimal % 2;
			   		binario[i] = resto;
			   		decimal = quociente;
			      	
				}
				  
				// MOSTRA NA TELA O RESULTADO EM BIANRIO A PARTIR DO NUMERO MAIS SIGNIFICATIVO 
				system("cls");
		    	printf("\n-----------------------------------------------------");
				printf("\n------------ |  DECIMAL --> BINARIO  | --------------");
				printf("\n-----------------------------------------------------");
				printf("\nO NUMERO %d EM BINARIO E: ", resultFinal);
				for (int i = 7 ; i >= 0 ; i--){		
					printf("%d", binario[i]);		
				}								
			    
			    //verifica se usuario deseja continuar
			    char continuar;			    
				do{ //looping para conferir se o valor inserido é valido
					printf("\n\nDESEJAR CONTINUAR CONVERTENDO? (s/n)\n");
			    	scanf(" %c", &continuar);	
							    	
			    	if(continuar != 's' && continuar != 'n'){
			    		system("cls");
			    		printf("\nENTRADA INVALIDA! DIGITE 's' PARA CONTINUAR OU 'n' PARA SAIR");
					}
			    	
			    }while(continuar != 's' && continuar != 'n');
			    
			    if(continuar == 's'){//se 's' ele reinicia o looping da opcao
			    	printf("\nOK! VAMOS CONTINUAR!");
			    	sleep(2);
			    	system("cls");
			    	loopingOpcao = 1;
				}
			    
			    if(continuar == 'n'){ //se 'n' sai do looping da opçao
			    	printf("\nOK! VOLTANDO AO MENU!");
			    	sleep(2);
			    	system("cls");
			    	loopingOpcao = 0; // o looping da opcao se torna negativo
					loopingMenu = 1; //  e o looping do menu 		    	
				}
				
			}while(loopingOpcao == 1); //FIM LOOPING OPCAO 1
		    		
		} //FIM PRIMEIRA OPCAO 
		
		//INICIA A SEGUNDA OPCAO
		if(opcao == 2){
			
			int loopingOpcao = 1; //inicia a variavel para controlar o looping da opcao
			
			do{
			
				system("cls");
		    	printf("\n----------------------------------------------------------------");
				printf("\n------------------ |  BINARIO --> DECIMAL  | -------------------");
				printf("\n----------------------------------------------------------------");
				sleep(1);
				
				int numBinario; // variavel de entrada do numero binario
				int numBinarioTemp; // variavel para testar se o numero é um numero binario
				int numBinarioInicial; // variavel para armazenar o numero digitado incialmente para mostrar-lo depois
				int temp;	
																	
				do { // looping que verifica se o numero inserido é um numero binario
			        printf("\n\nDIGITE UM NUMERO BINARIO: ");
			        scanf("%d", &numBinario);
			        
			        numBinarioTemp = numBinario;
			        numBinarioInicial = numBinario;
			
			        int eBinario = 1;
			
			        // Verifica se o número digitado é binário
			        while (numBinario != 0) {
			            temp = numBinario % 10;
			
			            // Verifica se o dígito não é 0 ou 1
			            if (temp != 0 && temp != 1) {
			                eBinario = 0; // Não é binário
			                system("cls");
			                printf("---O NUMERO DIGITADO NAO E INVALIDO. TENTE NOVEMNTE---\n");
			                sleep(1);
			                break; // Sai do loop interno
			            }
			
			            numBinario /= 10;
			        }
			
			        if (eBinario) {		        
			            break;
			        }
			
		    	} while (1);
	
		    	// SISTEMA DE CONVERSÃO
		    	int resto, i = 0, decimal = 0;	
					    	
		    	while (numBinarioTemp != 0) {
		    		resto = numBinarioTemp % 10;
		    		numBinarioTemp /= 10;
		    		decimal += resto * pow(2,i); // A função pow(2, i) é usada para calcular as potências de 2.
		    		++i;
				}
				//ESCREVA NA TELA O NUMERO CONVERTIDO
				system("cls");
				printf("\n----------------------------------------------------------------");
				printf("\n------------------ |  BINARIO --> DECIMAL  | -------------------");
				printf("\n----------------------------------------------------------------");
				printf("\n\nO NUMERO %d E EQUIVALENTE A %d EM DECIMAL.\n\n", numBinarioInicial, decimal);
				sleep(1);
				
				//PERGUNTA SE O USUARIO QUER CONTINUAR
				char continuar;
			    
				do{//looping para conferir se o valor inserido é valido
					printf("\n\nDESEJAR CONTINUAR CONVERTENDO? (s/n)\n");
			    	scanf(" %c", &continuar);	
							    	
			    	if(continuar != 's' && continuar != 'n'){
			    		system("cls");
			    		printf("\nENTRADA INVALIDA! DIGITE 's' PARA CONTINUAR OU 'n' PARA SAIR");
					}
			    	
			    }while(continuar != 's' && continuar != 'n');
			    
			    if(continuar == 's'){//se 's' ele reinicia o looping da opcao
			    	printf("\nOK! VAMOS CONTINUAR!");
			    	sleep(2);
			    	system("cls");
			    	loopingOpcao = 1;
				}
			    
			    if(continuar == 'n'){//se 'n' sai do looping da opçao
			    	printf("\nOK! VOLTANDO AO MENU!");
			    	sleep(2);
			    	system("cls");
			    	loopingOpcao = 0;// o looping da opcao se torna negativo
					loopingMenu = 1;			    	
				}
				
			}while(loopingOpcao == 1); //looping da opçao selecionada
		}	
	}while(loopingMenu == 1); //looping permanente do menu
						
}
