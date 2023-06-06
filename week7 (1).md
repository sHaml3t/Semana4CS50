# Week 7 cs50 SQL

## Data processing.

* We already know about some forms of data collection from various extensions, including CSV

* Through this session we have used Google Sheets, to get a list of responses drom the audience, in real time, this plataform is a web- based spreadsheet application, showing our data in rows and columns:

| Timestamp | Title      | genres                             |
| :-------- | :---------:| ---------------------------------: |
| 10/25/21  | squid game | Action, Adventure, Drama, Trhiller |
| 10/25/21  | Friends    | Comedy                             |
| 10/25/21  | Narcos     | Action, Crime, Drama, History      |

* As we know, e can download our data as a CSV file, which is an example of a **flat-file database**, where the data from eawch column is separated by commas, and each row is on a new line, saved simply as a text file in ASCII or Unicode.
    * A flat-file database is completely portable, which means that we can open it on early any operating system without special software like Microsoft Excel or Apple Numbers.

* Once opened in an editor:
 | Timestamp, | Title,      | genres                               |
 | :--------- | :----------:| -----------------------------------: |
 | 10/25/21,  | squid game, | "Action, Adventure, Drama, Trhiller" |
 | 10/25/21,  | Friends,    | Comedy                               |
 | 10/25/21,  | Narcos,     | "Action, Crime, Drama, History"      |


* Some rows have multiple genres, and those are sorrounded by quotes, like "Crime, Drama", so that the comas *within* our data aren't misinterpreted.

* Let's write a new program, **favorites.py**, to read our CSV file:

```python
import csv

with open("favorites.csv", "r")
    reader = csv.reader(file)
    next(reader)
    for row in reader:
        print(row[1])
```
    * We'll open the file with a reference called *file*, using the *with* keyword in Python that will close our file for us.

    * The *csv* library has a *reader* function that will create a *reader* variable we can use to read in thefile as CSV

    * We'll call *next* to skip the first row, since that's the header row.

    * Then, we'll use a loop to print the second column in each row, which is the title.        


```terminal
$ python favorites.py
...
Friends
...
friends
...
Friends
```
    * But for the show titled "Friends", some entries are capitalized and some are lowcased

## Cleaning.

* To improve our program, we'll first use a **DictReader**, dictionary reader, which creates a dictionary from each row, allowing us to access each column by its name. We also don't need to skip the header row in this case, since **DictReader** will use it automatically.

```python
import csv

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)

    for row in reader:
        print(row["title"])
```
    * Since the first row in our CSV has the names of the columns, it can be used to label each column in our data as well. Now our program will still work, even if the order of the columns are changed.

* Now let's try to filter our duplicates in our responses:

```python
import csv

titles = []

with open("favorites.csv","r") as file:
    reader = csv.DictReader(file)

    for row in reader:
        if not row["title"] in titles:
            titles.append(row["title"])

for title in titles:
    print(title)
```
    * Now, we've **canonicalized**, or standarized, our data, and our list of titles are much cleaner
    ```terminal
    $ python favorites.py
    ...
    NEW GIRL
    FRIENDS
    THE OFFICE
    BREAKING BAD
    ```

* It turns out that Python has another data structure built-in, *set*, which ensures that all values are unique:
```python
import csv

titles = set()

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)

    for row in reader:
        title = row["title"].strip().upper()
        titles.add(title)

for title in titles:
    print(title)
```
    * Now, we can **add** on the set, and not have to check ourselves if it's already in the set.

* To sort the titles, we can just change our loop to **for title in sorted(titles)**, which will sort our set before we iterate over it:
```python
import csv

titles = set()

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)

    for row in reader:
        title = row["title"].strip().upper()
        titles.add(title)

for title in sorted(titles):
    print(title)
```

```terminal
$ python favorites.py
ADVENTURE TIME
ANNE WITH AN E
...
AVATAR
AVATAR THE LAST AIRBENDER
AVATAR: THE LAST AIRBENDER
...
BROOKLYN-99
BROOKLYN-99
...
```
    * Now, we see our titles alphabetized, but there were still a few different ways that show's the titloe could be entered. We'll leave these differences there for now, since it will likely take a bit more effort to fully standardize our data.

## Counting.

* We can use a dictionary, instead of a set, to count the number of times we've seen each title, with the keys being an integer counting the number of times we see each of them:

```python
import csv

titles = {}

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)

    for row in reader:
        title = row["title"].strip().upper()
        titles[title] += 1

for title in sorted(titles):
    print(title)
```
    * As we read each row, we increase the value stored for that title in the dictionary by 1.

* We'll run this program, and see:
```terminal
$ python favorites.py
Traceback(most recent call last):
line 9

    titles[title] += 1
KeyError: 'HOW I MET YOUR MOTHER'
```
    * We have a **KeyError** since **HOW I MET YOUR MOTHER** isn't in the dictionary yet.

* Lets add the values, or counts, to our loop that prints every show name.

* We'll have to add each title to our dictionary first, and set the initial value to 0 and incremebt it by 1 no matter what::
```pyhon
import csv

titles = {}

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)

    for row in reader:
        title = row["title"].strip().upper()
        if title in titles:
            titles[title] += 0
        else:
            titles[title] = 1

for title in sorted(titles):
    print(title, titles[title])
```
```terminal
$python favorites.py
ADVENTURE TIME 1
ANNE WITH AN E 1
ARCHER 1
...
AVATAR THE LAST AIRBENDER 5
...
COMMUNITY 8
``` 

* Now the key exist in the dictionary, and we can safely refer to its value in the dictionary.

* We can sort by the value in the dictionary by changin our loop to:

```python
def get_value(title):
    return titles[title]

for title in sorted(titles,key=get_value,(title, titles[title]))
```
    * we define a function *f* which just returns the value of a title in the dictionary with **titles[title]**. the **sorted** function, in turn, will take in that function as the key to sort the dictionary. And we'll also pass in **reverse=True** to sort from largest to smallest, instead of smallest to largest; printing the most popular first:
    ```terminal
    $ python favorites.py
    THE OFFICE 15
    FRIENDS 9
    COMMUNITY 8
    GAME OF THRONES 6
    ...
    ```
* We can acturally define our function in the same line, with this syntax:
```python
for title in sorted(titles, key=lambda title: titles[title],reverse=True)_:
    print(title, titles[title])
```
    * We can write and pass in a **lambda**, or anonymus function, which has no name but takes in some argument or arguments, and returns a value immediately..
    * Notice that there are no parentheses or **return** keyword, but concisely has the same effect as our **get value** function earlier

