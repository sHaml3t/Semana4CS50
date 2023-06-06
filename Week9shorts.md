#FLASK WEEK 9 SHORTS

## FLASK

### Python

Python is not just used for command-line programming, though thats a major case

Python contains native funcionality to support networking and more, enabling site backends to be written in Python

### a framework

Web frameworks make tasks and programming process much easier, abstracting away the minutia of Python´s syntax ad providing helper functions.

Some of the most popular, include Django, Pyramid, and flask, this last is the used in this course because of the light weitght while still being feature-rich.

### HTML + Frameworks

We can use HTML to build websites, but websites built using pure HTML suffers from a serious limitation:
     they are static.
 

```Flask
<html>
     <head>
          <title>Current time in Cambridge</title>
     </head>
     <body>
          The current time in Cambridge is **14:11**
     </body>
</html>
```

*This is not useful, since the information we gather is too little to get in time responses*

Websites that are pure HTML are completely static. The only way we can update the content of our pages is to manually open up our source files, edit and save, and then the next time the user visits or refreshes the page they´ll get the content.

Incorporinating Python into our code can make our code quite a bit more flexible and instroduce a way for our pages to update or be dynamic without requiring our intervention.

```python
from flask import Flask
from datetime import datetime
from pytz import timezone

app = Flask(___name___)

@app.route("/")

def time():
     now = datetime.now(timezone('America/New_York'))
     return "The current date and time in Cambridge is {}".format(now)
```


## Starting with Flask

*from flask import Flask* 

Lower case flask, is the name of the module, while capital F, Flask is going to be the name of a function within that module, in particullar a **Class** just as the python syntax says (classes have assigned a capital letter)

After importing the Flask module, we need to initiate a Flask application:
     *app = Flask(___name__)*
Usualy done from App.py


## Coding

From there, it´s just a matter of writting functions that define the behavior of our application.
```python
@app.route("/")
def index():
     return "You are at the index page!"

@app.route("/sample")
def sample():
     return "You are on the sample page"
```


### Decorators

The lines added up before, are known as "decorators." They are ysed in Flask, to associate a particular function with a particular URL.

Decoration Function:

A decorator si a regular Python function that takes another function as input and returns a modified version of that function. The decorator function typically wraps the input function with additional fucntionality.

Syntax: To apply a decorator to a function or a class, you use the "@" symbol followed by the decorator, function´s name, placed immediately before the definition of the function or class.

Function Wrapping: When a decorated function is called, the decorator function is executed first, it can perform actions such as modifying the input function´s behavior, adding extra functionality, or performinf set up and teardown tasks. The decorator function then returns the mudified funciotn, which replaces the original function.


Decorators are powerful and flexible in Python. They allow you to add reusable functionality to functions or clasees, such as logging, timinf, authentication or validation without modifying the original code directly. The usage here is specifically to associate functions with visiting certain domains.

### Running Flask

First export the Flask app

```python
export FLASK_APP=application.py
     export FLASK_DEBUG=1
          flask run
```

We first store the app location, then tell to put the app in debug mode true, so if something goes wromg. it will get printed out to your terminal. This code is meant for the cs50 IDE, and when you want to run again your application you only have to write **flask run**, doing this you can open the same app over and over, until you export a new flask application

## Passing data in

Data can be passed in via URLs, akin to using HTTP GET.

```python
@app.route("/show/<number>")
def show(number):
     return "you passed in {}".format(number)
```
This code collects the information of the "last episode" of the show and its number.


Data can also be passed in via HTML forms, as with HTTP POST, but we need to indicate that Flask should respond to HTTP POST request explicitly. To do so, we first need to warn Flask.

```python
@app.route("/login", methods=['GET', 'POST']
def login():
     if not request.form.get("username")
          return apology("must providde username")
```



We could also vary the behavior of our function, depending on the type of HHTP request is rececieved:

Either, if the user provides the data via *get request* we might show them the form. But if we get a *post request*, the program is expecting to be provided some data via the forms.
So we can use one URL to do different things.

```python
@app.route("/login", methods=['GET', 'POST'])
def login():
     if request.method == "POST":
          # Do one thing
     else:
          # do a different thing
```

### Flask functions

Flask has a number of functions within its module that will be useful for application development, we just i mport them and leave 

```python
from flask import Flask, module
url_for()
redirect()
session()
render_template()


url_for(login)
```

In this example, the route is associated with a key thay is pased to the url, below we have to use the argumet to define the module.

