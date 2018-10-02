set ns [new Simulator]
set nf [open out.nam w]
$ns namtrace-all $nf
proc finish{} {
 $ns flush-trace
 close $nf
 exec nam out.nam &
 exit 0
}
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
$ns duplex-link $n0 $n1 2Mb 10ms DropTail
$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
$ns duplex-link $n2 $n3 2Mb 10ms DropTail
$ns duplex-link $n2 $n4 2Mb 10ms DropTail
$ns duplex-link $n3 $n4 2Mb 10ms DropTail
$ns queue-limit $n0 $n2 10
$ns duplex-link-op $n0 $n1 orient right
$ns duplex-link-op $n0 $n2 orient right-down
$ns duplex-link-op $n2 $n3 orient left-down
$ns duplex-link-op $n2 $n4 orient right-down
set tcp [new Agent/TCP]
$ns attach-agent $no $tcp
set sink [new Agent/TCPSink]
$ns attach-agent $n2 $sink
$ns connect $tcp $sink
set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ns at 0.1 "$ftp.start"
$ns at 2.0 "$ftp.stop"
$ns at 3.0 "finish"
$ns run
$ns rtproto DV
$ns rtmodel-at 0.1 up $n0 $n2
$ns rtmodel-at 0.5 down $n0 $n2
$ns rtmodel-at 1 up $n0 $n2


