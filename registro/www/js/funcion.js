$( document ).ready(function() {
                    var $server;
                    $server = 'http://localhost:8080/xampp/registro/www/'; 
	
	             $('#grabar').on('click',function(){
					$codigo=$('#codigo').val();
					$nombre=$('#nombre').val();	
					$apellido=$('#apellido').val();
					$usua=$('#usuario1').val();
					$contrasenia=$('#pass').val();
					$correo=$('#correo').val();
					$.ajax({

                               type: "get",
                               dataType  : 'html',
                               url: $server+"/registro.php",
                               data: "codigo="+$codigo+"&nombre="+$nombre+"&apellido="+$apellido+"&usua="+$usua+"&contrasenia="+$contrasenia+"&correo="+$correo+"&grabar=grabar",
                               success: function(data) {
                                    $('#pagina2').html(data);
                                },
						       error : function(data) {
								   $('#yes').html(data);
    }
                           });	
						
					})  ;

                 

            });
