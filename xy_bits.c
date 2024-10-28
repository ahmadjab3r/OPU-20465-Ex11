#include <stdio.h>
#include <stdbool.h>
#define THIRTEEN 13
#define SEVEN 7

#define ONE 1 // as in 0..01 in binary
#define ZERO 0 // as in 0..00 in binary
unsigned long move_bit (unsigned long binary_rep, int bit_to_turn_on)
{
  //It won't work with bit_to_turn_on 0, but it's not even needed
  while (bit_to_turn_on != 1)
    {
      binary_rep = binary_rep << 1;
      bit_to_turn_on -= 1;
    }
  return binary_rep;

}
unsigned long turn_specific_bit (unsigned long x, int bit_to_turn_on)
{
  unsigned long binary_rep = move_bit (ONE, bit_to_turn_on);
  return x | binary_rep;
}
unsigned long check_specific_bit_on (unsigned long y, int bit_to_turn_on)
{
  unsigned long binary_rep = move_bit (ONE, bit_to_turn_on);
  return (y & binary_rep) > 0 ? true : false;
}

void print_value_in_binary (unsigned long x)
{
  //in order to print in a correct manner and not reverse,
  //will turn on the significant bit in UL, which will look like 1000000000...0
  unsigned long start = (unsigned) -1 - (unsigned) -1 / 2; //TODO unsigned!!
  while (start > 0)
    {
      if (x & start)
        {
          printf ("%lu", (unsigned long) ONE);
        }
      else
        {
          printf ("%lu", (unsigned long) ZERO);
        }
      start = start >> 1;
    }
}

int main ()
{

  print_value_in_binary (687417593);
  unsigned long x_result = turn_specific_bit (687417593, THIRTEEN);
  bool result = check_specific_bit_on (3275277176, SEVEN);
  printf ("\nx's 13th bit was turned on and it became: ");
  print_value_in_binary (x_result);
  printf ("\ny's 6th bit is ON? %s", result ? "Yes" : "NO");

}

//100111110001110010011111000101
//00101000111110010011100011111001