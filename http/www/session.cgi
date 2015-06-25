<h2>session.cgi</h2>
<fieldset>
<legend>Variable de SESSION</legend>
s$varsession7= <?echo -n "<strong>LS : </strong>liste des fichiers et r&eacute;pertoires SYSTEM :<br>"
ls / | while read line; do 
    echo -n "<li>$line</li>"
done?>
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

</fieldset>
<br>
