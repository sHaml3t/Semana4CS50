
# Shorts SQL week7

* Often times, in order for us to build the most functional website we can, we depend on a **database** to store infromation.

* If you've ever used Microsoft Excel or Google spreadsheets (among others), odds are you're familiar with the notion of a database: a hierarchically organized set of tables, each of which contains a set of rows and columns.

## SQL

* SQL (the structured Query Lenguage) is a programming lenguage whose propose is to **query** a database.

* MySQL is one open-source platform on which you can establish the type of a relational database that SQL is most adept at working with.
  * SQLite is another, which we've actually use in Cs50 since 2016

* Many installations of SQL comes with a GUI tool called **phpMyAdmin** which can be used to ejecute database queries in a more user-friendly way.

* After you create a database, the next thing you'll most likely want to do is create a **table**-
  * The syntax for doing this is a ctually a bit awkwardo to do programmatically. at least at the oustset. and so this is where phpMyAdmin will come in handy.

## Tables

* As part of the process of creating a table, you'll ve asjed ti specify all of the **columns** in that table.

* Thereafter, all your queries will refer to **rows** of the table.

* Each column of your SQL table is capable of holding data of a particular data type.

## Datatypes

* SQL has various datatypes such as
  * INT (for integers), SMALLINT, TINYINT, MEDIUMINT, BIGINT (for different integer upper bounds 2 to the 31st power if they're unsigned integers)
  * DECIMAL, FLOAT (for double and float)
  * DATE, TIME, DATETIME, TIMESTAMP
  * GEOMETRY, LINESTRING(to store mapping or a drawing out of an area, such as using GIS data)
  * TEXT (for arbitrarily large chunks of text)
  * ENUM (from C is a column of your table that can be used to store a limited set of values)
  * CHAR (Unlike c, it doesnt refer to a single character. Rather is a fixed-length string, in most databases, including MySQL, you actually specify the fixed-length as part of the type definition, e.g. CHAR(10)) 
  * VARCHAR (Refers to a cariable-length string. It also requires you to specify the **maximum** posible length of a string that could be stored in that column, e.g. VARCHAR(99))

* To simplify things, SQLite provides something called "type affinity" t simplicity things, any other can be "reduced" to this five:
     * NULL. nothing

     * INTEGER. Ints

     * REAL. Decimal and float

     * TEXT. Including char and varchar
     
     * BLOB. Geometry data 


## Building tables

* One other important consideration when constructing a table in SQL is to choose one column to be your primary key

* Primary keys enable rows of a table to be uniquely and quickly identified
     * Choosing your primary key appropriately can make subsequent operations on the table much easier.


* It is also possible to establish a joint primary key - a combination of two columns that is always guaranteed to be unique.

## SQL tables

* SQL is a programming language, but its vocabulary is fairly limited.

* We will primerly consider just four operations thay one may perform on a table :

INSERT
SELECT
UPDATE
DELETE

* To explain a little better how tocreate a table, in an example we got a table of users and other of their mothers, we want to conect them, in order to do it, first we use the keyword INSERT(add new information to a table):
    
```sql
     INSERT INTO
     <table>
     (<columns>)
     VALUES
     (<values>)
```

* Filling parentheses with coma-separated elements 

    
```sql
     INSERT INTO
     <table>
     (username, password, fullname)
     VALUES
     ('newman', 'USMAIL', 'Newman')
```

If we execute this query will add a new row to our two main tables .

* When defining the column that ultimately ends up being your tables primary key, it's usually a good idea to have that column to be an integer 

* Moreover, so as to eliminate the situation where you might accidentally forget to specify a real value for the primary key column, you can figure that column to autoincrement , so it will pre-populate that column for you automatically when rows are added to the table.

## INSERT

* Add information to a table

```sql
INSERT INTO
moms
(username, mother)
VALUES
('kramer', 'Babs Kramer')
```

## SELECT

* Extract infromation from a table.

```sql
SELECT
<columns>
FROM
<table>
WHERE
<condition>
ORDERED BY
<column>
```

## RELATIONAL DATABASES

* Databases empower us to organize information into tables efficiently.
* We don't always need to store every possible relevant piece of information in the same table, but can use relationships across the tables to let us pull information from where we need it.

### SELECT JOIN
* Extract information from multiple tables.

```sql
SELECT
<columns>
FROM
<table1>
JOIN
<table2>
ON
<predicates>
```

## UPDATE
* Modify information in a table
  
```sql
UPDATE
<table1>
SET
<column> = <value>
WHERE
<predicatee>
```

## DELETE

* Remove information from a table
```sql
DELETE FROM
<table1>
WHERE
<condition>
```

## CONCLUSION

All of these operations are pretty easy to do in the graphical interface of phpMyAdmin.

* We want a way to do this programmatically, not just typing SQL comands into the "SQL" tab
* Fortunately,SQL integrates with other programming lenguages such as python or PHP very easy.