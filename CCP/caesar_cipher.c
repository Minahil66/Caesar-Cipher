//complete code
#include<stdio.h>
#include<string.h>
#include<conio.h>
void encrypt(char message[], int key); //encryption function declaration
void bruteforce(char message[]);//bruteforce function declaration
void decrypt(char message[], int key); //decryption function declaration

int main() {
    char text[500]="";
    int s_key;
    int part; 
    printf("+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n\n");
    printf(" CAESAR CIPHER ENCRYPTION TOOL\n\n");
    printf("+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n\n");
    printf("1. Encryption\n2. Decryption\n3. Brute force\nEnter your choice: ");
    scanf("%d", &part);
    getchar();

    switch(part){
        case(1):{
    printf("\nEnter a message to encrypt:");
    fgets(text,500,stdin);
    text[strcspn(text, "\n")]=0;
    printf("\nEnter the secret key: ");
    scanf("%d", &s_key);
    encrypt(text, s_key);
    break;
    }
        case(2): {
 printf("\nEnter a message to decrypt:");
 fgets(text,500,stdin);
 text[strcspn(text, "\n")]=0;
 printf("\nEnter the secret key: ");
 scanf("%d", &s_key);
 decrypt(text, s_key);
 break; 
    
    }
        case(3):{
    printf("\nEnter a message to generate all possible decryptions for:");
    fgets(text,500,stdin);
    text[strcspn(text, "\n")]=0;
    bruteforce(text);
    break;
        }
         default: {
    printf("Invalid selection");
    }
    }
    }

    void decrypt(char message[], int key){
    int length=strlen(message);
    int status, new_status;
    int i;
    for(i=0;i<length;i++){
    char ch=message[i];
    if(ch>='A' && ch<='Z'){
     status=ch-'A';
     new_status=(status - key + 26) % 26;
    message[i]=new_status+'A';
    }
    else if(ch>='a' && ch<='z'){
    status=ch-'a';
    new_status=(status - key + 26) % 26;
    message[i]=new_status+'a';
    }
    }
    printf("The decrypted message is: %s", message);
    }
    void encrypt(char message[], int key){
    int length=strlen(message);
    int status, new_status;
    int i;
    for(i=0;i<length;i++){
    char ch=message[i];
    if(ch>='A' && ch<='Z'){
    status=ch-'A';
    new_status=(status+key)%26;
    message[i]=new_status+'A';
    }
    else if(ch>='a' && ch<='z'){
    status=ch-'a';
    new_status=(status+key)%26;
    message[i]=new_status+'a';
    }
    }
    printf("The encrypted message is: %s", message);
    }
    void bruteforce(char message[]){
    int length=strlen(message);
    int status, new_status;
    int i;
    char temp_copy[500]; 
    for(int j=1;j<=25;j++){ 
    strcpy(temp_copy, message); 
    for(i=0;i<length;i++){
    char ch=temp_copy[i];
    if(ch>='A' && ch<='Z'){
     status=ch-'A';
    new_status=(status-j+26)%26;
    temp_copy[i]=new_status+'A';
    }
    else if(ch>='a' && ch<='z'){
    status=ch-'a';
     new_status=(status-j+26)%26;
     temp_copy[i]=new_status+'a';
    }
    }
    printf("key: %d decrypted message: %s",j, temp_copy);
    printf("\n");
    }
    }


