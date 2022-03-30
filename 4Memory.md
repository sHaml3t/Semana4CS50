allocates : designa

# WEEK 4 MEMORY
-----

## Valgrind
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


## Garbage Values
* Declared an array but dont initialize it with any values, and print it out, we'll see some random numbers called **garbage values**, from others programs running before maybe.
* We need to be careful with how our programs access memory
*if we try to go to an address that´s a garbage value, our program is likely to **crash** from a **segmentation fault*.

## Pointer Binky video
* Initially pointers dont point to anything, to allocate uses *x = malloc(sizeof(int));*

* With **x =42;* we dereference x follows the arrow to acces its pointee, which in this case stores 42 in there 
    
* We need to set up the pointee before dereferencing it, you cant just express **y = 13* without allocate y using *y = malloc(sizeof(int));*

* When using the assignment operator  *y = x* and both point the same address of 13


## Swap
* implementing a function like 
```c
#include <stdio.h>

void swap(int a, int b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(x, y);
    printf("x is %i, y is %i\n", x, y);
}

void swap(int a, int b)
{
    printf("a is %i, b is %i\n", a, b);
    int tmp = a;
    a = b;
    b = tmp;
    printf("a is %i, b is %i\n", a, b);
}
```
* In our swap function, we have a third variable to use as temporary storage space as well. We put *a* into *tmp*, and then set *a* to the value of *b*, and finally *b* can be changed to the original value of *a*, now in *tmp*.

* But, if we tried to use that function in a program, we don’t see any changes.

* It turns out that the swap function gets passed in copies of variables, *a* and *b*, which are local variables that only the surrounding function can access. Changing those values won’t change *x* and *y* in the main function.

* But it will work if we print the resullt with the values inside of the function

## Memory layout

```bash
     -------------------------
     |  |  |Machine code|  |  |
     -------------------------
     |  |  |  Globals   |  |  |
     -------------------------
     |  |  |   Heap     |  |  |
     -------------------------
     |  |  |  |  ↓   |  |  |  |
     -------------------------
     |  |  |  |      |  |  |  | 
     -------------------------
     |  |  |  |  ↑   |  |  |  |
     -------------------------                   
     |  |  |  Stack  |  |  |  |
     -------------------------
```
* The **machine code** section is our compiled program’s binary code. When we run our program, that code is loaded into memory.

* Just below, or in the next part of memory, are **global variables** we declared in our program.

* The **heap section** is an empty area from where malloc can get free memory for our program to use. As we call malloc, we start allocating memory from the top down.

* The **stack** section is used by functions and local variables in our program as they are called, and grows upwards.

* If we call *malloc* for too much memory, we will have a **heap overflow**, since we end up going past our heap. Or, if we call too many functions without returning from them, we will have a *stack overflow*, where our stack has too much memory allocated as well.

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
$ make swap
$ ./swap
x is 1, y is 2
x is 2, y is 1
```
* The addresses of *x* and *y* are passed in from *main* to *swap* with *&x* and *&y*, and we use the *int *a* syntax to declare that our *swap* function takes in pointers. Now *swap* can return, and the variables in main will still be changed.

* With *&x*, we can get the address of *x* to pass in.

## Scanf
* In c theres not such a type like string, so we need to store the character first pointer in an adress.

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
* *scanf* takes a format, *%i*, so the input is “scanned” for that format. We also pass in the address in memory where we want that input to go with *&x*.

* If the user types in a string of length 3 or less, our program will work safely. But if the user types in a longer string, *scanf* might be trying to write past the end of our array into unknown memory, causing our program to crash.


* *get_string* from the CS50 library continuously allocates more memory as *scanf* reads in more characters, so it doesn’t have this issue.


## Files

* With the ability to use pointers, we can also open files, like a digital phone book in phonebook.c:

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

* *fopen* is a new function we can use to open a file with a new type, *FILE*.

* We can use fprintf to write to a file.



## JPEG

* Let’s look at a program that opens a file and tells us if it’s a JPEG file, a particular format for image files, with jpeg.c:
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

```bash
$ make jpeg
$ ./jpeg .src4/lecture.jpg
Yes, possibly
```

* define a BYTE as 8 bits, so we can refer to a byte as a type more easily in C.

* read from a file with a function called fread.

* We can compare the first three bytes (in hexadecimal) to the three bytes required to begin a JPEG file. If they’re the same, then our file is likely to be a JPEG file (though, other types of files may still begin with those bytes). But if they’re not the same, we know it’s definitely not a JPEG file.


* BMP files, another format for images, have even more bytes in its header, or beginning of the file.


* Let´s implement our own version of image filters, like one that only shows the color red:

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

* Here, we have a loop that iterates over all the pixels in a two-dimensional array, and sets the blue and green values to 0.