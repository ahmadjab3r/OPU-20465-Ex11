#include <stdio.h>
#include <stdbool.h>

#define ALPHA_START_CAPITAL 65 //the letter 'A' in ASCII
#define ALPHA_END_CAPITAL 90 //the letter 'Z' in ASCII
#define ALPHA_START_SMALL 97 //the letter 'a' in ASCII
#define ALPHA_END_SMALL 122 //the letter 'z' in ASCII
#define ALPHA_CONVERT 32 //Used to convert from small to capital and vice-versa
#define NUMBERS_START 48 //The number 0 in ASCII
#define NUMBERS_END 57 //THE NUMBER 9 in ASCII

#define QUOTATIONS '"'
#define DOT '.'
/**
 * Checks if a given character ascii number is in the ascii small letters range
 * @param current_char character ascii representing number
 * @return true if small, false otherwise
 */
bool is_small_letter (int current_char)
{
  return current_char >= ALPHA_START_SMALL && current_char <= ALPHA_END_SMALL;
}
/**
 * Checks if a given character ascii number is in the ascii capital letters
 * range
 * @param current_char character ascii representing number
 * @return true if capital, false otherwise
 */
bool is_capital_letter (int current_char)
{
  return current_char >= ALPHA_START_CAPITAL
         && current_char <= ALPHA_END_CAPITAL;
}

/**
 * Checks if a given character ascii number is in the ascii numbers range
 * @param current_char character ascii representing number
 * @return true if a number, false otherwise
 */
bool is_number (int current_char)
{
  return current_char >= NUMBERS_START && current_char <= NUMBERS_END;
}
/**
 *
 * @param line
 * @param i
 * @return
 */
int quotations_case ()
{
  int current;
  while ((current = getchar ()) != QUOTATIONS)
    {
      if (current == EOF)
        {
          return false;
        }
      if (is_small_letter (current))
        {
          current -= ALPHA_CONVERT;
        }
      if (!is_number (current))
        {
          printf ("%c", current);
        }
    }
  //QUOTATIONS ARENT ADDED HERE!
  putchar (QUOTATIONS);
  return true;

}
int main ()
{
  bool is_start = true;
  int current;
  while ((current = getchar ()) != EOF)
    {
      //CASE 1: IS NUMBER, SKIP OVER IT
      if (is_number (current))
        {
          continue;
        }

      //CASE 2: IS LETTER
      if (is_capital_letter (current) ||
          is_small_letter (current))
        {
          //CASE 1.1 is START of Line
          if (is_start)
            {
              if (is_small_letter (current))
                {
                  current -= ALPHA_CONVERT;
                }
              is_start = false;
              //CASE 1.2 is NOT START OF LINE
            }
          else
            {
              //CASE 1.2.1 IS NOT START AND IS CAPITAL
              if (is_capital_letter (current))
                {
                  current += ALPHA_CONVERT;
                }
            }
        }
      putchar (current);
      //AM I END OF SENTENCE '.'?
      if (current == DOT)
        {
          is_start = true;
        }
      //CASE 3 IS '"'
      if (current == QUOTATIONS)
        {
          is_start = false;
          //WE REACHED END OF FILE BEFORE REACHING '"'
          //TODO!
          if (quotations_case () == false)break;

        }

    }
}

