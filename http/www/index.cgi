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
            </ul>
        </fieldset>
        
        if ($[page]!=) {
            if ($[page]!=home) {
                include($[page].cgi)
            }
        }
        
        if($[varsession3]!=) {
        <p>variable de session <b>varsession3</b> = $[varsession3]</p>
        s$varsession4=salut le monde4 format
        } else {
            s$varsession1=salut le monde1
            s$varsession2=salut le monde2
            s$varsession3=salut le monde3
            s$varsession4=salut le monde4
        }
    </body>
</html>
