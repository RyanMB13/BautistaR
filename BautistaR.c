#include <stdio.h>
#include <string.h>

typedef char String50 [51];

int 
validPassword(String50 Password){
    
    char userInput;
    if (strlen(Password) == strlen(userInput) && strcmp(Password, userInput) == 0){

        return 1;
    }
    else{
        return 0;
    }
} 




int main(){
    

    return 0;
}