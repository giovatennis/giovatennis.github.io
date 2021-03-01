<?php
session_start();

if(isset($_POST['clicked'])) {
    unset($_SESSION['email']);
    unset($_SESSION['password']);
    session_destroy();
}

?>
<!DOCTYPE html>

<html>
    <head>
        <meta charset="UTF-8">
        <link rel="stylesheet" type="text/css" href="index.css"/>
        <title>Wesleyan University</title>
    </head>
    <body>
       
        <header>
            <h1>Wesleyan University Website</h1>
            <img src="../images/header.jpg" width="760"
                 height="330">
        </header>
        <h1>Log in</h1>
        <section div class="pad">
        <form action= "log_in_authenticator.php" method="post" id="index">
            <label>Email:</label><input div class="lefted2" type="text" name="email" value="<?php if (isset($_SESSION['email'])) { echo $_SESSION['email'];  } ?>"/>
            <label div class="lefted1">Password:</label><input div class="lefted2" type="text" name="password" value="<?php  if (isset($_SESSION['password'])) { echo $_SESSION['password'];  } ?>"/>
            <input div class="button" type="submit" value="Submit">
        </form>
         <a div class="link" href="../register_student_form.php"> Not Registered? Create an account!</a>
         </section>
    </body>
    <footer>
        <div class="snow">
        <p div class="copyright">
           &copy; <?php echo date("Y"); ?> Wesleyan University™
     </p>
     </div>
    </footer>
</html>
