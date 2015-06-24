<h2>if.cgi</h2>
<fieldset>
    <legend>Condition WHILE</legend>
    $a=0
    if ($[a]==0) {
        while($[a]!=201) {
            $[a]    <br>
            $a=<?echo -n "$(($[a]+1))" ?>
        }
    }
</fieldset>
<br>

