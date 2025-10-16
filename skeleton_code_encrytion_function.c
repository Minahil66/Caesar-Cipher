//skeleton code aka foundation
#include<stdio.h>
#include<string.h>
void encrypt(char message[], int key); //encryption function declaration
void bruteforce(char message[]);//bruteforce function is here;
//decrypt function will be declared here;

int main() {
    char text[500]="";
    int s_key;
    int part; //switch variable
    printf("+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n\n");
    printf(" CAESAR CIPHER ENCRYPTION TOOL\n\n");
    printf("+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n\n");
    printf("1. Encryption\n2. Decryption\n3. Brute force\nEnter your choice: ");
    scanf("%d", &part);
    //put switch here
    switch(part){
        case(1):{
    //encrytion function calling
    printf("\nxxx NOTE: TYPE IN A MESSAGE WITHOUT ANY SPACES xxx");
    printf("\nEnter the message that you want to encrypt:");
    scanf("%s", text);
    printf("\nEnter the secret key: ");
    scanf("%d", &s_key);
    encrypt(text, s_key);
    return 0;
    }
        case(2): {
            //decrytion function calling
    
    }
        case(3):{
            //bruteforce fucntion calling
    printf("\nxxx NOTE: TYPE IN A MESSAGE WITHOUT ANY SPACES xxx");
    printf("\nEnter the message that you want all possible 26 encryptions for:");
    scanf("%s", text);
    bruteforce(text);
    return 0;
        }
    default: {
        printf("Invalid selection");
    }

    }
    }
//decrypt function definition starts here;
//{
//}

//encrytion function definition is here:
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
        printf("%s", message);
        }
    //bruteforce function definition is here:
    void bruteforce(char message[]){
         int length=strlen(message);
         int status, new_status;
         int i;
         char temp_copy[500]; //make a copy so the original one is unchanged
        for(int j=1;j<=25;j++){ //for all possible 25 combinations
             strcpy(temp_copy, message); //so the program doesnt keep encrypting the encrypted message
            for(i=0;i<length;i++){
            char ch=temp_copy[i];
        if(ch>='A' && ch<='Z'){
            status=ch-'A';
            new_status=(status+j)%26;
            temp_copy[i]=new_status+'A';
        }
        else if(ch>='a' && ch<='z'){
            status=ch-'a';
            new_status=(status+j)%26;
            temp_copy[i]=new_status+'a';
        }
        }
        printf("%s", temp_copy);
        printf("\n");
        }
        }
