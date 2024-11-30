#include <stdio.h>
#include <stdbool.h>
#define THIRTEEN 13
#define SEVEN 7

#define ONE 1 /*as in 0..01 in binary*/
#define ZERO 0 /*as in 0..00 in binary*/
#define TRUE 1
#define FALSE 0
#define MAX_WORD_SIZE 1024
/**
 * shifts 000000...1 by bit_to_turn_on-1 times
 * @param bit_to_turn_on
 * @return
 */
unsigned long move_bit (int bit_to_turn_on)
{
  return ONE<<(bit_to_turn_on-1);
}
/**
 * Creates the number 2^bit_to_turn_on, then turns it with OR in x
 * @param x the number to turn a specific bit on
 * @param bit_to_turn_on the bit to turn on
 * @return the number with the bit turned on
 */
unsigned long turn_specific_bit (unsigned long x, int bit_to_turn_on)
{
  unsigned long binary_rep = move_bit ( bit_to_turn_on);
  return x | binary_rep;
}
/**
 * Creates the number 2^bit_to_turn_on, then checks it with the original
 * number to see if it's turned on or not.
 * @param x the number to check if the specific bit is on
 * @param bit_to_turn_on the bit to check
 * @return true if it's on, false otherwise
 */
int check_specific_bit_on (unsigned long y, int bit_to_turn_on)
{
  unsigned long binary_rep = move_bit ( bit_to_turn_on);
  return (y & binary_rep) > 0 ? TRUE : FALSE;
}

/**
 * Prints a number in Binary format.
 * @param x the number to print in binary
 */
void print_value_in_binary (unsigned long x)
{
  /*in order to print in a correct manner and not reverse,
  will turn on the significant bit in UL, which will look like 1000000000...0*/
  unsigned long start = (unsigned long ) -1 - (unsigned long) -1 / 2;
  while (start > 0)
    {
      if (x & start) printf ("%lu", (unsigned long) ONE);
      else printf ("%lu", (unsigned long) ZERO);

      start = start >> 1;
    }
}

int main (void)
{
  unsigned long x,y,x_result;
  int result;
  char buff[MAX_WORD_SIZE];
  printf("Please enter the value of x and y using a comma: \nExample: 10,"
         "25: ");
  fgets(buff,MAX_WORD_SIZE,stdin);
  /*With the assumption that we are getting correct values (from the EX Notes)*/
  if (sscanf (buff, "%lu,%lu", &x,&y) !=2){
    printf("Didn't provide both x and y");
    return -1;
  }
  x_result = turn_specific_bit (x, THIRTEEN);
  /*3275277176*/
  result = check_specific_bit_on (y, SEVEN);
  printf ("\nx's 13th bit was turned on and it became: ");
  print_value_in_binary (x_result);
  printf ("\ny's 7th bit is ON? %s", result ? "Yes" : "NO\n");
  return 0;
}