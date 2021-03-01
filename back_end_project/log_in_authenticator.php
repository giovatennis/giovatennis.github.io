<?php

//php stuff to verify if it is the correct user/pass

require_once('../class_project/database.php');

$email = filter_input(INPUT_POST, 'email');
$password = filter_input(INPUT_POST, 'password');
 $query_password = 'select email, password from student where email = :email
          and password = :password';
  $statement_password = $db->prepare($query_password);
  $statement_password ->bindValue(':email', $email);
  $statement_password ->bindValue(':password', $password);
  $statement_password ->execute();
  $valid = $statement_password->fetchAll();
  $statement_password->closeCursor();
  
  //if error
  if ($valid == null){
        
        include('../class_project/errors/log_in_error.php');
        
    }
    else{
    
    //else create session
    
    if(session_id() === null ){
        //$lifetime = 60 * 60 * 24 * 14;    // 2 weeks in seconds
        session_set_cookie_params(0);  
    }
    
    session_start();
   
    $_SESSION['email'] = $email;
    $_SESSION['password'] = $password;
    include("../class_project/logged_in/home.php");
    }

?>

