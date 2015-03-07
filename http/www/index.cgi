#! ./../../lw

$ii=aa
$ipa=<?/sbin/ifconfig | grep 'inet adr' | cut -d: -f2 | cut -d' ' -f1?>
$ifconfig=<?/sbin/ifconfig?>

$ls= <?echo -n "<strong><strong>LS : </strong>liste des fichiers et r&eacute;pertoires :</strong><br>"
ls | while read line; do 
    echo -n "-$line<br>"
done?>
$env= <?env?>
$title= Welcome

$python1= <?python -c "print(\"$[title], it is a python script !\")
a=1
b=2
if a==2:
    print(\"OK\")
else:
    print(\"NO\")"
?>

$titlePerl= <?perl -e "print '$[title] in LeeWee'"?>
$mot=welcome
$\$[mot]=Welcome in LeeWee Script

<html>
    <head>
        <title >$[titlePerl] </title>
    </head>
    <body>
        <h1>$[welcome]</h1>
        <fieldset>
            <legend>Exemple formulaire POST :</legend>
            <form method="POST">
                Text1 :<input type="text" name="txt_post" value="$[txt_post]"><br>
                Text2 :<textarea name="txt2_post" >$[txt2_post]</textarea><br>
                <input type="submit" value="Valider">
            </form>
        </fieldset>
        
        <fieldset>
            <legend>Exemple formulaire POST FILE :</legend>
            <form method="POST" enctype="multipart/form-data">
                Fichier1 $[file_post_type]: <input type="file" name="file_post">
                if(!=$[file_post_filename]){
                    <br><a href="$[file_post_filename]">Télécharger</a>
                }
                <br>
                Fichier2 $[file2_post_type]: <input type="file" name="file2_post">
                if(!=$[file2_post_filename]){
                    <br><a href="$[file2_post_filename]">Télécharger</a>
                }
                <br>
                <input type="submit" value="Valider">
            </form>
        </fieldset>
        
        <fieldset>
            <legend>Exemple formulaire GET :</legend>
            <form method="GET">
                Text1 :<input type="text" name="txt_get" value="$[txt_get]"><br>
                Text2 :<input type="text" name="txt2_get" value="$[txt2_get]"><br>
                <input type="submit" value="Valider">
            </form>
        </fieldset>
        
        <fieldset>
            <strong>IP :</strong><br>
            $[ipa]
            <br><br>
            
            <strong>IFCONFIG :</strong><br>
            $[ifconfig]<br><br>
            
            $[ls]
            <br><br>
            $[env]
            <br><br>
            <strong>Variable d'environnement 'QUERY_STRING' :</strong><br>
            $[QUERY_STRING]
            <br><br>
            
            #modification de la variable $ls
            $ls=<?echo "modification de la variable \$ls<br><br>"?>
            $[ls]
            
            $a=1
            $b=$[a]
            if($[a]=$[b]){
                <br><strong>condition 1 True Line 1</strong><br><br>
                if($[a]!=$[b]){
                    <br><strong>condition 2 True Line 1</strong>
                    <br><strong>condition 2 True Line 2</strong><br><br>
                }else{
                    <br><strong>condition 2 False Line 1</strong><br>
                    if($[a]=$[b]){
                        <br><strong>condition 3 True Line 1</strong>
                        <br><strong>condition 3 True Line 2</strong><br>
                        $ls=RE-modification de la variable $ls<br><br>
                        $[ls]
                    }else{
                        <br><strong>condition 3 False Line 1</strong>
                        <br><strong>condition 3 False Line 2</strong><br><br>
                    }
                    <br><strong>condition 2 False Line 2</strong><br><br>
                }
            }else{
                <br><strong>condition 1 False Line 1</strong><br><br>
            }
            <br>
            $[python1]
        </fieldset>
    </body>
</html>

