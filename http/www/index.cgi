#! ./../../lw

$title=Welcome
$titlePerl= <?perl -e "print '$[title] in LeeWee Script'"?>
$titleGET=Exemple formulaire GET :
$titlePOST=Exemple formulaire POST :
$titleIF=Exemple condition IF :

<html>
s$varsession7= <?echo -n "<strong>LS : </strong>liste des fichiers et r&eacute;pertoires SYSTEM :<br>"
ls / | while read line; do 
    echo -n "<li>$line</li>"
done?>
    <head>
        <title>$[titlePerl]</title>
    </head>
    <body>
        <a href="index.cgi?page=home"><h1>$[titlePerl]</h1></a>
        <fieldset>
            <legend>WIKI</legend>
            <ul>
                <li><a href="?page=scripting">Scripting</a></li>
                <li><a href="?page=get">Variable GET</a></li>
                <li><a href="?page=post">Variable POST</a></li>
                <li><a href="?page=if">Condition IF</a></li>
                <li><a href="?page=while">Condition WHILE</a></li>
            </ul>
        </fieldset>
        
        if ($[page]!=) {
            if ($[page]!=home) {
                include($[page].cgi)
            }
        }
        $[varsession7]
        if($[varsession3]!=) {
            <p>variable de session <b>varsession3</b> = $[varsession3]</p>
            s$varsession7= <?echo -n "<strong>LS : </strong>liste des fichiers et r&eacute;pertoires HOME:<br>"
ls /home | while read line; do
echo -n "<li>$line</li>"
done?>
            s$varsession4=salut le monde4 format
            if($[varsession5]==) {
                s$varsession5=<?ls?>
            }

        } else {
            s$varsession1=salut le monde1
            s$varsession2=salut le monde2
            s$varsession3=salut le monde3
            s$varsession4=salut le monde4
        }
        if($[varsession5]!=) {
            <p><strong>$[varsession5]</strong></p>
             $[varsession7]
        }
    </body>
</html>
