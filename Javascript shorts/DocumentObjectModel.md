# Documet Object Model.



## What´s DOM in javascript 

* JavaScript objects are incredibly flexiible, and can contain various fields,
even when those fields are other objects.

* The *document object* is one way of employing this parafigm, whereby that object
organizes the entire contents of a web page.

* By organizing an entire page into JavaScript object, we can manipulate the page´s
elements programmatically.

## Inside.

* The document object himmself, as well as all of the objects contained within in,
have a number of *properties*, and a number of *methods* that can be used to drill
down to a very specific piece of your website.

* By resetting those properties or calling certain methods, the contents of our web pages can chage without us needig to refresh the page.



## DOM Properties.

* **innerHTML** Holds the HTML inside of a set of HTML tags (te title tag/node).

* **nodeName** The name of an HTML element or element´s attribute.
* **id** The "id" attribute of an HTML element (just like css).
* **parentNode** A reference to the ode one level up i the DOM (the parent node of title would be head, since title is nested in that structure).
* **childNodes** An array of references to the nodes one level down in the DOM.
* **attributes** An array of attributes of an HTML element.
* **style** An object encapsulating the CSS/HTML styling of an element.

## DOM Methods.

* **getElementById(id)** Gets the element within a given ID below this point in the DOM.
* **getElementsByTagName(tag)** Gets all elements with the given tag below this point in the DOM
* **appendChild(node)** Add the given node to the DOM below this point.
* **removeChild(node)** Remove the specified child node from the DOM.

## jQuery.


* It´s an alternative to shorthand the usage of JavaScript(since it can get quite lengthy)

* A popular open-source library, released in 2006, that is designed to simplify client-side scripting(such as DOM manipulations).

Examples:
```javascript
document.getElementById('colorDiv').style.backgroundColor = 'green'
```

```javascript
$('#colorDiv').css('bacground-color', 'green');

```
