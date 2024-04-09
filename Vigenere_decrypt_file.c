#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXN 1024

char* vigenere_decrypt(char* cipher, char* key){
    
    int length = strlen(cipher);
    int key_length = strlen(key);
    char* plaintext = (char*) malloc(sizeof(char) * (length + 1));
    int index = 0;
    while(cipher[index] != '\0'){
        
        int shift = tolower(key[index % key_length]) - 'a';
        
        if(islower(cipher[index])){
            
            plaintext[index] = 'a' + (cipher[index] - 'a' - shift + 26) % 26;
        }
        else if(isupper(cipher[index])){
            
            plaintext[index] = 'A' + (cipher[index] - 'A' - shift + 26) % 26;
        }
        else{
            
            plaintext[index] = cipher[index];    
        }
        index++;
    }
    plaintext[index] = '\0';
    return plaintext;
}

char* read_cypher(char* filename){
    
    FILE* file;
    file = fopen(filename, "r");
    
    if(file == NULL){
        
        printf("Error reading from file.");
        return NULL;
    }
    
    char* cypher = (char*) malloc(MAXN * sizeof(char));
    if(fgets(cypher, MAXN, file) == NULL){
        
        printf("Error reading from file.");
        
        return NULL;
    }
    
    fclose(file);
    return cypher;
}

int main(){
    printf("Enter filename: ");
    char filename[MAXN];
    scanf("%s", filename);
    
    char* cipher = read_cypher(filename);
    if(cipher == NULL){
        return EXIT_FAILURE;
    }
    
    char key[MAXN];
    scanf("%s", key);
    
    char* plaintext = vigenere_decrypt(cipher, key);

    printf("Plaintext: %s", plaintext);
    return EXIT_SUCCESS;
}
