<h2>while.cgi</h2>
<fieldset>
    <legend>Condition WHILE</legend>
    #boucle d'entier
    <h3>boucle while d'entier :</h3>
    $a=-5
    if ($[a]<=0) {
        while( $[a] <=5 ) {
            $[a]<br>
            $a=<?echo -n "$(($[a]+1))" ?>
        }
    }
    <hr>
    <h3>boucle while chaine de caractère :</h3>
    $a=Za
    while ($[a]<=50) {
            $a=$[a]a
    }
    #$a=$[a]a
    $[a]Z
    <hr>
    <h3>boucle while imbriqué :</h3>
    $a=0
    if ($[a]<=0) {
        while( $[a] <10 ) {
            if($[a]==5) {
                $a=10
            } else {
                if($[a]>2) {
                    $a=<?echo -n "$(($[a]+2))" ?>
                } else {
                    $a=<?echo -n "$(($[a]+1))" ?>
                }
            }
            <strong>$a->$[a]</strong><br>
            $b=0
            while($[b]<10) {
                $b=<?echo -n "$(($[b]+1))" ?>
                $b->$[b]<br>
            }
            Fin While B<br>
        }
        Fin While A<br>
    }
    Fin condition A<=0<br>
</fieldset>
<br>

