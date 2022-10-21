# PYTHON SHORTS

## Introduction
* C was first released in 1972, Python inn 1991.
* Python is an excellent and versatile language choice for making complex C operations much simpler.
    * String manipulation 
    * Networking

* Inspired by C (its primary interpreter, Cpython is written in C) and so the syntax should be a shallow learning curve

## Start

* by opening a file with .py extension

* Programs can run without compiling

## Variables
* No type specifier 
* Declared by initialization only.
* Python statements don´t need semicolons;
    ```Python
    x = 54
    line = "This is cs50"
    ```

All Conditionals are available to use, with simpler syntax changes:
```Python
    if y < 43 and z == 15:
        # code block 1
    else:
 ```

 ## Ternary function


```python
letters_only = True if input().isalpha() else False
```

## Loops

Two varieties: while and for


```python
counter = 0
while counter < 100:
     print(counter)
     counter += 1
```
and
```python
for x in range(100):
     print(x)
```
Range gives us a list of all the numbers between 0 and 100
now 2 by 2
```python
for x in range (0, 100, 2):
    print(x)
```

## Arrays

* Python arrays (more appropriately known as **lists**) are **not** fixed in size; they can grow or shrink as needed, and you can always tack extra elements onto your array and splice things in and out easily, making them more flexible to work with, but in python we call them Lists

## Lists

Declaring a list is pretty straightforward.
```python
nums = []
```
### List comprehension

Basically this use the for loop to generate a list of numbers for me, in this case all numbers between 0 and 499 since 500 is not considered
```python
nums = [x for x in range(500)]
```

adding new elements has a few ways:
```python
nums = [ 1, 2, 3, 4]
#nums.apend(5)
#nums.insert(4, 5)
nums[len(nums):] = [5]
```
The  *.insert* allow us to choose which position will the next number be added

the 3rd way is creating a new list and updating the one that existed before. nums list from position 4 (the length of nums), forward, gets this list assigned to it, **len** represents the length of **ANY** list (or python array)

## Tuples 

Tuples are ordered, immutable sets of data; they are great for associating collections of data, sort of like a struct in C, but where this values are unlikely to change

list of tuples:
```python
presidents = [
    ("George Washington", 1789),
    ("John Adams", 1797),
    ("Thomas Jefferson", 1801),
    ("James Madison", 1809)
]

#iteration and printing out: 
for prez, year in presindents:
    print("In{1}, {0} took office".format(prez,year))
```
Where {} are formaters to match arguments prez, year

```terminal
In 1797, John Adams took office
```
## Dictionaries
Python has Built in **dictionaries**, allowing you to specify list indices with words or phrases *(keys)* , instead of integers, which you where restricted to in C.

```python
pizzas = {
    "cheese" : 9,
    "pepperoni" : 10,
    "vegetable" : 11,
    "buffalo chicken" : 12
}
```
Association to other keys
```python
pizzas["cheese"] = 8

# usages
if pizza["vegetables"] < 12:
    # do something

# adding a value
pizzas["bacon"] = 14
```

## Loops (redux)
Iteration trough a Dictionary

We don't have indexes ranging from [0, n-1] anymore (not mathematical, but alphabetical)

So this is a *for loop* work

```python
for pie in pizzas: 
    #use pie in here as a stand-in for i


for pie in pizza print(pie)
    # Will iterate over all of the values

for pie, price in pizzas.items():
    print(price)
    # Will transform my dictionary into a list  
```
* A *for loop* iterate the keys automatically in a dictionary, as a side effect dictionaries wont maintain the list order or any other order.

```python
for pie, price in pizzas.items():
    print("A whole {} pizza costs ${}".format(pie, price))
```

## Printing and variable interpolation.

```python
print("A whole {} pizza costs ${}".format(pie, price))

print("A whole " + pie + " pizza costs $" + str(price))
# We transform price to a string because everything else here is a string 


# you may see this, but avoid; deprecated in python 3
print("A whole %s pizza costs $%2d" % (pie, price))
```

## Function 

Python has support for functions. But like variables we dont need to specify the return type of the function, nor the data types of any parameters (ditto)

Starting with the *def* keyword.
    * No need for main; the interpreter reads from top to bottom
    * If you wish to define *main* you must add at the very end of your code the following:

    ```python
    if __name__ == "__main__":
        main()
    ```

### Defining functions
```python
def square(x):
    # return x * x
    # x times x
    return x ** 2
    # x times times 2, x squared, no exponential operator

# Add x to itself x times
def square(x):
    result = 0
    for i in range (0, x):
        result += x
    return result
```

## Objects

Just like a C structures, objects also contain a number of fields, which we might also call properties
    * But properties themselves can not ever stand on their own

C:
```c++
struct car
{
    int year;
    char *model;
}

//notice that we use dot notation to help .year and .model
struct car herbie;
herbie.year = 1963;
herbie.model = "Beetle";
```

* Objects also has methods, or functions that are inherent to the object, and mean nothing outside of it. You define the methods inside of the object also.
    * Thus, properties and methods don´t ever stand on their own

So we call methods on objects:
```python
object.method()
```
* You define a type of object using the *class* keyword in Python.

* Classes require an initialization function, also more-generally known as a constructor, which sets the starting values of the properties of the object

* In defining each method of an object, *self* should be its parameter, which stipulates in what what object the method is called:

```python
# OBJECTS

class Student():

    def __int__(self, name, id):
        self.name = name
        self.id = id
    
    def changeID(self, id):
        self.id = id
    
    def print(self):
        print("{} - {}".format(sef.name, self.id))

jane = Student("Jane", 10)
jane.print()
jane.changeID(11)
jane.print()
```

## Style.

Tabs and identation matter in this language.
    * No more curly braces to delineate blocks, those are used to declare dictionaries


## Including files

Just like C programs can consist of multiple files to from a single program, so python programs tie files together.

```python
import cs50


cs50.get_int()
cs50.get_float()
cs50.get_string()
```

## Python syntax

Files can be prewritten in .py files, but you can also write and test short Python snippets using the python interpreter from the command line.

In order to invoke the interpreter and start to use it at the command-line:
```terminal
python <file>
```
Adding **shebang** to the top of your python files, automatically finds and executes the interpreter for you.
#!/usr/bin/env python3
    * If you do this, you need to change the **permissions** on your file as weel using the Linux command chmod as follows:
        ```terminal
        python <file>
        ```


