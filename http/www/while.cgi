<h2>if.cgi</h2>
<fieldset>
    <legend>Condition WHILE</legend>
    #boucle d'entier
    $a=-5
    if ($[a]<=0) {
        while( $[a] <=5 ) {
            $[a]<br>
            $a=<?echo -n "$(($[a]+1))" ?>
        }
    }
    
    #boucle chaine de caractère
    $a=Za
    while ($[a]<=50) {
            $a=$[a]a
    }
    #$a=$[a]a
    $[a]Z
</fieldset>
<br>

