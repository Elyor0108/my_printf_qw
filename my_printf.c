#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

void putch(char str){
    write(1 , &str, 1);
}

// длинные строки
int putsizeall(char * str2){ 
        int i = 0;
    while(i < strlen(str2)){
        putch(str2[i]);
        i++;
    }
    return i;
}
char * int_to_char(int b1,int b2){
        int arr[10000];
        int arr_i = 0;
        int nigga = 0;
    if(b1 < 0){
        b1 = b1*(-1);
        nigga++;
    }
    while(b1 > 0){
        arr[arr_i] = b1 % 10;
        b1 = b1 / 10;
        arr_i++;
    }


        char *res;
        res = malloc(arr_i);
        char *nigres;
        nigres = malloc(arr_i+1);
        int res_int = 0;


    for(int i = arr_i -1;i >= 0;i--){
        res[res_int] = arr[i] + '0';
        res_int++;
    }
    if(nigga > 0){
        if(b2 == 0){
            nigres[0] = '-';
            for(int i = 0; i < strlen(res);i++){
                nigres[i + 1] = res[i];
            }
            return nigres;
        }
        else{
            return res;
        }
    }
    return res;
}
// int p_fun(int i){
//     printf("%d\n",i);
//     int *pointer = &i;
//     printf("%p\n",i);
//     printf("%p",pointer);
char* INNadres(int base, unsigned long number)
{
    char* output;
    int last_index = 0;
    if (number == 0)
    {
        return "0";
    }

    char ch;
    unsigned long digit, num_copy = number;
    int size_of_output = 0;
    while (number != 0)
    {
        number = number / base;
        size_of_output++;
    }

    output = (char*)malloc(sizeof(output) * size_of_output);
    last_index = --size_of_output;

    while (num_copy != 0)
    {
        digit = num_copy % base;
        if (digit > 9 && digit < 16 && base == 16)
        {
            ch = digit + '0' + 7;
        }
        else
        {
            ch = digit + '0';
        }
        output[last_index] = ch;
        last_index--;
        num_copy = num_copy / base;
    }

    return output;
    free(output);
}
// }
int my_printf(char * p1, ...){
    int hel = 0;
    char b;
    char * s;
    int d;
    unsigned long inAdress;
    va_list lst;
    va_start(lst, p1);

    for (int i= 0 ;i < strlen(p1);i++ ){
        if(p1[i] == '%'){
            i++;
            switch (p1[i]){
                case 'c':
                    b = (char)va_arg(lst, int);
                    hel++; 
                    putch(b);
                break;

                case 's':
                    s = va_arg(lst, char*);
                    if(s == (char *)NULL){
                        s = "(null)";
                    }
                    hel += putsizeall(s);
                break;

                case 'd':
                    d = va_arg(lst,int);
                    if(d == 0){
                        char revstr = d + '0';
                        putch(revstr);
                        hel++;
                    }
                    else{
                        putsizeall(int_to_char(d,0));
                        hel += strlen(int_to_char(d,0));
                    }
                break;

                case 'o':
                    d = va_arg(lst, int);
                    char num[10000], i = 0;
                    while(d != 0){
                        num[i++] = d % 8 + '0';
                        d = d / 8;
                        hel++;
                    }
                    for(int i = strlen(num)-1;i >= 0; i--){
                        putch(num[i]);
                    }
                break;

                case 'u':
                    d = va_arg(lst,int);
                    if(d == 0){
                        char revint = d + '0';
                        putch(revint);
                        hel++;
                    }
                    else{
                        putsizeall(int_to_char(d,0));
                        hel += strlen(int_to_char(d,0));
                    }
                break;

                case 'x':
                    d = va_arg(lst, int);
                    int in;
                    int t = 0;
                    char numb[100];
                    while(d != 0){
                        hel++;
                        in = d % 16;
                        if(in < 10)
                            numb[t++] = 48 + in;
                        else
                            numb[t++] = 55 + in;
                            d = d / 16;
                    }
                    putsizeall(numb);
                break;
                case 'p':
                    inAdress = (unsigned long)va_arg(lst, void*);
                    putch('0');
                    putch('x');
                    hel += 2;
                    putsizeall(INNadres(16, inAdress));
                    s=INNadres(16, inAdress);
                while(*s != '\0'){
                    hel++;
                    s++;  
                    break;         
                }
            }
        }
        else{
            hel++;
            putch(p1[i]);
        }
    }
    return hel;
    
}

// int main(){
//     // int v = my_printf("%c!\n",'H');
//     // int v = my_printf("%c%c%c%c%c!\n", 'H', 'e', 'l', 'l', 'o');
//     // int v =  my_printf("Hello %s!\n","QWASAR.IO");
//     // int v = my_printf("Hello %s %s!\n", "Mr", "Gaetan");
//     // int v = my_printf("NULL STRING %s!\n", (char*)NULL);
//     // int v = my_printf("%d!\n", 1337);
//     // int v = my_printf("%d - %d - %d!\n", 2048, 0, -1337);
//     // int v = my_printf("%o!\n",100);
//     // int v = my_printf("%d!\n", -1337);
//     // int v =  my_printf("%x!\n", 14);
//     // int v =  my_printf("%p!\n",);
// }
//int main()
//{
  //  if (13 == my_printf("Hello world!\n")) my_printf("OK 1!\n");
    //if (3 == my_printf("%c!\n", 'H')) my_printf("OK 2!\n");
   // if (7 == my_printf("%c%c%c%c%c!\n", 'H', 'e', 'l', 'l', 'o'))
     //   my_printf("OK! 3\n");
   // if (17 == my_printf("Hello %s!\n", "QWASAR.IO")) my_printf("OK 4!\n");
   // if (17 == my_printf("Hello %s %s!\n", "Mr", "Gaetan")) my_printf("OK 5!\n");
   // if (20 == my_printf("NULL STRING %s!\n", (char *)NULL))
     //   my_printf("NULL OK!\n");
   // if (6 == my_printf("%d!\n", 1337)) my_printf("NUM OK!\n");
   // if (18 == my_printf("%d-%d-%d!\n", 2048, 0, -1337))
     //   my_printf("NUMS OK!\n");  // q 16/23
   // if (5 == my_printf("%o!\n", 100)) my_printf("Octal ok!\n");  // q 17/23
    // if (6 == my_printf("%u\n!", -1337)) my_printf("UDEC ok!\n");  // q 19/23
   // if (3 == my_printf("%x!\n", 14)) my_printf("HEX ok!\n");  // 21/23
   // int var = 69;
   // my_printf("%p\n", &var);
   // if (16 == my_printf("%p!\n", &var)) my_printf("PTR OK!\n");
   // return 0;
// }
