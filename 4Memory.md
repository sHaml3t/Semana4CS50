**ampersand *&* is used when we call an address *from* a variable**


# Valgrind
* Using *malloc* we get memory for 3 times the size of an *int*, which we can find out with *sizeof*.

* Deliberately wrote 2 mistakes, with arrays 0-indexed, starting at *x[1]* and don´t freed the memory allocated

* **Valgrind** is a command-line tool used to run our programs and see if it has any memory-related issues.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *x = malloc(3 * sizeof(int));
    x[1]= 72;
    x[2]= 73;
    x[3]= 33;
}
```

```terminal
$ valgrind ./memory

==5902== Invalid write of size 4
==5902==    at 0x401162: main (memory.c:9)
==5902==  Address 0x4bd604c is 0 bytes after a block of size 12 alloc'd
==5902== LEAK SUMMARY:
==5902==    definitely lost: 12 bytes in 1 blocks
```
* once you start by *x[0]* and *free(x);* the code will be fixed.


# Garbage Values
* Declared an array but dont initialize it with any values, and print it out, we'll see some random numbers called **garbage values**, from others programs running before maybe.
* We need to be careful with how our programs access memory
*if we try to go to an address that´s a garbage value, our program is likely to **crash** from a **segmentation fault*.

# Pointer Binky video
* Initially pointers dont point to anything, to allocate uses *x = malloc(sizeof(int));*

* With **x =42;* we dereference x follows the arrow to acces its pointee, which in this case stores 42 in there 
    
* We need to set up the pointee before dereferencing it, you cant just express **y = 13* without allocate y using *y = malloc(sizeof(int));*

* When using the assignment operator  *y = x* and both point the same address of 13


# Swap
* implementing a function like 
```c
#include <stdio.h>
#include <stdlib.h>

int swap(int a, int b){
    int tmp = a;
    a = b;
    b = tmp;
}
```
* uses tmp as temporary space for store the value of *a* and then set *a* to the value of *b* and finally *b* can be changed to the original vlue of *a* stored in *temp*

* Afunction like this gets passed in copies of variables, *a* and *b* which are **local variables** that only the surrounding functtion can access. Changing those values won´t change *x* and *y* in *main* function

* if we print directly from the function, as we´re working with its new copy functions it will swap the values.

# Memory layout

* Inside of our memory the types of data are stored in an organized sections:<br>
| machine code | <br>
| ------------ | <br>
|    globals   |<br>
|    heap      | <br>
| ! | <br>
<br>
| ¡ |<br>
|stack|

 * **machine code** section is our compiled program´s binary code. When we run our program, that code is loaded into memory

 * Just below, or in the next part are **global variables** we declared in our program.

 * The **heap** section is an empty area where *malloc* can get free memory for our program to use. As we call malloc, we start allocating memory from the top to down.

 * **stack** section is used by functions and local variables in our program, as they are called, and grows upwards.

 * if we call *malloc* for tooo much memory, we will have a **heap overflow**, since we end up going past our heap. Or, if we call too many functions, wshitout returning from them, we will have a **stack overflow**, where our stack has too much memory allocated as well.

 ```c
#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(&x, &y);
    printf("x is %i, y is %i\n", x, y);
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
}
```

* By passing in the address of *x* and *y*, our *swap* function will be able to change the original values, since they are passed in from *main* to *swap* with *&x* and *&y*, and we use the *int *a* syntax to declare that  our *swap* function takes in pointers.

* Saving the first value to *tmp* by following the pointer *a*, and then set the second value location, pointed to by *a* by following the second pointer *b*, to finally store the value of *temp* to the location pointed to by *b*

* Now *swapW can return, and the variables in *main* will still be changed.

* We need yo pass in the addres of *x* and *y* to our *swap* function and with *&x*, we can get the address of *x* to pass in.

# Scanf

* scanf takes a format *%i*, so thhe input is "scanned" for that format. We also pass in the adress in memory where we want that input to go with &x
```c
#include <stdio.h>

int main(void)
{
    char s[4];
    printf("s: ");
    scanf("%s", s);
    printf("s: %s\n", s);
}
```
* If the user types in a string of length 3 or less, our program will work safely, but if the users types in a longer string *scanf* might be trying to write past the end of our arrat¿y into unknown memory, causing a crash or even a sementation fault.

# Files
* using pointers we can open files.

```c
// Saves names and numbers to a CSV file
  
#include <cs50.h>
#include <stdio.h>
#include <string.h>
  
int main(void)
{
    // Open CSV file
    FILE *file = fopen("phonebook.csv", "a");
    if (!file)
    {
        return 1;
    }
  
    // Get name and number
    string name = get_string("Name: ");
    string number = get_string("Number: ");
  
    // Print to file
    fprintf(file, "%s,%s\n", name, number);
  
    // Close file
    fclose(file);
}
```
* *fopen* is a new function we can use to open a file with a new type, *file*

* By using *fprintf* we can write to a file

# JPEG
* The next program opens a file and tells us if it´s a JPEG file:

```c
// Detects if a file is a JPEG
  
#include <stdint.h>
#include <stdio.h>
  
typedef uint8_t BYTE;
  
int main(int argc, char *argv[])
{
    // Check usage
    if (argc != 2)
    {
        return 1;
    }
  
    // Open file
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        return 1;
    }
  
    // Read first three bytes
    BYTE bytes[3];
    fread(bytes, sizeof(BYTE), 3, file);
  
    // Check first three bytes
    if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff)
    {
        printf("Yes, possibly\n");
    }
    else
    {
        printf("No\n");
    }
  
    // Close file
    fclose(file);
}
```

1. define *BYTE* as 8 bits, so we can refer to a byte as a type more easily in C.
 
1. We can compare the first three bytes (in hecadecimal) to the three bytes requierd to being a JPEG file. If they are the same our file is likely to be a JPEG file (though, other types of files may still begin with those bytes), if they´re different, we definitely know is not a JPEG file

## implementing our own version of image filters like this program that only shows color red:

```c
#include "helpers.h"
  
// Only let red through
void filter(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = 0x00;
            image[i][j].rgbtGreen = 0x00;
        }
    }
}
```

* Here´s a loop that iterates over all the pixels in a two dimensional array, and sets the blue and green values to 0.

```c
#include "helpers.h"
  
// Only let red through
void filter(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = 0x00;
            image[i][j].rgbtGreen = 0x00;
        }
    }
}
```