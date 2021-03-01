<?php

require_once( $_SERVER['DOCUMENT_ROOT'].'/database.php');
if (!isset($_SESSION)) { session_start(); }
$student_info = "select student_name, birthday,gender, email from student where email = :email";
$statement_info = $db->prepare($student_info);
$statement_info->bindValue(':email', $_SESSION["email"]);
$statement_info->execute();
$all_info = $statement_info->fetchAll();
$statement_info->closeCursor();

?>

<html>
    <head>
        <meta charset="UTF-8">
        <link rel="stylesheet" type="text/css" href="../Profile/update_student_form.css"/>
        <title>Wesleyan University</title>
    </head>
    <body>
    <h1>Personal Information</h1>
    <img src="https://media2.giphy.com/media/xT5LMysSyB5qZZirwQ/giphy.gif" width="265"
                 height="150">
    <div class="righted">
    <form action= "update_student.php" method="post" id="update_student_form">
         <?php foreach($all_info as $info ) : ?>
        <label div class="margin">Name:</label><input div class="margin1" type="text" name="name" value="<?php echo $info['student_name'] ?>"/><br>
        <label div class="margin">Birthday:</label><input div class="margin2" type="text" name="birthday" value="<?php echo $info['birthday'] ?>"/><br>
        <label div class="margin">Gender:</label><input div class="margin3" type="text" name="gender" value="<?php echo $info['gender'] ?>"/><br>
        <label div class="margin">E-mail:</label><input div class="margin4" type="text" name="email" value="<?php echo $info['email'] ?>"/><br>
      <input  type="submit" value="Update student"/> 
       <?php endforeach; ?>
    </form>
    </div>
    <a href="../Profile/password_change.php">Change password?</a>
    </body>
</html>