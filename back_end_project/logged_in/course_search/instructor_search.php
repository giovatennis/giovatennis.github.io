<?php

require_once( $_SERVER['DOCUMENT_ROOT'].'/database.php');

$instructor = filter_input(INPUT_POST, 'instructor');

$query_instructor = "select * from course where instructor = :ins";
$statement_instructor= $db->prepare($query_instructor);
$statement_instructor ->bindValue(':ins', $instructor);
$statement_instructor  ->execute();
$coursesbyinst = $statement_instructor ->fetchAll();
$statement_instructor ->closeCursor();

if($coursesbyinst == null){
    
    include ($_SERVER['DOCUMENT_ROOT'].'/errors/invalid_input.php');
}
else{
    include("../course_search/instructor_search_result.php");
}

