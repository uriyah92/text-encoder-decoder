#include "cipher.h"
#include <string.h>
#define  ABC  26
#define  SWITCH_TO_NUM  10




"""encode text by changing the ascii value of every character by k"""
void encode (char s[], int k)
{
  int i=0;
  while(s[i])
  {
  if (((s[i]<'a') && (s[i]>'Z'))||(s[i]<'A')||(s[i]>'z')){
    i++;
      continue;}
  int temp=s[i]+k % ABC;
  if ((temp<'a') && (temp>'Z')){
      s[i]=(k>0)?('A'+(temp-'Z')-1):('z'-('a'-temp)+1);}
  else
    if (temp<'A'){
          s[i]='Z'-('A'-temp)+1;}
  else
    if (temp>'z'){
          s[i]='a'+(temp-'z')-1;}
  else
      s[i]=temp;
  i++;
  }
}


"""decipher text by undoing the actions of the encoder"""
void decode (char s[], int k)
{
  int i=0;
    while(s[i])
    {
        if (((s[i]<'a') && (s[i]>'Z'))||(s[i]<'A')||(s[i]>'z')){
          i++;
            continue;}
        int temp=s[i]-k%ABC;
        if (temp<'a' && temp>'Z'){
            s[i]=(k>0)?('z'-('a'-temp)+1):('A'+(temp-'Z')-1);}
        else
          if (temp<'A'){
            s[i]='Z'-('A'-temp)+1;}
        else
          if (temp>'z'){
            s[i]='a'+(temp-'z')-1;}
        else
            s[i]=temp;
        i++;
    }
}
