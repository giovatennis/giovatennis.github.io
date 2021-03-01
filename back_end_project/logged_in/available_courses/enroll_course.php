<?php

require_once( $_SERVER['DOCUMENT_ROOT'].'/database.php');

        $email_enroll = filter_input(INPUT_POST, 'email');
        $id_enroll = filter_input(INPUT_POST, 'id');
        $name_enroll = filter_input(INPUT_POST, 'name');
        $class_enroll = filter_input(INPUT_POST, 'class');
        $semester_enroll = filter_input(INPUT_POST, 'semester');
        $instructor_enroll = filter_input(INPUT_POST, 'instructor');
        $time_enroll = filter_input(INPUT_POST, 'time');


        $query_enroll = "insert into enroll (student_email,course_id,course_name,classroom,semester,instructor,
            time) values(:student_email,:course_id,:course_name,:classroom,:semester,:instructor,:time)";
        $statement_enroll = $db->prepare($query_enroll);
        $statement_enroll ->bindValue(':student_email', $email_enroll);
        $statement_enroll ->bindValue(':course_id', $id_enroll);
        $statement_enroll ->bindValue(':course_name', $name_enroll);
        $statement_enroll ->bindValue(':classroom', $class_enroll);
        $statement_enroll ->bindValue(':semester', $semester_enroll);
        $statement_enroll ->bindValue(':instructor', $instructor_enroll);
        $statement_enroll ->bindValue(':time', $time_enroll);
        $statement_enroll ->execute();
        $statement_enroll->closeCursor();     

?>

