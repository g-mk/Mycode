<?php
    include 'MailInit.php';
    $mail->addAddress('gmk3071996@gmail.com');   // Add a recipient
    $bodyContent = '<h1>MEPCO SCHLENK ENGG. COLLEGE </h1>';
    $bodyContent .= '<p>Graduation Day Registration Verification</p>';
    $bodyContent .= '<a href="http://localhost:8000/Confirmation.php?code="';
    $mail->Subject = 'Mail Verification';
    $mail->Body    = $bodyContent;
    $stat = $mail->send();
    if(!$stat) {
        echo 'Message could not be sent.';
        echo 'Mailer Error: ' . $mail->ErrorInfo;
    } else {
        echo 'Message has been sent';
    }
?>

