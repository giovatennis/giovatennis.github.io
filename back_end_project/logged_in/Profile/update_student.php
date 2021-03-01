<?php


require_once( $_SERVER['DOCUMENT_ROOT'].'/database.php');
if (!isset($_SESSION)) { session_start(); }

$name_update = filter_input(INPUT_POST, 'name');
$birthday_update = filter_input(INPUT_POST, 'birthday');
$gender_update = filter_input(INPUT_POST, 'gender');
$email_update = filter_input(INPUT_POST, 'email');

     
//then do query with all these values to update the customer where custID
$query_update = "UPDATE student SET student_name = :name,
        birthday = :birthday, gender = :gender, email = :email_new  where
        email = :email_old";
$statement_update = $db->prepare($query_update);
$statement_update->bindValue(':name', $name_update);
$statement_update->bindValue(':birthday', $birthday_update);
$statement_update->bindValue(':gender', $gender_update);
$statement_update->bindValue(':email_new', $email_update); 
$statement_update->bindValue(':email_old', $_SESSION["email"]);
$statement_update->execute();
$statement_update->closeCursor();



$query_update2 = "UPDATE enroll SET student_email = :email_new
         where student_email = :email_old";
$statement_update2 = $db->prepare($query_update2);
$statement_update2->bindValue(':email_new', $email_update); 
$statement_update2->bindValue(':email_old', $_SESSION["email"]);
$statement_update2->execute();
$statement_update2->closeCursor();

//update session info with new email
$_SESSION["email"] = $email_update;

  
include ('../Profile/profile_index.php');

?>