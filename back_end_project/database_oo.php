<?php

class Database{
    private $dsn;
    private $username;
    private $password;
    
     public function setDSN($value) {
        $this->dsn = $value;
       }

    public function getDSN() {
        return $this->dsn;
      }
    public function setUsername($value) {
        $this->username = $value;
       }

    public function getUsername() {
        return $this->username;
      }
    public function setPassword($value) {
        $this->password = $value;
       }

    public function getPassword() {
        return $this->password;
      }
        
    
    
    
    
}

?>