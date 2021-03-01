<?php
require_once( $_SERVER['DOCUMENT_ROOT'].'/database.php');
if (!isset($_SESSION)) { session_start(); }

$enrolled_query = "select course_id,course_name,semester,instructor,classroom,time from enroll where student_email = :email";
$statement_enroll2 = $db->prepare($enrolled_query);
$statement_enroll2->bindValue(':email', $_SESSION["email"]);
$statement_enroll2->execute();
$all_enroll = $statement_enroll2->fetchAll();
$statement_enroll2->closeCursor();
?>

<html>
    <head>
        <meta charset="UTF-8">
        <link rel="stylesheet" type="text/css" href="../Profile/profile_index.css"/>
        <title>Wesleyan University</title>
    </head>
    <header>
            <h1>Wesleyan University Website</h1>
           
    </header>
    <div class="container">
    <body>
        <a href="../home.php">Home</a> <br>  
    <h1> Enrolled so far!</h1>
     <table>
           <tr>
            <th> Course ID </th>
            <th> Course Name</th>
            <th> Semester </th>
            <th> Instructor </th>
            <th> Classroom </th>
            <th> Time </th>
            <th> &numsp;</th>
            
        </tr>
       
        <?php foreach ((array)$all_enroll as $enroll) : ?>
        <tr>    
          <td><?php echo $enroll['course_id']; ?></td>
          <td><?php echo $enroll['course_name']; ?></td>
          <td><?php echo $enroll['semester']; ?></td>
          <td><?php echo $enroll['instructor']; ?></td>
          <td><?php echo $enroll['classroom']; ?></td>
          <td><?php echo $enroll['time']; ?></td>
          <td><form action="../Profile/course_deletion.php" method="post">
            <input type="hidden" name="course_id"
           value="<?php echo $enroll['course_id']; ?>">
            <input type="submit" value="Withdraw">
            </form>    
          </td>
        </tr>
        <?php endforeach; ?>  
        </table>     
    <a div class = "stay" href="../Profile/update_student_form.php">Update personal information</a>
    </body>
     <footer>
        <div class="snow">
        <p div class="copyright">
           &copy; <?php echo date("Y"); ?> Wesleyan University™
     </p>
     </div>
    </footer>
    </div>
</html>