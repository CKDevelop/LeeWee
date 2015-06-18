#! ./../../lw

$title=Welcome
$titlePerl= <?perl -e "print '$[title] in LeeWee Script'"?>
$titleGET=Exemple formulaire GET :
$titlePOST=Exemple formulaire POST :
$titleIF=Exemple condition IF :

<html>
    <head>
        <title >$[titlePerl] </title>
    </head>
    <body>
        <a href="index.cgi?page=home"><h1>$[titlePerl]</h1></a>
        <fieldset>
            <legend>WIKI</legend>
            <ul>
                <li><a href="?page=scripting.cgi">Scripting</a></li>
                <li><a href="?page=get.cgi">Variable GET</a></li>
                <li><a href="?page=post.cgi">Variable POST</a></li>
                <li><a href="?page=if.cgi">Condition IF</a></li>
            </ul>
        </fieldset>
        
        if ($[page]!=) {
            if ($[page]!=home) {
            include($[page])
            }
        }
        
        
    </body>
</html>
