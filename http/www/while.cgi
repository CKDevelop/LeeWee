<h2>if.cgi</h2>
<fieldset>
    <legend>Condition WHILE</legend>
    #boucle d'entier
    <p>boucle while d'entier :</p>
    $a=-5
    if ($[a]<=0) {
        while( $[a] <=5 ) {
            $[a]<br>
            $a=<?echo -n "$(($[a]+1))" ?>
        }
    }
    
    <p>boucle while chaine de caractère :</p>
    $a=Za
    while ($[a]<=50) {
            $a=$[a]a
    }
    #$a=$[a]a
    $[a]Z
    
    <p>boucle while imbriquer :</p>
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
            $a->$[a]<br>
            if($[a]>=10) {
                $b=0
                while($[b]<=10) {
                    $b=<?echo -n "$(($[b]+1))" ?>
                }
                $b->$[b]<br>
            }
        }
    }
</fieldset>
<br>

