<?php

require_once( $_SERVER['DOCUMENT_ROOT'].'/database.php');

$course_name = filter_input(INPUT_POST, 'name');

$query_course_name = "select * from course where course_name = :name";
$statement_course_name = $db->prepare($query_course_name);
$statement_course_name ->bindValue(':name', $course_name);
$statement_course_name  ->execute();
$coursesbyname = $statement_course_name ->fetchAll();
$statement_course_name ->closeCursor();


if($coursesbyname == null){
    
    include ($_SERVER['DOCUMENT_ROOT'].'/errors/invalid_input.php');
}
else{
    include("../course_search/course_name_search_result.php");
}
