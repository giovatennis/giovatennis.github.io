<?php

require_once( $_SERVER['DOCUMENT_ROOT'].'/database.php');

$course_id = filter_input(INPUT_POST, 'id');

$query_course_id = "select * from course where course_id = :id";
$statement_course_id = $db->prepare($query_course_id);
$statement_course_id ->bindValue(':id', $course_id);
$statement_course_id  ->execute();
$coursesbyid = $statement_course_id ->fetchAll();
$statement_course_id ->closeCursor();

if($coursesbyid == null){
    
    include ($_SERVER['DOCUMENT_ROOT'].'/errors/invalid_input.php');
}
else{
    include("../course_search/courseid_search_result.php");
}


?>
