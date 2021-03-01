<?php
require_once('../class_project/database.php');

//php stuff to register the studnet in the db
$name = filter_input(INPUT_POST, 'name');
$id = filter_input(INPUT_POST, 'student_id');
$birthday = filter_input(INPUT_POST, 'birthday');
$gender = filter_input(INPUT_POST, 'gender');
$email_student = filter_input(INPUT_POST, 'email');
$password_student = filter_input(INPUT_POST, 'password');
 $query_student= 'insert into student (student_id,student_name,birthday,gender,email,password)
         values(:id,:name,:birthday,:gender,:email,:password)';
  $statement_student = $db->prepare($query_student);
  $statement_student ->bindValue(':name', $name);
  $statement_student ->bindValue(':id', $id);
  $statement_student ->bindValue(':birthday', $birthday);
  $statement_student ->bindValue(':gender', $gender);
  $statement_student ->bindValue(':email', $email_student);
  $statement_student ->bindValue(':password', $password_student);
  $statement_student ->execute();
  $statement_student->closeCursor();




include("../class_project/index.php");

?>
