#! ./../../lw

$title=Welcome
$titlePerl= <?perl -e "print '$[title] in LeeWee Script'"?>
$titleGET=Exemple formulaire GET :
$titlePOST=Exemple formulaire POST :
$titleIF=Exemple condition IF :
$test1=0
$test2=0
<html>
    <head>
        <title >$[titlePerl] </title>
    </head>
    <body>
        éèà
        :test1
        <fieldset>
            <legend>WIKI</legend>
            <ul>
                <li><a href="scripting.cgi">Scripting</a></li>
                <li><a href="get.cgi">Variable GET</a></li>
                <li><a href="post.cgi">Variable POST</a></li>
                <li><a href="if.cgi">Condition IF</a></li>
            </ul>
        </fieldset>
        
        if ($[test1]==0){
            include(post.cgi)
            include(get.cgi)
            aaa<br>
            bb
            
            :test2
            if ($[test2]!=3){
                <br>test2= $[test2]<br>
                $test2=<?echo -n "$(($[test2]+1))" ?>
                ->test2
            } else {
                <br>Fin variable test2</br>
                include(if.cgi)
                $test1=<?echo -n "$(($[test1]+1))" ?>
                ->test1
            }
        }
    </body>
</html>
