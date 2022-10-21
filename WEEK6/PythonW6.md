# PYTHON W6

## Hello, python

To print “hello, world”, all we need to write is: 
```python
print("Hello, world")
```

## From C to python

* In Scratch and C, we might have had multiple functions: 
```c
string answer = get_string("What's your name? "); printf("hello, %s\n", answer);
```
* In Python, the equivalent would look like: 
```python
answer = get_string("What's your name? ") print("hello, " + answer)
```
    * We can create a variable called answer without specifying the type, and we can join, or concatenate, two strings together with the + operator before we pass it into print.

* We can also write:
```python
print(f"hello, {answer}") 
```
    * The f before the double quotes indicates that this is a format string, which will allow us to use curly braces, {}, to include variables that should be substituted, or interpolated.
    
 
 
* We can create variables with just counter = 0. To **increment a variable**, we can write counter = counter + 1 or counter += 1. 

* **Conditionals** look like: 
```python
if x < y: print("x is less than y") elif x > y: print("x is greater than y")
```

* We can create a variable called answer without specifying the type, and we can join, or concatenate, two strings together with the + operator before we pass it into print.

```python
else: print("x is equal to y")
```

* Unlike in C, where curly braces are used to indicate blocks of code, the exact indentation of each line determines the level of nesting in Python. And there is **no need parentheses around the Boolean expressions**. And instead of else if, we just say elif. We can create a forever loop with a while loop: 
```python
while True: print("meow") Both True and False are capitalized in Python.
```

* While loop with a variable:
```python
i = 0 while i < 3: print("meow") i += 1
```
* We can write a for loop, where we can do something for each value in a list: 
```python
for i in [0, 1, 2]: 
    print("hello, world")
```

* Lists in Python, [0, 1, 2], are like arrays or linked lists in C. This for loop will set the variable i to 0, run, then to the second value, 1, run, and so.

* We can write a while loop with a variable: 
```python
i = 0 while i < 3: print("meow") i += 1
```

* We can write a for loop, where we can do something for each value in a list: 
```python
for i in [0, 1, 2]: 
    print("hello, world")
```
* Lists in Python, [0, 1, 2], are like arrays or linked lists in C. This for loop will set the variable i to 0, run, then to the second value, 1, run, and so on. And we can use a special function, range, to get any number of values:
```python
for i in range(3): 
    print("hello, world") range(3)
```
    - This will give us a **list** up to but **not** including 3: values 0, 1, and 2,


**range()** takes other arguments as well, so we can have lists that start at different values


## Python, built-in data types


* bool: True or False 
* float: real numbers
* int: integers which can grow as needed 
* str: strings


Other types in Python include:
* range: sequence of numbers list, sequence of mutable values, or values we can change 
* tuple: sequence of immutable values 
* dict: dictionaries, collection of key/value pairs, like a hash table set, collection of unique values, or values without duplicates

## Run

To run a program we wrote in Python, we’ll only need to execute: python hello.py python is the name of a program called an interpreter, which reads in our source code and translates it to code that our CPU can understand, line by line. Our source code files will also end in .py, to indicate that they’re written in the Python language.

* Programs in Python will take some extra time to be interpreted as they are run.

## Examples

We can blur an image with: 

```python
from PIL import Image

ImageFilter before = Image.open("bridge.bmp") 
after = before.filter(ImageFilter.BoxBlur(10))
after.save("out.bmp") 
```

* In Python, we include other libraries with import, and here we’ll import the Image and ImageFilter names from the PIL library. Image is an object.

* Objects in Python can have not just values, but functions that we can access with the **.** syntax, such as with Image.open. And before is an object with a filter function as well, which we can find in the documentation for the library.


* we’ll notice that it takes a few seconds longer to run than the C version. Even though it was much faster for us to write, we aren’t able to fully optimize our code by way of managing memory and implementing all.
    It turns out, we can cache, or save, the interpreted version of our Python program, so it runs faster after the first time. And Python is actually partially compiled too, into an intermediate step called bytecode, which is then run by the interpreter.

## Libraries

* We need to write cs50.get_int(...) when we import the entire library. This allows us to namespace functions, or keep their names in different spaces, with different prefixes. Then, multiple libraries with a get_int function won’t collide.

## Error exceptions

* If we call input ourselves, we get back strings for our values: x = input("x: ") y = input("y: ") print(x + y) $ python calculator.py x: 1 y: 2 12 And we print the two strings, joined together as another string. So we need to cast, or convert, each value from input into an int before we store it: x = int(input("x: ")) y = int(input("y: ")) print(x + y)

