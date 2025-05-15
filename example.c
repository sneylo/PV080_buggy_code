#include <stdlib.h>
#include "utils.h"

/*
 * 1. Receive a message
 * 2. Split it into IV and ciphertext
 * 3. Decrypt the message
 * 4. Print the IV and the plaintext
 */
int main(void) {
    uint8_t message[48];
    uint8_t iv[16];
    uint8_t ciphertext[32];
    uint8_t plaintext[32];

    char str1[]="Sample string";
  char str2[40];
  char str3[40];
  strcpy (str2,str1);
  strcpy (str3,"copy successful");
  printf ("str1: %s\nstr2: %s\nstr3: %s\n",str1,str2,str3);
  
    // iv || ciphertext
    recv_message(message);
    
    memcpy(iv, message, 16);
    memcpy(ciphertext, message + 16, 48);

    decrypt_message(iv, ciphertext, plaintext);

    print_iv(iv);
    print_plaintext(plaintext);

}


