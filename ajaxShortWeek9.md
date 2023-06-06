# AJAX WEEK 9 SHORTS.

* As part of JavaScript, we can add complexity to our websites by using Ajax (formmerly Asynchronous JavaScript and XML) allows ud to dynamically update a webpage 

* We can add functionality to some sections so they automatically update, without having to refresh the whole page.

## Syntax

* Central to our ability to asynchronous update our pages is to make use of a special JavaScript object called an XMLHttpRequest.

```javascript
var xhttp = new XMLHttpRequest();
```

* After obtaining your new object, you need to define its *onreadystatechange* behavior.
     * Thiss is a function (typically an anonymous function) that will be called when the asynchronous HTTP request has completed, and thus typically defines what is expected to change on your site.


```javascript
function ajax_request(argument)
{
    var aj = new XMLHttpRequest();
    aj.onreadystatechange = function(){
        if (aj.readyState == 4 && aj.status == 200)
            // do simething to the page
    };
    
    aj.open("GET", /* url */, true);
    aj.send();
};
```


## States

* XMLHttpRequests have two additional properties that are used to detect when the page finishes loading.
     * The *readyState* property will change from 0 (requesto not yet initialized) to 1, 2, 3, and finally 4(request finished, response ready).
     * The **status** property will (hopefully!) be *200 (OK).*

* Then just make your asynchronous request usintg the **open()** method to define the request and the **send()** method to actually send it.
     * You can also use jQuerys in order to make Ajax request, by just changing the syntaxis slightly.

## jQuery request

* This are more commonly used instead of "raw" JavaScrript


```javascript
ajax.onreadystatechange = function(){
    if (ajax.readyState == 4 && ajax.status == 200 ){
        $('#infodiv').html(ajax.responseText);
    }
}
```
    * this just updates a single div tag