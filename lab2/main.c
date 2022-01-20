#include <stdio.h>
#include <math.h>

#define TARGET_NUMBER 10
#define HALF 2
#define ALIGN -3
#define HALFWAY_BACKWARDS 2
#define EVEN 2
#define NO_REMAINDER 0

/**
 * Lab 2
 *
 * @name: Bradley Masciotra A01247718git sta
 * @date: January 20th 2022
 * @version: 1.0
 */

//---------------------------------------Part-A:-Multiplication---------------------------------------------------------

/**
 * Prints the multiplication table for Zero up to TARGET_NUMBER
 */
void printMultiplicationTable(){

    int i,j,first_line,product;

    first_line = 1; // flag for the first line
    printf("Multiplication Table For The Integer %d\n\n", TARGET_NUMBER);

    for(i = 0; i < TARGET_NUMBER + 1; i++){

        printf("%*d\t",ALIGN,i); // print the initial line

        for(j = 1; j < TARGET_NUMBER + 1; j++)
        {
            product = j;
            switch(first_line){
                case 0:
                    product = j * i;
                    printf("%*d\t",ALIGN,product);
                    break;
                case 1:
                    printf("%*d\t",ALIGN,product);
                    break;
                default:
                    printf("Error\n");
                    break;
            }
        }
        first_line = 0;
        printf("\n");
    }
}

//---------------------------------------Part-B:-Palindromes------------------------------------------------------------

/**
 * Prints an array from the given array passed.
 *
 * @param elements the array we would like to print.
 * @param size the size of the array.
 */
void printArray(int elements[],int size)
{
    int i;
    printf("The Integer Array: \"");
    for(i = 0; i < size;i++ )
    {
        printf("%d,",elements[i]);
    }
    printf("\"");
}

/**
 * Checks conditionals to see if the array is a palindrome.
 */
void displayAnswer(int sameInteger, int elements[], int size){
    printArray(elements,size);
    switch(sameInteger){
        case 0:
            printf(" is not a palindrome\n");
            break;
        case 1:
            printf(" is a palindrome\n");
            break;
        default:
            printf("Error: %d is an incorrect boolean value for this function.\n",sameInteger);
    }
}

/**
 * Compares the two arrays to see if its the same characters forward as it is backwards.
 *
 * @param firstHalf the first half of the array we are checking
 * @param secondHalf the second half of the array we are checking
 * @param halfwayIndex the halfway point of the original array.
 * @return boolean value representing if the array is a palindrome.
 */
int compareArray(int const firstHalf[], int const secondHalf[], int halfwayIndex){
    int k,palindromeBoolean;
    for(k = 0; k < halfwayIndex; k++)
    {
        if(firstHalf[k] == secondHalf[k])
        {
            palindromeBoolean = 1;
        }
        else
        {
            palindromeBoolean = 0;
            break; // if one integer is incorrect, break the loop and confirm not a palindrome.
        }
    }
    return palindromeBoolean;
}

/**
 * Checks the size of the array to see if it is even or not.
 *
 * @param size the size of the array.
 * @return boolean representing if the array is even.
 */
int iseven(int size)
{
    int even = 0; // false.

    if(size % EVEN == NO_REMAINDER)
    {
        even = 1; // set to true.
    }
    return even;
}

/**
 * Calculates the halfway point of the array.
 *
 * @return the halfway index as an integer of the array.
 */
int findHalfwayIndex(int size){
    int halfwayIndex;

    if(iseven(size))
    {
        halfwayIndex = round(size / HALF); // gets the halfwayIndex point of the array to compare first half and second half
    }
    else
    {
        halfwayIndex = round(size / HALF) + 1; // adds one more index to incorporate the odd number array element.
    }
    return halfwayIndex;
}

/**
 * Validates whether the array passed is a palindrome.
 *
 * @param elements the array of integers being passed.
 * @param size the size of the array.
 * @return boolean value representing if the array is a palindrome.
 */
int isPalindrome(int elements[], int size){
    int i,j,count,palindromeBoolean,halfwayIndex;

    halfwayIndex = findHalfwayIndex(size);

    int firstHalf[halfwayIndex + 1],secondHalf[halfwayIndex + 1]; // declaring arrays

    // loop through the first half of the array to set the first half of the palindrome
    for(i = 0; i < halfwayIndex; i ++){
        firstHalf[i] = elements[i];
    }

    count = 0; // sets the array elements to the start of the array.

    for(j = size - 1; j > halfwayIndex - HALFWAY_BACKWARDS; j--) // loop through the array backwards.
    {
        secondHalf[count] = elements[j];
        count += 1;
    }

    palindromeBoolean = compareArray(firstHalf, secondHalf, halfwayIndex); // calling the comparison function.

    displayAnswer(palindromeBoolean, elements, size); // comment this line out if you would like no print statements.

    return palindromeBoolean;
}

/**
 * Drives the program.
 *
 * @return 0.
 */
int main() {
    int test_case_1[]    = {1,1,2,3,4,3,2,1,1}; // testing array with odd numbers of elements.
    int size_test_one    = sizeof(test_case_1)/ sizeof(int);
    int test_case_2[]    = {1,2,2,4,4,1,3,1,4,4,2,3,1};
    int size_test_two    = sizeof(test_case_2)/ sizeof(int);
    int test_case_3[]    = {1}; // testing single number.
    int size_three       = sizeof(test_case_3)/ sizeof(int);
    int test_case_4[]    = {1,2,3,4,4,3,2,1}; // testing even amount of elements.
    int size_four        = sizeof(test_case_4) / sizeof (int);
    int test_case_5[]    = {1,2,3,4,5,6,4,3,2,1};
    int size_five        = sizeof(test_case_5) / sizeof(int);
    int test_case_6[]    = {-1,2,-3,4,5,5,4,-3,2,-1};
    int size_six        = sizeof(test_case_6) / sizeof(int);
    int test_case_7[]    = {-1,2,-3,4,5,4,-3,2,-1};
    int size_seven        = sizeof(test_case_7) / sizeof(int);

    printf("\n------------------Print-Multiplication-Table------------------\n\n");

    printMultiplicationTable();

    printf("\n------------------------Is-Palindrome--------------------------\n\n");

    isPalindrome(test_case_1,size_test_one);
    isPalindrome(test_case_2,size_test_two);
    isPalindrome(test_case_3,size_three);
    isPalindrome(test_case_4,size_four);
    isPalindrome(test_case_5,size_five);
    isPalindrome(test_case_6,size_six);
    isPalindrome(test_case_7,size_seven);

    return 0;
}
