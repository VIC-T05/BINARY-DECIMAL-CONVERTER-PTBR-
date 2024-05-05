#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define BIN_SIZE 8

// Função para imprimir um número binário
void print_binary(int *binary) {
    for (int i = BIN_SIZE - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
}

// Função para verificar se um número é binário
int is_valid_binary(int num) {
    while (num != 0) {
        int temp = num % 10;
        if (temp != 0 && temp != 1) {
            return 0; // Não é binário
        }
        num /= 10;
    }
    return 1; // É binário
}

// Função para converter um número decimal para binário
int decimal_to_binary(int decimal, int *binary) {
    for (int i = 0; i < BIN_SIZE; i++) {
        binary[i] = decimal % 2;
        decimal /= 2;
    }
}

// Função para converter um número binário para decimal
int binary_to_decimal(int binary) {
    int decimal = 0, i = 0;
    while (binary != 0) {
        int remainder = binary % 10;
        binary /= 10;
        decimal += remainder * pow(2, i);
        ++i;
    }
    return decimal;
}

// Função para obter uma opção válida do usuário
int get_valid_option() {
    int option;
    while (1) {
        if (scanf("%d", &option) != 1 || (option != 1 && option != 2)) {
            printf("\nOPCAO INVALIDA. TENTE NOVAMENTE.\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
        } else {
            break;
        }
    }
    return option;
}

// Função para obter uma resposta válida para continuar ou sair
char get_valid_continue() {
    char choice;
    while (1) {
        scanf(" %c", &choice);
        if (choice != 's' && choice != 'n') {
            printf("\nENTRADA INVÁLIDA! DIGITE 's' PARA CONTINUAR OU 'n' PARA SAIR\n");
        } else {
            break;
        }
    }
    return choice;
}

int main(void) {
    printf("\n\n   01110111 01100101 01101100 01100011 01101111 01101101 01100101");
    printf("\n\n   01110111 01100101|    BEM VINDO    |01101111 01101101 01100101");
    printf("\n\n   01110111 01100101 01101100 01100011 01101111 01101101 01100101\n\n");
    sleep(1);

    while (1) {
        printf("\n----------------------------------------------------------------");
        printf("\n------------------ |   CONVERSOR BINARIO   | -------------------");
        printf("\n----------------------------------------------------------------");
        printf("\n\nDIGITE O NNMERO DA OPCAO QUE DESEJA EXECUTAR:");
        printf("\n\n| 1 | CONVERTER UM NUMERO DECIMAL PARA BINARIO");
        printf("\n| 2 | CONVERTER UM NUMERO BINARIO PARA DECIMAL\n");

        // Obter e validar a opção do usuário
        int option = get_valid_option();

        if (option == 1) {
            printf("\n-----------------------------------------------------");
            printf("\n------------ |  DECIMAL --> BINARIO  | --------------");
            printf("\n-----------------------------------------------------");

            int decimal;
            printf("\n\nINSIRA UM NUMERO DECIMAL INTEIRO QUE DESEJA CONVERTER PARA BINARIO: ");
            scanf("%d", &decimal);

            int binary[BIN_SIZE];
            decimal_to_binary(decimal, binary);

            printf("\nO NUMERO %d EM BINARIO E: ", decimal);
            print_binary(binary);
        } else if (option == 2) {
            printf("\n----------------------------------------------------------------");
            printf("\n------------------ |  BINARIO --> DECIMAL  | -------------------");
            printf("\n----------------------------------------------------------------");

            int binary;
            printf("\n\nDIGITE UM NUMERO BINARIO: ");
            scanf("%d", &binary);

            while (!is_valid_binary(binary)) {
                printf("\nO NUMERO DIGITADO NAO E VALIDO. TENTE NOVAMENTE: ");
                scanf("%d", &binary);
            }

            int decimal = binary_to_decimal(binary);
            printf("\nO NUMERO BINARIO %d E EQUIVALENTE A %d EM DECIMAL.\n\n", binary, decimal);
        }

        printf("\n\nDESEJA CONTINUAR CONVERTENDO? (s/n)\n");
        char continue_choice = get_valid_continue();

        if (continue_choice == 'n') {
            printf("\nOK! ENCERRANDO O PROGRAMA.\n");
            break;
        }
    }

    return 0;
}
