<fieldset>
    <legend>$[titlePOST]</legend>
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
            <br><img src="$[file_post_filename]" width="200px">
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

