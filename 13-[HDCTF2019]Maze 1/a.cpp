#include <iostream>

int main(){
    
    int asc_408078 = 7;
    int dword_40807C = 0;
    char Str[] = "123456";

    // 0 - 0
    // 1 - 3
    // 2 - 18
    // 3 - 22 * 不能到达
    char byte_401112[] = {0,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,2,4,4,4,3}; // 23
    for(int i = 0 ; i <= 1;i++){
        int x = Str[i] - 'a';
        if(x > 22){
            continue;
        }

        switch(byte_401112[x]){
            case 0: //loc_401096
            asc_408078 -= 1;    // a 
            break;
            case 1: //loc_4010A5
            asc_408078 += 1;    // d
            break;
            case 2: // loc_401085
            dword_40807C -= 1; // s 
            break;
            case 3: // loc_401074 // w
            dword_40807C =+ 1;
            break;
        }
    }

    if(asc_408078 == 5 && dword_40807C == -4){
        // congruation
    }


}

// ssaaasaassdddw