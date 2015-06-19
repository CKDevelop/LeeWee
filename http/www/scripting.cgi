<h2>scripting.cgi</h2>

$ii=aa
$ipa=<?/sbin/ifconfig | grep 'inet adr' | cut -d: -f2 | cut -d' ' -f1?>
$ifconfig=<?/sbin/ifconfig?>

$ls= <?echo -n "<strong><strong>LS : </strong>liste des fichiers et r&eacute;pertoires :</strong><br>"
ls | while read line; do 
    echo -n "-$line<br>"
done?>
$env= <?env?>
$title=Welcome

$python1= <?python -c "print(\"<strong>$[title]</strong>, it is a python script !\")
a=1
b=1
if a==b:
    print(\"<strong>OK</strong>\")
else:
    print(\"<strong>NO</strong>\")"
?>

$mot=welcome
$\$[mot]=$[title] in LeeWee Script
        <h1>$[welcome]</h1>
        
        <fieldset>
            <strong>IP :</strong><br>
            $[ipa]
            <br><br>
            
            <strong>IFCONFIG :</strong><br>
            $[ifconfig]<br><br>
            
            $[ls]
            <br><br>
            $[env]
            <br><br>
            <strong>Variable d'environnement 'QUERY_STRING' :</strong><br>
            $[QUERY_STRING]
            <br><br>
            
            #modification de la variable $ls
            $ls=<?echo "modification de la variable \$ls<br><br>"?>
            $[ls]
            
            <br>
            $[python1]
        </fieldset>
<h2>Example PHP</h2>
$php_example=<?php -r "phpinfo();"?>
$[php_example]
