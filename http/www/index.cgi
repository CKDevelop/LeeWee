#! ./../../lw

$title=Welcome
$titlePerl= <?perl -e "print '$[title] in LeeWee Script'"?>
$titleGET=Exemple formulaire GET :
$titlePOST=Exemple formulaire POST :
$titleIF=Exemple condition IF :
<html>
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
                <li><a href="?page=function"><span style="color:#c4a000;">[FIXME]</span> Gestion des FONCTIONS</a></li>
                <li><a href="?page=session"><span style="color:#c4a000;">[FIXME]</span> Variable de SESSION</a></li>
            </ul>
        </fieldset>
        
        if ($[page]!=) {
            if ($[page]!=home) {
                include($[page].cgi)
            }
        }
    </body>
</html>
