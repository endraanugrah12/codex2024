#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int match = 1;

int main() {
  char flag[] = {0x00,0x20,0x20,0x20,0x20,0x00,0x7b,0x00,0x00,0x38,0x23,0x54,0x22,0x49,0x7c,0x6f,0x07,0x61,0x00,0x2c,0x57,0x50,0x3e,0x67,0x01,0x7e,0x6b,0x62,0x4e,0x45,0x44,0x05};
  char key[] = "Codex2024";
  int len = sizeof(flag);
  char input[len+1];
  char dec_flag[len+1];

  xor_func(flag,len,key,dec_flag);

  printf("\n===== WELCOME TO CODEX 2024 =====\n\n");
  printf("Enter the secret: ");
  fgets(input, sizeof(input), stdin);
  printf("%d", len);
  printf("%lu", strlen(input));
  compare_strings(dec_flag,input,len);
  if(match) {
    printf("Nice");
  } else {
    printf("Too Bad");
  }
  return 0;

}

int compare_strings(const unsigned char *decrypted_data, const char *input, int data_len) {
  printf("%s\n", input);
  printf("%s\n", decrypted_data);
  for(int i = 0; i < data_len; i++) {
    if(input[i] != decrypted_data[i]) {
      printf("Try Again");
      match = 0;
      exit(1337);
    }
  }
}

void xor_func(const unsigned char *encrypted_data, int data_len, const char *key, unsigned char *output) {
  int key_len = strlen(key);
  for (int i = 0; i < data_len; i++) {
    output[i] = encrypted_data[i] ^ key[i % key_len];
  }
  output[data_len] = '\0';
}
