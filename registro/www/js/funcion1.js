(function(){
	var $server;
	$server = 'http://localhost:8080/xampp/registro/www/'$('#aceptar').on('click',function(){
	$usuario=$('#usuario').val();
	$contra=$('#contra').val();
	$.ajax({
		type: "get",
		dataType: 'html',
		url:$server+"/validar.php",
		data: "nombre="+$usuario+"contra"+$contra+"&aceptar=aceptar",
		success:function(data){
			$('#pagina').html(data);
		},
		error:function(data){
			$('#yes').html(data);
		}
	});
});
/*function hora(){
	$.ajax({
		type:"get",
		dataType:'html',
		url:$server+"/validar.php",
		data:"aceptar=",
		success:function(data){
			$('#yes').html(data);
		}
	})
}*/
});