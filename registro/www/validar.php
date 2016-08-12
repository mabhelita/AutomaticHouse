<?php

include "conecta.php";

    
 

if($_GET['aceptar']=="aceptar"){
	$usu=$_GET['nombre'];
	$contra=$_GET['contra'];
	 $SQL = "SELECT * FROM login WHERE usuario='$usu'";
	
     $re = mysql_query($SQL, $serve);
	$n=mysql_num_rows($re);
	if($n>0){
		$SQL1 = "SELECT * FROM login WHERE contra='$contra'";
		$re1 = mysql_query($SQL1, $serve);
	$n1=mysql_num_rows($re1);
		if($n1>0){
			print"logueado";
			header("location:principal.html");
		}
		else{
			
			print"la contraseña es incorrecta";
			
		}
	}
	else{
		
		print"el usuario no existe";
	}
}


//echo "Temperatura: ".mysql_result($re,0,'usuario')."°C"."</br>";



?>