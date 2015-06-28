LeeWee Script version 1.0 2015-06-28
==================================
by David Lhoumaud

craft@ckdevelop.org

[www.ckdevelop.org](http://ckdevelop.org/index.php?article42/leewee-petit-language-interprete-en-c)

![Logo LeeWee](https://github.com/davidlhoumaud/LeeWee/blob/master/thumbnail.jpg "Logo LeeWee")

###An example script is available in the directory :
http/www/index.cgi 

###Compilation :
make

###Test http://localhost:8080/index.cgi :
make test

###Install color scheme for gtksourceview :
make color

###Uninstall color scheme for gtksourceview :
make uncolor

###Install binary file in /usr/bin/ :
make install

###Uninstall binary file of /usr/bin/ :
make uninstall

###Delete binary file :
make clean


WIKI
====

#assign a variable: 
```
$my_variable=hello world !!
```
#assign a variable session: 
```
s$my_variable=hello world !!
```

#variable a display:
```
$[my_variable]
```

#naming a variable with another variable:
```
$namevar=my_variable
$\$[namevar]=hello world !!
```

#display this variable:
```
$[my_variable]
```

#execute a command:
```
<?ls?>
```
#execute a command and store it in a variable:
```
$my_variable=<?ls?>
```

#execute and store the output of a python script or another language:
##python:
```
$python_example= <?python -c "print(\"$[my_variable], it is a python script !\")
a=1
b=2
if a==2:
    print(\"OK\")
else:
    print(\"NO\")"
?>
```

##php:
```
$php_example=<?php -r "phpinfo();"?>
```

#echo command Shell/Bash
```
$echo_example= <?echo -n "&lsaquo;strong&rsaquo;&lsaquo;strong&rsaquo;LS : &lsaquo;/strong&rsaquo;liste des fichiers et r&eacute;pertoires :&lsaquo;/strong&rsaquo;&lsaquo;br&rsaquo;"
ls | while read line; do
    echo -n "-$line<br>"
done?>
```

#CONDITION IF/ELSE
##Operator
Operator  | Description
----------| -------------
==        | equal
!=        | not equal
<         | less than
<=        | less than or equal
>         | bigger than
>=        | greater or equal

##simple IF
```
if ($[my_variable]==) {
    variable empty
}
```

##IF and ELSE
```
if ($[my_variable]!=) {
    variable not empty
} else {
    variable empty
}
```

#CONDITION WHILE
##Operator
Operator  | Description
----------| -------------
==        | equal
!=        | not equal
<         | less than
<=        | less than or equal
>         | bigger than
>=        | greater or equal

##simple WHILE
```
$num=0
while ($[num]<101) {
    $[num]<br>
    $num=<?echo -n "$(($[num]+1))" ?>
}
```

#USING MARKER
##add a marker
```
:marker_name
```
##go to a marker
```
->marker_name
```

#INCLUDE A FILE
```
include(filename.cgi)
```

#USING FUNCTION
```
function _test1() {
    <h3>->Lecture de la fonction N&deg;1</h3>
    _test2()
    _test3()
}
function _test2() {
    <h3>->Lecture de la fonction N&deg;2</h3>
    include(scripting.cgi)
}
function _test3() {
    <h3>->Lecture de la fonction N&deg;3</h3>
    include(if.cgi)
}
#read function _test1
_test1()
```
