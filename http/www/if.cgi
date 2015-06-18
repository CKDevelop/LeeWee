<fieldset>
    <legend>$[titleIF]</legend>
    #bascule change la valeur de la variable $b pour tester la condition
    $a=1
    $b=1
    $c=4

    <br>condition: $a=$[a] avec $b=$[b]
    if ($[a]!=$[c]){
    <br>a!=c Pas égale<br>
    }
    if ($[a]==$[b]){
        <br><strong>condition 1 [OK] Line 1</strong><br><br>
        if($[a]!=$[b]){
            <br><strong>condition 2 [NO] Line 1</strong>
            <br><strong>condition 2 [NO] Line 2</strong><br><br>
        }else{
             <br><strong>condition 2 [OK] Line 1</strong><br>
            if($[a]==1){
                <br><strong>condition 3 [OK] Line 1</strong>
                <br><strong>condition 3 [OK] Line 2</strong><br>
                $ls=RE-modification de la variable $ls<br><br>
                $[ls]
            }else{
                <br><strong>condition 3 [NO] Line 1</strong>
                <br><strong>condition 3 [NO] Line 2</strong><br><br>
            }
            <br><strong>condition 2 [OK] Line 2</strong><br><br>
        }
        <br><strong>condition 1 [OK] Line 2</strong><br><br>
                
        <br>condition: 1 avec $b=$[b]
        if(1==$[b]){
            <br><strong>sub condition 1 [OK] Line 3</strong><br><br>
        }else{
            <br><strong>sub condition 1 [NO] Line 3</strong><br><br>
        }
                
    }    else {
        <br>condition: $c=$[c] avec 4
        if($[c]==4)     {
            <br><strong>sub condition 1 [NO] Line 2-1</strong><br><br>
        }else{
            <br><strong>sub condition 1 [NO] Line 2-2</strong><br><br>
        }
    }
    <br>
</fieldset>

