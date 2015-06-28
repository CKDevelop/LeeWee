<h2>function.cgi</h2>

function _test1() {
    <h3>->Lecture de la fonction N&deg;1</h3>
    _test2()
    <h3>->FIN Lecture de la fonction N&deg;1</h3>
}
function _test2() {
    <h3>->Lecture de la fonction N&deg;2</h3>
    include(scripting.cgi)
    _test3()
    <h3>->FIN Lecture de la fonction N&deg;2</h3>
}
function _test3() {
    <h3>->Lecture de la fonction N&deg;3</h3>
    include(if.cgi)
    <h3>->FIN Lecture de la fonction N&deg;3</h3>
}
<fieldset>
<legend>Les Fonctions</legend>
    _test1()
#    _test4()
    <p style="font-weight:bold;">Fin de la lecture des fonctions</p>
</fieldset>

