#include <stdio.h>
#include <string.h>
#include <math.h>

// hamming encode --input 0x3E465C
    //    1      2       3       4
void encode(int argc, char *argv[]){
    int i = 3;

    while (i < argc){
        // Aqui almaceno el resultado de todos los hexadecimal
        unsigned long long int total_result;
        // Valor hexadecimal que obtengo de args
        unsigned long int hex;
        sscanf(argv[i], "%lX", &hex);
        // Cantidad de bits del hexadecimal
        int bits = (int)log2(hex) + 1;
        // Numero maximo de hammings que voy a hacer
        int max_hammings = ceil(bits/7);
        // Numero de hammings que llevo
        int i_hammings = 0;
        while (i_hammings < max_hammings){
            // Aqui almaceno el resultado de los hammings de ESTE hexadecimal
            unsigned long long int hammings_result;
            int parity_done = 0;
            for (int index = 7 * i_hammings; index < 7 * (i_hammings + 1); index++){
                // Variable donde almaceno temporalmente el resultado del hamming
                unsigned int hamming = 0;
                if((index%7)==3 || (index%7)==7 || (index%7)>=9){
                    // TODO calculo de parity
                    parity_done++;
                    continue;
                }
                hamming = hamming | (((parity_done >> (index+parity_done)) & 1) << (index+parity_done));
            }
            printf("%llx ",hammings_result);
            i_hammings++;
        }

        i++;
    }
}
// hamming decode --input 0x3E465C --error 5
//    1      2       3       4       5     6
void decode(int argc, char *argv[]){
    
}

int main(int argc, char *argv[]) {
	
    char *arg;
    int mode = 0;


    if (argc < 4){
        printf("Muy pocos argumentos\n");
        return 0;
    }

    // hamming encode --input 0x3E465C
    //    1      2       3       4
    if(strcmp(argv[1], "encode") == 0){
        printf("encode\n");
        // Encode
        encode(argc, argv);
    }if(strcmp(argv[1], "decode") == 0){
        // Decode
        printf("decode\n");
        decode(argc, argv);
    }
	return 0;
}