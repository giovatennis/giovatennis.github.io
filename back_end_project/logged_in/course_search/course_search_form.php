<html>
    <head>
        <meta charset="UTF-8">
        <title>Wesleyan University</title>
        <link rel="stylesheet" type="text/css" href="../course_search/course_search.css"/>
    </head>
    <header></header>  
    <body>
        <a href="../home.php">Home</a> 
        
        <h1>Search By:</h1>
        <div class="righted">
        <form action= "id_course_search.php" method="post" >
            <label>Course ID:</label><input div class="text1" type="text" name="id"/>
            <input type="submit" value="Submit" >
        </form>
        <form action= "name_search.php" method="post">
            <label>Name of Course:</label><input div class="text2" type="text" name="name"/>
            <input type="submit" value="Submit">
        </form>
        <form action= "instructor_search.php" method="post">
            <label>Instructor:</label><input div class="text3" type="text" name="instructor"/>
            <input type="submit" value="Submit">
        </form>
       </div>
    </body>
</html>