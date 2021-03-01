<?php
    require_once($_SERVER['DOCUMENT_ROOT'].'/database_oo.php');


    $db_instance = new Database();
    $db_instance ->setDSN('mysql:host=127.0.0.1;port=3306;dbname=school_db');
    
    $db_instance ->setUsername('Giova');
    
    $db_instance ->setPassword('V27198123g');
    
    $db = new PDO($db_instance ->getDSN(), $db_instance ->getUsername(), 
                $db_instance ->getPassword());

?>