#! ./../../lw

$title=Welcome
$titlePerl= <?perl -e "print '$[title] in LeeWee Script'"?>
$titleGET=Exemple formulaire GET :
$titlePOST=Exemple formulaire POST :
$titleIF=Exemple condition IF :
$test1=0
<html>
    <head>
        <title >$[titlePerl] </title>
    </head>
    <body>
        éèà
        <fieldset>
            <legend>WIKI</legend>
            <ul>
                <li><a href="scripting.cgi">Scripting</a></li>
                <li><a href="get.cgi">Variable GET</a></li>
                <li><a href="post.cgi">Variable POST</a></li>
                <li><a href="if.cgi">Condition IF</a></li>
            </ul>
        </fieldset>
        
        
        include(post.cgi)
        include(get.cgi)
        :get
        if ($[test1]!=3){
            <br>variable $[test1]</br>
            $test1=<?echo -n "$(($[test1]+1))" ?>
            ->get
        } else {
            <br>Fin variable $[test1]</br>
            include(if.cgi)
        }
    </body>
</html>