* **Notice that *int* in Python is a function that we can pass a value into.**


* **ValueError** is a type of exception, or something that goes wrong when our code is running.

```python
try: x = int(input("x: ")) 
except ValueError: print("That is not an int!") 
exit() 
try: y = int(input("y: ")) 
except ValueError: print("That is not an int!") 
exit() 
print(x + y)
```

* We get **floating-point**, decimal values back, even if we divided two integers. The division operator in Python doesn’t truncate those values by default. (We can get the same behavior as in C, truncation, with the // operator, like z = x // y.)

* We can use a format string to print out more digits after the decimal point:

```python
z = x / y print(f"{z:.50f}")

print(f"{z:.50f}")
```

we still have floating-point imprecision.


## Strings 

* Comments in Python start with a #: We can check the parity of a number with the remainder operator, %: To compare strings, Python doesn’t have a data type for single characters, so we check Y and other letters as strings. We can compare strings directly with ==, and we can use or and and in our Boolean expressions.


* Strings are also immutable, or unchangeable. When we make changes to a string, a new copy is made for us, along with all the memory management.

## Functions

we need to define our function before we use it. So we’ll define a main function first: 

```python
def main():
    for i in range(3):
        meow() def meow():
            print("meow") 
            

main()
```

* by the time we actually call our **main** function at the end of our program, the meow function will already have been defined.


* functions can take arguments, too.


* We can create global variables by initializing them outside of main, though Python doesn’t have constants.

## Loops

```python
def main():
    meow(3) def meow(n):
        for i in range(n):
            print("meow") 

main() 
```
    - Our meow function takes in a parameter, n, and passes it to range in a for loop. Notice that we don’t need specify the type of an argument.


**In Python, there is *no* do while loop, but we can achieve the same effect:**

```python
from cs50 import get_int

while True:
    n = get_int("Height: ") 
    if n > 0: 
        break for i in range(n): print("#")
```
 - We’ll write an infinite loop, so we do something at least once, and then use break to exit the loop if we’ve met some condition.


* variables are scoped to a function, meaning we can use them *outside* of the loop they’re created in.

```python
for i in range(4): 
    print("?", end="")
    print()
``` 
```terminal
$ python mario.py
????
```
    - When we print each question mark, we don’t want the automatic new line, so we can pass a named argument, also known as keyword argument, to the print function. (So far, we’ve only seen positional arguments, where arguments are set based on their position in the function call.)

- We pass in end="" to specify that nothing should be printed at the end of our string.

- we look at the documentation for print, we’ll see that the default value for end is \n, a new line.

- we pass in end="" to specify that nothing should be printed at the end of our string. If we look at the documentation for print, we’ll see that the default value for end is \n, a new line.


- Finally, after we print our row with the loop, we can call print

- we pass in end="" to specify that nothing should be printed at the end of our string. If we look at the documentation for print, we’ll see that the default value for end is \n, a new line. Finally, after we print our row with the loop, we can call print with no other arguments to get a new line. We can also use the multiply operator to join a string to itself many times, and print that directly with: print("?" * 4).


implement nested loops
```python
for i in range(3):
    for j in range(3):
        print("#", end="") 
        print() 
```
```terminal
$ python mario.py 
### ### ###
```

*The official Python documentation includes references for built-in functions.*

## Lists
```python
scores = [72, 73, 33] 
average = sum(scores) / len(scores) 
print(f"Average: {average}") 
```
 - We can use sum, a function built into Python, to add up the values in our list, and divide it by the number of scores, using the len function to get the length of the list.

```python
from cs50 import get_int 

scores = [] 
for i in range(3):
    score = get_int("Score: ") 
    scores.append(score) 
    average = sum(scores) / len(scores) 
    print(f"Average: {average}") 

```
- With the append method, a function built into list objects, we can add new values to scores. We can also join two lists with scores += [score]. Notice that we need to put score into a list of its own.

```python
from cs50 import get_string 
before = get_string("Before: ") 
print("After: ", end="") 
for c in before: 
    print(c.upper(), end="") 
    print() 
```      
 -Python will iterate over each character in the string for us with just for c in before

* To make a string uppercase, we can also just write after = before.upper(), without having to iterate over


```python
from sys import argv 

if len(argv) == 2: 
    print(f"hello, {argv[1]}") 
    else:
         print("hello, world")
```
         
         
         
```terminal         
 $ python argv.py hello, world 
 $ python argv.py David 
 hello, David 
 ```
We import argv from sys, the system module, built into Python. Since argv is a list, we can get the second item with argv[1]. argv[0] would be the name of our program, like



We can also let Python iterate over the list for us: 

 ```python
from sys import argv 

for arg in argv: print(arg)
 ``` 
 ```terminal 
$ python argv.py argv.py 
$ python argv.py foo bar baz argv.py foo bar baz
 ```

With Python, we can start at a different index in a list: 
 
 ```python 
for arg in argv[1:]:
     print(arg)
 ```     
     
This lets us slice the list from 1 to the end. We can write argv[:-1] to get everything in the list except the last element. We can return exit codes when our program exits, too: 

 ```python
from sys import argv, exit 

if len(argv) != 2:
    print("Missing command-line argument") exit(1) print(f"hello, {argv[1]}") exit(0)



import sys numbers = [4, 6, 8, 2, 7, 5, 0] 

if 0 in numbers: 
    print("Found") sys.exit(0) 
    print("Not found") sys.exit(1) 
```

With *if 0 in numbers:*, we’re asking Python to check the list for us.


## Dictionaries
a dictionary, a set of key-value pairs, we can also check for a particular key, and look at the value stored for it:

 ```python
from cs50 import get_string 

people = { "Carter": "+1-617-495-1000", "David": "+1-949-468-2750" } 
name = get_string("Name: ") 
if name in people:
    number = people[name] 
    print(f"Number: {number}")
```

```terminal
$ python phonebook.py 
Name: David 
Number: +1-949-468-2750 
```

We first declare a dictionary, people, where the keys are strings of each name we want to store, and the value for each key is a string of a corresponding phone number. Then, we use if name in people: to search the keys of our dictionary for a name. If the key exists, then we can get the value with the bracket notation, people[name].


## Files

 ```python
import csv from cs50 import get_string 

file = open("phonebook.csv", "a") 
name = get_string("Name: ") 
number = get_string("Number: ") 
writer = csv.writer(file) 
writer.writerow([name, number])
file.close()
 ```
 
 ```terminal
$ python phonebook.py 
Name: Carter 
Number: +1-617-495-1000 

$ ls phonebook.csv phonebook.py
 ```


after we open the file for appending, we can call csv.writer to create a writer object from the file. Then, we can use a method inside it, writer.writerow, to write a list as a row.

use the with keyword, which will close the file for us after we’re finished: ... with open("phonebook.csv", "a") as file: writer = csv.writer(file) writer.writerow((name, number))

 ```python
import csv

 houses = { "Gryffindor": 0, "Hufflepuff": 0, "Ravenclaw": 0, "Slytherin": 0 } 
 
 with open("hogwarts.csv", "r") as file:
    reader = csv.reader(file) next(reader)
    for row in reader:
        house = row[1] houses[house] += 1 
        
        for house in houses:
            count = houses[house] print(f"{house}: {count}")
 ```           
            
We use the reader function from the csv library, skip the header row with next(reader), and then iterate over each of the rest of the rows. The second item in each row, row[1], is the string of a house, so we can use that to access the value stored in houses for that key, and add one to it with houses[house] += 1. Finally, we’ll print out the count for each house. 

We can improve our program by reading each row as a dictionary, using the first row in the file as the keys for each value: ... with open("hogwarts.csv", "r") as file: reader = csv.DictReader(file) for row in reader: house = row["House"] houses[house] += 1 ... Now, we can say house = row["House"] to get the value in that column. On our own Mac or PC, we can use another library to convert text to speech (since VS Code in the cloud)

## Speech recognition

 ```python
# Responds to a name 
# https://pypi.org/project/SpeechRecognition/ 

import re 
import speech_recognition 

# Obtain audio from the microphone 

recognizer = speech_recognition.Recognizer() 
with speech_recognition.Microphone() as source:
     print("Say something:") 
     audio = recognizer.listen(source) 
     
# Recognize speech using Google Speech Recognition 
words = recognizer.recognize_google(audio) 

# Respond to speech 
matches = re.search("my name is (.*)", words) 

if matches:
    print(f"Hey, {matches[1]}.")
    else:
        print("Hey, you.") 
 ```

## QR code
We can create a QR code, or two-dimensional barcode, with another library: 
 ```python
import os 
import qrcode 

img = qrcode.make("https://youtu.be/xvFZjo5PgG0")
img.save("qr.png", "PNG")
os.system("open qr.png") 
 ```
Now, when we run our program, a QR code will be generated and opened. 

