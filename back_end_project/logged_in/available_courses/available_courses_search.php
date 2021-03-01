<?php
require_once( $_SERVER['DOCUMENT_ROOT'].'/database.php');


$query_courses = "select * from course ";
$statement_courses = $db->prepare($query_courses);
$statement_courses ->execute();
$all_courses = $statement_courses->fetchAll();
$statement_courses->closeCursor();
//just php code here to get all courses






include("../available_courses/available_courses_result.php");
?>


