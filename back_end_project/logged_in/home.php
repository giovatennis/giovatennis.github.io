<?php
if (!isset($_SESSION)) { session_start(); }
?>

<html>
    <head>
        <meta charset="UTF-8">
        <link rel="stylesheet" type="text/css" href="../logged_in/home.css"/>
        <title>Wesleyan University</title>
    </head>
    <header>
            <h1>Wesleyan University Website</h1>
           
    </header>
    <body>
        
        
        <aside div class="right">
        <p1 div class="login_message">Logged in as </p1> <?php echo $_SESSION["email"]; ?> <br>
        <form action="../index.php" method="post" >
          <input div class="submit_button" type="submit" name="clicked" value="Log out"/>
          </form> 
        </aside>
        
        <a div class= "profile" href="../logged_in/Profile/profile_index.php">Profile</a><br>
        <br>
        <br>
        <br>
        <section div class="adjust">
        <a  div class="all1" href="../logged_in/available_courses/available_courses_search.php">All Available courses</a><p div class="all">At Wesleyan we offer world class
        education in all areas of studies, led by academic professionals who care deeply about students' success. 
        Enroll now to join our awesome community!</p><br>
        <a div class="spec" href="../logged_in/course_search/course_search_form.php">Search a course</a><p div class="spec">Looking for a specific course? Look it up
            by the course ID, name of the class, or name of the instructor!</p><br>
        </section>
        <img src="https://media1.tenor.com/images/e72ac68f1f1dc1c503c333cafa920991/tenor.gif?itemid=16745812" width="250"
                 height="130">
        <img src="https://media0.giphy.com/media/TjA6DAFMkIf5cZCOMz/giphy.gif" width="150" height="100"
                 >
       
    </body>
     <footer>
        <div class="snow">
        <p div class="copyright">
           &copy; <?php echo date("Y"); ?> Wesleyan University™
     </p>
     </div>
    </footer>
</html>
