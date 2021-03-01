<?php

require_once( $_SERVER['DOCUMENT_ROOT'].'/database.php');
if (!isset($_SESSION)) { session_start(); }

$password_new = filter_input(INPUT_POST, 'password');

$query_update_pass = "UPDATE student SET password = :pass
         where email = :email";
$statement_newpass1= $db->prepare($query_update_pass);
$statement_newpass1->bindValue(':pass', $password_new);
$statement_newpass1->bindValue(':email', $_SESSION["email"]);
$statement_newpass1->execute();
$statement_newpass1->closeCursor();

$_SESSION["password"] = $password_new;

include ("../Profile/profile_index.php");



?>

