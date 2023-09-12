#include "cipher.h"
#include "tests.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define MAX_LINE 1026
#define COMMAND 1
#define TEST 1
#define K_VALUE 2
#define SOURCE 3
#define PATH 4
#define TEST_COMMAND 2
#define CODING_COMMAND 5
#define  SWITCH_TO_NUM  10
#define  ASCII_0  48
#define  ASCII_9  57
#define  SUCCESS 1
#define  FAIL 0
#define  NEGATIVE "-"
#define  NEGATIVE_CHAR '-'


int checkk(char str[]);
void command(char str[],char text[],int k);
int checkcomand(char str[]);
int checkfiles(FILE *f,FILE *result);



int main(int argc, char *argv[]){
  if ((argc!=TEST_COMMAND) && (argc!=CODING_COMMAND)){
    fprintf(stderr,"The program receives 1 or 4 arguments only.\n");
    return EXIT_FAILURE;}
  if (argc==TEST_COMMAND){
    int is_test=strcmp(argv[TEST],"test");
    if (is_test==0){
  int output=test_decode_cyclic_lower_case_negative_k()
      &&test_decode_cyclic_lower_case_special_char_positive_k()&&
      test_decode_cyclic_upper_case_positive_k()&&
      test_decode_non_cyclic_lower_case_positive_k()&&
      test_decode_non_cyclic_lower_case_special_char_negative_k()&&
      test_encode_cyclic_lower_case_negative_k()&&
      test_encode_non_cyclic_lower_case_special_char_negative_k()&&
      test_encode_non_cyclic_lower_case_positive_k()&&
      test_encode_cyclic_lower_case_special_char_positive_k()
      &&test_encode_cyclic_upper_case_positive_k ();
      if (output)
      return EXIT_FAILURE;
    return EXIT_SUCCESS;}
    fprintf(stderr,"Usage: cipher test\n");
    return EXIT_FAILURE;}
  if (argc==CODING_COMMAND){
    if (checkcomand(argv[COMMAND])==0){
      fprintf(stderr,"The given command is invalid.\n");
      return EXIT_FAILURE;}
    if (checkk(argv[K_VALUE])==0){
      fprintf(stderr,"The given shift value is invalid.\n");
      return EXIT_FAILURE;}
    int k = strtol(argv[K_VALUE], NULL, SWITCH_TO_NUM);
    FILE *f=fopen(argv[SOURCE],"r");
    FILE *result=fopen(argv[PATH],"w");
    if (checkfiles(f,result)==0){
      fprintf(stderr,"The given file is invalid.\n");
    return EXIT_FAILURE;}
    char line[MAX_LINE]={0};
    while(fgets(line,MAX_LINE,f)){
      command(argv[COMMAND],line,k);
      fprintf(result,line);}
      fclose (f);
      fclose(result);
      return EXIT_SUCCESS;
    }}


void command(char str[],char text[],int k){
  if (strcmp(str,"decode")==0){
    decode(text,k);}
  else{
    if ((strcmp(str,"encode"))==0){
    encode(text,k);}
  }
}
int checkk(char str[]){
  int i=0;
  if (!strcmp(str,NEGATIVE)){
    return FAIL;}

  while(str[i]){
    if (i==0&&str[i]==NEGATIVE_CHAR){
      i++;
      continue;}
    if (str[i]>ASCII_9||str[i]<ASCII_0){
      return FAIL;}
    i++;
  }
  return SUCCESS;
}

int checkcomand(char str[]){
  if ((strcmp(str,"decode"))==0){
    return SUCCESS;}
  if ((strcmp(str,"encode"))==0){
      return SUCCESS;}
  return FAIL;
}
int checkfiles(FILE *f,FILE *result){
  if (f!=NULL){
  if (result!=NULL)
    return SUCCESS;
  }
  return FAIL;
}
