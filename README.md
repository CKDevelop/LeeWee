LeeWee Script version 1 2015-04-17
by David Lhoumaud
craft@ckdevelop.org
www.ckdevelop.org

An example script is available in the directory :
http/www/index.cgi 

Compilation :
make

Test http://localhost:8080/index.cgi :
make test

Install color scheme for gtksourceview :
make color

Uninstall color scheme for gtksourceview :
make uncolor

Install binary file in /usr/bin/ :
make install

Uninstall binary file of /usr/bin/ :
make uninstall

Delete binary file :
make clean


=============WIKI=============

#assign a variable: 
$my_variable=hello world !!

#variable a display:
$[my_variable]

#naming a variable with another variable:
$namevar=my_variable
$\$[namevar]=hello world !!
#display this variable:
$[my_variable]

#execute a command:
<?ls?>
#execute a command and store it in a variable:
$my_variable=<?ls?>

#execute and store the output of a python script or another language:
##python:
$python_example= <?python -c "print(\"$[my_variable], it is a python script !\")
a=1
b=2
if a==2:
    print(\"OK\")
else:
    print(\"NO\")"
?>

##php:
$php_example=<?php -r "phpinfo();"?>

#echo command Shell/Bash
$echo_example= <?echo -n "<strong><strong>LS : </strong>liste des fichiers et r&eacute;pertoires :</strong><br>"
ls | while read line; do 
    echo -n "-$line<br>"
done?>

#condition IF/ELSE
##simple IF
if ($[my_variable]==) {
    <strong>variable empty</strong>
}

##IF and ELSE
if ($[my_variable]!=) {
    <strong>variable not empty</strong>
} else {
    <strong>variable empty</strong>
}
