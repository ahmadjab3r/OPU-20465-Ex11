#include <stdio.h>

#define ALPHA_START_CAPITAL 65 /*the letter 'A' in ASCII*/
#define ALPHA_END_CAPITAL 90 /*the letter 'Z' in ASCII*/
#define ALPHA_START_SMALL 97 /*the letter 'a' in ASCII*/
#define ALPHA_END_SMALL 122 /*the letter 'z' in ASCII*/
#define ALPHA_CONVERT 32 /*Used to convert from small to capital and vice-versa*/
#define NUMBERS_START 48 /*The number 0 in ASCII*/
#define NUMBERS_END 57 /*THE NUMBER 9 in ASCII*/

#define QUOTATIONS '"'
#define DOT '.'
#define TRUE 1
#define FALSE 0
/**
 * Checks if a given character ascii number is in the ascii small letters range
 * @param current_char character ascii representing number
 * @return true if small, false otherwise
 */
int is_small_letter (int current_char)
{
  return current_char >= ALPHA_START_SMALL && current_char <= ALPHA_END_SMALL;
}
/**
 * Checks if a given character ascii number is in the ascii capital letters
 * range
 * @param current_char character ascii representing number
 * @return true if capital, false otherwise
 */
int is_capital_letter (int current_char)
{
  return current_char >= ALPHA_START_CAPITAL
         && current_char <= ALPHA_END_CAPITAL;
}

/**
 * Checks if a given character ascii number is in the ascii numbers range
 * @param current_char character ascii representing number
 * @return true if a number, false otherwise
 */
int is_number (int current_char)
{
  return current_char >= NUMBERS_START && current_char <= NUMBERS_END;
}
/**
 * In case of quotations, starts with the first quote, and keeps running
 * until it reaches the last quote.
 * returns: true if success, false otherwise
 */
int quotations_case (void)
{
  int current;
  while ((current = getchar ()) != QUOTATIONS)
    {
      /*Case 1 Is EOF, stop reading. and completely stop*/
      if (current == EOF)
        {
          return FALSE;
        }
        /*Case 2 is small letter? change it to Capital*/
      if (is_small_letter (current))
        {
          current -= ALPHA_CONVERT;
        }
        /*Case 3 if it's not a number, write it*/
      if (!is_number (current))
        {
          printf ("%c", current);
        }
    }
  /*QUOTATIONS AREN'T WITHOUT THIS! AS IT STOPS THE WHILE*/
  putchar (QUOTATIONS);
  return TRUE;

}
int main (void)
{
  int is_start = TRUE;
  int current;
  while ((current = getchar ()) != EOF)
    {
      /*CASE 1: IS NUMBER, SKIP OVER IT*/
      if (is_number (current)) continue;
      /*CASE 2: IS LETTER*/
      if (is_capital_letter (current) ||
          is_small_letter (current))
        {
          /*CASE 2.1 is START of Line and maybe not capital*/
          if (is_start)
            current =
                is_small_letter (current) ? current - ALPHA_CONVERT :
                current;
          else
            /*CASE 2.2 IS NOT START AND IS CAPITAL*/
            current =
                is_capital_letter (current) ? current + ALPHA_CONVERT :
                current;

        }
      is_start = FALSE;
      putchar (current);
      /*AM I END OF SENTENCE '.'?*/
      if (current == DOT) is_start = TRUE;
      /*CASE 3 IS '"'*/
      if (current == QUOTATIONS)
        {
          is_start = FALSE;
          /*WE REACHED END OF FILE BEFORE REACHING '"'*/
          if (quotations_case () == FALSE)break;
        }

    }
    return TRUE;
}

