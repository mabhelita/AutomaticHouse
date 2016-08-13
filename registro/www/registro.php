<?php
if($_GET['grabar']=="grabar"){
	$codigo=$_GET['codigo'];
	$nombre=$_GET['nombre'];
	$apellido=$_GET['apellido'];
	$usuario=$_GET['usua'];
	$contrasenia=$_GET['contrasenia'];
	$correo=$_GET['correo'];
// process form
	
include"conecta.php";

$sql = "INSERT INTO login (codigo, nombre, apellido, usuario, contra,correo) VALUES ('$codigo', '$nombre', '$apellido', '$usuario','$contrasenia','$correo') " ;
 
$result = mysql_query($sql,$serve);
echo "se inserto correctaamente";
}
?>