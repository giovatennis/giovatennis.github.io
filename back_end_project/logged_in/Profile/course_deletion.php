<?php
require_once( $_SERVER['DOCUMENT_ROOT'].'/database.php');
if (!isset($_SESSION)) { session_start(); }


$course_id2 = filter_input(INPUT_POST, 'course_id');



    $query_deletion = 'DELETE FROM enroll WHERE course_id = :course_id and student_email = :email';
    $statement_deletion = $db->prepare($query_deletion);
    $statement_deletion->bindValue(':course_id', $course_id2);
    $statement_deletion->bindValue(':email', $_SESSION["email"]);
    $statement_deletion->execute();
    $statement_deletion->closeCursor();    

include('../Profile/profile_index.php');

?>