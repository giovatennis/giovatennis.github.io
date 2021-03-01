<?php
if (!isset($_SESSION)) { session_start(); }
?>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Wesleyan University</title>
        <link rel="stylesheet" type="text/css" href="../course_search/course_result.css"/>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
    </head>
    <script> //script so that when the form submits it doesnt leave the page
    $(document).ready(function(){
       var $form = $('form');
       $form.submit(function(){
          $.post($(this).attr('action'), $(this).serialize(), function(response){
                // do something here on success
          },'json');
          return false;
       });
    });
    </script>
     <header>
            <h1>Wesleyan University Website</h1>
           
    </header>
    <body>
        <a href="../home.php">Home</a> 
        
        <table>
           <tr>
            <th> Course ID </th>
            <th> Course Name</th>
            <th> Semester </th>
            <th> Instructor </th>
            <th> Classroom </th>
            <th> Time </th>
            <th> &nbsp; </th>
        </tr>
       
        <?php foreach ((array)$coursesbyname as $coursebyname) : ?>
        <tr>    
          <td><?php echo $coursebyname['course_id']; ?></td>
          <td><?php echo $coursebyname['course_name']; ?></td>
          <td><?php echo $coursebyname['semester']; ?></td>
          <td><?php echo $coursebyname['instructor']; ?></td>
          <td><?php echo $coursebyname['classroom']; ?></td>
          <td><?php echo $coursebyname['time']; ?></td>
          <td><form action="enroll_course.php" method="post" 
                    onsubmit="enroll_button.disabled = true;
                    return true;">
            <input type="hidden" name="email"
           value="<?php echo $_SESSION["email"]; ?>">
            <input type="hidden" name="id"
           value="<?php echo $coursebyname['course_id']; ?>">
            <input type="hidden" name="name"
           value="<?php echo $coursebyname['course_name']; ?>">
            <input type="hidden" name="semester"
           value="<?php echo $coursebyname['semester']; ?>">
            <input type="hidden" name="instructor"
           value="<?php echo $coursebyname['instructor']; ?>">
            <input type="hidden" name="class"
           value="<?php echo $coursebyname['classroom']; ?>">
            <input type="hidden" name="time"
           value="<?php echo $coursebyname['time']; ?>">
            <input type="submit" name="enroll_button" value="Enroll" >
           
            </form></td>
            
           
            
        </tr>
        <?php endforeach; ?>  
        </table>     
    </body>
    <footer>
        <div class="snow">
        <p div class="copyright">
           &copy; <?php echo date("Y"); ?> Wesleyan University™
     </p>
     </div>
    </footer>
</html>
