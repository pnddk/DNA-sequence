/*Name of file: dnaSequence.c
Purpose: Reads a DNA sequence from a text file and organizes 
into a three codon base and compared to a series of switch statements,
returning a one letter amino acid equivalent.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BASE_CODON 4
#define LEN_CODON 3

//Function that converts a three based codon into a one acronym amino acid and returns said letter to main.
char find_amino_acid (char codonOne, char codonTwo, char codonThree)
{
    char one_letter_aa;
    one_letter_aa = '?';

/*Succeeding if else statements (could also do with switch-case statements) that look for the first codon
(by these letters A,C,G,T),second codon (A,C,G,T) and third codon (A,C,G,T) of the three base Nucleobase
and print out its one letter amino acid representation and return that letter to the main function.*/

 if (codonOne == 'A' || codonOne == 'a')
   {
      if (codonTwo == 'T' || codonTwo == 't')
      {
         one_letter_aa = 'I';
            if (codonThree == 'G' || codonThree == 'g')
               one_letter_aa = 'M';
      }
      else if (codonTwo == 'C' || codonTwo == 'c')
      {
         one_letter_aa = 'T';
      }
      else if (codonTwo == 'A' || codonTwo == 'a')
      {
         one_letter_aa = 'K';
            if (codonThree == 'T' || codonThree == 't' || codonThree == 'C' || codonThree == 'c')
               one_letter_aa = 'N';
      }
      else if (codonTwo == 'G' || codonTwo == 'g')
      {
         one_letter_aa = 'R';
            if (codonThree == 'T' || codonThree == 't' || codonThree == 'C' || codonThree == 'c')
               one_letter_aa = 'S';
      }
   }

   else if (codonOne == 'C' || codonOne == 'c')
   {
      if (codonTwo == 'T' || codonTwo == 't')
      {
         one_letter_aa = 'L';
      }
      else if (codonTwo == 'C' || codonTwo == 'c')
      {
         one_letter_aa = 'P';
      }
      else if (codonTwo == 'A' || codonTwo == 'a')
      {
         one_letter_aa = 'Q';
            if (codonThree == 'T' || codonThree == 't' || codonThree == 'C' || codonThree == 'c')
               one_letter_aa = 'H';
      }
      else if (codonTwo == 'G' || codonTwo == 'g')
      {
         one_letter_aa = 'R';
      }
   }

   else if (codonOne == 'G' || codonOne == 'g')
   {
      if (codonTwo == 'T' || codonTwo == 't')
      {
         one_letter_aa = 'V';
      }
      else if (codonTwo == 'C' || codonTwo == 'c')
      {
         one_letter_aa = 'A';
      }
      else if (codonTwo == 'A' || codonTwo == 'a')
      {
         one_letter_aa = 'E';
            if (codonThree == 'T' || codonThree == 't' || codonThree == 'C' || codonThree == 'c')
               one_letter_aa = 'D';
      }
      else if (codonTwo == 'G' || codonTwo == 'g')
      {
         one_letter_aa = 'G';
      }
   }

   else if (codonOne == 'T' || codonOne == 't')
   {
      if (codonTwo == 'T' || codonTwo == 't')
      {
         one_letter_aa = 'L';
            if (codonThree == 'T' || codonThree == 't' || codonThree == 'C' || codonThree == 'c')
               one_letter_aa = 'F';
      }
      else if (codonTwo == 'C' || codonTwo == 'c')
      {
         one_letter_aa = 'S';
      }
      else if (codonTwo == 'A' || codonTwo == 'a')
      {
         one_letter_aa = '*';
            if (codonThree == 'T' || codonThree == 't' || codonThree == 'C' || codonThree == 'c')
               one_letter_aa = 'Y';
      }
      else if (codonTwo == 'G' || codonTwo == 'g')
      {
         one_letter_aa = 'W';
            if (codonThree == 'T' || codonThree == 't' || codonThree == 'C' || codonThree == 'c')
               one_letter_aa = 'C';
            else if (codonThree == 'A' || codonThree == 'a')
               one_letter_aa = '*';
      }
   }
return one_letter_aa;
}

//Main function
int main (int argc, char **argv)
{

//Variable declarations and initializations
int i, codon_bases = 0, aa_count = 0, base_count = 0;
char amino_acid, data_file_letter;
char sample_string [BASE_CODON];
sample_string[0] = '?';
sample_string[1] = '?';
sample_string[2] = '?';
FILE *given_file = fopen (argv[1], "r");

//while loop done to count bases that are of valid characters (A,C,G,T) and keeps track if the codon base is 3 or not
while ((data_file_letter = fgetc(given_file))!= EOF)
{
    if (data_file_letter == 'A' || data_file_letter == 'a' || data_file_letter == 'T' || data_file_letter == 't'||
        data_file_letter == 'G' || data_file_letter == 'g' || data_file_letter == 'C' || data_file_letter == 'c')
    {
        sample_string[codon_bases] = data_file_letter;
        base_count++;
        codon_bases++;

/*Checking to see if there are three codons that make up a nucleobase and execute the find_amino_acid function
as well as incrementing the number of codon bases and amino acid count by 1.*/

        if (codon_bases == LEN_CODON)
        {
            amino_acid = find_amino_acid(sample_string[0], sample_string[1], sample_string[2]);
            printf("%c", amino_acid);
            codon_bases = 0;
            aa_count++;
        }
    }
}
fclose (given_file);

//print the total number of bases and amino acids
   printf ("\nTotal number of bases processed: %d\n", base_count);      
   printf ("Total number of amino acids decoded: %d\n", aa_count);

   return(0);
}
