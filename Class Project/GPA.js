var $ = function (id) {
	return document.getElementById(id);
};


var calculation = function() {
    
    var cred_1 = parseInt($("course_1_ch").value);
    var grade_1 = $("course_1_lg").value;
    var cred_2= parseInt($("course_2_ch").value);
    var grade_2= $("course_2_lg").value;
    
    //check to see if these are value or not
    var cred_3= parseInt($("course_3_ch").value);
    var grade_3= $("course_3_lg").value;
    var cred_4= parseInt($("course_4_ch").value);
    var grade_4= $("course_4_lg").value;
    var cred_5= parseInt($("course_5_ch").value);
    var grade_5= $("course_5_lg").value;
    
   // alert(parseInt($("course_3_ch").value)); //Nan
   // alert($("course_3_lg").value);//empty
    
    
    
    //change letter to num of course 1
     if (grade_1 == 'A'){
        grade_1 = 4.0;
    }
    if (grade_1 == 'B'){
        grade_1 = 3.0;
    }
    if (grade_1 == 'C'){
        grade_1  = 2.0;
    }
    if (grade_1 == 'D'){
        grade_1  = 1.0;
    }
    if (grade_1 == 'F'){
        grade_1  = 0.0;
    }
    
    
    //change letter to num of course 2
      if (grade_2 == 'A'){
        grade_2 = 4.0;
    }
    if (grade_2 == 'B'){
        grade_2 = 3.0;
    }
    if (grade_2 == 'C'){
        grade_2  = 2.0;
    }
    if (grade_2 == 'D'){
        grade_2  = 1.0;
    }
    if (grade_2 == 'F'){
        grade_2  = 0.0;
    }
   
    

       //change letter to num of course 3
      if (grade_3 == 'A'){
        grade_3 = 4.0;
    }
    if (grade_3 == 'B'){
        grade_3 = 3.0;
    }
    if (grade_3 == 'C'){
        grade_3  = 2.0;
    }
    if (grade_3 == 'D'){
        grade_3  = 1.0;
    }
    if (grade_3 == 'F'){
        grade_3  = 0.0;
    }
    
    

       //change letter to num of course 4
    if (grade_4 == 'A'){
        grade_4 = 4.0;
    }
    if (grade_4 == 'B'){
        grade_4 = 3.0;
    }
    if (grade_4 == 'C'){
        grade_4  = 2.0;
    }
    if (grade_4 == 'D'){
        grade_4  = 1.0;
    }
    if (grade_4 == 'F'){
        grade_4  = 0.0;
    }
    

       //change letter to num of course 5
    if (grade_5 == 'A'){
        grade_5 = 4.0;
    }
    if (grade_5 == 'B'){
        grade_5 = 3.0;
    }
    if (grade_5 == 'C'){
        grade_5  = 2.0;
    }
    if (grade_5 == 'D'){
        grade_5  = 1.0;
    }
    if (grade_5 == 'F'){
        grade_5  = 0.0;
    }
    
    
    
   // if only 1 and 2 have value
    
    if( (isNaN(cred_3))  && (isNaN(cred_4)) && (isNaN(cred_5)) ){
        
    var total_1 = cred_1 * grade_1;
    var total_2 = cred_2 * grade_2;
  
    var total_up = total_1 + total_2;
    
    var total_down = cred_1 + cred_2;
    
    var result = total_up/total_down;
    
    $("avg_gpa").value = result.toFixed(2);
          
          
        
    }
    
    //if only 1 and 2 and 3 have value
    
     if( ( grade_3 != "") && (isNaN(cred_4)) && (isNaN(cred_5)) ){
        
    var total_1 = cred_1 * grade_1;
    var total_2 = cred_2 * grade_2;
    var total_3 = cred_3 * grade_3;
    
    
    var total_up = total_1 + total_2 + total_3;
    
    var total_down = cred_1 + cred_2 + cred_3 ;
    
    var result = total_up/total_down;
    
    $("avg_gpa").value = result.toFixed(2);
          
          
          
        
        
    }
    
    //if only 1,2,3,4 have value
    
    if( ( grade_3 != "") && ( grade_4 != "") && (isNaN(cred_5)) ){
        
    var total_1 = cred_1 * grade_1;
    var total_2 = cred_2 * grade_2;
    var total_3 = cred_3 * grade_3;
    var total_4 = cred_4 * grade_4;
   
    var total_up = total_1 + total_2 + total_3 + total_4;
    
    var total_down = cred_1 + cred_2 + cred_3 + cred_4;
    
    var result = total_up/total_down;
    
    $("avg_gpa").value = result.toFixed(2);
          
          
          
          
          
          
        
        
    }
    
    
    
    //if all have value
    
     if( ( grade_3 != "") && ( grade_4 != "")  && ( grade_5 != "") ){
        
        
    var total_1 = cred_1 * grade_1;
    var total_2 = cred_2 * grade_2;
    var total_3 = cred_3 * grade_3;
    var total_4 = cred_4 * grade_4;
    var total_5 = cred_5 * grade_5;
    
    var total_up = total_1 + total_2 + total_3 + total_4 + total_5;
    
    var total_down = cred_1 + cred_2 + cred_3 + cred_4 + cred_5;
    
    var result = total_up/total_down;
    
    $("avg_gpa").value = result.toFixed(2);
         
     }
    
}

window.onload = function() {
    
    $("course_1_ch").focus();
    $("submit").onclick = calculation;
    //reset button everything blank
    
}