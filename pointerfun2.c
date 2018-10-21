#include <stdio.h>
#include <string.h>
#include <float.h>

struct PlayStruct{
  int int_value;
  double double_value;
  char a_string[100];
};

void print_struct(struct PlayStruct ps, struct PlayStruct *pps)
{
  printf("Values of ps: %d %lf %s\n",ps.int_value, ps.double_value, ps.a_string );
  printf("Values of pps: %d %lf %s\n",pps->int_value, pps->double_value, pps->a_string );
}

void change_struct(struct PlayStruct ps, struct PlayStruct *pps)
{
  ps.int_value = 10;
  ps.double_value = 5.5;
  strcpy (ps.a_string, "changed");
  //this will be only changed in th efunction change_struct.
  pps->int_value = 20;
  pps->double_value = 20.5;
  strcpy (pps -> a_string, "changed2");
  //his is the value of ps and pps after calling this function.
}

void print_string(char string[]) {

  printf("print string %s\n",string);
}

void change_string(char string[], char *stringPointer[])
{
  string[2] = 0;
  stringPointer[1] = 0;
}

int main(int argc, char const *argv[])
{
  struct PlayStruct play_struct = {5,3.5, "Simon Hellrigl"};
  struct PlayStruct *play_struct_pointer = &play_struct;
  char new_string[10] = "new";
  char *new_string_p = new_string;

  print_struct(play_struct,play_struct_pointer);
  change_struct(play_struct,play_struct_pointer);
  print_struct(play_struct,play_struct_pointer);

  print_string(play_struct.a_string);
  change_string(play_struct.a_string,&new_string_p);
  print_string(play_struct.a_string);
  print_string(new_string_p);

  return 0;
}
