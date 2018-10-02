<?php
    require 'PHPMailer/PHPMailerAutoload.php';
    $mail = new PHPMailer;

    $mail->isSMTP();                            // Set mailer to use SMTP
    $mail->Host = 'ssl://smtp.gmail.com';             // Specify main and backup SMTP servers
    $mail->SMTPAuth = true;                     // Enable SMTP authentication
    $mail->Username = 'theycallmegm300796@gmail.com';          // SMTP username
    $mail->Password = 'GuruMk@30796'; // SMTP password
    $mail->SMTPSecure = 'tls';                  // Enable TLS encryption, `ssl` also accepted
    $mail->Port = 465;                          // TCP port to connect to
    $mail->From='theycallmegm300796@gmail.com';
    $mail->FromName = 'Guru';
    $mail->addReplyTo('no-reply@gmail.com', 'GM');
    $mail->isHTML(true);  // Set email format to HTML
?>

