<?php
require_once( $_SERVER['DOCUMENT_ROOT'].'/database.php');
if (!isset($_SESSION)) { session_start(); }

$password1 = filter_input(INPUT_POST, 'password');

$password_query = "select password from student where password = :old_pass and email = :email";
$statement_newpass= $db->prepare($password_query);
$statement_newpass->bindValue(':old_pass', $password1);
$statement_newpass->bindValue(':email', $_SESSION["email"]);
$statement_newpass->execute();
$old_password= $statement_newpass->fetch();
$statement_newpass->closeCursor();

if($old_password == null){
    
    include ($_SERVER['DOCUMENT_ROOT'].'/errors/invalid_password.php');
}
else{
    include('../Profile/new_password_success.php');
}

?>

